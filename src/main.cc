#include <iostream>

#include "error-info.hh"
#include "tokenizer.hh"
#include "parser.hh"
#include "exec-tree.hh"

int main(void) {
    trail::TokenStream tokens;
    trail::SyntaxErrorInfo err;
    if (!tokens.parse_istream(std::cin, &err)) {
        std::cout << "In file -: " << err.get_line() << ": " << err.get_column()
                  << ": "
                  << "Syntax error: " << err.get_message() << '\n';

        return 1;
    }

    std::vector<trail::Executable *> exec = trail::parse(tokens, &err);
    if (exec.empty()) {
        std::cout << "In file -: " << err.get_line() << ": " << err.get_column()
                  << ": "
                  << "Syntax error: " << err.get_message() << '\n';

        return 1;
    } else {
        trail::Environment env;
        exec[0]->execute(env);
    }
}
