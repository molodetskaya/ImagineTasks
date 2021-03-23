
project(rotation)

add_library(${PROJECT_NAME}
  src/Rotation.cpp
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    src
)


include( FindPkgConfig )

find_package( GTest REQUIRED )

include_directories(${GTEST_INCLUDE_DIRS})
enable_testing()


add_executable( ${PROJECT_NAME}_test
  test/RotationTest.cpp
)

add_test(
    RotationTest RotationTest.cpp
)

target_link_libraries( ${PROJECT_NAME}_test
  PUBLIC
    GTest::Main
    GTest::GTest
    ${PROJECT_NAME}
)
