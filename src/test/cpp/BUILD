
cc_test(

    name = "computer-science-unit-test",

    srcs = [
        "computer/science/Test.cpp",
        "computer/science/DummyTest.cpp",
        "computer/science/ContainerTest.cpp",
        "computer/science/SimpleCalendarTest.cpp",
        "computer/science/MultipleParametersCalendarTest.cpp",
        "computer/science/FixtureCalendarTest.cpp",
        "computer/science/ParameterizedFixtureCalendarTest.cpp",
        "computer/science/FixtureWithParameterizedTestCalendarTest.cpp",
        "computer/science/pluralsight/mocking/MetaDataProcessorTest.cpp",
        "computer/science/pluralsight/mocking/JsonHelperTests.cpp",
        "computer/science/pluralsight/mocking/TheMovieDbDataFactoryTests.cpp",
        "computer/science/pluralsight/mocking/StringHtmlEncoderTests.cpp",
        "computer/science/pluralsight/mocking/TheMovieDbRepositoryTests.cpp",
        "computer/science/unitTest.cpp",
    ],

#    hdrs = [
#        "computer/science/Test.hpp",
#        "computer/science/ContainerTest.hpp",
#        "computer/science/DummyTest.hpp",
#        "computer/science/FixtureCalendarTest.hpp",
#        "computer/science/FixtureWithParameterizedTestCalendarTest.hpp",
#        "computer/science/MultipleParametersCalendarTest.hpp",
#        "computer/science/ParameterizedFixtureCalendarTest.hpp",
#    ],

    includes = [
        ".",
    ],

    copts = [
        "-std=c++17",
        "-lgtest",
    ],

    deps = [
        ":computer-science-main",
    ],

#    linkopts = [
#        "gtest",
#    ],
)

