# CMakeList.txt : CMake project for accountswithcatch, include source and define project specific logic here.
#
find_package(Catch2)

add_executable(
  accountswithcatchtests
  "entity_tests/accounttest.cpp"
  "entity_tests/transactiontest.cpp"
  "entity_tests/sourcedocumenttest.cpp"
  "entity_tests/businessentitytest.cpp"
  "repository_tests/repositorytest.cpp")

target_link_libraries(
  accountswithcatchtests
  PRIVATE accountswithcatch project_warnings project_options
  PUBLIC Catch2::Catch2WithMain)

createtargetlink(accountswithcatchtests)
