
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")
load("@rules_pkg//:pkg.bzl", "pkg_tar", "pkg_deb")

licenses(["notice"])  # Apache License

cc_test(

    name = "computer-science-unit-test.bin",

    srcs = [
        "computer/science/unitTest.cpp",
        "computer/science/Test.cpp",
        "computer/science/Test.hpp",
        "computer/science/DummyTest.cpp",
        "computer/science/DummyTest.hpp",
        "computer/science/ContainerTest.cpp",
        "computer/science/ContainerTest.hpp",
        "computer/science/SimpleCalendarTest.cpp",
        "computer/science/MultipleParametersCalendarTest.cpp",
        "computer/science/MultipleParametersCalendarTest.hpp",
        "computer/science/FixtureCalendarTest.cpp",
        "computer/science/FixtureCalendarTest.hpp",
        "computer/science/ParameterizedFixtureCalendarTest.cpp",
        "computer/science/ParameterizedFixtureCalendarTest.hpp",
        "computer/science/FixtureWithParameterizedTestCalendarTest.cpp",
        "computer/science/FixtureWithParameterizedTestCalendarTest.hpp",
        "computer/science/pluralsight/mocking/MetaDataProcessorTest.cpp",
        "computer/science/pluralsight/mocking/MetaDataProcessorTest.hpp",
        "computer/science/pluralsight/mocking/JsonHelperTests.cpp",
        "computer/science/pluralsight/mocking/TheMovieDbDataFactoryTests.cpp",
        "computer/science/pluralsight/mocking/StringHtmlEncoderTests.cpp",
        "computer/science/pluralsight/mocking/TheMovieDbRepositoryTests.cpp",
        "computer/science/pluralsight/mocking/FakeRestApiClient.hpp",
    ],

    includes = [
        ".",
    ],

    copts = [
       "-std=c++17",
       "-DLOG_LEVEL=1",
       #"-lapr-1",
       #"-laprutil-1",
       #"-llog4cxx",
       #"-lgtest",
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
     ],


    deps = [
        "//src/main/cpp:computer-science-main",
    ],

    data = [
        "//src/main/resources/configs:log4cxx.xml",
    ],

)

