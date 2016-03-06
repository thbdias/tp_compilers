/*
	Membros do grupo:
	Herbert Alves Batista
	Luiz Gustavo Avelino Mendes
	Thiago Henrique Balbino Dias
*/

#ifndef LEXANALYZER_H
	#define LEXANALYZER_H

	#include <stdio.h>
	#include <string>
	#include <iostream>
	#include "SymbTab.h"	

	class LexAnalyzer{	
		public:
			SymbTab tabelaSimbolo;
			int ESTADO;

			LexAnalyzer(); //construtor
			~LexAnalyzer(); //destrutor
			void testeLex();
			void lerArq(const char *arq);
			void proxToken();	
			int getEstado();
			void setEstado(int est);
	};//end class

#endif