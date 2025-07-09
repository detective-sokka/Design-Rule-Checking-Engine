include(FetchContent)

# Download GTest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(test_drc_engine test_drc_engine.cpp)
add_executable(test_db_object test_db_object.cpp)
add_executable(test_drc_violation test_drc_violation.cpp)

# Link GTest and your library
target_link_libraries(test_drc_engine
    gtest_main
    drc_system    
)

target_link_libraries(test_db_object
    GTest::gmock
    GTest::gtest
    GTest::gmock_main
    gtest_main
    drc_system    
)

target_link_libraries(test_drc_violation
    gtest_main
    drc_system    
)

target_include_directories(
    test_db_object
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/mocks
)

target_include_directories(test_drc_engine
  PRIVATE
  ${gtest_SOURCE_DIR}/include
  ${gmock_SOURCE_DIR}/include
  ${DRC_MOCKS_INCLUDE_DIR}
)

include(GoogleTest)

gtest_discover_tests(test_drc_engine)
gtest_discover_tests(test_db_object)
gtest_discover_tests(test_drc_violation)
