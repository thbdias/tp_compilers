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

/*
	construtor
 */
LexAnalyzer::LexAnalyzer(){		
	tabelaSimbolo.inicialize();
	ESTADO = 0;	
}//construtor



/*
	destrutor
 */
LexAnalyzer::~LexAnalyzer(){	
}//destrutor



//teste
void LexAnalyzer::testeLex(){
	//cout << "\n\nteste lexico ok.";	
	//tabelaSimbolo.exibir(); //funcionando
	//char ch = '\'';
	//if (isApost(ch))
	//	cout << "\n\nE igual!\n"<< (int)ch << "\n";
	//else
	//	cout << "\n\nNao e igual\n"<< (int)ch << "\n";
	
}//end teste


//ESTE METODO ESTA TESTANDO AS OUTRAS FUNCIONALIDADES DO SISTEMA--------------------
/*
	metodo que abre e ler arquivo
	@param arq: nome do arquivo que sera lido	
 */
void LexAnalyzer::lerArq(const char * arq){
	ifstream fin (arq); //abre arquivo para leitura
	string lexema = "";
	char ch; //char que sera lido do arquivo
	char classToken; //classe do token
	int flag; //controle --- ler ultimo lexema


	while (fin.get(ch)){ //le um char do arquivo

		//branco - quebra linha - tabulacao
		if ((ch != ' ') && (ch != '\n') && (ch != '\t')){
			if (isAlfbt(ch))
				lexema = lexema + ch;
				flag = 1;
		}
		else{
				if (lexema != ""){					
					classToken = obterClassToken(lexema);
					tabelaSimbolo.insert(classToken, lexema);
					flag = 0;
				}//end if
				lexema = "";
			}//end if	
		
	}//end while


	if (flag == 1){		
		classToken = obterClassToken(lexema);
		tabelaSimbolo.insert(classToken, lexema);
	}//end if

	fin.close();

	tabelaSimbolo.exibir();
}//end lerArq



/*
	metodo que verifica se um char pertence ao alfabeto
 */
bool LexAnalyzer::isAlfbt (char ch){
	bool resp = false;

	if (isDigito(ch)) //precisar alterar. q6, q8, q10, sao numeros
		resp = true;
	else if (isLetraMi(ch))
			resp = true;
	else if (isLetraMa(ch))
			resp = true;
	else
		switch (ch){
			case '{':
				ESTADO = 1;
				resp = true;
				break;
			case '}':
				ESTADO = 15;
				resp = true;
				break;
			case '(':
				ESTADO = 2;
				resp = true;
				break;
			case ')':
				ESTADO = 16;
				resp = true;
				break;
			case ';':
				ESTADO = 26;
				resp = true;
				break;
			case ',':
				ESTADO = 23;
				resp = true;
				break;
			case '+':
				ESTADO = 22;
				resp = true;
				break;
			case '*':
				ESTADO = 22;
				resp = true;
				break;
			case '-':
				ESTADO = 27;
				resp = true;
				break;
			case '_':
				resp = true;
				break;
			case ':':
				resp = true;
				break;
			case '[':
				resp = true;
				break;
			case ']':
				resp = true;
				break;
			case '\'':		//apostrofo
				resp = true;
				break;
			case '"':
				resp = true;
				break;
			case '!':
				resp = true;
				break;
			case '?':
				resp = true;
				break;	
			case '>':
				resp = true;
				break;
			case '<':
				resp = true;
				break;
			case '=':
				resp = true;
				break;
			case '/':
				resp = true;
				break;	
			case '.':
				resp = true;
				break;
		}//end switch

	return resp;
}//end isAlfbt



//FALTA EDITAR
void LexAnalyzer::proxToken (){
	cout << "\nentrou aki token\n";
}//end proxToken



/*
	metodo que atualiza o ESTADO
	@param est: novo estado
 */
void LexAnalyzer::setEstado (int est){	
}//end setEstado



/*
	metodo que retorna o estado atual
	@return: estado atual
 */
int LexAnalyzer::getEstado (){
	return ESTADO;
}//end getEstado



/*
	metodo que verifica se char e' numero (0-9)
	@return: true or false
 */
bool LexAnalyzer::isDigito (char ch){
	return (((int)ch >= 48) && ((int)ch <= 57));
}//end isDigito



/*
	metodo que verifica se char e' letra minuscula (a-z)
	@return: true or false
 */
bool LexAnalyzer::isLetraMi (char ch){
	return (((int)ch >= 97) && ((int)ch <= 122));
}//end isLetraMi



/*
	metodo que verifica se char e' letra maiuscula (A-Z)
	@return: true or false
 */
bool LexAnalyzer::isLetraMa (char ch){
	return (((int)ch >= 65) && ((int)ch <= 90));
}//end isLetraMa



/*
	funcao que verifica a qual classe de token o lexema pertence
 */
char LexAnalyzer::obterClassToken (string lexema){
	char resp = '0';

	if (lexema == "if")
		return resp = '3';
	else if (lexema == "else")
			return resp = '4';	
	else if (lexema == "while")
			return resp = '5';
	else if (lexema == "readln")
			return resp = '6';	
	else if ((lexema == "write") || (lexema == "writeln"))
			return resp = '7';	
	else if (lexema == "(")
			return resp = '8';	
	else if (lexema == ")")
			return resp = '9';
	else if ((lexema == ">") || (lexema == "<") || (lexema == ">=") || (lexema == "<=") || (lexema == "=="))
			return resp = 'A';
	else if (lexema == ",")
			return resp = 'B';
	else if ((lexema == "+") || (lexema == "-") || (lexema == "*")) //tratar barra
			return resp = 'C';
	else if (lexema == "{")
			return resp = 'D';
	else if (lexema == "}")
			return resp = 'E'; 
	//else if (lexema == ) //expressão
	else if (lexema == "const")
			return resp = 'G';
	//else if (lexema == ) //id
	//else if (lexema == ) //id-byte
	//else if (lexema == ) //atribuição =
	//else if (lexema == ) //tipos de dados
	//else if (lexema == ) //operador logico (and or)
	else if (lexema == ";")
			return resp = 'K';

	return resp;
}//end obterClassToken