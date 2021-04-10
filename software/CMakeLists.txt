# ----------------------------------------------------
# Environment
# ----------------------------------------------------

set (TARGET_NAME "${PROJECT_NAME}")

set (APPLICATION_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# ----------------------------------------------------
# Includes
# ----------------------------------------------------

include (CompilerWarningsForCpp)

# ----------------------------------------------------
# Options
# ----------------------------------------------------

enable_language (CXX)

set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_STANDARD 17)

# ----------------------------------------------------
# Sources
# ----------------------------------------------------

set (APPLICATION_SOURCE_FILES
    ${APPLICATION_PATH}/src/board.cpp
    ${APPLICATION_PATH}/src/piece.cpp
    ${APPLICATION_PATH}/src/main.cpp
)

# ----------------------------------------------------
# Targets
# ----------------------------------------------------

add_executable (${TARGET_NAME} ${APPLICATION_SOURCE_FILES})

set_target_properties (${TARGET_NAME}
    PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
)

# ----------------------------------------------------
# Dependencies (Libraries)
# ----------------------------------------------------

target_link_libraries(${TARGET_NAME}
    PRIVATE
)

# ----------------------------------------------------
# Include
# ----------------------------------------------------

set (APPLICATION_INCLUDE_PATHS
    ${APPLICATION_PATH}/src
)

target_include_directories (${TARGET_NAME}
    PRIVATE
        ${APPLICATION_INCLUDE_PATHS}
)

target_include_directories (${TARGET_NAME}
    SYSTEM PRIVATE
)

# ----------------------------------------------------
# Compiler
# ----------------------------------------------------

# Optimization
if (CMAKE_BUILD_TYPE MATCHES Debug)
    set (OPTIMIZATION_FLAGS -O0)
else ()
    set (OPTIMIZATION_FLAGS -O2 -g0 -flto)
    target_compile_definitions (${TARGET_NAME} PRIVATE NDEBUG)
endif ()

# ----------------------------------------------------
# Installation
# ----------------------------------------------------

install (
    TARGETS ${TARGET_NAME}
    RUNTIME DESTINATION usr/bin
)
