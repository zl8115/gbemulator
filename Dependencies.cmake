include(cmake/CPM.cmake)
#
function(myproject_setup_dependencies)
  if(NOT TARGET Catch2::Catch2WithMain)
    cpmaddpackage("gh:catchorg/Catch2@3.9.1")
  endif()

  if(NOT TARGET nlohmann_json::nlohmann_json)
    cpmaddpackage("gh:nlohmann/json@3.12.0")
  endif()

# find_package(Catch2 CONFIG REQUIRED)
# find_package(RapidJSON CONFIG REQUIRED)

endfunction()

myproject_setup_dependencies()
# include(CTest) # not sure if this is 100% necessary
# enable_testing()

# find_package(Catch2 CONFIG REQUIRED)

# include(CTest) # not sure if this is 100% necessary
# enable_testing()
# include(Catch)
# catch_discover_tests(tests)
# .\vcpkg.exe install libiconv --overlay-triplets=D:\github\my-vcpkg-triplets-master --triplet=x64-win-llvm
