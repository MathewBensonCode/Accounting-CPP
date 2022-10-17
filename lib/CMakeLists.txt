# CMakeList.txt : CMake project for accountswithcatch, include source and define
# project specific logic here.
#

set(systemheaders)
set(systemincludepath usr/include/c++/12.2.0)

list(APPEND systemheaders
        memory
        vector
        string
        iostream
     )

 set(systemmodules)
 set(moduleoutputdir "${CMAKE_CURRENT_BINARY_DIR}/gcm.cache/${systemincludepath}")

 #file(MAKE_DIRECTORY ${moduleoutputdir})

 foreach(header ${systemheaders})
     set(module "${moduleoutputdir}/${header}.gcm")

     message(${module})
     list(APPEND systemmodules ${module})

     add_custom_command(
         OUTPUT ${header}
         COMMAND "/usr/bin/g++ -std=c++20 -fmodules-ts -fmodule-header=system -x c++-system-header ${header}"
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
         )

 endforeach()

add_library (accountswithcatch account.cpp transaction.cpp)

target_include_directories(accountswithcatch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(accountswithcatch PUBLIC cxx_std_20)

add_library(accountswithcatch::accountswithcatch ALIAS accountswithcatch)
