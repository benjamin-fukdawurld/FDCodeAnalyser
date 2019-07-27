#include <FDCodeAnalyser/matchers.h>

#include <iostream>
#include <filesystem>

using namespace FDCodeAnalyser;
using namespace clang;
using namespace clang::ast_matchers;

DeclarationMatcher Matchers::variableMatcher = 
    varDecl(decl().bind("id"));

DeclarationMatcher Matchers::namespaceMatcher =
    namespaceDecl(decl().bind("id"));

DeclarationMatcher Matchers::classMatcher =
    cxxRecordDecl(decl().bind("id"));

DeclarationMatcher Matchers::structMatcher =
    recordDecl(
        decl().bind("id"),
        isStruct()
    );

DeclarationMatcher Matchers::functionMatcher =
    functionDecl(decl().bind("id"));


clang::ast_matchers::DeclarationMatcher Matchers::memberMatcher =
    fieldDecl(decl().bind("id"));

clang::ast_matchers::DeclarationMatcher Matchers::methodMatcher =
    cxxMethodDecl(decl().bind("id"));





void DeclMatchCallback::run(const clang::ast_matchers::MatchFinder::MatchResult &result)
{
    m_context = result.Context;
    m_sourceMgr = result.SourceManager;
    const NamedDecl *named = result.Nodes.getNodeAs<clang::NamedDecl>("id");
    if(!named)
    return;

    DeclMatchFilter filter(m_sourceMgr);
    filter.setFileFilter([](const std::string &path)
    {
        const std::string str("playground.cpp");
        for(auto it = str.rbegin(), path_it = path.rbegin(); it != str.rend(); ++it, ++path_it)
        {
            if(*it != *path_it)
            return false;
        }

        return true;
    });
    
    filter.setNameFilter([](const std::string &name){ std::cout << name << std::endl; return true; });
    if(!filter.match(named))
    return;

    {
        const NamespaceDecl *ns = result.Nodes.getNodeAs<clang::NamespaceDecl>("id");
        if (ns)
        {
            foundNamespace(ns);
            return;
        }
    }

    {
        const VarDecl *var = result.Nodes.getNodeAs<clang::VarDecl>("id");
        if (var)
        {
            foundVariable(var);
            return;
        }
    }

    {
        const FunctionDecl *func = result.Nodes.getNodeAs<clang::FunctionDecl>("id");
        if (func)
        {
            foundFunction(func);
            return;
        }
    }

    {
        const RecordDecl *struc = result.Nodes.getNodeAs<clang::RecordDecl>("id");
        if (struc)
        {
            foundStruct(struc);
            return;
        }
    }

    {
        const CXXRecordDecl *clas = result.Nodes.getNodeAs<clang::CXXRecordDecl>("id");
        if (clas)
        {
            foundClass(clas);
            return;
        }
    }

    {
        const FieldDecl *member = result.Nodes.getNodeAs<clang::FieldDecl>("id");
        if (member)
        {
            foundMember(member);
            return;
        }
    }

    {
        const CXXMethodDecl *method = result.Nodes.getNodeAs<clang::CXXMethodDecl>("id");
        if (method)
        {
            foundMethod(method);
            return;
        }
    }
}

void DeclMatchCallback::foundNamespace(const clang::NamespaceDecl *decl)
{

}

void DeclMatchCallback::foundVariable(const clang::VarDecl *decl)
{

}

void DeclMatchCallback::foundFunction(const clang::FunctionDecl *decl)
{

}

void DeclMatchCallback::foundClass(const clang::CXXRecordDecl *decl)
{

}

void DeclMatchCallback::foundStruct(const clang::RecordDecl *decl)
{

}

void DeclMatchCallback::foundMember(const clang::FieldDecl *decl)
{

}

void DeclMatchCallback::foundMethod(const clang::CXXMethodDecl *decl)
{

}