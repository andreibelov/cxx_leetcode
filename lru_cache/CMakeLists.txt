# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 22:59:13 by abelov            #+#    #+#              #
#    Updated: 2025/03/03 22:59:14 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

project(lru_cache CXX C ASM)

set(TARGET_EXE_NAME "${PROJECT_NAME}_exe")

add_executable(${TARGET_EXE_NAME}
        src/main.cpp
        src/LRUCache.cpp)

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
