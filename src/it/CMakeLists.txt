
add_executable (${PROJECT_NAME}.integration-test)

target_sources(${PROJECT_NAME}.integration-test
    PRIVATE
        computer/science/DummyTestSteps
)

apply_style_targets_command(${PROJECT_NAME}.integration-test ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}.integration-test
    PUBLIC
        ${PROJECT_NAME}.main
        CUCUMBER-CPP::CUCUMBER-CPP
        GMock::GMock
        GTest::GTest
        #BENCHMARK::BENCHMARK
)

#add_feature_test_command(${PROJECT_NAME}.integration-test ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(
    OUTPUT
        "${CMAKE_CURRENT_BINARY_DIR}/generated_file"
    COMMAND
        ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/generated_file
    COMMENT
        "Creating ${CMAKE_CURRENT_BINARY_DIR}/generated_file"
)

add_custom_command(TARGET ${PROJECT_NAME}.integration-test
    POST_BUILD

    COMMAND
        ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/qa/atp

    COMMAND
        ${PROJECT_NAME}.integration-test --port 3902  >/dev/null &

    COMMAND
        cucumber ${FEATURE_TEST_FORMAT} ${FEATURE_TEST_OPTION}
            --out ${CMAKE_INSTALL_PREFIX}/qa/atp/${PROJECT_NAME}.Feature-Tests-Report.html
            --strict ${CMAKE_CURRENT_SOURCE_DIR}/features

    COMMAND
        :
    #lsof -ti tcp:3902 | xargs kill # kill -9 $(lsof -t -i:3902 -sTCP:LISTEN) # kill -9 $(lsof -i:3902 -t) 2> /dev/null
    #lsof -ti tcp:3902 | ([[ $? == 0 ]] && xargs kill -9 || echo "Not Cucumber s PID to kill found" )

    WORKING_DIRECTORY
        ${CMAKE_CURRENT_SOURCE_DIR}

    COMMENT
        "Running ${PROJECT_NAME}  integration test!!!"
)

add_dependencies(integration-test ${PROJECT_NAME}.integration-test)

