/*
	Membros do grupo:
	Herbert Alves Batista
	Luiz Gustavo Avelino Mendes
	Thiago Henrique Balbino Dias
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "SymbTab.h"

class LexAnalyzer{
	private:
		void teste1(){
			SymbTab tabela;

			tabela.inicialize();
			tabela.exibir();
		}//end teste1



	public:
		LexAnalyzer(){} //construtor
		~LexAnalyzer(){} //destrutor

		void controle (){
			teste1();
		}//end controle

};

int main(){
	LexAnalyzer lex;

	lex.controle();
	
	return 0;
}