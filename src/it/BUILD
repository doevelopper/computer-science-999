
cc_binary(

    name = "computer-science-integration-test.bin",

    srcs = [
        "computer/science/features/step_definitions/DummyTestSteps.cpp",
        "computer/science/features/step_definitions/DummyTestSteps.hpp",
        "computer/science/features/step_definitions/ItTest.cpp",
        "computer/science/features/step_definitions/ItTest.hpp",
    ],

    includes = [
        ".",
    ],

    copts = [
        "-std=c++17",
        "-DLOG_LEVEL=1",
        "-lapr-1",
        "-laprutil-1",
        "-llog4cxx",
        "-D_REENTRANT",
        "-I/usr/local/include/",
    ],

    linkopts = [
        "-L/usr/local/lib",
        "-lapr-1",
        "-laprutil-1",
        "-llog4cxx",
        "-lgtest",
        "-lgmock",
        "-lboost_thread",
        "-lboost_system",
        "-lboost_regex",
        "-lboost_date_time",
        "-lboost_program_options",
        "-lboost_filesystem",
        "-lcucumber-cpp",
    ],

    deps = [
        "//src/main/cpp:computer-science-main",
    ],
)

