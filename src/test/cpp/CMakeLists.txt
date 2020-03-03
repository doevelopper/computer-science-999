
add_executable(${PROJECT_NAME}.unit-test.bin)
add_library(${PROJECT_NAME}.unit-test)

target_sources(${PROJECT_NAME}.unit-test.bin
	PRIVATE
		computer/science/unitTest
)

target_sources(${PROJECT_NAME}.unit-test
    PUBLIC
		computer/science/Test
        computer/science/DummyTest
        computer/science/ContainerTest
        computer/science/SimpleCalendarTest
        computer/science/MultipleParametersCalendarTest
        computer/science/FixtureCalendarTest
        computer/science/ParameterizedFixtureCalendarTest
        computer/science/FixtureWithParameterizedTestCalendarTest
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

target_link_libraries(${PROJECT_NAME}.unit-test.bin
    PRIVATE
        ${PROJECT_NAME}.unit-test
)

gtest_discover_tests(${PROJECT_NAME}.unit-test.bin
    TEST_PREFIX
        "${PROJECT_NAME} :-: "
    TEST_SUFFIX
        ----
    PROPERTIES LABELS ${PROJECT_NAME}
    DISCOVERY_TIMEOUT
        10
    EXTRA_ARGS
	     --gtest_repeat=1 --gtest_color=auto --gtest_print_utf8=0 --gtest_output=xml:${CMAKE_INSTALL_PREFIX}/qa/tr/${PROJECT_NAME}-Unit-Test-Report.xml
    WORKING_DIRECTORY
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

add_dependencies(test-compile ${PROJECT_NAME}.unit-test.bin)

