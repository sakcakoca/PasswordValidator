include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)	# For Windows: Prevent overriding the parent project's compiler/linker settings
FetchContent_MakeAvailable(googletest)

# Find Google Test package
#find_package(GTest REQUIRED COMPONENTS gtest gmock gtest_main gmock_main)

# Tests need to be added as executables first
set(TEST_EXECUTABLE_NAME PasswordValidatorTester.cpp)
add_executable(${TEST_EXECUTABLE_NAME} PasswordValidatorTester.cpp)

# I'm using C++20 in the test
target_compile_features(${TEST_EXECUTABLE_NAME} PRIVATE cxx_std_20)


# Should be linked to the main library, as well as the GoogleTest testing library
target_link_libraries(${TEST_EXECUTABLE_NAME} PRIVATE passwordvalidator_library GTest::gtest GTest::gtest_main)


# Discover tests for ctest
include(GoogleTest)
gtest_discover_tests(${TEST_EXECUTABLE_NAME})