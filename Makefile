# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 16:54:24 by abelov            #+#    #+#              #
#    Updated: 2025/08/14 16:54:24 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Scaffolding Makefile for cxx_leetcode
# Usage:
#   make new
#   make list-template
#
# It creates:
#   <NAME>/
#     CMakeLists.txt        (from template, placeholders substituted)
#     src/main.cpp
#     src/Solution.cpp
#     include/Solution.hpp  (optional per-problem header)

SHELL			:= /bin/bash
TEMPLATE_DIR	?= templates/assignment
PLACEHOLDER		?= __PROJECT_NAME__


# Defaults to quiet. Use "make V=1" to have verbose output.
V ?= 0
ifeq ($(V),0)
  Q := @
  MAKEFLAGS += --no-print-directory
else
  Q :=
endif
export V

ifeq ($(MAKELEVEL),0)
	ifeq ($(filter "--output-sync=target",$(MAKEFLAGS)),)
		MAKEFLAGS += --output-sync=target
	endif
endif

all: ensure-template
	$(Q)printf '\n'
	$(Q)printf '=%.0s' {1..60}; printf '\n\n'
	$(Q)echo -e "  Usage: make new\n"
	$(Q)echo -e "  Creates new assignment project folder based on a template\n"
	$(Q)printf '=%.0s' {1..60}; printf '\n\n'

## Core rule: make new-<name>
new-%: ensure-template
	$(Q)set -e; \
	export name="$*"; \
	if [ -e "$$name" ]; then \
		printf "Directory '%s' already exists\n" "$$name" >&2; exit 1; \
	fi; \
	printf "Creating '%s'...\n" "$$name"; \
	sed -e '0,/main/{/main/i\' -e "/$$name/$$name" -e '}' -i .gitignore; \
	mkdir -p "$$name/src" "$$name/include"; \
	rsync -a "$(TEMPLATE_DIR)/" "$$name/"; \
	export files=( \
	  "$$name/CMakeLists.txt" \
	  "$$name"/src/*.cpp \
	  "$$name"/include/*.hpp \
	); \
	perl -pi -e 's/$(PLACEHOLDER)/'"$$name"'/g;' \
		$${files[@]} 2>/dev/null || true; \
	for f in $${files[@]}; do \
	  vim -Es -Nu NONE -c "runtime plugin/stdheader.vim" +"Stdheader" +wq -- "$$f"; \
	done; \
	echo "add_subdirectory($$name)" >> CMakeLists.txt; \
	git add "$$name" .gitignore; \
	printf "Assignment '%s' created.\n" "$$name"; \
	cmake -S . -B .build -G Ninja && \
	cmake --build .build --target "$$name";

## Sanity check that template exists
ensure-template:
	$(Q)[ -d "$(TEMPLATE_DIR)" ] || { \
		printf "Missing template dir: %s\n" "$(TEMPLATE_DIR)" >&2; \
		printf "Create it and add CMakeLists.txt, src/, include/ templates.\n" >&2; \
		exit 3; \
	}

# Show what is in the template
list-template: ensure-template
	$(Q)printf "Template files under %s:\n" "$(TEMPLATE_DIR)"
	$(Q)find "$(TEMPLATE_DIR)" -maxdepth 2 -type f | sed 's|^|  |'

# Name for interactive mode if NAME was not provided
PROJECT_NAME ?= $(shell bash -c "echo 'Name of the new stack to be created:' >&2; read -e -p $$'> ' stack_name;"' echo $$stack_name')

# Interactive variant, will prompt for the name
new: ensure-template
	+$(Q)$(MAKE) --no-print-directory new-$(PROJECT_NAME)

.PHONY: all new-% new list-template ensure-template