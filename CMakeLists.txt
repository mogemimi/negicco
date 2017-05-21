
cmake_minimum_required (VERSION 3.8)

project (NEGICCO
         LANGUAGES CXX
         VERSION 1.0.0)

# Aggregates created binaries.
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

find_package (LLVM REQUIRED CONFIG)
message (STATUS "Found LLVM ${LLVM_VERSION}")
message (STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

find_package (Clang REQUIRED CONFIG)

add_subdirectory (01-getting-started)
add_subdirectory (02-named-declarations)
add_subdirectory (03-comments)
add_subdirectory (04-help-text)
add_subdirectory (05-enum-classes)
add_subdirectory (06-variables)
# add_subdirectory (07-functions)
