%{
#include <iostream>
#include <string>
#include <cmath>
#include <FlexLexer.h>
%}

%require "3.5.1"
%language "C++"

%define api.parser.class {Parser}
%define api.namespace {utec::compilers}
%define api.value.type variant
%parse-param {FlexScanner* scanner} {int* result}

%code requires
{
    namespace utec::compilers {
        class FlexScanner;
    } // namespace utec::compilers
}

%code
{
    #include "FlexScanner.hpp"
    #define yylex(x) scanner->lex(x)
}

%start	programa 

%token	<int>	NUMBER
%token  INTEGER RETURN VOID WHILE IF ELSE MAIN LESS_EQUAL 
%token  GREATER_EQUAL EQUAL NOT_EQUAL GREATER LESS COMA 
%token  OP_ASSIGN OP_ADD OP_SUBS OP_MULT OP_DIVISION 
%token  PARENTHESES_LEFT PARENTHESES_RIGHT BRACKET_LEFT BRACKET_RIGHT 
%token  BRACES_LEFT BRACES_RIGHT SEMICOLON
%token  <std::string> VARIABLE

%left	PLUS REST
%left	MULT

%%

programa: lista_declaracion {printf("Hola");}
		;

lista_declaracion: lista_declaracion declaracion
        | declaracion
        ;


declaracion: var_declaracion
        | fun_declaracion
        ;

var_declaracion: INTEGER VARIABLE SEMICOLON
        | INTEGER VARIABLE BRACKET_LEFT NUMBER BRACKET_RIGHT SEMICOLON;


tipo: INTEGER 
        | VOID
        ;

fun_declaracion: tipo VARIABLE PARENTHESES_LEFT params PARENTHESES_RIGHT sent_compuesta 
        ;

params: lista_params
        | VOID
        ;

lista_params: lista_params COMA param 
        | param
        ;

param: tipo VARIABLE
        ;

sent_compuesta: BRACES_LEFT declaracion_local lista_sentencias BRACES_RIGHT
        ;

declaracion_local: declaracion_local var_declaracion 
        | /* empty */
        ;

lista_sentencias: lista_sentencias sentencia
        | /* empty */
        ;

sentencia: sentencia_expresion
        | sentencia_seleccion
        | sentencia_iteracion
        | sentencia_retorno
        ;

sentencia_expresion: expresion SEMICOLON
        | SEMICOLON
        ;

sentencia_seleccion: IF PARENTHESES_LEFT expresion PARENTHESES_RIGHT sentencia
        | IF PARENTHESES_LEFT expresion PARENTHESES_RIGHT sentencia ELSE sentencia
        ;

sentencia_iteracion: WHILE PARENTHESES_LEFT expresion PARENTHESES_RIGHT BRACES_LEFT lista_sentencias BRACES_RIGHT
        ;

sentencia_retorno: RETURN SEMICOLON
        | RETURN expresion SEMICOLON
        ;

expresion: var OP_ASSIGN expresion
        | expresion_simple
        ;
        
var: VARIABLE
        | VARIABLE BRACKET_LEFT expresion BRACKET_RIGHT
        ;

expresion_simple: expresion_aditiva relop expresion_aditiva
        | expresion_aditiva
        ;

relop: LESS 
        | LESS_EQUAL
        | GREATER
        | GREATER_EQUAL
        | EQUAL
        | NOT_EQUAL
        ;

expresion_aditiva: expresion_aditiva addop term
        | term
        ;

addop: OP_ADD
        | OP_SUBS
        ;
    
term: term mulop factor
        | factor
        ;
        
mulop: OP_MULT 
        | OP_DIVISION
        ;

factor: PARENTHESES_LEFT expresion PARENTHESES_RIGHT
        | var
        | call
        | NUMBER
        ;

call: VARIABLE PARENTHESES_LEFT args PARENTHESES_RIGHT
        ;

args: lista_arg 
        | /* empty */
        ;

lista_arg: lista_arg COMA expresion
        | expresion
        ;


%%

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