#include "iostream"
#include "string"
#include "stdlib.h"
#include "stdint.h"
#include "stdio.h"
#include "sstream"
#include "fstream"

#include "ast/ast.hpp"
#include "common/ShellColors.hpp"

#include "parser/parser.hpp"

#define SHELL_PROMPT_TEXT "Sloth-beta"

class SlothShell
{
    std::vector<std::string> SHELL_HISTORY;
    sloth::Parser *parser;
    sloth::LexicalParser *lexicalParser;

public:
    SlothShell()
    {
        this->parser = new sloth::Parser();
        this->lexicalParser = new sloth::LexicalParser();
    }

    inline void displayPrompt()
    {
        int sys_tmp;
        setColor(RED);
        std::cout << SHELL_PROMPT_TEXT;
        setColor(GREEN);
        std::cout << " > ";
        setColor(WHITE);
    }

    auto interpreter(std::string input)
    {
        auto [tokens, lexicalResults] = this->lexicalParser->parse(input);
        auto [nodes, parserResults] = this->parser->parse(tokens);
        std::cout << std::endl;
        for (auto i : nodes)
        {
            // std::cout << "\t" << i->getName();
            fflush(stdout);
        }
        return 1;
    }

    void shellLoop()
    {
        while (true)
        {
            displayPrompt();

            std::string userInput;
            std::getline(std::cin, userInput);

            setColor(YELLOW);
            std::string val;
            try
            {
                SHELL_HISTORY.push_back(userInput);
                val = interpreter(userInput);
            }
            catch (std::exception &e)
            {
                std::cout << "Error Occured! " << e.what();
            }
            setColor(BRIGHT_GREEN);
            std ::cout << std::endl
                       << val << std::endl;
        }
    }

    void executeCode(std::string filename)
    {
        auto in = std::fstream(filename);
        std::string code(static_cast<std::stringstream const &>(std::stringstream() << in.rdbuf()).str());
        std::cout << "\nExecuting Code -->\n\n";
        setColor(YELLOW);
        auto val = interpreter(code);
        setColor(BRIGHT_GREEN);
        std ::cout << std::endl
                   << val << std::endl;
    }
};

int main(int argc, char **argv)
{
    printf("\nInitializing Sloth...\n");
    SlothShell shell;

    if (argc > 1)
    {
        shell.executeCode(std::string(argv[1]));
    }
    else
    {
        shell.shellLoop();
    }
    // Trie<std::string>   trie;
    // trie.save("help", "WOW THIS WORKS");
    // trie.save("fuck", "THIS");
    // trie.save("helpme", "FUCKING");
    // trie.save("helpm", "WORKS");

    // std::cout<<trie.get("help") << std::endl<<trie.get("fuck") << std::endl<<trie.get("helpme") << std::endl<<trie.get("helpm") << std::endl;

    return 0;
}
