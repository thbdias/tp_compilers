/*
	Membros do grupo:
	Herbert Alves Batista
	Luiz Gustavo Avelino Mendes
	Thiago Henrique Balbino Dias
*/


#ifndef SINTANALYZER_H
	#define SINTANALYZER_H

	#include <stdio.h>
	#include <string>
	#include <iostream>
	#include "SymbTab.h"
	#include "RegLexico.h"
	#include "LexAnalyzer.h"

	typedef char byte;

	class SintAnalyzer{
		private:
			LexRecord *currentToken;
			RegLexico registroLexico;
			LexAnalyzer lex;
			bool notNull;

		public:
			SintAnalyzer (); //construtor
			~SintAnalyzer (); //destrutor
			void teste();
			void principal(const char *arq);
			void S();
			void DECL();
			void TIPO();
			void VALOR();
			void BLOCO();
			void COMANDO();
			void COMANDO_ATRIB();
			void COMANDO_REPET();
			void COMANDO_TESTE();
			void COMANDO_NULO();
			void COMANDO_LEITURA();
			void COMANDO_ESCRITA();
			void EXPRESSAO();
			void OPERADOR_P5();
			void EXP_4();
			void OPERADOR_P4();
			void EXP_3();
			void OPERADOR_P3();
			void EXP_2();
			void EXP_1();
			void CONST();
			void match(char);
	};

#endif
