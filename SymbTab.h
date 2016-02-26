/*
	Membros do grupo:
	Herbert Alves Batista
	Luiz Gustavo Avelino Mendes
	Thiago Henrique Balbino Dias
*/

#ifndef SYMBTAB_H
	#define SYMBTAB_H

	#include <stdio.h>
	#include <iostream>
	#include <string>
	using namespace std;

	class SymbTab{
		private:
			//o tamanho da matriz foi arbitrário
			//necessário discussão do grupo	
			//1-cod do identificador ---- 2-lexema
			string tabSimb[500][2]; //tabela de simbolos

		public:
			SymbTab(); //construtor
			~SymbTab(); //destrutor
			void inicialize();
			void exibir(); //teste
	};

#endif