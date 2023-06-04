load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

package(default_visibility = ["//visibility:public"])

genrule(
  name = "build_version",
  srcs = [],
  cmd = "echo '\"bazel\"\n' > $@",
  outs = ["build-version.inc"],
)

cc_library(
    name = "libshaderc",
    hdrs = glob(["libshaderc/include/**/*.h", "libshaderc/include/**/*.hpp", "libshaderc/include/**/*.inc"]),
    srcs = glob(["libshaderc/src/*.c", "libshaderc/src/*.cc", "libshaderc/src/*.h"], exclude=["**/*_test.cc"]),
    strip_include_prefix = "libshaderc/include",
    includes = ["libshaderc/include/shaderc"],
    deps = [
      ":libshaderc_util",
      "@glslang//:glslang",
      "@glslang//:SPIRV",
      "@spirv_tools//:spirv_tools",
      "@spirv_tools//:spirv_tools_opt",
      "@spirv_headers//:spirv_cpp_headers",
    ]
)

cc_library(
    name = "libshaderc_util",
    hdrs = glob(["libshaderc_util/include/**/*.h", "libshaderc_util/include/**/*.inc"]),
    srcs = glob(["libshaderc_util/src/*.c", "libshaderc_util/src/*.cc", "libshaderc_util/src*.h"], exclude=["**/*_test.cc"]),
    strip_include_prefix = "libshaderc_util/include",
    includes = ["libshaderc_util/include/libshaderc_util"],
    deps = [
      "@glslang//:glslang",
      "@glslang//:SPIRV",
      "@spirv_tools//:spirv_tools",
      "@spirv_tools//:spirv_tools_opt",
      "@spirv_headers//:spirv_cpp_headers",
    ],
    copts = [
      '/showIncludes',
    ]
)

cc_binary(
    name = "glslc",
    srcs = glob(["glslc/src/*.c", "glslc/src/*.cc", "glslc/src/*.h"], exclude=["**/*_test.cc"]) + [':build_version'],
    includes = ["libshaderc/include/shaderc"],
    deps = [
        ":libshaderc",
        ":libshaderc_util",
    ],
)
