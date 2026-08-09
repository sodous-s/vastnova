cmake_minimum_required(VERSION 3.10)
project(VastNovaCompiler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find LLVM
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/CodeGen.cpp
)

# Create executable
add_executable(vastnova ${SOURCES})

# Link LLVM libraries
llvm_map_components_to_libnames(llvm_libs Support Core)
target_link_libraries(vastnova ${llvm_libs})
