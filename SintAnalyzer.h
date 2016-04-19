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

	typedef char byte;

	class SintAnalyzer{
		private:
			LexRecord *currentToken;
			RegLexico registroLexico;

		public:			
			SintAnalyzer (); //construtor
			~SintAnalyzer (); //destrutor
			void teste();
			void principal();
			void S();
	};

#endif