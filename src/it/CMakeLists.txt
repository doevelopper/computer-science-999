
add_executable (${PROJECT_NAME}.integration-test)

target_sources(${PROJECT_NAME}.integration-test
    PRIVATE
        computer/science/DummyTestSteps
)

apply_style_targets_command(${PROJECT_NAME}.integration-test ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}.integration-test
    PUBLIC
        ${PROJECT_NAME}.main
        CucumberCpp::cucumber-cpp
        #BENCHMARK::BENCHMARK
)

add_feature_test_command(${PROJECT_NAME}.integration-test ${CMAKE_CURRENT_SOURCE_DIR})

