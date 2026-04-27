cmake_minimum_required(VERSION 4.0)

project(AccountsTestedWithCatch CXX)

include(cmake/PreventInSourceBuilds.cmake)

include(cmake/CreateTargetLink.cmake)

add_subdirectory(lib)

include(CTest)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()

file(CREATE_LINK ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_SOURCE_DIR}/compile_commands.json COPY_ON_ERROR SYMBOLIC)
