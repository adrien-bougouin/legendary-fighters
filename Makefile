################################################################################
# Makefile
#
# Targets:
#   - default:            Creates the executable of the project.
#   - test:               Runs unit tests.
#   - osx:                Creates an OS X application (.app).
#   - all:                Creates the executable, runs unit test and creates an
#                         OS X application.
#   - clean:              Removes object files (.o) generated during
#                         compilation.
#   - clean-all:          Removes the BUILD_DIR directory.
#
# Required information:
#   - PROJECT:            The name of the project.
#   - VERSION:            The current version of the project.
#   - ICON:               The path to the icon of the project.
#
#   - SOURCE_DIR:         The root directory of the project sources code.
#   - TEST_DIR:           The root directory of the project tests.
#   - RESOURCE_DIR:       The root directory of the project resources.
#   - BUILD_DIR:          The root directory where to build the project.
#   - INSTALLED_LIB_DIRS: The root directories where external libraries are
#                         installed to be used to compile the project.
#
#   - SOURCE_MAIN         The path of the project main file.
#   - TEST_MAIN           The path of the project tests main file.
#
#   - IS_CPP:             True if the project is writen in C++, false otherwise.
#   - LIBS:               The name of the libraries used by the project.
#   - TEST_LIBS           The name of the libraries used by the project tests.
#   - FRAMEWORKS:         The name of the OS X frameworks used by the project.
#   - TEST_FRAMEWORKS:    The name of the OS X frameworks used by the project
#                         tests.
#
#   - CC:                 The C compiler.
#   - CXX:                The C++ compiler.
#   - CFALGS:             The flags to use with the C compiler (except -I).
#   - CXXFLAGS:           The flags to use with the C++ compiler (except -I).
#   - LDFLAGS:            The flags to use during linkage (except -L, -l and
#                         -framework).

##### Configuration ############################################################

PROJECT = legendary-fighters
VERSION = 0.1a
ICON    =

SOURCE_DIR    = src
TEST_DIR      = test
RESOURCE_DIR  = res
BUILD_DIR     = build

SOURCE_MAIN = $(SOURCE_DIR)/main.cpp
TEST_MAIN   = $(TEST_DIR)/test.cpp

IS_CPP          = true
LIBS            = SDL2 SDL2_image
TEST_LIBS       = cppunit
FRAMEWORKS      =
TEST_FRAMEWORKS =

CC                  = clang
CXX                 = clang++
CFLAGS              +=
CXXFLAGS            += -std=c++11
LDFLAGS             +=
INSTALLED_LIB_DIRS  = /usr/local

################################################################################

ifeq ($(IS_CPP), true)
COMP        = $(CXX)
COMP_FLAGS  = $(CXXFLAGS)
LD          = $(CXX)
IMPL_EXT    = cpp
HEADER_EXT  = hpp
else
COMP        = $(CC)
COMP_FLAGS  = $(CFLAGS)
LD          = $(CC)
IMPL_EXT    = c
HEADER_EXT  = h
endif
COMP_FLAGS  += $(foreach dir, \
                 $(addprefix -I, $(INSTALLED_LIB_DIRS)), \
                 $(dir)/include)
LDFLAGS     += $(foreach dir, \
                 $(addprefix -L, $(INSTALLED_LIB_DIRS)), \
                 $(dir)/lib) \
               $(addprefix -l, $(LIBS)) \
               $(addprefix -framework, $(FRAMEWORKS)) \

################################################################################

EXEC      = $(shell echo $(PROJECT) | tr '[:upper:]' '[:lower:]' | sed "s/-/_/g")
TEST_EXEC = $(shell echo $(PROJECT) | tr '[:upper:]' '[:lower:]' | sed "s/-/_/g")_test

SOURCE_DIRS         = ${shell find ${SOURCE_DIR} -type d -print}
TEST_DIRS           = ${shell find ${TEST_DIR} -type d -print}
OBJECT_DIR          = $(BUILD_DIR)/.obj
SOURCE_IMPLS        = $(foreach dir, \
                        $(SOURCE_DIRS), \
                        $(wildcard $(dir)/*.$(IMPL_EXT)))
TEST_IMPLS          = $(foreach dir, \
                        $(TEST_DIRS), \
                        $(wildcard $(dir)/*.$(IMPL_EXT)))
SOURCE_HEADERS      = $(foreach dir, \
                        $(SOURCE_DIRS), \
                        $(wildcard $(dir)/*.$(HEADER_EXT)))
TEST_HEADERS        = $(foreach dir, \
                        $(TEST_DIRS), \
                        $(wildcard $(dir)/*.$(HEADER_EXT)))
SOURCE_OBJECTS      = $(addprefix $(OBJECT_DIR)/, \
                        $(patsubst %.cpp, %.o, $(SOURCE_IMPLS)))
TEST_OBJECTS        = $(addprefix $(OBJECT_DIR)/, \
                        $(patsubst %.cpp, %.o, $(TEST_IMPLS)))
TEST_OBJECTS        += $(foreach obj, \
                         $(SOURCE_OBJECTS), \
                         $(if $(findstring $(patsubst %.cpp, \
                                             %.o, \
                                             $(OBJECT_DIR)/$(SOURCE_MAIN)), \
                                $(obj)),, \
                                $(obj)))

##### Main targets #############################################################

.PHONY: init test osx clean clean-all
default: init $(BUILD_DIR)/$(EXEC)
# TODO all: init $(BUILD_DIR)/$(EXEC) test osx
all: init $(BUILD_DIR)/$(EXEC) test
test: init $(BUILD_DIR)/$(TEST_EXEC)
	@echo "Makefile >> Running tests"
	@./$(BUILD_DIR)/$(TEST_EXEC)

init:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(addprefix $(OBJECT_DIR)/, $(SOURCE_DIRS))
	@mkdir -p $(addprefix $(OBJECT_DIR)/, $(TEST_DIRS))

##### Executable ###############################################################

$(BUILD_DIR)/$(EXEC): $(SOURCE_OBJECTS)
	@echo "Makefile >> $@"
	@$(LD) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/$(TEST_EXEC): $(TEST_OBJECTS)
	@echo "Makefile >> $@"
	@$(LD) $(LDFLAGS) \
	       $(addprefix -l, $(TEST_LIBS)) \
	       $(addprefix -framework, $(TEST_FRAMEWORKS)) -o $@ $^

$(OBJECT_DIR)/%.o: %.cpp $(SOURCE_HEADERS) $(TEST_HEADERS)
	@echo "Makefile >> $< > $@"
	@$(COMP) $(COMP_FLAGS) -o $@ -c $<

##### OS-X #####################################################################

# TODO
#APP       = $(PROJECT).app
#PLIST     = info.plist
#PLIST_SED = -e "s/__EXEC__/$(EXEC)/g" \
#            -e "s/__PROJECT__/$(PROJECT)/g" \
#            -e "s/__VERSION__/$(VERSION)/g" \
#            -e "s/__ICON__/$(EXEC)/g"
#DMG       = $(PROJECT)-$(VERSION).dmg
#
#osx: init $(BUILD_DIR)/$(DMG)
#
#$(BUILD_DIR)/$(DMG): $(BUILD_DIR)/$(APP)
#	@echo ">> Creating $@"
#	@hdiutil create -fs HFS+ -srcfolder $< -volname $(basename $(DMG)) $@ \
#	 > /dev/null
#
#$(BUILD_DIR)/$(APP): $(BUILD_DIR)/$(EXEC) $(PLIST)
#	@echo ">> Creating $@"
#	@mkdir -p $@/Contents/MacOS
#	@mkdir -p $@/Contents/Resources
#	@cp -R $(RESOURCE_DIR) $@/Contents/Resources/$(RESOURCE_DIR)
#	@cp $(ICON) $@/Contents/Resources/$(EXEC)$(suffix $(ICON))
#	@sed $(PLIST_SED) $(PLIST) > $@/Contents/Info.plist
#	@echo "APPL????" > $@/Contents/PkgInfo
#	@cp $< $@/Contents/MacOS

##### Cleaning #################################################################

clean:
	@rm -rf $(OBJECT_DIR)

clean-all:
	@rm -rf $(BUILD_DIR)

