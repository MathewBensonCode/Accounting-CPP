# CMakeList.txt : CMake project for accountswithcatch, include source and define
# project specific logic here.
#
find_package(Catch2 REQUIRED)

cmake_minimum_required(VERSION 3.8)
# Add source to this project's executable.
add_executable(
  accountswithcatchtests
  "catchmain.cpp" "accounttest.cpp" "transactiontest.cpp"
  "sourcedocumenttest.cpp" "businessentitytest.cpp")

target_include_directories(accountswithcatchtests PRIVATE accountswithcatch)

target_link_libraries(
  accountswithcatchtests PRIVATE accountswithcatch Catch2::Catch2
                                 project_warnings project_options)
