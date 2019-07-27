#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-variable"

// Declares clang::SyntaxOnlyAction.
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
// Declares llvm::cl::extrahelp.
#include <llvm/Support/CommandLine.h>

#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>

#pragma clang diagnostic pop

#include <FDCodeAnalyser/matchers.h>



using namespace clang;
using namespace clang::tooling;
using namespace llvm;
using namespace clang::ast_matchers;

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static cl::OptionCategory MyToolCategory("FDCodeAnalyser options");

// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);

// A help message for this specific tool can be added afterwards.
static cl::extrahelp MoreHelp("\nMore help text...\n");

int main(int argc, const char **argv)
{
    CommonOptionsParser OptionsParser(argc, argv, MyToolCategory);
    ClangTool Tool(OptionsParser.getCompilations(),
                 OptionsParser.getSourcePathList());


    FDCodeAnalyser::DeclMatchCallback declCB;
    MatchFinder Finder;
    Finder.addMatcher(FDCodeAnalyser::Matchers::namespaceMatcher, &declCB);
    Finder.addMatcher(FDCodeAnalyser::Matchers::variableMatcher, &declCB);
    Finder.addMatcher(FDCodeAnalyser::Matchers::functionMatcher, &declCB);
    Finder.addMatcher(FDCodeAnalyser::Matchers::classMatcher, &declCB);
    Finder.addMatcher(FDCodeAnalyser::Matchers::structMatcher, &declCB);
    Finder.addMatcher(FDCodeAnalyser::Matchers::memberMatcher, &declCB);
    Finder.addMatcher(FDCodeAnalyser::Matchers::methodMatcher, &declCB);

    return Tool.run(newFrontendActionFactory(&Finder).get());
}
