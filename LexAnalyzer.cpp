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
	//tabelaSimbolo.exibir(); //funcionando
	//char ch = 'A';
	//int asc = (int)ch;
	//cout << "\n\n asc = " << asc << endl;
}


/*
	metodo que abre e ler arquivo
	*param arq: nome do arquivo que sera lido	
 */
void LexAnalyzer::lerArq(const char * arq){
	ifstream fin (arq); //abre arquivo para leitura
	char ch; //char que sera lido do arquivo

	//while (fin.get(ch)) //le um char do arquivo
	//	cout << ch;
	if (isAlfab('*'))
		cout << "\n\nesta no alfabeto\n\n";
	else
		cout << "\n\nNAO\n\n";

	fin.close();
}//end abrirFonte



void LexAnalyzer::proxToken (){
	cout << "\nentrou aki token\n";
}//end proxToken


/*
	funcao que verifica se um char pertence ao alfabeto
	da linguagem L
	*param ch: caracter a ser lido
	*return: true ou false
 */
bool LexAnalyzer::isAlfab(char letra){	
	bool resp = false;

	if ( ((int)letra >= 65) && ((int)letra <= 90) ) //estado q1
		resp = true;
	else if ( ((int)letra >= 97) && ((int)letra <= 122) ) //estado q2
			resp = true;
	else {

		switch (letra){
			case '_':	//estado q3
				resp = true;
				break;
			case '.':	//estado q4
				resp = true;
				break;
			case ',':	//estado q5
				resp = true;
				break;
			case ';':	//estado q6
				resp = true;
				break;
			case ':':	//estado q7
				resp = true;
				break;
			case '(':	//estado q8
				resp = true;
				break;
			case ')':	//estado q9
				resp = true;
				break;
			case '[':	//estado q10
				resp = true;
				break;
			case ']':	//estado q11
				resp = true;
				break;
			case '{':	//estado q12
				resp = true;
				break;
			case '}':	//estado q13
				resp = true;
				break;
			case '+':	//estado q14
				resp = true;
				break;
			case '-':	//estado q15
				resp = true;
				break;
			case '\"':	//estdao q16 e q17
				resp = true;
				break;
			case '\'':	//estado q18
				resp = true;
				break;
			case '/':	//estado q19
				resp = true;
				break;
			case '!':	//estado q20
				resp = true;
				break;
			case '?':	//estado q21
				resp = true;
				break;
			case '>':	//estado q22
				resp = true;
				break;
			case '<':	//estado q23
				resp = true;
				break;
			case '=':	//estado q24
				resp = true;
				break;
			case '*':	//estado q25
				resp = true;
				break;
		}//end switch

	}//end if


	return resp;
}//end isAlfab