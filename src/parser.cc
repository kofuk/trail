#include "parser.hh"

namespace trail {
    std::vector<Executable *> parse(TokenStream &tokens, SyntaxErrorInfo *err) {
        std::vector<Executable *> result;
        auto tk = tokens.next();
        if (!tk) {
            if (err != nullptr) {
                err->set_message("Unexpected EOF");
            }
            return result;
        }
        if (tk->get_type() != TokenType::IDENT) {
            if (err != nullptr) {
                err->set_message("IDENT expected");
                err->set_line(tk->get_line());
                err->set_column(tk->get_column());
            }
            return result;
        }
        std::string func_name = tk->get_token();

        tk = tokens.next();
        if (!tk) {
            if (err != nullptr) {
                err->set_message("Unexpected EOF");
            }
            return result;
        }
        if (tk->get_type() != TokenType::L_PAR) {
            if (err != nullptr) {
                err->set_message("L_PAR expected");
                err->set_line(tk->get_line());
                err->set_column(tk->get_column());
            }
            return result;
        }

        tk = tokens.next();
        if (!tk) {
            if (err != nullptr) {
                err->set_message("Unexpected EOF");
            }
            return result;
        }
        if (tk->get_type() != TokenType::IDENT) {
            if (err != nullptr) {
                err->set_message("IDENT expected");
                err->set_line(tk->get_line());
                err->set_column(tk->get_column());
            }
            return result;
        }
        std::string arg = tk->get_token();

        tk = tokens.next();
        if (!tk) {
            if (err != nullptr) {
                err->set_message("Unexpected EOF");
            }
            return result;
        }
        if (tk->get_type() != TokenType::R_PAR) {
            if (err != nullptr) {
                err->set_message("R_PAR expected");
                err->set_line(tk->get_line());
                err->set_column(tk->get_column());
            }
            return result;
        }

        tk = tokens.next();
        if (!tk) {
            if (err != nullptr) {
                err->set_message("Unexpected EOF");
            }
            return result;
        }
        if (tk->get_type() != TokenType::END_STATEMENT) {
            if (err != nullptr) {
                err->set_message("END_STATEMENT expected");
                err->set_line(tk->get_line());
                err->set_column(tk->get_column());
            }
            return result;
        }

        auto *funcall = new FunctionCall(func_name, arg);
        result.push_back(funcall);

        return result;
    }
}
