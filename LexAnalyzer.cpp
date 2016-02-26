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
#include <fstream> //tratar arquivos
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


void LexAnalyzer::abrirFonte(string arq){
	cout << "\nentrou aki fonte\n"; //teste
}//end abrirFonte



void LexAnalyzer::proxToken (){
	cout << "\nentrou aki token\n";
}//end proxToken