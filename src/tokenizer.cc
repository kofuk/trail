#include <iostream>

#include "token.hh"
#include "tokenizer.hh"

namespace trail {
    namespace {
        // clang-format off
        constexpr int ident_nonleading[256] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
            0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        // clang-format on
    } // namespace

    bool TokenStream::parse_istream(std::istream &strm, SyntaxErrorInfo *err) {
        int line = 1;
        int col = 1;

        for (char c = strm.get(); !strm.fail(); c = strm.get()) {
            switch (c) {
            case '(':
                tokens_.emplace_back(TokenType::L_PAR, "(", line, col);
                col++;
                break;
            case ')':
                tokens_.emplace_back(TokenType::R_PAR, ")", line, col);
                col++;
                break;
#include "alpha.inc" /* case 'a' ... 'z', 'A' ... 'Z' */
            case '_': {
                std::string token;
                col++;
                do {
                    token.push_back(c);
                    c = strm.get();
                    col++;
                } while (!strm.fail() &&
                         ident_nonleading[static_cast<size_t>(c)]);
                if (!strm.fail()) {
                    strm.unget();
                    col--;
                }
                tokens_.emplace_back(TokenType::IDENT, token, line,
                                     col - token.size());
                break;
            }
            case ';':
                tokens_.emplace_back(TokenType::END_STATEMENT, ";", line, col);
                col++;
                break;
            case '\n':
                line++;
                col = 1;
                break;
            case ' ':
            case '\r':
            case '\v':
            case '\t':
                col++;
                break;
            default:
                if (err != nullptr) {
                    err->set_line(line);
                    err->set_column(col);
                    err->set_message("Unexpected character.");
                }
                return false;
            }
        }
        return true;
    }
} // namespace trail
