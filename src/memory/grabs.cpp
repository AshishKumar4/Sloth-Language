#include "grabs.hpp"

#include "ast/ast.hpp"
#include "parser/lexical/lexical.hpp"

namespace sloth
{

Grabs<LexicalToken> LexicalToken::grabsToken("tokens");
// Grabs<TokenTree> TokenTree::grabsToken("tokenTreeNodes");

// Grabs<VariableTreeNode> VariableTreeNode::grabsToken("varTreeNodes");
// Grabs<ReturnTreeNode> ReturnTreeNode::grabsToken("returnTreeNodes");
// Grabs<FunctionTreeNode> FunctionTreeNode::grabsToken("funcTreeNodes");
// Grabs<LambdaTreeNode> LambdaTreeNode::grabsToken("lambdaTreeNodes");
// Grabs<ConditionalTreeNode> ConditionalTreeNode::grabsToken("conditionalTreeNodes");
// Grabs<LoopTreeNode> LoopTreeNode::grabsToken("loopTreeNodes");
// Grabs<TempLiteralTreeNode> TempLiteralTreeNode::grabsToken("tempTreeNodes");

// Grabs<OperatorTreeNode> OperatorTreeNode::grabsToken("operatorTreeNodes");
// Grabs<UnaryOperatorTreeNode> UnaryOperatorTreeNode::grabsToken("unaryOperatorTreeNodes");
// Grabs<BinaryOperatorTreeNode> BinaryOperatorTreeNode::grabsToken("binaryOperatorTreeNodes");

void init_grabs()
{
}
}