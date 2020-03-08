load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")
load("@rules_pkg//:pkg.bzl", "pkg_tar", "pkg_deb")

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

pkg_tar(
    name = "computer-science-integration-test.bin-pkg",
    # testonly = True,
    srcs = [
        ":computer-science-integration-test.bin",
    ],
    package_dir = "/opt/cs/bin",
    strip_prefix = "/src/it",
    tags = ["manual"],
)

pkg_tar(
    name = "computer-science-integration-test",
    extension = "tar.gz",
    deps = [
        ":computer-science-integration-test.bin-pkg",
    ],
)

