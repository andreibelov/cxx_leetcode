# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 12:58:14 by abelov            #+#    #+#              #
#    Updated: 2025/08/15 19:07:08 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.27)

include_directories(include)

set(CMAKE_CXX_COMPILER gcc)
#set(CMAKE_CXX_COMPILER g++)
#set(CMAKE_CXX_COMPILER clang++)

project(cxx_leetcode CXX C ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

set(COMMON_LDFLAGS
        -lstdc++
        -fsanitize=address
        -fsanitize=undefined
        -fno-sanitize-recover
        -fsanitize=float-divide-by-zero
        -fsanitize=float-cast-overflow)
set(COMMON_CFLAGS
        -Wall -Wextra -Werror
        -Wwrite-strings -Wnarrowing
        -Wno-error=unused-parameter
        -Wno-error=unused-variable
        -O0
        -masm=att
        -ffunction-sections
        -fdata-sections
        -fno-omit-frame-pointer
        -fdwarf2-cfi-asm
        -fcf-protection=none
        -mmanual-endbr
        -g3 -gdwarf-3
        -fasynchronous-unwind-tables
        -fsanitize=address
        -fsanitize=undefined
        -fno-sanitize-recover
        -fsanitize=float-divide-by-zero
        -fsanitize=float-cast-overflow
)

add_subdirectory(valid_parentheses)
add_subdirectory(merge_sorted_array)
add_subdirectory(merge_two_sorted_lists)
add_subdirectory(lru_cache)
add_subdirectory(rotate_array)
add_subdirectory(remove_element)
add_subdirectory(remove_duplicates_from_sorted_array)
add_subdirectory(remove_duplicates_from_sorted_array_ii)
add_subdirectory(majority_element)
