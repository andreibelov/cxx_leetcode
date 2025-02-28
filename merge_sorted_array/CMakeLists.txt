# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 13:05:37 by abelov            #+#    #+#              #
#    Updated: 2025/02/26 13:05:38 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(merge_sorted_array CXX C ASM)

set(TARGET_EXE_NAME "${PROJECT_NAME}_exe")

add_executable(${TARGET_EXE_NAME}
        src/main.cpp
        src/Solution.cpp)

target_compile_definitions(${TARGET_EXE_NAME} PRIVATE USE_SIMPLE )
target_compile_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_CFLAGS})
target_link_options(${TARGET_EXE_NAME} PRIVATE ${COMMON_LDFLAGS})
set_target_properties(${TARGET_EXE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
        OUTPUT_NAME "${PROJECT_NAME}")
