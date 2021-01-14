# test



message(${ExternalLib})

file(GLOB VectorTestSrc ./Container/*.cpp)

find_package(Threads REQUIRED)

foreach(TestFile ${VectorTestSrc})
  get_filename_component(TestFileName ${TestFile} NAME_WE)
  add_executable(${TestFileName} ${TestFile} )
  target_include_directories(${TestFileName}  PUBLIC ${IncludeDir})
  target_link_libraries(${TestFileName} gtest gtest_main  ${CMAKE_THREAD_LIBS_INIT} ${ExternalLib} )
  # target_link_libraries(${TestFileName} PRIVATE  )
  add_test(${TestFileName} ${TestFileName})
  set_tests_properties(${TestFileName} PROPERTIES TIMEOUT 5)
endforeach()

file(GLOB BaseTestSrc ./Base/*.cpp)

foreach(TestFile ${BaseTestSrc})
  get_filename_component(TestFileName ${TestFile} NAME_WE)
  add_executable(${TestFileName} ${TestFile} )
  target_include_directories(${TestFileName}  PUBLIC ${IncludeDir})
  target_link_libraries(${TestFileName} gtest gtest_main  ${CMAKE_THREAD_LIBS_INIT} ${ExternalLib} )
  # target_link_libraries(${TestFileName} PRIVATE  )
  add_test(${TestFileName} ${TestFileName})
  set_tests_properties(${TestFileName} PROPERTIES TIMEOUT 5)
endforeach()