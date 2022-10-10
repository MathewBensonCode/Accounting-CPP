cmake_minimum_required(VERSION 3.5...3.24)

project(AccountsTestedWithCatch CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)

add_subdirectory(tests)
