
# Formatting library
include(FetchContent)
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 9.1.0)
FetchContent_MakeAvailable(fmt)

# Adds fmt::fmt
#find_package(FMT REQUIRED)

add_executable(app app.cpp)
target_compile_features(app PRIVATE cxx_std_20)

target_link_libraries(app PRIVATE passwordvalidator_library fmt::fmt)
