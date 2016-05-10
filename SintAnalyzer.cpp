/*
	Membros do grupo:
	Herbert Alves Batista
	Luiz Gustavo Avelino Mendes
	Thiago Henrique Balbino Dias
*/

//----------------------------------
// BIBLIOTECAS
//----------------------------------


#include <stdio.h>
#include <iostream>
#include <string>
#include "SintAnalyzer.h"
#include "SymbTab.h"
#include "RegLexico.h"
#include "LexAnalyzer.h"
using namespace std;

/**
*   Construtor
*/
SintAnalyzer::SintAnalyzer(){
registroLexico;

}// end construtor()


/**
*   Destrutor
*/
SintAnalyzer::~SintAnalyzer(){
}//end destrutor()


void SintAnalyzer::teste(){
	cout << "\n\nteste ok\n\n";
}//end teste

/**
 *  Procedimento S
 */
void SintAnalyzer::S(){
    if(currentToken != NULL){
            notNull = true;
        if(currentToken->cod == 'G' || currentToken->cod == '2'){
            while(notNull){
                if(currentToken->cod == 'G' || currentToken->cod == '2')
                    DECL();
                else
                    notNull = false;
                }
            }

        BLOCO();
    }

}// end S

/**
 *  Procedimento DECL
 */
void SintAnalyzer::DECL(){
    if(currentToken != NULL){
            notNull = true;
        if(currentToken->cod == 'G'){
            match('G');
            match('H');
            match('1');
            VALOR();
            match('K');
        } else {
            TIPO();
            match('H');
            if(notNull){
                if(currentToken->cod == '1'){
                    match('1');
                    VALOR();
                }
            }
            while(notNull){
                if(currentToken->cod == 'B'){
                    match('B');
                    match('H');
                    if(notNull){
                        if(currentToken->cod == '1'){
                            match('1');
                            VALOR();
                        }
                    }
                } else notNull = false;
            }
            match('K');
        }
    }
}

/**
 *  Procedimento TIPO
 */
void SintAnalyzer::TIPO(){
	match('2');
}

/**
 *  Procedimento VALOR
 */
void SintAnalyzer::VALOR(){
    if(currentToken != NULL){
        notNull = true;
        if(currentToken->lexema.compare("-") == 0){
            match('C');
        }
        if(notNull){
            if(currentToken->cod == 'F'){
                match('F');
            } else if(notNull){
                if(currentToken->cod == 'L'){
                    match('L');
                } else if(notNull){
                    if(currentToken->cod == 'M' || currentToken->cod == 'I'){
                        match('M');
                    } else match('N');
                }
            }
        }
    }
}

/**
 *  Procedimento BLOCO
 */
void SintAnalyzer::BLOCO(){
	match('D');
	if(currentToken != NULL){
            notNull = true;
        if(currentToken->cod == 'H' || currentToken->cod == 'I' || currentToken->cod == '5' || currentToken->cod == '3' ||
            currentToken->cod == 'K' || currentToken->cod == '6' || currentToken->cod == '7'){

            while(notNull){
                if(currentToken->cod == 'H' || currentToken->cod == 'I' || currentToken->cod == '5' || currentToken->cod == '3' ||
                currentToken->cod == 'K' || currentToken->cod == '6' || currentToken->cod == '7'){
                    COMANDO();
                } else notNull = false;
            }
        }
	}
	match('E');
}

/**
 *  Procedimento COMANDO
 */
void SintAnalyzer::COMANDO(){

	if (currentToken->cod == 'H' || currentToken->cod == 'I') COMANDO_ATRIB();
	else if (currentToken->cod == '5') COMANDO_REPET();
	else if (currentToken->cod == '3') COMANDO_TESTE();
	else if (currentToken->cod == 'K') COMANDO_NULO();
	else if (currentToken->cod == '6') COMANDO_LEITURA();
	else if (currentToken->cod == '7') COMANDO_ESCRITA();
}

/**
 *  Procedimento COMANDO_ATRIB
 */
void SintAnalyzer::COMANDO_ATRIB(){
	match('H');
	match('1');
	EXPRESSAO();
	match('K');
}

/**
 *  Procedimento COMANDO_REPET
 */
void SintAnalyzer::COMANDO_REPET(){
	match('5');
	EXPRESSAO();
    if(currentToken != NULL){
        if (currentToken->cod == 'D')
            BLOCO();
        else
            COMANDO(); //*****
    }
}


/**
 *  Procedimento COMANDO_TESTE
 */
void SintAnalyzer::COMANDO_TESTE(){
	match('3');
	EXPRESSAO();
	match('P');

	if(currentToken != NULL){
        if (currentToken->cod == 'D')
            BLOCO();
        else
            COMANDO(); //*****
    }

    if(currentToken != NULL){
        if (currentToken->cod == '4'){
            match('4');

            if(currentToken != NULL){
                if (currentToken->cod == 'D')
                    BLOCO();
                else
                    COMANDO(); //*****
            }
        }
    }
}


/**
 *  Procedimento COMANDO_NULO
 */
void SintAnalyzer::COMANDO_NULO(){
	match('K');
}


/**
 *  Procedimento COMANDO_LEITURA
 */
void SintAnalyzer::COMANDO_LEITURA(){
	match('6');
	match('B');
	match('H');
	match('K');
}

/**
 *  Procedimento COMANDO_ESCRITA
 */
void SintAnalyzer::COMANDO_ESCRITA(){
	match('7');
	match('B');
	EXPRESSAO();

    if(currentToken != NULL){
            notNull = true;
        if (currentToken->cod == 'B'){
            while(notNull){
                if(currentToken->cod == 'B'){
                    match('B');
                    EXPRESSAO();
                }else notNull = false;
            }
        }
    }
	match('K');
}

/**
 *  Procedimento EXPRESSAO
 */
void SintAnalyzer::EXPRESSAO(){
	EXP_4();

    if(currentToken != NULL){
        notNull = true;
        if (currentToken->cod == 'A'){
            while(notNull){
                if(currentToken->cod == 'A'){
                    OPERADOR_P5();
                    EXP_4();
                } else notNull = false;
            }
        }
    }
}

/**
 *  Procedimento OPERADOR_P5
 */
void SintAnalyzer::OPERADOR_P5(){
	match('A');
}


/**
 *  Procedimento EXP_4
 */
void SintAnalyzer::EXP_4(){
    if(currentToken != NULL){
        if (currentToken->lexema.compare("-") == 0)
            match('C');
    }

	EXP_3();

    if(currentToken != NULL){
        notNull = true;
        if ((currentToken->lexema.compare("-") == 0) || (currentToken->lexema.compare("+") == 0) || (currentToken->lexema.compare("or") == 0)){
            while(notNull){
                if((currentToken->lexema.compare("-") == 0) || (currentToken->lexema.compare("+") == 0) || (currentToken->lexema.compare("or") == 0)){
                    OPERADOR_P4();
                    EXP_3();
                } else notNull = false;
            }
        }
    }
}

/**
 *  Procedimento OPERADOR_P4
 */
void SintAnalyzer::OPERADOR_P4(){
    if(currentToken != NULL){
        if ((currentToken->lexema.compare("-") == 0) || (currentToken->lexema.compare("+") == 0))
            match('C');
        else
            match('J');
    }
}

/**
 * Procedimento EXP_3
 */
void SintAnalyzer::EXP_3(){
	EXP_2();

    if(currentToken != NULL){
        if ((currentToken->lexema.compare("*") == 0) | (currentToken->lexema.compare("/") == 0) | (currentToken->lexema.compare("and") == 0)){
            while(notNull){
                if((currentToken->lexema.compare("*") == 0) | (currentToken->lexema.compare("/") == 0) | (currentToken->lexema.compare("and") == 0)){
                    OPERADOR_P3();
                    EXP_2();
                } else notNull = false;
            }
        }
    }
}


/**
 *  Procedimento OPERADOR_P3
 */
void SintAnalyzer::OPERADOR_P3(){
    if(currentToken != NULL){
        if ((currentToken->lexema.compare("*") == 0) || (currentToken->lexema.compare("/") == 0))
            match('C');
        else
            match('J');
    }
}


/**
 *  Procedimento EXP_2
 */
void SintAnalyzer::EXP_2(){
    if(currentToken != NULL){
        if ((currentToken->lexema.compare("not") == 0))
            match('J');
    }
	EXP_1();
}


/**
 *  Procedimento EXP_1
 */
void SintAnalyzer::EXP_1(){
    if(currentToken != NULL){
        if (currentToken->cod == '8'){
            match('8');
            EXPRESSAO();
            match('9');
        }
        else
            CONST();
    }
}


/**
 *  Procedimento CONST
 */
void SintAnalyzer::CONST(){
    if(currentToken != NULL){
        if (currentToken->cod == 'F')
            match('F');
        else if (currentToken->cod == 'M' || currentToken->cod == 'I')
            match('M');
        else if (currentToken->cod == 'L')
            match('L');
        else if (currentToken->cod == 'N')
            match('N');
        else if (currentToken->cod == 'H' || currentToken->cod == 'I')
            match('H');
    }
}

/**
 *  Metodo casaToken
 */
void SintAnalyzer::match(char tipo){

	if(currentToken == NULL){
      	cout << registroLexico.getLastToken()->lineNumber << ":fim de arquivo nao esperado";
        exit(0);
	}
	else {
            cout << "token: " << tipo << " - " << currentToken->cod << "\n";
		if(currentToken->cod == 'I'){
			if(tipo == 'H' || tipo == 'M')
				currentToken->cod = tipo;
		}
		if(currentToken->cod == tipo){
			currentToken = registroLexico.getNextToken();
			if(currentToken == NULL)
                notNull = false;
                else
                    notNull = true;
		} else {
			cout << currentToken->lineNumber << ":token nao esperado [" << currentToken->lexema << "].";
            exit(0);
		}
	}

}

/**
 * metodo que inicia a analise da gramatica
 */
void SintAnalyzer::principal(const char *arq){
	lex.lerArq(arq);

	registroLexico = lex.getRegistroLexico();
	registroLexico.resetNext();
	currentToken = registroLexico.getNextToken();
	notNull = true;
	S();
	//cout << currentToken->cod;
	if(currentToken != NULL)
        cout << currentToken->lineNumber << ":token nao esperado [" << currentToken->lexema << "].";

	//cout << "\n\nteste: " << currentToken->cod << "\n\n";
	//cout << "\n\nteste: " << currentToken->lexema << "\n\n";

	//cout << "\n\nteste: " << currentToken->next->cod << "\n\n";

}//end principal



