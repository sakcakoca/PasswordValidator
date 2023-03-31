
# Formatting library
#include(FetchContent)
#FetchContent_Declare(
#  fmt
#  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#  GIT_TAG 9.1.0)
#FetchContent_MakeAvailable(fmt)

#Logging library
include(FetchContent)
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG ad0e89cbfb4d0c1ce4d097e134eb7be67baebb36)
FetchContent_MakeAvailable(spdlog)

add_executable(app app.cpp)
target_compile_features(app PRIVATE cxx_std_20)

target_link_libraries(app PRIVATE passwordvalidator_library spdlog::spdlog) #fmt::fmt