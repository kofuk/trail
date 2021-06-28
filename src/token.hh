#ifndef TOKEN_HH
#define TOKEN_HH

#include <ostream>
#include <string>

namespace trail {

    enum class TokenType {
        IDENT,
        L_PAR,
        R_PAR,
        END_STATEMENT,
    };

    std::ostream &operator<<(std::ostream &out, TokenType ty);

    class Token {
        TokenType ty_;
        std::string token_;
        int line_;
        int col_;

    public:
        Token(TokenType ty, const std::string &token, int line, int col)
            : ty_(ty), token_(token), line_(line), col_(col) {}

        TokenType get_type() const { return ty_; }

        const std::string &get_token() const { return token_; }

        int get_line() const { return line_; }

        int get_column() const { return col_; }
    };

    std::ostream &operator<<(std::ostream &out, Token tk);

} // namespace trail

#endif
