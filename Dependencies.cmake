include(cmake/CPM.cmake)

function(myproject_setup_dependencies)
  if(NOT TARGET Catch2::Catch2WithMain)
    cpmaddpackage("gh:catchorg/Catch2@3.9.1")
  endif()
endfunction()

myproject_setup_dependencies()
