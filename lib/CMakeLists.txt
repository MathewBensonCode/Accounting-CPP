# CMakeList.txt : CMake project for accountswithcatch, include source and define
# project specific logic here.
#

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

find_package(ODB REQUIRED COMPONENTS sqlite)

set(accounts_odb_headers include/account.hpp include/businessentity.hpp
                         include/sourcedocument.hpp include/transaction.hpp)

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
  c++14)

add_library(accountswithcatch)

target_sources(
  accountswithcatch
  PRIVATE src/account.cpp src/transaction.cpp src/sourcedocument.cpp
          src/businessentity.cpp
  PUBLIC FILE_SET headers TYPE HEADERS FILES ${accounts_odb_headers})

target_include_directories(
  accountswithcatch PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
                           ${ODB_INCLUDE_DIRECTORIES})

target_link_libraries(accountswithcatch PRIVATE project_warnings project_options)

add_library(accountsodb)

#target_sources(
#  accountsodb
#  PRIVATE ${accounts_odb_sources}
#  PRIVATE FILE_SET odb_headers TYPE HEADERS FILES ${accounts_odb_headers})
#
#target_include_directories(
#  accountsodb PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/odb_gen
#                     ${CMAKE_CURRENT_SOURCE_DIR}/include)
