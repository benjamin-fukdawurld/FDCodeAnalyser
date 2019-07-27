/*#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Tooling/Tooling.h>

using namespace clang;

class FindNamedClassVisitor
  : public RecursiveASTVisitor<FindNamedClassVisitor> {
public:
  explicit FindNamedClassVisitor(ASTContext *Context)
    : Context(Context) {}

  bool VisitCXXRecordDecl(CXXRecordDecl *Declaration) {
    if (Declaration->getQualifiedNameAsString() == "n::m::C") {
      FullSourceLoc FullLocation = Context->getFullLoc(Declaration->getBeginLoc());
      if (FullLocation.isValid())
        llvm::outs() << "Found declaration at "
                     << FullLocation.getSpellingLineNumber() << ":"
                     << FullLocation.getSpellingColumnNumber() << "\n";
    }
    return true;
  }

private:
  ASTContext *Context;
};

class FindNamedClassConsumer : public clang::ASTConsumer {
public:
  explicit FindNamedClassConsumer(ASTContext *Context)
    : Visitor(Context) {}

  virtual void HandleTranslationUnit(clang::ASTContext &Context) {
    Visitor.TraverseDecl(Context.getTranslationUnitDecl());
  }
private:
  FindNamedClassVisitor Visitor;
};

class FindNamedClassAction : public clang::ASTFrontendAction {
public:
  virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
    clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
    return std::unique_ptr<clang::ASTConsumer>(
        new FindNamedClassConsumer(&Compiler.getASTContext()));
  }
};

int main(int argc, char **argv) {
  if (argc > 1) {
    clang::tooling::runToolOnCode(new FindNamedClassAction, argv[1]);
  }
}*/

// Declares clang::SyntaxOnlyAction.
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
// Declares llvm::cl::extrahelp.
#include "llvm/Support/CommandLine.h"

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

#include <FDCodeAnalyser/matchers.h>

using namespace clang;
using namespace clang::tooling;
using namespace llvm;
using namespace clang::ast_matchers;

/*StatementMatcher LoopMatcher =
  forStmt(
      hasLoopInit(
          declStmt(
              hasSingleDecl(
                  varDecl(
                    hasInitializer(
                        integerLiteral(
                            equals(0)
                            )
                        )
                    )
                )
            )
        )
    ).bind("forLoop");

class LoopPrinter : public MatchFinder::MatchCallback
{
    public :
        virtual void run(const MatchFinder::MatchResult &Result)
        {
            if (const ForStmt *FS = Result.Nodes.getNodeAs<clang::ForStmt>("forLoop"))
            FS->dump();
        }
};*/

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
//static cl::OptionCategory MyToolCategory("FDCodeAnalyser options");

// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
//static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);

// A help message for this specific tool can be added afterwards.
//static cl::extrahelp MoreHelp("\nMore help text...\n");

/*class FindNamedClassVisitor : public RecursiveASTVisitor<FindNamedClassVisitor>
{
    public:
        explicit FindNamedClassVisitor(ASTContext *Context)
            : Context(Context) {}

        bool VisitCXXRecordDecl(CXXRecordDecl *Declaration)
        {
            if (true)//(Declaration->getQualifiedNameAsString() == "main")
            {
                FullSourceLoc FullLocation = Context->getFullLoc(Declaration->getBeginLoc());
                if (FullLocation.isValid())
                {
                    llvm::outs() << "Found declaration at "
                                << FullLocation.getSpellingLineNumber() << ":"
                                << FullLocation.getSpellingColumnNumber() << "\n";
                }
            }
            return true;
        }

    private:
        ASTContext *Context;
};

class FindNamedClassConsumer : public clang::ASTConsumer
{
    public:
        explicit FindNamedClassConsumer(ASTContext *Context)
            : Visitor(Context) {}

        virtual void HandleTranslationUnit(clang::ASTContext &Context)
        {
            // Traversing the translation unit decl via a RecursiveASTVisitor
            // will visit all nodes in the AST.
            Visitor.TraverseDecl(Context.getTranslationUnitDecl());
        }
    private:
        // A RecursiveASTVisitor implementation.
        FindNamedClassVisitor Visitor;
};

class FindNamedClassAction : public clang::ASTFrontendAction
{
    public:
        virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
            clang::CompilerInstance &Compiler, llvm::StringRef InFile)
        {
            return std::unique_ptr<clang::ASTConsumer>(new FindNamedClassConsumer(&Compiler.getASTContext()));
        }
};*/

/*int main(int argc, const char **argv)
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
}*/