"""
# Copyright 2018, OpenCensus Authors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"""
"""Compiler options for OpenCensus.
Flags specified here must not impact ABI. Code compiled with and without these
opts will be linked together, and in some cases headers compiled with and
without these options will be part of the same program.
We use the same flags as absl, plus turn some warnings into errors.
"""

WERROR = [
    "-Werror=return-type",
    "-Werror=switch",
    "-Werror=reorder",
    "-Werror=non-virtual-dtor",
    "-fmax-errors=5",
    "-Werror=aggressive-loop-optimizations",
    "-Werror=missing-field-initializers",
    "-Werror=conversion",
    "-Werror=format-security",
    "-Werror=shadow",
    "-Werror=address",
    "-Werror=sequence-point",
]

CLANG_CL_TEST_FLAGS = [
    "-Wno-c99-extensions",
    "-Wno-deprecated-declarations",
    "-Wno-missing-noreturn",
    "-Wno-missing-prototypes",
    "-Wno-missing-variable-declarations",
    "-Wno-null-conversion",
    "-Wno-shadow",
    "-Wno-shift-sign-overflow",
    "-Wno-sign-compare",
    "-Wno-unused-function",
    "-Wno-unused-member-function",
    "-Wno-unused-parameter",
    "-Wno-unused-private-field",
    "-Wno-unused-template",
    "-Wno-used-but-marked-unused",
    "-Wno-zero-as-null-pointer-constant",
    "-Wno-gnu-zero-variadic-macro-arguments",
]

LLVM_FLAGS = [
    "-Wall",
    "-Wextra",
    "-Weverything",
    "-Wno-c++98-compat-pedantic",
    "-Wno-conversion",
    "-Wno-covered-switch-default",
    "-Wno-deprecated",
    "-Wno-disabled-macro-expansion",
    "-Wno-double-promotion",
    "-Wno-comma",
    "-Wno-extra-semi",
    "-Wno-extra-semi-stmt",
    "-Wno-packed",
    "-Wno-padded",
    "-Wno-sign-compare",
    "-Wno-float-conversion",
    "-Wno-float-equal",
    "-Wno-format-nonliteral",
    "-Wno-gcc-compat",
    "-Wno-global-constructors",
    "-Wno-exit-time-destructors",
    "-Wno-non-modular-include-in-module",
    "-Wno-old-style-cast",
    "-Wno-range-loop-analysis",
    "-Wno-reserved-id-macro",
    "-Wno-shorten-64-to-32",
    "-Wno-switch-enum",
    "-Wno-thread-safety-negative",
    "-Wno-unknown-warning-option",
    "-Wno-unreachable-code",
    "-Wno-unused-macros",
    "-Wno-weak-vtables",
    "-Wno-zero-as-null-pointer-constant",
    "-Wbitfield-enum-conversion",
    "-Wbool-conversion",
    "-Wconstant-conversion",
    "-Wenum-conversion",
    "-Wint-conversion",
    "-Wliteral-conversion",
    "-Wnon-literal-null-conversion",
    "-Wnull-conversion",
    "-Wobjc-literal-conversion",
    "-Wno-sign-conversion",
    "-Wstring-conversion",
]

LLVM_TEST_FLAGS = [
    "-Wno-c99-extensions",
    "-Wno-deprecated-declarations",
    "-Wno-missing-noreturn",
    "-Wno-missing-prototypes",
    "-Wno-missing-variable-declarations",
    "-Wno-null-conversion",
    "-Wno-shadow",
    "-Wno-shift-sign-overflow",
    "-Wno-sign-compare",
    "-Wno-unused-function",
    "-Wno-unused-member-function",
    "-Wno-unused-parameter",
    "-Wno-unused-private-field",
    "-Wno-unused-template",
    "-Wno-used-but-marked-unused",
    "-Wno-zero-as-null-pointer-constant",
    "-Wno-gnu-zero-variadic-macro-arguments",
]

GCC_FLAGS = [
    "-Wall",
    "-Wcast-qual",
    "-Wctor-dtor-privacy",
    "-Wconversion-null",
    "-Wextra",
    "-Wfloat-equal",
    "-Wmissing-declarations",
    "-Wno-missing-field-initializers",
    "-Wno-sign-compare",
    "-Wnull-dereference",
    "-Woverlength-strings",
    "-Woverloaded-virtual",
    "-Wpedantic",
    "-Wpointer-arith",
    "-Wreturn-type",
    "-Wsequence-point",
    "-Wsign-compare",
    "-Wstack-protector",
    "-Wswitch-default",
    "-Wunused-local-typedefs",
    "-Wunused-result",
    "-Wunused-value",
    "-Wunused-variable",
    "-Wunused-parameter",
    "-Wuseless-cast",
    "-Wvarargs",
    "-Wvla",
    "-Wwrite-strings",
]

GCC_TEST_FLAGS = [
    "-Wno-conversion-null",
    "-Wno-deprecated-declarations",
    "-Wno-missing-declarations",
    "-Wno-sign-compare",
    "-Wno-unused-function",
    "-Wno-unused-parameter",
    "-Wno-unused-private-field",
]

ARM64_FLAGS = [
    "-march=armv8-a+crypto",
]

CHECK_MEMORY_FLAGS = [
    "-fsanitize=memory",
    "-fsanitize-memory-track-origins=2",
    "-fno-omit-frame-pointer",
    "-fsanitize=null",
    "-fsanitize=unreachable",
    "-fstack-check",
    "-fvtable-verify=std",
]

