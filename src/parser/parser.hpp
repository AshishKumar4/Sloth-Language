#pragma once

#include <string>
#include <vector>

#include "lexical/lexical.hpp"
#include "parseTree/treeNodes/treeNodes.hpp"
#include "parseTree/tree.hpp"

namespace sloth 
{
    typedef std::vector<TreeNode*> TreeNodeList;

    enum class ParserStatus
    {
        SUCCESS,
        INCOMPLETE,
        ERROR,
    };

    struct ParserResult 
    {
        ParserStatus status;
        std::string output;
    };

    typedef std::tuple<TreeNodeList, ParserResult> ParserOutput; 

    class Parser 
    {
    public:
        Parser() 
        {
        }

        ParserOutput parse(LexicalTokenList tokens);
    };
}