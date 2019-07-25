TARGET_NAME := FDCodeAnalyser

include ../FDMakeUtils/utils.mk
include ../FDMakeUtils/llvm_utils.mk
include ../FDMakeUtils/python_utils.mk

#################################################################

# PROJECT CONFIG

#################################################################

PROJECT_CFLAGS := $(DEFAULT_CFLAGS)
PROJECT_CXXFLAGS := $(DEFAULT_CXXFLAGS) $(PYBIND_CXXFLAGS) $(LLVM_CXXFLAGS) -fpic
PROJECT_LDFLAGS := $(DEFAULT_LDFLAGS) $(PYBIND_LDFLAGS) $(LLVM_LDFLAGS)
PROJECT_DEFINES := $(DEFAULT_DEFINES)
PROJECT_INCLUDEPATH := $(DEFAULT_INCLUDEPATH) $(PYBIND_INCLUDEPATH) $(CLANG_INCLUDEPATH)
PROJECT_LIBPATH := $(DEFAULT_LIBPATH)
PROJECT_LIBS := $(DEFAULT_LIBS) $(CLANG_LIBS)
PROJECT_WARNINGS := $(DEFAULT_WARNINGS)

CXX_COMPILE = $(CXX) -c $(CXXFLAGS) $(DEFINES) $(INCLUDEPATH)
CXX_LINK = $(CXX) $(LDFLAGS) -shared -Wl,-rpath,\$$ORIGIN/../../../thirdparty/llvm/build/lib/

#################################################################

# OUTPUT CONFIG

#################################################################

PWD = $(shell pwd)
BUILD_DIR = $(PWD)/build
OBJECTS_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin
TEST_OBJECTS_DIR = $(BUILD_DIR)/obj/test


$(TARGET_NAME): bin_dir $(TARGET_NAME)_main.o
	$(CXX_LINK) -o $(BIN_DIR)/$(TARGET_NAME) $(OBJECTS_DIR)/$(TARGET_NAME)_main.o
	$(COPY) $(CXX) $(BIN_DIR)

$(TARGET_NAME)_main.o: obj_dir src/main.cpp
	$(CXX_COMPILE) -o $(OBJECTS_DIR)/$(TARGET_NAME)_main.o src/main.cpp

$(TARGET_NAME).so: bin_dir $(TARGET_NAME).o
	$(CXX_LINK) -o $(BIN_DIR)/$(TARGET_NAME).so $(OBJECTS_DIR)/$(TARGET_NAME).o

$(TARGET_NAME).o: obj_dir src/$(TARGET_NAME).cpp
	$(CXX_COMPILE) -o $(OBJECTS_DIR)/$(TARGET_NAME).o src/$(TARGET_NAME).cpp

test.o: all test_obj_dir test/test.cpp
	$(CXX_COMPILE) -o $(TEST_OBJECTS_DIR)/test.o test/test.cpp

test: bin_dir test.o
	$(CXX_LINK) -o $(BIN_DIR)/$(TARGET_NAME)@test.so $(TEST_OBJECTS_DIR)/test.o