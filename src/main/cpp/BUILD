
package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("@rules_pkg//:pkg.bzl", "pkg_tar", "pkg_deb")

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
		"-D_REENTRANT",
        "-I/usr/local/include/",
    ],

    linkopts = [
        "-L/usr/local/lib",
		"-pthread",
        "-lapr-1",
        "-laprutil-1",
        "-llog4cxx",
	],

	includes = [
		".",
	],

    #visibility = ["//visibility:public"],
    #visibility = ["//main:__pkg__"],
)

cc_binary(
    name = "computer-science-main.bin",
    srcs = ["computer/science/main.cpp"],
    copts = [
       "-std=c++17",
    ],

    deps = [
        ":computer-science-main",
    ],
)

pkg_tar(
    name = "computer-science-libs",
    strip_prefix = "/computer/science/cpp",
    package_dir = "/opt/cs/lib",
    srcs = ["//src/main/cpp:computer-science-main"],
    mode = "0755",
)

pkg_tar(
    name = "computer-science-hdrs-pkg",
#    testonly = True,
    srcs = glob([
        "**/*.hpp",
    ]),
    # extension = "tar.gz",
    package_dir = "/opt/cs/include",
    strip_prefix = "/src/main/cpp",
    tags = ["manual"],
    visibility = ["//visibility:public"],
    mode = "0644",
)

pkg_tar(
    name = "computer-science-bin-pkg",
#    testonly = True,
    srcs = [
        # ":cfs-algo-main",
        ":computer-science-main.bin",
    ],
    # extension = "tar.gz",
    package_dir = "/opt/cs/bin",
    strip_prefix = "/src/main/cpp",
    tags = ["manual"],
)

pkg_tar(
    name = "computer-science",
    extension = "tar.gz",
    deps = [
        ":computer-science-libs",
        ":computer-science-hdrs-pkg",
        ":computer-science-bin-pkg",
    ],
)

pkg_deb(
    name = "computer-science-deb-pkg",
    testonly = True,
    architecture = "amd64",
    data = ":computer-science",
    description = "Computer science lectures",
    homepage = "https://gitlab.com/doevelopper/cfs-algo",
    maintainer = "Adrien H.",
    package = "CS101",
    tags = ["manual"],
    version = "0.0.1",
    visibility = ["//visibility:public"],
)

