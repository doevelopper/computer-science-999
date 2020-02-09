
add_executable(${PROJECT_NAME}.unit-test)

target_sources(${PROJECT_NAME}.unit-test
	PRIVATE
		computer/science/unitTest.cpp
		computer/science/unitTest
		computer/science/Test
)

apply_style_targets_command(${PROJECT_NAME}.unit-test ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME}.unit-test 
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/computer/science>
        $<INSTALL_INTERFACE:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/computer/science>
)

target_link_libraries(${PROJECT_NAME}.unit-test
    PUBLIC  
        ${PROJECT_NAME}.main
        GMock::GMock
        GTest::GTest
)

gtest_discover_tests(${PROJECT_NAME}.unit-test
    TEST_PREFIX "C_S:-: "
    TEST_SUFFIX ----
    PROPERTIES LABELS C_S TEST
    DISCOVERY_TIMEOUT 10
    EXTRA_ARGS
	     --gtest_repeat=1 --gtest_color=auto --gtest_print_utf8=0 --gtest_output=xml:${CMAKE_INSTALL_PREFIX}/qa/tr/${PROJECT_NAME}-Unit-Test-Report.xml
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
