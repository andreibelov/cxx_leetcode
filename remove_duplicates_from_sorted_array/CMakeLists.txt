# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 16:47:24 by abelov            #+#    #+#              #
#    Updated: 2025/08/17 00:07:21 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.16)
project(remove_duplicates_from_sorted_array CXX C ASM)

set(TARGET_EXE_NAME "${PROJECT_NAME}_exe")

add_executable(${TARGET_EXE_NAME}
		src/main.cpp
		src/Solution.cpp)

target_compile_definitions(${TARGET_EXE_NAME} PRIVATE USE_SIMPLE)
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS})
target_link_libraries(${TARGET_EXE_NAME} PRIVATE ${COMMON_LIBS})
target_include_directories(${TARGET_EXE_NAME}
		PRIVATE "${PROJECT_SOURCE_DIR}/include")

# Drop the binary next to sources for quick runs
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
		OUTPUT_NAME "${PROJECT_NAME}")
