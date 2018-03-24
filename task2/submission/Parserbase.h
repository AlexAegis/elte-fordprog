// Generated by Bisonc++ V4.13.01 on Sat, 24 Mar 2018 23:18:48 +0100

#ifndef ParserBase_h_included
#define ParserBase_h_included

#include <exception>
#include <vector>
#include <iostream>

// $insert preincludes
#include <iostream>

namespace // anonymous
{
    struct PI__;
}



class ParserBase
{
    public:
// $insert tokens

    // Symbolic tokens:
    enum Tokens__
    {
        STMT_DOT = 257,
        STMT_COMMA,
        STMT_OPN,
        COMMENT,
        PROGRAM,
        DATA,
        TYPE,
        TYPE_INTEGER,
        TYPE_BOOLEAN,
        OP_MOVE,
        OP_READ,
        OP_ADD,
        OP_WRITE,
        DIR_TO,
        DIR_BY,
        DIR_FROM,
        STRUCT_IF,
        STRUCT_WHILE,
        STRUCT_ELSE,
        STRUCT_ELSEIF,
        STRUCT_ENDIF,
        STRUCT_ENDWHILE,
        COMP_LS,
        COMP_GT,
        COMP_EQ,
        LOGIC_AND,
        LOGIC_OR,
        LOGIC_NOT,
        MATH_SUB,
        MATH_MULT,
        MATH_DIV,
        VARIABLE,
        NUMBER,
    };

// $insert LTYPE
    struct LTYPE__
    {
        int timestamp;
        int first_line;
        int first_column;
        int last_line;
        int last_column;
        char *text;
    };
    
// $insert STYPE
typedef int STYPE__;

    private:
        int d_stackIdx__;
        std::vector<size_t>   d_stateStack__;
        std::vector<STYPE__>  d_valueStack__;
// $insert LTYPEstack
        std::vector<LTYPE__>      d_locationStack__;

    protected:
        enum Return__
        {
            PARSE_ACCEPT__ = 0,   // values used as parse()'s return values
            PARSE_ABORT__  = 1
        };
        enum ErrorRecovery__
        {
            DEFAULT_RECOVERY_MODE__,
            UNEXPECTED_TOKEN__,
        };
        bool        d_debug__;
        size_t      d_nErrors__;
        size_t      d_requiredTokens__;
        size_t      d_acceptedTokens__;
        int         d_token__;
        int         d_nextToken__;
        size_t      d_state__;
        STYPE__    *d_vsp__;
        STYPE__     d_val__;
        STYPE__     d_nextVal__;
// $insert LTYPEdata
        LTYPE__   d_loc__;
        LTYPE__  *d_lsp__;

        ParserBase();

        void ABORT() const;
        void ACCEPT() const;
        void ERROR() const;
        void clearin();
        bool debug() const;
        void pop__(size_t count = 1);
        void push__(size_t nextState);
        void popToken__();
        void pushToken__(int token);
        void reduce__(PI__ const &productionInfo);
        void errorVerbose__();
        size_t top__() const;

    public:
        void setDebug(bool mode);
}; 

inline bool ParserBase::debug() const
{
    return d_debug__;
}

inline void ParserBase::setDebug(bool mode)
{
    d_debug__ = mode;
}

inline void ParserBase::ABORT() const
{
    throw PARSE_ABORT__;
}

inline void ParserBase::ACCEPT() const
{
    throw PARSE_ACCEPT__;
}

inline void ParserBase::ERROR() const
{
    throw UNEXPECTED_TOKEN__;
}


// As a convenience, when including ParserBase.h its symbols are available as
// symbols in the class Parser, too.
#define Parser ParserBase


#endif


