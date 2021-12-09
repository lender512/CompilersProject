%{
#include "parser.hpp"
#include "FlexScanner.hpp"
#define YY_DECL int utec::compilers::FlexScanner::lex(utec::compilers::Parser::semantic_type *yylval)


int line_number = 1;

%}

%{
    int mylineno = 1;
%}

%option c++ interactive noyywrap noyylineno nodefault

DIGITO [0-9]
LETRA  [a-z]

%%

"/*".+"*/" {}

"entero"  { return Parser::token::INTEGER; }
"retorno"  { return Parser::token::RETURN; }
"sin_tipo"  { return Parser::token::VOID; }
"mientras"  { return Parser::token::WHILE; }
"si"  { return Parser::token::IF; }
"sino"  { return Parser::token::ELSE; }
{LETRA}+  { return Parser::token::VARIABLE; }
{DIGITO}* { return Parser::token::NUMBER; }

"<="  { return Parser::token::LESS_EQUAL; }
">="  { return Parser::token::GREATER_EQUAL; }
"=="  { return Parser::token::EQUAL; }
"!="  { return Parser::token::NOT_EQUAL; }
">"  { return Parser::token::GREATER; }
"<"  { return Parser::token::LESS; }

","  { return Parser::token::COMA; }
";"  { return Parser::token::SEMICOLON; }

"="  { return Parser::token::OP_ASSIGN; }

"+"  { return Parser::token::OP_ADD; }
"-"  { return Parser::token::OP_SUBS; }

"*"  { return Parser::token::OP_MULT; }
"/"  { return Parser::token::OP_DIVISION; }

"("  { return Parser::token::PARENTHESES_LEFT; }
")"  { return Parser::token::PARENTHESES_RIGHT; }
"["  { return Parser::token::BRACKET_LEFT; }
"]"  { return Parser::token::BRACKET_RIGHT; }
"{"  { return Parser::token::BRACES_LEFT; }
"}"  { return Parser::token::BRACES_RIGHT; }

[ \t]*		{}
[\n]		{ mylineno++;	}

.		{ std::cout<<"Error\n"; std::cerr << "SCANNER "; /*yyerror("");*/ exit(1);	}

%%

int yyFlexLexer::yylex() {
    throw std::runtime_error("Invalid call to yyFlexLexer::yylex()");
}
