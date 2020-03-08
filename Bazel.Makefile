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


ifeq ($(BRANCH),master)
    RELEASE_LEVEL := "CANDIDATE"
else ifeq ($(BRANCH),develop)
    RELEASE_LEVEL := "ALPHA"
else ifeq ($(BRANCH),release)
    RELEASE_LEVEL := "FINAL"
else ifeq ($(BRANCH),hotfix)
    RELEASE_LEVEL := "CANDIDATE"
else ifeq ($(BRANCH),feature)
    RELEASE_LEVEL := "CANDIDATE"
else
    RELEASE_LEVEL := "SNAPSHOOT"
endif

SHELL = /bin/sh
RM = /opt/bin/cmake -E remove -f


.PHONY: compile
compile: ## Build projects main sources
	@bazel build //...

.PHONY: test
test: compile ## Build projects test sources and run unit test
	@bazel test //... --test_output=all

.PHONY: clean
clean: ## Cleaned up the objects and intermediary files
	@bazel clean

.PHONY: all
all: compile

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

