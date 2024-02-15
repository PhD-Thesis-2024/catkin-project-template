## Fetch Catch2 dependency.
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2
)

FetchContent_MakeAvailable(Catch2)

## Declare C++ unit tests (Catch2).
add_executable(run_catch_tests cpp/test_cases.cpp)
target_link_libraries(run_catch_tests PRIVATE Catch2::Catch2WithMain catkin_deps)

## Discover tests (Catch2).
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)

catch_discover_tests(run_catch_tests EXTRA_ARGS -r console --abort)

## Declare Python unit tests (nosetests).
catkin_add_nosetests(python DEPENDENCIES ${catkin_EXPORTED_TARGETS} ${${PROJECT_NAME}_EXPORTED_TARGETS})
