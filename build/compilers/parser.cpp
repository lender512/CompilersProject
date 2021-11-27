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
#line 1 "/home/luis/repos/Compilers/CompilersProject/compilers/parser.y"

#include <iostream>
#include <string>
#include <cmath>
#include <FlexLexer.h>

#line 47 "/home/luis/repos/Compilers/CompilersProject/build/compilers/parser.cpp"


#include "parser.hpp"


// Unqualified %code blocks.
#line 24 "/home/luis/repos/Compilers/CompilersProject/compilers/parser.y"

    #include "FlexScanner.hpp"
    #define yylex(x) scanner->lex(x)

#line 59 "/home/luis/repos/Compilers/CompilersProject/build/compilers/parser.cpp"


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

#line 12 "/home/luis/repos/Compilers/CompilersProject/compilers/parser.y"
namespace utec { namespace compilers {
#line 132 "/home/luis/repos/Compilers/CompilersProject/build/compilers/parser.cpp"


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

      case 30: // VARIABLE
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

      case 30: // VARIABLE
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

      case 30: // VARIABLE
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

      case 30: // VARIABLE
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

      case 30: // VARIABLE
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

      case 30: // VARIABLE
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

      case 30: // VARIABLE
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

      case 30: // VARIABLE
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
#line 44 "/home/luis/repos/Compilers/CompilersProject/compilers/parser.y"
                            {printf("Hola");}
#line 660 "/home/luis/repos/Compilers/CompilersProject/build/compilers/parser.cpp"
    break;


#line 664 "/home/luis/repos/Compilers/CompilersProject/build/compilers/parser.cpp"

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
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -87;

  const signed char Parser::yytable_ninf_ = -14;

  const signed char
  Parser::yypact_[] =
  {
      -2,   -23,   -87,    45,    -2,   -87,   -87,   -10,   -87,    36,
     -87,   -87,    35,    63,   -87,    24,    47,   -87,    50,    41,
      51,    59,   -87,    48,   -87,    52,    66,   -87,   -87,   -87,
     -87,    74,   -23,   -87,     3,   -87,     6,    57,    58,    20,
     -87,   -87,    -8,   -87,   -87,   -87,   -87,   -87,    53,    65,
     -87,    40,    16,   -87,   -87,   -87,    55,    20,    20,    61,
      20,    20,   -87,    20,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,    20,    20,   -87,   -87,    20,   -87,    62,    64,
     -87,   -87,    67,    70,    68,   -87,   -87,    29,    16,   -87,
      69,    39,   -87,    20,   -87,   -87,    80,   -87,    11,    39,
     -87,   -87
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,    10,     0,     2,     4,     5,     0,     6,     0,
       1,     3,     0,     0,     7,     0,     0,     9,    10,     0,
       0,    12,    15,     0,    16,     0,     0,     8,    19,    11,
      14,    21,     0,    18,     0,    56,     0,     0,     0,     0,
      17,    27,    35,    20,    22,    23,    24,    25,     0,    54,
      34,    38,    46,    50,    55,    31,     0,     0,     0,     0,
      59,     0,    26,     0,    40,    42,    43,    44,    41,    39,
      47,    48,     0,     0,    51,    52,     0,    32,     0,     0,
      53,    61,     0,    58,     0,    33,    54,    37,    45,    49,
       0,     0,    57,     0,    36,    21,    28,    60,     0,     0,
      30,    29
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -87,   -87,   -87,    86,    71,   -14,   -87,   -87,   -87,    72,
     -87,   -87,    -3,   -86,   -87,   -87,   -87,   -87,   -36,    -9,
     -87,   -87,    21,   -87,    22,   -87,    23,   -87,   -87,   -87
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     3,     4,     5,     6,     7,     8,    20,    21,    22,
      29,    31,    34,    43,    44,    45,    46,    47,    48,    49,
      50,    72,    51,    73,    52,    76,    53,    54,    82,    83
  };

  const signed char
  Parser::yytable_[] =
  {
      56,    19,     1,    59,     2,    96,    35,     9,    36,    35,
      37,    38,    19,   101,    35,    60,    36,    61,    37,    38,
      12,    78,    79,    35,    81,    84,    39,    85,    17,    39,
      18,    40,    41,    42,    39,    55,    42,    74,    75,   100,
      41,    42,    35,    39,    36,    10,    37,    38,    70,    71,
      42,    64,    65,    66,    67,    68,    69,    97,    15,    70,
      71,    13,    39,    86,    86,    14,    16,    86,    41,    42,
      17,    24,     2,    23,   -13,    25,    26,    27,    32,    28,
      57,    58,    62,    63,    77,    80,    90,    93,    91,    99,
      11,    92,    98,    87,    94,    88,    95,     0,    30,    89,
       0,     0,    33
  };

  const signed char
  Parser::yycheck_[] =
  {
      36,    15,     4,    39,     6,    91,     3,    30,     5,     3,
       7,     8,    26,    99,     3,    23,     5,    25,     7,     8,
      30,    57,    58,     3,    60,    61,    23,    63,     4,    23,
       6,    28,    29,    30,    23,    29,    30,    21,    22,    28,
      29,    30,     3,    23,     5,     0,     7,     8,    19,    20,
      30,    11,    12,    13,    14,    15,    16,    93,    23,    19,
      20,    25,    23,    72,    73,    29,     3,    76,    29,    30,
       4,    30,     6,    26,    24,    24,    17,    29,     4,    27,
      23,    23,    29,    18,    29,    24,    24,    17,    24,     9,
       4,    24,    95,    72,    26,    73,    27,    -1,    26,    76,
      -1,    -1,    31
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     4,     6,    35,    36,    37,    38,    39,    40,    30,
       0,    37,    30,    25,    29,    23,     3,     4,     6,    39,
      41,    42,    43,    26,    30,    24,    17,    29,    27,    44,
      43,    45,     4,    38,    46,     3,     5,     7,     8,    23,
      28,    29,    30,    47,    48,    49,    50,    51,    52,    53,
      54,    56,    58,    60,    61,    29,    52,    23,    23,    52,
      23,    25,    29,    18,    11,    12,    13,    14,    15,    16,
      19,    20,    55,    57,    21,    22,    59,    29,    52,    52,
      24,    52,    62,    63,    52,    52,    53,    56,    58,    60,
      24,    24,    24,    17,    26,    27,    47,    52,    46,     9,
      28,    47
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    34,    35,    36,    36,    37,    37,    38,    38,    39,
      39,    40,    41,    41,    42,    42,    43,    44,    45,    45,
      46,    46,    47,    47,    47,    47,    48,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    60,    61,    62,    62,
      63,    63
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     2,     0,
       2,     0,     1,     1,     1,     1,     2,     1,     5,     7,
       7,     2,     3,     3,     1,     1,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     4,     1,     0,
       3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "NUMBER", "INTEGER", "RETURN", "VOID",
  "WHILE", "IF", "ELSE", "MAIN", "LESS_EQUAL", "GREATER_EQUAL", "EQUAL",
  "NOT_EQUAL", "GREATER", "LESS", "COMA", "OP_ASSIGN", "OP_ADD", "OP_SUBS",
  "OP_MULT", "OP_DIVISION", "PARENTHESES_LEFT", "PARENTHESES_RIGHT",
  "BRACKET_LEFT", "BRACKET_RIGHT", "BRACES_LEFT", "BRACES_RIGHT",
  "SEMICOLON", "VARIABLE", "PLUS", "REST", "MULT", "$accept", "programa",
  "lista_declaracion", "declaracion", "var_declaracion", "tipo",
  "fun_declaracion", "params", "lista_params", "param", "sent_compuesta",
  "declaracion_local", "lista_sentencias", "sentencia",
  "sentencia_expresion", "sentencia_seleccion", "sentencia_iteracion",
  "sentencia_retorno", "expresion", "var", "expresion_simple", "relop",
  "expresion_aditiva", "addop", "term", "mulop", "factor", "call", "args",
  "lista_arg", YY_NULLPTR
  };


  const unsigned char
  Parser::yyrline_[] =
  {
       0,    44,    44,    47,    48,    52,    53,    56,    57,    60,
      61,    64,    67,    68,    71,    72,    75,    78,    81,    82,
      85,    86,    89,    90,    91,    92,    95,    96,    99,   100,
     103,   106,   107,   110,   111,   114,   115,   118,   119,   122,
     123,   124,   125,   126,   127,   130,   131,   134,   135,   138,
     139,   142,   143,   146,   147,   148,   149,   152,   155,   156,
     159,   160
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
    };
    const int user_token_number_max_ = 288;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 12 "/home/luis/repos/Compilers/CompilersProject/compilers/parser.y"
} } // utec::compilers
#line 1080 "/home/luis/repos/Compilers/CompilersProject/build/compilers/parser.cpp"

#line 164 "/home/luis/repos/Compilers/CompilersProject/compilers/parser.y"


void utec::compilers::Parser::error(const std::string& msg) {
    std::cerr << msg << " " /*<< yylineno*/ <<'\n';
    exit(1);
}

// exp:  exp opsuma term { $$ = $1 + $3; }
//     | exp oprest term { $$ = $1 - $3; }
//     | term  { $$ = $1; }
//     ;

// opsuma: PLUS
//     ;

// oprest: REST
//     ;

// term: term opmult factor  { $$ = $1 * $3; }
//     | factor  { $$ = $1; }
//     ;

// opmult: MULT
//     ;

// factor: PAR_BEGIN exp PAR_END { $$ = $2; }
//     | INTEGER_LITERAL 	{ $$ = $1; }
//     ;
