# CMakeList.txt : CMake project for accountswithcatch, include source and define project specific logic here.
#
find_package(Catch2 REQUIRED)

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

  include(CTest)
  include(Catch)
  catch_discover_tests(accountswithcatchtests)
