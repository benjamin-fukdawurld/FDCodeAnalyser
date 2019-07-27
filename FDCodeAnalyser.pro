TARGET = FDCodeAnalyser
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++17

INCLUDEPATH += \
    include \
    ../thirdparty/rapidjson/include \
    ../thirdparty/llvm/llvm/include \
    ../thirdparty/llvm/clang/include \
    ../thirdparty/llvm/build/include \
    ../thirdparty/llvm/build/tools/clang/include \
    ../thirdparty/llvm/clang/lib/Headers \
    ../thirdparty/build/tools/clang/lib/Headers \
    ../thirdparty/build/lib/clang/10.0.0/include \

DEPENDPATH += \
    include \
    ../thirdparty/rapidjson/include \
    ../thirdparty/llvm/llvm/include \
    ../thirdparty/llvm/clang/include \
    ../thirdparty/llvm/build/include \
    ../thirdparty/llvm/build/tools/clang/include \
    ../thirdparty/llvm/clang/lib/Headers \
    ../thirdparty/build/tools/clang/lib/Headers \
    ../thirdparty/build/lib/clang/10.0.0/include \

DEFINES += \
    _GNU_SOURCE \
    _DEBUG \
    __STDC_CONSTANT_MACROS \
    __STDC_FORMAT_MACROS \
    __STDC_LIMIT_MACROS \
    LLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING=1 \

HEADERS += \
    include/FDCodeAnalyser/matchers.h

SOURCES += \
    src/main.cpp \
    src/matchers.cpp

LIBS += \
    -lLLVMLTO \
    -lLLVMPasses \
    -lLLVMObjCARCOpts \
    -lLLVMFuzzMutate \
    -lLLVMMCA \
    -lLLVMTableGen \
    -lLLVMDlltoolDriver \
    -lLLVMLineEditor \
    -lLLVMXRay \
    -lLLVMOrcJIT \
    -lLLVMJITLink \
    -lLLVMSymbolize \
    -lLLVMDebugInfoPDB \
    -lLLVMTestingSupport \
    -lLLVMXCoreDisassembler \
    -lLLVMXCoreCodeGen \
    -lLLVMXCoreDesc \
    -lLLVMXCoreInfo \
    -lLLVMWebAssemblyDisassembler \
    -lLLVMWebAssemblyCodeGen \
    -lLLVMWebAssemblyDesc \
    -lLLVMWebAssemblyAsmParser \
    -lLLVMWebAssemblyInfo \
    -lLLVMSystemZDisassembler \
    -lLLVMSystemZCodeGen \
    -lLLVMSystemZAsmParser \
    -lLLVMSystemZDesc \
    -lLLVMSystemZInfo \
    -lLLVMSparcDisassembler \
    -lLLVMSparcCodeGen \
    -lLLVMSparcAsmParser \
    -lLLVMSparcDesc \
    -lLLVMSparcInfo \
    -lLLVMPowerPCDisassembler \
    -lLLVMPowerPCCodeGen \
    -lLLVMPowerPCAsmParser \
    -lLLVMPowerPCDesc \
    -lLLVMPowerPCInfo \
    -lLLVMNVPTXCodeGen \
    -lLLVMNVPTXDesc \
    -lLLVMNVPTXInfo \
    -lLLVMMSP430Disassembler \
    -lLLVMMSP430CodeGen \
    -lLLVMMSP430AsmParser \
    -lLLVMMSP430Desc \
    -lLLVMMSP430Info \
    -lLLVMMipsDisassembler \
    -lLLVMMipsCodeGen \
    -lLLVMMipsAsmParser \
    -lLLVMMipsDesc \
    -lLLVMMipsInfo \
    -lLLVMLanaiDisassembler \
    -lLLVMLanaiCodeGen \
    -lLLVMLanaiAsmParser \
    -lLLVMLanaiDesc \
    -lLLVMLanaiInfo -lLLVMHexagonDisassembler -lLLVMHexagonCodeGen \
    -lLLVMHexagonAsmParser -lLLVMHexagonDesc -lLLVMHexagonInfo -lLLVMBPFDisassembler \
    -lLLVMBPFCodeGen -lLLVMBPFAsmParser -lLLVMBPFDesc -lLLVMBPFInfo \
    -lLLVMARMDisassembler -lLLVMARMCodeGen -lLLVMARMAsmParser -lLLVMARMDesc \
    -lLLVMARMUtils -lLLVMARMInfo -lLLVMAMDGPUDisassembler -lLLVMAMDGPUCodeGen \
    -lLLVMMIRParser -lLLVMAMDGPUAsmParser -lLLVMAMDGPUDesc -lLLVMAMDGPUUtils \
    -lLLVMAMDGPUInfo -lLLVMAArch64Disassembler -lLLVMAArch64CodeGen \
    -lLLVMAArch64AsmParser -lLLVMAArch64Desc -lLLVMAArch64Utils -lLLVMAArch64Info \
    -lLLVMObjectYAML -lLLVMLibDriver -lLLVMOption -lLLVMWindowsManifest -lLLVMTextAPI \
    -lLLVMX86Disassembler -lLLVMX86AsmParser -lLLVMX86CodeGen -lLLVMGlobalISel \
    -lLLVMSelectionDAG -lLLVMAsmPrinter -lLLVMDebugInfoDWARF -lLLVMX86Desc \
    -lLLVMMCDisassembler -lLLVMX86Utils -lLLVMX86Info -lLLVMMCJIT -lLLVMInterpreter \
    -lLLVMExecutionEngine -lLLVMRuntimeDyld -lLLVMCodeGen -lLLVMTarget \
    -lLLVMCoroutines -lLLVMipo -lLLVMInstrumentation -lLLVMVectorize \
    -lLLVMScalarOpts -lLLVMLinker -lLLVMIRReader -lLLVMAsmParser \
    -lLLVMInstCombine -lLLVMBitWriter -lLLVMAggressiveInstCombine \
    -lLLVMTransformUtils -lLLVMAnalysis -lLLVMCoverage -lLLVMProfileData \
    -lLLVMObject -lLLVMMCParser -lLLVMMC -lLLVMDebugInfoCodeView -lLLVMDebugInfoMSF \
    -lLLVMBitReader -lLLVMCore -lLLVMRemarks -lLLVMBinaryFormat -lLLVMSupport \
    -lLLVMDemangle -lz -lrt -ldl -lpthread -lm -lncurses \
    -lclangAnalysis -lclangARCMigrate -lclangAST -lclangASTMatchers -lclangBasic -lclangCodeGen \
    -lclang-cpp -lclangCrossTU -lclangDependencyScanning -lclangDirectoryWatcher -lclangDriver \
    -lclangDynamicASTMatchers -lclangEdit -lclangFormat -lclangFrontend -lclangFrontendTool \
    -lclangHandleCXX -lclangHandleLLVM -lclangIndex -lclangLex -lclangParse -lclangRewrite \
    -lclangRewriteFrontend -lclangSema -lclangSerialization -lclang -lclangStaticAnalyzerCheckers \
    -lclangStaticAnalyzerCore -lclangStaticAnalyzerFrontend -lclangTooling -lclangToolingASTDiff \
    -lclangToolingCore -lclangToolingInclusions -lclangToolingRefactoring -lclangToolingSyntax
