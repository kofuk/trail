#ifndef TOKENIZER_HH
#define TOKENIZER_HH

#include <optional>
#include <vector>

#include "error-info.hh"
#include "token.hh"

namespace trail {
    class TokenStream {
        std::vector<Token> tokens_;
        size_t index_ = 0;

    public:
        bool parse_istream(std::istream &strm, SyntaxErrorInfo *err);

        std::optional<Token> next() {
            if (index_ < tokens_.size()) {
                index_++;
                return tokens_[index_ - 1];
            }
            return std::nullopt;
        }
    };
} // namespace trail

#endif
