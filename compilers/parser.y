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
%define parse.error verbose
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
%token  INTEGER RETURN VOID WHILE IF ELSE  LESS_EQUAL 
%token  GREATER_EQUAL EQUAL NOT_EQUAL GREATER LESS COMA 
%token  OP_ASSIGN OP_ADD OP_SUBS OP_MULT OP_DIVISION 
%token  PARENTHESES_LEFT PARENTHESES_RIGHT BRACKET_LEFT BRACKET_RIGHT 
%token  BRACES_LEFT BRACES_RIGHT SEMICOLON
%token  <std::string> VARIABLE

%left	PLUS REST
%left	MULT

%left  PARENTHESES_LEFT
%left  SEMICOLON

%%

programa: lista_declaracion 
	;

lista_declaracion: lista_declaracion declaracion
        | declaracion
        ;


declaracion: INTEGER VARIABLE declaracion_fact 
        | VOID VARIABLE PARENTHESES_LEFT params PARENTHESES_RIGHT sent_compuesta
        ;
        
declaracion_fact: var_declaracion_fact
        | PARENTHESES_LEFT params PARENTHESES_RIGHT  sent_compuesta
        ;

var_declaracion_fact: SEMICOLON
        | BRACKET_LEFT NUMBER BRACKET_RIGHT SEMICOLON
        ;

/* fun_declaracion: tipo VARIABLE PARENTHESES_LEFT params PARENTHESES_RIGHT sent_compuesta 
        ; */

tipo:   INTEGER {printf("Entero de  tipo");}
        | VOID {printf("Void de tipo");}
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

declaracion_local: declaracion_local INTEGER VARIABLE var_declaracion_fact 
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

sentencia_seleccion: IF PARENTHESES_LEFT expresion PARENTHESES_RIGHT BRACES_LEFT sentencia BRACES_RIGHT
        | IF PARENTHESES_LEFT expresion PARENTHESES_RIGHT BRACES_LEFT sentencia BRACES_RIGHT ELSE BRACES_LEFT sentencia BRACES_RIGHT
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