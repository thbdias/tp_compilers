/*
	Membros do grupo:
	Herbert Alves Batista
	Luiz Gustavo Avelino Mendes
	Thiago Henrique Balbino Dias
*/

#ifndef SYMBTAB_H
	#define SYMBTAB_H

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

	#define SIZE 99     // tamanho da tabela de simbolos
                        // o tamanho da tabela foi arbitrário
                        // necessário discussão do grupo

    //-----------------------------
	// DEFINICAO DE TIPOS
	//-----------------------------

    typedef char byte;

    struct SymbolNode{
        byte cod;            //codigo da classe do token
        std::string lexema;
        SymbolNode * next;   //proximo token
    };

    //-----------------------------
	// INTERFACE CLASSE SYMBTAB
	//-----------------------------

	class SymbTab{
		private:
			SymbolNode * tabSimb;       //tabela de simbolos

		public:
			SymbTab(); //----------------------------------------construtor
			~SymbTab(); //---------------------------------------destrutor
			void inicialize(); //--------------------------------inserir palavras reservadas
			void exibir(); //------------------------------------teste
			//void input(byte cod, std::string lexema);//----------metodo de entrada para o analisador lexico
			SymbolNode *insert(byte cod, std::string lexema);//--inserir simbolo
			int spreading(std::string lexema);//-----------------funcao espalhamento
			SymbolNode * search(std::string lexema);//-----------função de busca
	};

#endif

