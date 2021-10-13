%{
#include <stdio.h>
/* \. always dot */
/* cadena mas larga */

%}


DIGITO [0-9]
LETRA [a-z]
%%

"/*".+"/*"

"entero"  printf("TIPO_ENTERO\t");
"retorno"  printf("RETORNO\t");
"sin_tipo"  printf("TIPO_SIN_TIPO\t");
"mientras"  printf("MIENTRAS\t");
"si"  printf("SI\t");
"sino"  printf("SINO\t");
"main"  printf("MAIN\t");
{LETRA}+  printf("IDENTIFICADOR\t");
{DIGITO}* printf("NUMERO\t");

"<="  printf("RELOP\t");
">="  printf("RELOP\t");
"=="  printf("RELOP\t");
"!="  printf("RELOP\t");
">"  printf("RELOP\t");
"<"  printf("RELOP\t");

","  printf("SEPARADOR_COM\t");
";"  printf("SEPARADOR_PUN\t");

"="  printf("ASSIGNACION\t");

"+"  printf("ADDOP\t");
"-"  printf("ADDOP\t");

"*"  printf("MULOP\t");
"/"  printf("MULOP\t");

"("  printf("PARENTESIS_IZQ\t");
")"  printf("PARENTESIS_DER\t");
"["  printf("CORCHETE_IZQ\t");
"]"  printf("CORCHETE_DER\t");
"{"  printf("LLAVE_IZQ\t");
"}"  printf("LLAVE_DER\t");

.|\t
%%