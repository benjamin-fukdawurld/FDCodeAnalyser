#ifndef FDCODEANALYSER_MATCHERS_H
#define FDCODEANALYSER_MATCHERS_H

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-variable"

#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>

#pragma clang diagnostic pop

#include <functional>

namespace FDCodeAnalyser
{
    struct Matchers
    {
        static clang::ast_matchers::DeclarationMatcher namespaceMatcher;
        static clang::ast_matchers::DeclarationMatcher variableMatcher;
        static clang::ast_matchers::DeclarationMatcher functionMatcher;
        static clang::ast_matchers::DeclarationMatcher classMatcher;
        static clang::ast_matchers::DeclarationMatcher structMatcher;
        static clang::ast_matchers::DeclarationMatcher memberMatcher;
        static clang::ast_matchers::DeclarationMatcher methodMatcher;
    };

    class DeclMatchFilter
    {
        public:
            DeclMatchFilter(clang::SourceManager *sourceMgr) : m_sourceMgr(sourceMgr)
            {}

            bool match(const clang::NamedDecl *decl) const
            {
                if(!decl->getIdentifier())
                    return false;

                return (!m_fileFilter || m_fileFilter(m_sourceMgr->getFilename(decl->getLocation())))
                        && (!m_nameFilter || m_nameFilter(decl->getNameAsString()));
            }

            std::function<bool(const std::string &)> getFileFilter() const
            {
                return m_fileFilter;
            }

            template<typename FilterFunc>
            void setFileFilter(FilterFunc func)
            {
                m_fileFilter = func;
            }

            std::function<bool(const std::string &)> getNameFilter() const
            {
                return m_nameFilter;
            }

            template<typename FilterFunc>
            void setNameFilter(FilterFunc func)
            {
                m_nameFilter = func;
            }
        
        private:
            clang::SourceManager *m_sourceMgr;
            std::function<bool(const std::string &)> m_fileFilter;
            std::function<bool(const std::string &)> m_nameFilter;
    };

    /**
     * A Functor object used when a matcher matched something
     */
    class DeclMatchCallback : public clang::ast_matchers::MatchFinder::MatchCallback
    {
        public:
            void run(const clang::ast_matchers::MatchFinder::MatchResult &result) override;

        private:
            clang::ASTContext *m_context;
            clang::SourceManager *m_sourceMgr;
            std::string m_fileName;

        protected:
            void foundNamespace(const clang::NamespaceDecl *decl);
            void foundVariable(const clang::VarDecl *decl);
            void foundFunction(const clang::FunctionDecl *decl);
            void foundClass(const clang::CXXRecordDecl *decl);
            void foundStruct(const clang::RecordDecl *decl);
            void foundMember(const clang::FieldDecl *decl);
            void foundMethod(const clang::CXXMethodDecl *decl);
    };
}

#endif // FDCODEANALYSER_MATCHERS_H
