#ifndef FDCODEANALYSER_NODEFILTER_H
#define FDCODEANALYSER_NODEFILTER_H

#include <unordered_set>

namespace FDCodeAnalyser
{
    class NodeFilter
    {
        public:
            NodeFilter();

        private:
            std::unordered_set<std::string> m_ignore;
            std::unordered_set<std::string> m_parse;
    }
}

#endif // FDCODEANALYSER_NODEFILTER_H