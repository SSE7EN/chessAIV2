#------------------------------------------------------------------------------
# Author:       Mateusz Maciąg, Krzysztof Bartnicki, Kornel Swierzy
# Date:         2020-09-11
#
# Brief:        Automation of common tasks
#------------------------------------------------------------------------------

target_name			= chessAI
build_dir			?= 
cmake_flags			?=
debug				?= y
parallel			?= $(shell nproc)
target				?= 
verbose				?= n

#------------------------------------------------------------------------------

# AT :=
AT := @

CMAKE_CONF_FLAGS +=

ifeq ($(debug),y)
CMAKE_CONF_FLAGS    += -DCMAKE_BUILD_TYPE=Debug
else
CMAKE_CONF_FLAGS    += -DCMAKE_BUILD_TYPE=Release
endif

ifeq ($(build_dir),)
ifeq ($(debug),y)
build_dir = _build_debug
else
build_dir = _build_release
endif
endif

ifeq ($(target),)
	target_cmake = $(target_name)
endif

CMAKE_BUILD_FLAGS   += --target $(target_cmake)

ifeq ($(verbose),y)
CMAKE_BUILD_FLAGS   += -v
endif

CMAKE_CONF_FLAGS    += $(cmake_flags)

#------------------------------------------------------------------------------

CMAKE               := cmake
CPACK				:= cpack
CMAKE_CONFIGURE     := $(CMAKE) $(CMAKE_CONF_FLAGS) ..
CMAKE_BUILD         := $(CMAKE) --build . $(CMAKE_BUILD_FLAGS) -- -j$(parallel)
CMAKE_INSTALL		:= ${CMAKE} --install . --prefix ../_deploy/${build_dir}
CMAKE_PACK         	:= ${CPACK} --configuration CPackConfig.cmake

#------------------------------------------------------------------------------

default: fast-build
.PHONY: default

#------------------------------------------------------------------------------

configure: | .mk-build-dir
	$(AT) cd $(build_dir) && \
	        $(CMAKE_CONFIGURE)
	$(AT) echo "DONE"
.PHONY: configure

#------------------------------------------------------------------------------

fast-build: | .mk-build-dir
	$(AT) cd $(build_dir) && \
	        [ -f CMakeCache.txt ] \
	            && echo "warning: fast build mode: omitting configuration phase" \
	            || $(CMAKE_CONFIGURE) && \
	        $(CMAKE_BUILD)
	$(AT) echo "DONE"
.PHONY: fast-build

#------------------------------------------------------------------------------

build: | .mk-build-dir
	$(AT) cd $(build_dir) && \
	        $(CMAKE_CONFIGURE) && $(CMAKE_BUILD)
	$(AT) echo "DONE"
.PHONY: build

#------------------------------------------------------------------------------

run:
	$(AT) ./$(build_dir)/software/$(target_name)
.PHONY: run

#------------------------------------------------------------------------------

rebuild: clean fast-build
.PHONY: rebuild

#------------------------------------------------------------------------------

install:
	$(AT) cd $(build_dir) && \
	        $(CMAKE_INSTALL)
	$(AT) echo "DONE"
.PHONY: install

#------------------------------------------------------------------------------

package:
	$(AT) cd $(build_dir) && \
	        $(CMAKE_PACK) && \
			mkdir -p ../_deploy/${build_dir} && \
			cp *.deb ../_deploy/${build_dir}/
	$(AT) echo "DONE"
.PHONY: pack

#------------------------------------------------------------------------------

clean-all: clean
.PHONY: clean-all

#------------------------------------------------------------------------------

clean:
	$(AT) $(RM) -rf "$(build_dir)"
.PHONY: clean

#------------------------------------------------------------------------------

.mk-build-dir:
	$(AT) mkdir -p "$(build_dir)"
.PHONY: .mk-build-dir

#------------------------------------------------------------------------------

help:
	$(AT) echo "Top-level Makefile for automating CMake tasks."
	$(AT) echo ""
	$(AT) echo "Target parameters:"
	$(AT) echo "  build_dir   (string:'')    - specifies CMake build directory"
	$(AT) echo "  cmake_flags (string:'')    - additional flags for CMake configuration step"
	$(AT) echo "  debug       (bool:y)       - specifies whether to build Debug or Release CMake configuration"
	$(AT) echo "  target      (string:all)   - specifies CMake build target"
	$(AT) echo "  verbose     (bool:n)       - enables CMake verbose mode"
	$(AT) echo ""
	$(AT) echo "Following targets are available:"
	$(AT) echo " --- Basic build --- "
	$(AT) echo "  configure   - performs CMake project configuration"
	$(AT) echo "  build       - build specified target with configuration step"
	$(AT) echo "  fast-build  - build specified target with optional configuration step if no cache is found"
	$(AT) echo "  install     - installs project to '_deploy' directory at repository root"
	$(AT) echo "  clean       - removes CMake build directory"
	$(AT) echo "  rebuild     - runs clean and fast-build"
	
.PHONY: help