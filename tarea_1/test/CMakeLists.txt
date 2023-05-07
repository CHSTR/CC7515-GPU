add_executable(
  TareaTests
  point_test.cpp
  vector_test.cpp
  polygon_test.cpp
  ../include/Point/point.hpp
  ../include/Vector/vector.hpp
  ../include/Polygon/polygon.hpp
)

target_link_libraries(
  TareaTests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(TareaTests)

