/*
	Membros do grupo:
	Herbert Alves Batista
	Luiz Gustavo Avelino Mendes
	Thiago Henrique Balbino Dias
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "LexAnalyzer.h"
#include "SymbTab.h"
#include <fstream.h> //tratar arquivos
using namespace std;

LexAnalyzer::LexAnalyzer(){		
	tabelaSimbolo.inicialize();
}//construtor

LexAnalyzer::~LexAnalyzer(){	
}//destrutor

//teste
void LexAnalyzer::testeLex(){
	cout << "\n\nteste lexico ok.\n\n";
	tabelaSimbolo.exibir();
}


void LexAnalyzer::lerArq(const char * arq){
	cout << "\nentrou aki fonte\n"; //teste	

	ifstream fin (arq); //abre arquivo para leitura
	char ch; //char que sera lido do arquivo

		while (fin.get(ch)) //le um char do arquivo
			cout << ch;

	fin.close();
}//end abrirFonte



void LexAnalyzer::proxToken (){
	cout << "\nentrou aki token\n";
}//end proxToken