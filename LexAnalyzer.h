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
	#include "RegLexico.h"

	class LexAnalyzer{
		private:
			SymbTab tabelaSimbolo;
			RegLexico registroLexico;
			int ESTADO;
			bool parado;
			string lexema;

        public:
			LexAnalyzer (); //construtor
			~LexAnalyzer (); //destrutor
			void testeLex ();
			void lerArq (const char *arq);
			void transition(char c);
			void resetMachine();
			bool isDigito (char ch);
			bool isLetraMi (char ch);
			bool isLetraMa (char ch);
			char obterClassToken (int estado);

	};//end class

#endif
