#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include "memory/grabs.hpp"

namespace sloth 
{
    enum class LexicalTypes 
    {
        UNKNOWN,
        LITERAL,
        KEYWORD,
        IDENTIFIER,
        NUMBER,
        OPERATOR,
        DELIMITER,
        IGNORE,
        INFER,
        SEPERATOR,
        COMMENT,
        count
    };

    class LexicalToken
    {
        static Grabs<LexicalToken> grabsToken;
        LexicalTypes lexicalType;
        std::string data;
    public:
        LexicalToken(std::string data, LexicalTypes type) : data(data), lexicalType(type)
        {
        }

        void* operator new(std::size_t size)
        {
            LexicalToken* tok = grabsToken.grab();
            return tok;
        }

        void operator delete(void* ptr)
        {
            grabsToken.giveBack((LexicalToken*)ptr);
        }
    };

    typedef std::vector<LexicalToken*> LexicalTokenList;

    enum class LexicalParserStatus 
    {
        SUCCESS,
        INCOMPLETE,
        ERROR,
    };

    struct LexicalParserResult 
    {
        LexicalParserStatus status;
        std::string output;
    };

    typedef std::tuple<LexicalTokenList, LexicalParserResult> LexicalParserOutput;

    class LexicalParser
    {
    public:
        LexicalParser() 
        {

        }

        LexicalParserOutput parse(std::string input);
    };
}