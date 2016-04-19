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
#include "SymbTab.h"
#include "RegLexico.h"
using namespace std;

//----------------------------------
// IMPLEMENTACAO CLASSE REGLEXICO
//----------------------------------

/**
*   Construtor
*/
RegLexico::RegLexico(){
    firstToken = nextToken = lastToken = NULL;
    numberTokens = 0;
}// end construtor()

/**
*   Destrutor
*/
RegLexico::~RegLexico(){
}//end destrutor()

/**
 *  Metodo que adiciona um token no registro léxico
 */
 void RegLexico::addToken(SymbolNode * symbol, int lineNumber){

     if(symbol == NULL){
            return;
     }

     LexRecord * rec = new LexRecord;
     rec->cod = symbol->cod;
     rec->lexema = symbol->lexema;
     rec->type = getType(rec->cod);
     rec->adressTable = symbol;
     rec->lineNumber = lineNumber;
     rec->next = NULL;

    if(numberTokens == 0){
        firstToken = rec;
        lastToken = rec;
        nextToken = firstToken;
        numberTokens++;
    } else {
        lastToken->next = rec;
        lastToken = rec;
        numberTokens++;
    }
    rec = NULL;
 }

/**
  * Metodo que calcula o tipo para tokens da classe expressao
  */
  std::string RegLexico::getType(byte classe){
      switch(classe){
      case 'F':
        return "Decimal";

      case 'L':
        return "Boolean";

      case 'M':
        return "Hexadecimal";

      case 'N':
        return "String";

      default:
        return "Not a constant";
      }
  }

  /**
   *    Metodo que retorna o proximo token do registro lexico e move o ponteiro para o seguinte
   */
   LexRecord * RegLexico::getNextToken(){
       LexRecord * token = nextToken;

        if(nextToken != NULL){
            nextToken = nextToken->next;
        }
        return token;
   }

   /**
    *   Funcao para testar
    */
void RegLexico::exibir (){// Alterado para verificar se o registro lexico esta funcionando

    cout << "\nRegistro Lexico";
    cout << "\nquant\tidToken\tlexema\n\n";

    int quantidade = 0;

    while(nextToken != NULL){
        cout << ++quantidade << "\t" << nextToken->cod << "\t" << nextToken->lexema << "\n";
        getNextToken();
    } // end while
}// end exibir()



/**
 * metodo que retorna o primeiro token do registro lexico
 */
LexRecord *RegLexico::getFirstToken(){
  return firstToken;
}//end getFirstToken