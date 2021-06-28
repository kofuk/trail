#ifndef VARIABLE_HH
#define VARIABLE_HH

namespace trail {
    enum class VariableType {
        NONE,
        STRING,
    };

    class Variable {
        VariableType type_;
        bool readonly_;

    public:
        Variable(VariableType type, bool readonly)
            : type_(type), readonly_(readonly) {}

        bool is_readonly() const { return readonly_; }

        void make_readonly() { readonly_ = true; }

        VariableType get_type() const {
            return type_;
        }
    };

    namespace constants {
        extern const Variable v_void;
    }
} // namespace trail

#endif
