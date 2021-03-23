
project(particles)

add_library(${PROJECT_NAME}
  src/Particles.cpp
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
  test/ParticlesTest.cpp
)

add_test(
    ParticlesTest ParticlesTest.cpp
)

target_link_libraries( ${PROJECT_NAME}_test
  PUBLIC
    GTest::Main
    GTest::GTest
    ${PROJECT_NAME}
)
