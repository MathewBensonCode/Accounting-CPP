# CMakeList.txt : CMake project for accountswithcatch, include source and define
# project specific logic here.
#

add_library (accountswithcatch account.cpp transaction.cpp)

target_include_directories(accountswithcatch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(accountswithcatch PUBLIC cxx_std_20)

add_library(accountswithcatch::accountswithcatch ALIAS accountswithcatch)
