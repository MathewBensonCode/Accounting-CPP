# CMakeList.txt : CMake project for accountswithcatch, include source and define
# project specific logic here.
#
find_package(Catch2 REQUIRED)

cmake_minimum_required (VERSION 3.8)
# Add source to this project's executable.
add_executable (accountswithcatchtests "accounttest.cpp" "transactiontest.cpp" "catchmain.cpp")

target_include_directories(accountswithcatch PRIVATE accountswithcatch::accountswithcatch)

target_link_libraries(accountswithcatchtests PRIVATE accountswithcatch::accountswithcatch Catch2::Catch2)

enable_testing()
