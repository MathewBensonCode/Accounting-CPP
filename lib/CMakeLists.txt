# CMakeList.txt : CMake project for accountswithcatch, include source and define project specific logic here.
#

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

find_package(ODB REQUIRED COMPONENTS sqlite)

set(accounts_odb_headers
    include/account.hpp
    include/businessentity.hpp
    include/sourcedocument.hpp
    include/transaction.hpp)

include(${ODB_USE_FILE})

odb_compile(
  accounts_odb_sources
  FILES
  ${accounts_odb_headers}
  DB
  sqlite
  GENERATE_QUERY
  GENERATE_SESSION
  STANDARD
  c++20)

add_library(accountswithcatch)

target_sources(
  accountswithcatch
  PRIVATE 
          ${accounts_odb_sources}
          src/account.cpp
          src/transaction.cpp
          src/sourcedocument.cpp
          src/businessentity.cpp
          src/repository.cpp
  PUBLIC FILE_SET
         HEADERS
         BASE_DIRS
         ${CMAKE_CURRENT_SOURCE_DIR}/include
         ${ODB_LIBODB_INCLUDE_DIRS}
         ${CMAKE_CURRENT_BINARY_DIR}/odb_gen
         FILES
         ${accounts_odb_headers})

set_target_properties(accountswithcatch PROPERTIES "VERIFY_INTERFACE_HEADER_SETS" ON)
