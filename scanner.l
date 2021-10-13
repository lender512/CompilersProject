%{
#include <stdio.h>
/* \. always dot */
/* cadena mas larga */

%}


DIGITO [0-9]
LETRA [a-z]
%%

"/*".+"/*"

"entero" return printf("TIPO_ENTERO\n");
"retorno" return printf("RETORNO\n");
"sin_tipo" return printf("TIPO_SIN_TIPO\n");
"mientras" return printf("MIENTRAS\n");
"si" return printf("SI\n");
"sino" return printf("SINO\n");
"main" return printf("MAIN\n");

{LETRA}+  printf("IDENTIFICADOR\n");
[+-]?{DIGITO}+\.{DIGITO}* printf("Digito\n");

"<=" return printf("RELOP\n");
">=" return printf("RELOP\n");
"==" return printf("RELOP\n");
"!=" return printf("RELOP\n");
">" return printf("RELOP\n");
"<" return printf("RELOP\n");

";" return printf("SEPARADOR\n");

"=" return printf("ASSIGNACION\n");

"+" return printf("ADDOP\n");
"-" return printf("ADDOP\n");

"*" return printf("MULOP\n");
"/" return printf("MULOP\n");

"(" return printf("PARENTESIS_IZQ\n");
")" return printf("PARENTESIS_DER\n");
"[" return printf("CORCHETE_IZQ\n");
"]" return printf("CORCHETE_DER\n");
"{" return printf("LLAVE_IZQ\n");
"}" return printf("LLAVE_DER\n");

.|\n
%%