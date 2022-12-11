# CMakeList.txt : CMake project for accountswithcatch, include source and define project specific logic here.
#
find_package(Catch2)

if(NOT Catch2_FOUND)

  include(FetchContent)

  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.0.1 # or a later release
  )

  FetchContent_MakeAvailable(Catch2)

endif()

add_executable(
  accountswithcatchtests
  "catchmain.cpp"
  "accounttest.cpp"
  "transactiontest.cpp"
  "sourcedocumenttest.cpp"
  "businessentitytest.cpp")

target_include_directories(accountswithcatchtests PRIVATE accountswithcatch Catch2::Catch2)

target_link_libraries(
  accountswithcatchtests
  PRIVATE accountswithcatch
          Catch2::Catch2
          project_warnings
          project_options)
