/*
	Membros do grupo:
	Herbert Alves Batista
	Luiz Gustavo Avelino Mendes
	Thiago Henrique Balbino Dias
*/

#ifndef REGLEXICO_H_INCLUDED
#define REGLEXICO_H_INCLUDED

//-----------------------------
	// BIBLIOTECAS
	//-----------------------------

	#include <stdio.h>
	#include <iostream>
	#include <string>
	using namespace std;

	//-----------------------------
	// DEFINICAO DE CONSTANTES
	//-----------------------------


    //-----------------------------
	// DEFINICAO DE TIPOS
	//-----------------------------

    struct LexRecord{
        byte cod;
        std::string lexema;
        SymbolNode* adressTable;
        std::string type;
        int lineNumber;
        LexRecord* next;
    };

    //-----------------------------
	// INTERFACE CLASSE REGLEXICO
	//-----------------------------

	class RegLexico{
		private:
			LexRecord * firstToken;     //inicio do registro léxico
			LexRecord * nextToken;      //proximo token a ser entregue ao analisador sintatico
			LexRecord * lastToken;      //fim do registro léxico
			int numberTokens;           //quantidade de tokens no registro lexico

		public:
			RegLexico(); //--------------------------------------construtor
			~RegLexico(); //-------------------------------------destrutor
			void exibir(); //------------------------------------teste
			void addToken(SymbolNode* symbol, int lineNumber);//-adiciona um token no registro lexico
			LexRecord * getNextToken();//------------------------retorna o proximo token do registro lexico
			std::string getType(byte cod);//---------------------retorna o tipo de dado para tolen constante			
			LexRecord *getFirstToken();
	};


#endif // REGLEXICO_H_INCLUDED
