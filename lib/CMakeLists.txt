# CMakeList.txt : CMake project for accountswithcatch, include source and define
# project specific logic here.
#

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

find_package(ODB REQUIRED COMPONENTS sqlite)

set(systemheaders)

list(
  APPEND
  systemheaders
  memory
  vector
  string
  iostream
  string_view)

foreach(header ${systemheaders})

  execute_process(
    COMMAND
      "g++ -v -std=c++20 -fmodules-ts -fmodule-header\=system -x c++\-system\-header ${header}"
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    RESULT_VARIABLE create_system_module_headers ECHO_ERROR_VARIABLE
                    COMMAND_ECHO STDOUT)

  if(NOT create_system_module_headers EQUAL "0")
    message("Failed to create system module header : ${header}")
  endif()

endforeach()

set(accounts_odb_headers include/account.hpp include/businessentity.hpp
                         include/sourcedocument.hpp include/transaction.hpp)

include(${ODB_USE_FILE})

odb_compile( accounts_odb_sources FILES ${accounts_odb_headers} DB sqlite
GENERATE_QUERY GENERATE_SESSION STANDARD c++20)


add_library(accountswithcatch)

target_sources(
  accountswithcatch
  PRIVATE src/account.cpp src/transaction.cpp src/sourcedocument.cpp
          src/businessentity.cpp
  PUBLIC FILE_SET headers TYPE HEADERS FILES ${accounts_odb_headers})

target_include_directories(
  accountswithcatch PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
                           ${ODB_INCLUDE_DIRECTORIES}
                           )

target_compile_options(accountswithcatch PUBLIC -fmodules-ts)

target_link_libraries(accountswithcatch PUBLIC project_warnings
                                               project_options)

add_library(accountsodb)

target_sources(accountsodb PRIVATE ${accounts_odb_sources})

target_include_directories(accountsodb PUBLIC ${CMAKE_CURRENT_BINARY_DIR/odb_gen})

target_link_libraries(accountsodb PUBLIC accountswithcatch)
