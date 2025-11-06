include(FetchContent)
include(cmake/CPM.cmake)

# TODO: Restrict pulling dependencies if not building tests

function(myproject_setup_dependencies)
  if(NOT TARGET Catch2::Catch2WithMain)
    cpmaddpackage("gh:catchorg/Catch2@3.9.1")
  endif()
  if(NOT TARGET nlohmann_json::nlohmann_json)
    cpmaddpackage("gh:nlohmann/json@3.12.0")
  endif()
  if(NOT TARGET SDL3::SDL3)
    cpmaddpackage("gh:libsdl-org/SDL#release-3.2.26")
  endif()
endfunction()

myproject_setup_dependencies()

FetchContent_Declare(
  sm83testcases
  GIT_REPOSITORY https://github.com/SingleStepTests/sm83.git
  GIT_TAG        f9c30210245dd691661db39f5ace022c465ecc2f # initial commit
)
FetchContent_MakeAvailable(sm83testcases)
