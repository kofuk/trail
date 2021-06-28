#include "token.hh"

namespace trail {

    std::ostream &operator<<(std::ostream &out, TokenType ty) {
        switch (ty) {
        case TokenType::IDENT:
            out << "TokenType::IDENT";
            break;
        case TokenType::L_PAR:
            out << "TokenType::L_PAR";
            break;
        case TokenType::R_PAR:
            out << "TokenType::R_PAR";
            break;
        case TokenType::END_STATEMENT:
            out << "TokenType::END_STATEMENT";
            break;
        }
        return out;
    }

    std::ostream &operator<<(std::ostream &out, Token tk) {
        return out << tk.get_type() << " at " << tk.get_line() << ": "
                   << tk.get_column();
    }

} // namespace trail
