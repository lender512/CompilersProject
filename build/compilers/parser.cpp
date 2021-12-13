// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 1 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"

#include <iostream>
#include <string>
#include <cmath>
#include <FlexLexer.h>
#include "symbolTable.hpp"

using namespace std;

extern int mylineno; 


#line 53 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"


#include "parser.hpp"


// Unqualified %code blocks.
#line 33 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"

    #include "FlexScanner.hpp"
    #define yylex(x) scanner->lex(x)
    auto instance = Structure::getInstance();


    enum variableType {
            VARIABLE,
            ARRAY,
            FUNCTION
    };

    variableType currentVariable = variableType::VARIABLE;
    int arraySize = 0;

    string currentParamName = "";
    int currentParamType = 0;

    std::vector<std::tuple<std::string, int>> currentParams;

    std::vector<std::string> currentParamElement;

#line 83 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 18 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
namespace utec { namespace compilers {
#line 156 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (FlexScanner* scanner_yyarg, int* result_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      result (result_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
  {
    switch (this->type_get ())
    {
      case 3: // NUMBER
        value.move< int > (std::move (that.value));
        break;

      case 29: // VARIABLE
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->type_get ())
    {
      case 3: // NUMBER
        value.copy< int > (YY_MOVE (that.value));
        break;

      case 29: // VARIABLE
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 3: // NUMBER
        value.move< int > (YY_MOVE (s.value));
        break;

      case 29: // VARIABLE
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 3: // NUMBER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 29: // VARIABLE
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 3: // NUMBER
        value.move< int > (YY_MOVE (that.value));
        break;

      case 29: // VARIABLE
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // NUMBER
        value.copy< int > (that.value);
        break;

      case 29: // VARIABLE
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // NUMBER
        value.move< int > (that.value);
        break;

      case 29: // VARIABLE
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 3: // NUMBER
        yylhs.value.emplace< int > ();
        break;

      case 29: // VARIABLE
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 75 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
                            {
    instance->printNiceType();
    }
#line 727 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"
    break;

  case 5:
#line 85 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
                                               {
        switch(currentVariable) {
                case variableType::VARIABLE:
                        instance->addVariable(yystack_[1].value.as < std::string > (), 1);
                        break;
                case variableType::ARRAY:
                        instance->addVariableArray(yystack_[1].value.as < std::string > (), 1, arraySize);
                        break;
                default:
                        cout << "Error: variable type not allowed" << endl;
                        exit(1);
                        break;
        }
}
#line 746 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"
    break;

  case 7:
#line 100 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
                                                                               {int type = 0;
            instance->addFunction(yystack_[4].value.as < std::string > (), type, currentParams);
            currentParams.clear();
        }
#line 755 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"
    break;

  case 8:
#line 104 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
                                                                            {int type = 1;
            instance->addFunction(yystack_[4].value.as < std::string > (), type, currentParams);
            currentParams.clear();
        }
#line 764 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"
    break;

  case 11:
#line 117 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
                                {currentVariable = variableType::VARIABLE;}
#line 770 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"
    break;

  case 12:
#line 118 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
                                                      {currentVariable = variableType::ARRAY; arraySize = yystack_[2].value.as < int > ();}
#line 776 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"
    break;

  case 13:
#line 119 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
                          {yyerrok; yyclearin;}
#line 782 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"
    break;

  case 14:
#line 125 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
                  {currentParamType = 1;}
#line 788 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"
    break;

  case 20:
#line 138 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
                     {currentParamName = yystack_[0].value.as < std::string > (); currentParams.push_back(std::make_tuple(currentParamName, currentParamType));}
#line 794 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"
    break;

  case 32:
#line 161 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
                          {yyerrok; yyclearin;}
#line 800 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"
    break;

  case 35:
#line 166 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
                             {yyerrok; yyclearin;}
#line 806 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"
    break;

  case 39:
#line 174 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
                          {yyerrok; yyclearin;}
#line 812 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"
    break;


#line 816 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -46;

  const signed char Parser::yytable_ninf_ = -18;

  const signed char
  Parser::yypact_[] =
  {
      -2,   -28,   -11,    22,    -2,   -46,    37,    15,   -46,   -46,
      27,     2,    61,   -46,   -46,   -46,     2,   -46,   -46,    66,
      38,    76,    84,   -46,    67,    78,   -46,   -12,    17,    74,
      25,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,    99,
      77,     4,    34,    47,   -46,    44,    82,    83,     7,   -46,
     -46,    21,   -46,   -46,   -46,   -46,   -46,    80,    90,   -46,
      69,    75,   -46,   -46,   -46,   -46,   -46,   -46,    81,     7,
       7,    87,     7,     7,   -46,     7,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,     7,     7,   -46,   -46,     7,   -46,
      88,    89,   -46,   -46,    91,    97,    92,   -46,   -46,    79,
      75,   -46,    93,    94,   -46,     7,   -46,   -46,   -46,   -46,
      12,    41,   -46,   106,    95,   -46,    49,   -46
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     2,     4,     0,     0,     1,     3,
       0,     0,     0,    11,     5,     9,     0,    13,    14,    15,
       0,     0,    16,    19,     0,     0,    20,     0,     0,     0,
       0,    23,     7,    10,    15,    18,    12,     8,     6,    25,
       0,     0,     0,     0,    63,     0,     0,     0,     0,    21,
      31,    42,    24,    26,    27,    28,    29,     0,    61,    41,
      45,    53,    57,    62,    22,    35,    32,    37,     0,     0,
       0,     0,    66,     0,    30,     0,    47,    49,    50,    51,
      48,    46,    54,    55,     0,     0,    58,    59,     0,    38,
       0,     0,    60,    68,     0,    65,     0,    40,    61,    44,
      52,    56,     0,     0,    64,     0,    43,    25,    25,    67,
       0,     0,    36,    33,     0,    25,     0,    34
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -46,   -46,   -46,   112,   -46,    85,   -46,   102,   -46,    96,
      98,   -46,   -22,   -46,   -46,   -46,   -46,   -46,   -45,     6,
     -46,   -46,    39,   -46,    40,   -46,    42,   -46,   -46,   -46
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     3,     4,     5,    14,    15,    20,    21,    22,    23,
      33,    39,    41,    52,    53,    54,    55,    56,    57,    58,
      59,    84,    60,    85,    61,    88,    62,    63,    94,    95
  };

  const signed char
  Parser::yytable_[] =
  {
      68,     6,     1,    71,     2,    43,    18,    44,    19,    45,
      44,    46,    47,    43,    31,    44,    32,    45,     7,    46,
      47,    18,     8,    34,    90,    91,    48,    93,    96,    48,
      97,    49,    50,    51,    48,    10,    51,    16,    10,   112,
      50,    51,    43,    72,    44,    73,    45,    44,    46,    47,
      43,    31,    44,    37,    45,    17,    46,    47,    12,    11,
     109,    12,    13,    48,    24,    13,    48,    26,   113,    50,
      51,    48,    67,    51,    65,    66,   117,    50,    51,    76,
      77,    78,    79,    80,    81,   110,   111,    82,    83,   -17,
      98,    98,    29,   116,    98,    86,    87,    82,    83,    27,
      28,    30,    36,    40,    69,    70,    42,    75,    74,    89,
      92,   102,   103,   105,   104,   114,     9,   106,    25,   107,
     108,   115,     0,    99,    35,   100,     0,    64,    38,     0,
     101
  };

  const signed char
  Parser::yycheck_[] =
  {
      45,    29,     4,    48,     6,     1,     4,     3,     6,     5,
       3,     7,     8,     1,    26,     3,    28,     5,    29,     7,
       8,     4,     0,     6,    69,    70,    22,    72,    73,    22,
      75,    27,    28,    29,    22,     1,    29,    22,     1,    27,
      28,    29,     1,    22,     3,    24,     5,     3,     7,     8,
       1,    26,     3,    28,     5,    28,     7,     8,    24,    22,
     105,    24,    28,    22,     3,    28,    22,    29,    27,    28,
      29,    22,    28,    29,    27,    28,    27,    28,    29,    10,
      11,    12,    13,    14,    15,   107,   108,    18,    19,    23,
      84,    85,    25,   115,    88,    20,    21,    18,    19,    23,
      16,    23,    28,     4,    22,    22,    29,    17,    28,    28,
      23,    23,    23,    16,    23,     9,     4,    25,    16,    26,
      26,    26,    -1,    84,    28,    85,    -1,    42,    30,    -1,
      88
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     4,     6,    34,    35,    36,    29,    29,     0,    36,
       1,    22,    24,    28,    37,    38,    22,    28,     4,     6,
      39,    40,    41,    42,     3,    40,    29,    23,    16,    25,
      23,    26,    28,    43,     6,    42,    28,    28,    43,    44,
       4,    45,    29,     1,     3,     5,     7,     8,    22,    27,
      28,    29,    46,    47,    48,    49,    50,    51,    52,    53,
      55,    57,    59,    60,    38,    27,    28,    28,    51,    22,
      22,    51,    22,    24,    28,    17,    10,    11,    12,    13,
      14,    15,    18,    19,    54,    56,    20,    21,    58,    28,
      51,    51,    23,    51,    61,    62,    51,    51,    52,    55,
      57,    59,    23,    23,    23,    16,    25,    26,    26,    51,
      45,    45,    27,    27,     9,    26,    45,    27
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    33,    34,    35,    35,    36,    36,    36,    36,    37,
      37,    38,    38,    38,    39,    39,    40,    40,    41,    41,
      42,    43,    44,    44,    45,    45,    46,    46,    46,    46,
      47,    47,    47,    48,    48,    48,    49,    50,    50,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      59,    59,    59,    59,    60,    61,    61,    62,    62
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     3,     6,     6,     6,     1,
       4,     1,     4,     2,     1,     1,     1,     1,     3,     1,
       2,     4,     4,     0,     2,     0,     1,     1,     1,     1,
       2,     1,     2,     7,    11,     2,     7,     2,     3,     2,
       3,     1,     1,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     4,     1,     0,     3,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "NUMBER", "INTEGER", "RETURN", "VOID",
  "WHILE", "IF", "ELSE", "LESS_EQUAL", "GREATER_EQUAL", "EQUAL",
  "NOT_EQUAL", "GREATER", "LESS", "COMA", "OP_ASSIGN", "OP_ADD", "OP_SUBS",
  "OP_MULT", "OP_DIVISION", "PARENTHESES_LEFT", "PARENTHESES_RIGHT",
  "BRACKET_LEFT", "BRACKET_RIGHT", "BRACES_LEFT", "BRACES_RIGHT",
  "SEMICOLON", "VARIABLE", "PLUS", "REST", "MULT", "$accept", "programa",
  "lista_declaracion", "declaracion", "declaracion_fact",
  "var_declaracion_fact", "tipo", "params", "lista_params", "param",
  "sent_compuesta", "declaracion_local", "lista_sentencias", "sentencia",
  "sentencia_expresion", "sentencia_seleccion", "sentencia_iteracion",
  "sentencia_retorno", "expresion", "var", "expresion_simple", "relop",
  "expresion_aditiva", "addop", "term", "mulop", "factor", "call", "args",
  "lista_arg", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    75,    75,    80,    81,    85,    99,   100,   104,   111,
     113,   117,   118,   119,   125,   126,   130,   131,   134,   135,
     138,   141,   144,   145,   148,   149,   152,   153,   154,   155,
     159,   160,   161,   164,   165,   166,   169,   172,   173,   174,
     177,   178,   181,   182,   185,   186,   189,   190,   191,   192,
     193,   194,   197,   198,   201,   202,   205,   206,   209,   210,
     213,   214,   215,   216,   219,   222,   223,   226,   227
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
    };
    const int user_token_number_max_ = 287;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 18 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"
} } // utec::compilers
#line 1331 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/build/compilers/parser.cpp"

#line 231 "/home/lordmarcusvane/lordmarcusvane/Hackprog/compiladores/CompilersProject/compilers/parser.y"


void utec::compilers::Parser::error(const std::string& msg) {
    std::cout << msg << " in line "<< mylineno <<  '\n';
    
    /* exit(1); */
}
