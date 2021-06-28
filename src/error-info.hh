#ifndef ERROR_INFO_HH
#define ERROR_INFO_HH

#include <string>

namespace trail {

    class ErrorInfo {
        std::string message_;

    public:
        void set_message(const std::string &message) { message_ = message; }

        const std::string &get_message() const { return message_; }
    };

    class SyntaxErrorInfo : public ErrorInfo {
        int line_;
        int col_;

    public:
        void set_line(int line) { line_ = line; }

        int get_line() const { return line_; }

        void set_column(int column) { col_ = column; }

        int get_column() const { return col_; }
    };

} // namespace trail

#endif
