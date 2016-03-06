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

			LexAnalyzer (); //construtor
			~LexAnalyzer (); //destrutor
			void testeLex ();
			void lerArq (const char *arq);
			void proxToken ();	
			int getEstado ();
			void setEstado (int est);
			bool isIgual (char ch);
			bool isAParent (char ch);
			bool isFParent (char ch);
			bool isMaior (char ch);
			bool isMenor (char ch);
			bool isVirgula (char ch);
			bool isMais (char ch);
			bool isMenos (char ch);
			bool isMult (char ch);
			bool isBarra (char ch);
			bool isACha (char ch);
			bool isFCha (char ch);
			bool isAAspas (char ch);
			bool isFAspas (char ch);
			bool isNumero (char ch);
			bool isSemicolon (char ch);
			bool isLetraMi (char ch);
			bool isLetraMa (char ch);
			bool isSublinhado (char ch);
			bool isDoisPonto (char ch);
			bool isAColc (char ch);
			bool isFColc (char ch);
			bool isApost (char ch);
			bool isExclam (char ch);
			bool isQuestion (char ch);
	};//end class

#endif