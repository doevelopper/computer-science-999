.DEFAULT_GOAL:=help

ifeq ("$(origin V)", "command line")
    KBUILD_VERBOSE = $(V)
endif
ifndef KBUILD_VERBOSE
    KBUILD_VERBOSE = 0
endif

ifeq ($(KBUILD_VERBOSE),1)
    quiet =
    Q =
	QQ =
else
    quiet=quiet_
    Q = @
	QQ = > /dev/null
endif

ifneq ($(findstring s,$(filter-out --%,$(MAKEFLAGS))),)
    quiet=silent_
    tools_silent=s
endif

ifeq (0,${MAKELEVEL})
	whoami    := $(shell whoami)
	host-type := $(shell arch)
	# MAKE := ${MAKE} host-type=${host-type} whoami=${whoami}
endif

MAKEFLAGS += --no-print-directory

export BUILD_DIRECTORY ?= $(shell basename $(shell git rev-parse --show-toplevel))-build
export PRJNAME := $(shell basename $(shell git rev-parse --show-toplevel))
export BRANCH := $(shell git rev-parse --abbrev-ref HEAD)
export HASH := $(shell git rev-parse HEAD)

SHELL = /bin/sh
RM = /opt/bin/cmake -E remove -f

.PHONY : edit_cache
edit_cache: ## Special rule for the target edit_cache
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	@$(CMAKE_COMMAND) -i .

.PHONY : rebuild_cache
rebuild_cache: ## rebuild cache
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	@$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)

.PHONY: generate
generate: ## Create build directories
	@cmake -E make_directory ${BUILD_DIRECTORY}

.PHONY: configure
configure: generate ## Generate Cmake Build configurations in ${BUILD_DIRECTORY}
	@cmake -E chdir ${BUILD_DIRECTORY} cmake -G "Unix Makefiles" -DCMAKE_PREFIX_PATH=/opt/dds -DCMAKE_INSTALL_PREFIX=$(basename $(pwd))-build/.local ..

.PHONY: build
build: configure ## Build projects main sources
	@cmake --build ${BUILD_DIRECTORY} --target compile

.PHONY: test
test: build ## Build projects test sources and run unit test
	@cmake --build ${BUILD_DIRECTORY} --target test-compile
	@cmake --build ${BUILD_DIRECTORY} --target test

.PHONY:  integration-test
integration-test: ## Build integrations steps and run integrqtion test
	@cmake --build ${BUILD_DIRECTORY} --target integration-test

.PHONY: install
install: ## Install package in outpout directory build
	@cmake --build ${BUILD_DIRECTORY} --target install

.PHONY: end-to-end
end-to-end: ## Run all goals
	@cmake --build ${BUILD_DIRECTORY} --target all

.PHONY: usage
usage: ## Displays all goals available for cmake build
	@cmake --build ${BUILD_DIRECTORY} --target help

.PHONY: all
all: build

.PHONY: help
help: ## Display this help and exits.
	$(Q)echo "$@ ->"
	$(Q)echo '---------------$(CURDIR)------------------'
	$(Q)echo '+----------------------------------------------------------------------+'
	$(Q)echo '|                        Available Commands                            |'
	$(Q)echo '+----------------------------------------------------------------------+'
	$(Q)echo
	$(Q)awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {sub("\\\\n",sprintf("\n%22c"," "), $$2);printf " \033[36m%-20s\033[0m  %s\n", $$1, $$2}' $(MAKEFILE_LIST)
	$(Q)echo ""
	$(Q)echo

