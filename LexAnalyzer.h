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

			LexAnalyzer(); //construtor
			~LexAnalyzer(); //destrutor
			void testeLex();
			void abrirFonte(string arq);
			void proxToken();
	};//end class

#endif