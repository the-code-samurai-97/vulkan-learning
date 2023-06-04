load("@rules_cc//cc:defs.bzl", "cc_library")
cc_library(
    name = "glfw",
    hdrs = glob(["glfw-3.3.4/include/GLFW/glfw3.h"]),
    srcs = glob(["glfw-3.3.4/src/*.c"]),
    includes = ["glfw-3.3.4/include/"],
    strip_include_prefix = "external/glfw-3.3.4/include/",
    visibility = ["//visibility:public"],
    copts = ["-std=c++17"],
)