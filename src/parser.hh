#ifndef PARSER_HH
#define PARSER_HH

#include <vector>

#include "tokenizer.hh"
#include "exec-tree.hh"
#include "error-info.hh"

namespace trail {
    std::vector<Executable *> parse(TokenStream &tokens, SyntaxErrorInfo *err);
}

#endif
