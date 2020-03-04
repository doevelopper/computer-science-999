
#load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(

    name = "computer-science-main",

    srcs = [
        "computer/science/CSList.cpp",
        "computer/science/CSQueue.cpp",
        "computer/science/CSVector.cpp",
        "computer/science/Calendar.cpp",
        "computer/science/Dummy.cpp",
        "computer/science/LoggingService.cpp",
        "computer/science/pluralsight/mocking/FileErrorRepository.cpp",
        "computer/science/pluralsight/mocking/JsonHelper.cpp",
        "computer/science/pluralsight/mocking/MetaDataProcessor.cpp",
        "computer/science/pluralsight/mocking/MovieData.cpp",
        "computer/science/pluralsight/mocking/RestApiClient.cpp",
        "computer/science/pluralsight/mocking/SettableMovieData.cpp",
        "computer/science/pluralsight/mocking/StringHtmlEncoder.cpp",
        "computer/science/pluralsight/mocking/TheMovieDbDataFactory.cpp",
        "computer/science/pluralsight/mocking/TheMovieDbRepository.cpp",
    ],

    hdrs = [
        "computer/science/IContainer.hpp",
        "computer/science/Interface.hpp",
        "computer/science/CSList.hpp",
        "computer/science/CSQueue.hpp",
        "computer/science/CSVector.hpp",
        "computer/science/Calendar.hpp",
        "computer/science/Dummy.hpp",
        "computer/science/LoggingService.hpp",
        "computer/science/pluralsight/mocking/ErrorRepository.hpp",
        "computer/science/pluralsight/mocking/APIKEy.hpp",
        "computer/science/pluralsight/mocking/InvalidInputException.hpp",
        "computer/science/pluralsight/mocking/JsonHelper.hpp",
        "computer/science/pluralsight/mocking/FileErrorRepository.hpp",
        "computer/science/pluralsight/mocking/MetaDataProcessor.hpp",
        "computer/science/pluralsight/mocking/MovieDataFactory.hpp",
        "computer/science/pluralsight/mocking/MovieMetaDataRepository.hpp",
        "computer/science/pluralsight/mocking/MovieNotFoundException.hpp",
        "computer/science/pluralsight/mocking/RestApiClient.hpp",
        "computer/science/pluralsight/mocking/SettableMovieData.hpp",
        "computer/science/pluralsight/mocking/StringHtmlEncoder.hpp",
        "computer/science/pluralsight/mocking/MovieData.hpp",
        "computer/science/pluralsight/mocking/TheMovieDbDataFactory.hpp",
        "computer/science/pluralsight/mocking/TheMovieDbRepository.hpp",
    ],

    copts = [
        "-std=c++17",
        "-DLOG_LEVEL=1",
        "-lapr-1",
        "-laprutil-1",
        "-llog4cxx",
    ],

	includes = [
		".",
#		"computer",
#		"computer/science",
#		"computer/science/pluralsight",
#		"computer/science/google",
#		"computer/science/gotw",
	],

    linkopts = [
		"-pthread",
#		"-apr-1",
#		"-aprutil-1",
#		"-log4cxx",
	],

    #visibility = ["//visibility:public"],
    visibility = ["//main:__pkg__"],
)


#cc_binary(
#    name = "computer-science-main.bin",
#    srcs = ["computer/science/main.cpp"],
#    copts = [
#       "-std=c++17",
#       "-DLOG_LEVEL=1",
##       "-lapr-1",
##       "-laprutil-1",
##       "-llog4cxx",
#    ],

#    deps = [
#        ":computer-science-main",
#    ],
#)

