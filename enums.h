enum Category { TIPO_ENTERO = 255, 
                RETORNO, 
                TIPO_SIN_TIPO, 
                MIENTRAS, 
                SI, 
                SINO, 
                MAIN, 
                IDENTIFICADOR, 
                NUMERO,
                RELOP,
                SEPARADOR_COM,
                SEPARADOR_PUN,
                MULOP, 
                PARENTESIS_IZQ,
                PARENTESIS_DER, 
                CORCHETE_IZQ,
                CORCHETE_DER,
                LLAVE_IZQ,
                LLAVE_DER,
                ERROR,
                END
                };

struct Token {
    Category category;
    char* lexeme;
};