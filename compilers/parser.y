%{
#include <iostream>
#include <string>
#include <cmath>
#include <FlexLexer.h>
#include "symbolTable.hpp"

using namespace std;

extern int mylineno; 

%}

%require "3.5.1"
%language "C++"

%define api.parser.class {Parser}
%define api.namespace {utec::compilers}
%define api.value.type variant
%define parse.error verbose
%error-verbose
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

programa: lista_declaracion {
    instance->printNiceType();
    }
;

lista_declaracion: lista_declaracion declaracion
        | declaracion
        ;


declaracion: INTEGER VARIABLE declaracion_fact {
        switch(currentVariable) {
                case variableType::VARIABLE:
                        instance->addVariable($2, 1);
                        break;
                case variableType::ARRAY:
                        instance->addVariableArray($2, 1, arraySize);
                        break;
                default:
                        cout << "Error: variable type not allowed" << endl;
                        exit(1);
                        break;
        }
}
        | VOID VARIABLE PARENTHESES_LEFT params PARENTHESES_RIGHT sent_compuesta
        | INTEGER VARIABLE PARENTHESES_LEFT params PARENTHESES_RIGHT SEMICOLON {int type = 0;
            instance->addFunction($2, type, currentParams);
            currentParams.clear();
        }
        | VOID VARIABLE PARENTHESES_LEFT params PARENTHESES_RIGHT SEMICOLON {int type = 1;
            instance->addFunction($2, type, currentParams);
            currentParams.clear();
        }

        ;
        
declaracion_fact: var_declaracion_fact
        
        | PARENTHESES_LEFT params PARENTHESES_RIGHT  sent_compuesta 
        /* | error {yyerrok; } */
        ;

var_declaracion_fact: SEMICOLON {currentVariable = variableType::VARIABLE;}
        | BRACKET_LEFT NUMBER BRACKET_RIGHT SEMICOLON {currentVariable = variableType::ARRAY; arraySize = $2;}
        | error SEMICOLON {yyerrok; yyclearin;}
        ;

/* fun_declaracion: tipo VARIABLE PARENTHESES_LEFT params PARENTHESES_RIGHT sent_compuesta 
        ; */

tipo:   INTEGER   {currentParamType = 1;}
        | VOID 
        ;
        

params: lista_params
        | VOID 
        ;

lista_params: lista_params COMA param 
        | param
        ;

param: tipo VARIABLE {currentParamName = $2; currentParams.push_back(std::make_tuple(currentParamName, currentParamType));}
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
        | error SEMICOLON {yyerrok; yyclearin;}
        ;

sentencia_seleccion: IF PARENTHESES_LEFT expresion PARENTHESES_RIGHT BRACES_LEFT lista_sentencias BRACES_RIGHT
        | IF PARENTHESES_LEFT expresion PARENTHESES_RIGHT BRACES_LEFT lista_sentencias BRACES_RIGHT ELSE BRACES_LEFT lista_sentencias BRACES_RIGHT
        | error BRACES_RIGHT {yyerrok; yyclearin;}
        ;

sentencia_iteracion: WHILE PARENTHESES_LEFT expresion PARENTHESES_RIGHT BRACES_LEFT lista_sentencias BRACES_RIGHT
        ;

sentencia_retorno: RETURN SEMICOLON
        | RETURN expresion SEMICOLON
        | error SEMICOLON {yyerrok; yyclearin;}
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
    std::cout << msg << " in line "<< mylineno <<  '\n';
    
    /* exit(1); */
}
