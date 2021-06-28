#ifndef EXEC_TREE_HH
#define EXEC_TREE_HH

#include <iostream>
#include <string>
#include <unordered_map>

#include "variable.hh"

namespace trail {
    using Environment = std::unordered_map<std::string, Variable>;

    class Executable {
    public:
        virtual Variable execute(Environment &env) = 0;
    };

    class FunctionCall: public Executable {
        std::string func_name_;
        std::string arg_;

    public:
        FunctionCall(std::string func_name, std::string arg)
            : func_name_(func_name), arg_(arg) {}

        Variable execute(Environment &env) override {
            if (func_name_ == "print") {
                if (arg_ == "__VERSION__") {
                    std::cout << "0.1" << '\n';
                } else {
                    std::cout << "Undefined variable\n";
                }
            } else {
                std::cout << "Undefined function\n";
            }

            return trail::constants::v_void;
        }
    };
} // namespace trail

#endif
