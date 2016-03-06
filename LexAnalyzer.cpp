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
	cout << "\n\nteste lexico ok.\n\n";
	tabelaSimbolo.exibir();
	//tabelaSimbolo.exibir(); //funcionando
	//char ch = 'A';
	//int asc = (int)ch;
	//cout << "\n\n asc = " << asc << endl;
}



/*
	metodo que abre e ler arquivo
	@param arq: nome do arquivo que sera lido	
 */
void LexAnalyzer::lerArq(const char * arq){
	ifstream fin (arq); //abre arquivo para leitura
	char ch; //char que sera lido do arquivo

	//while (fin.get(ch)) //le um char do arquivo
	//	cout << ch;
	//if (isAlfab('*'))
		cout << "\n\nesta no alfabeto\n\n";
	//else
		cout << "\n\nNAO\n\n";

	fin.close();
}//end abrirFonte



//falta editar
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
	metodo que verifica se char e' sinal igual (=)
	@return: true or false
 */
bool LexAnalyzer::isIgual (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' abre parenteses '('
	@return: true or false
 */
bool LexAnalyzer::isAParent (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' fecha parenteses ')'
	@return: true or false
 */
bool LexAnalyzer::isFParent (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' sinal de maior (>)
	@return: true or false
 */
bool LexAnalyzer::isMaior (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' sinal de menor (<)
	@return: true or false
 */
bool LexAnalyzer::isMenor (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' virgula (,)
	@return: true or false
 */
bool LexAnalyzer::isVirgula (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' sinal de mais (+)
	@return: true or false
 */
bool LexAnalyzer::isMais (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' sinal de menos (-)
	@return: true or false
 */
bool LexAnalyzer::isMenos (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' sinal de multiplicacao (*)
	@return: true or false
 */
bool LexAnalyzer::isMult (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' sinal de divisao (/)
	@return: true or false
 */
bool LexAnalyzer::isBarra (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' abre chaves ({)
	@return: true or false
 */
bool LexAnalyzer::isACha (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' fecha chaves (})
	@return: true or false
 */
bool LexAnalyzer::isFCha (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' abre aspas (")
	@return: true or false
 */
bool LexAnalyzer::isAAspas (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' fecha aspas (")
	@return: true or false
 */
bool LexAnalyzer::isFAspas (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' numero (0-9)
	@return: true or false
 */
bool LexAnalyzer::isNumero (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' ponto e virgula (;)
	@return: true or false
 */
bool LexAnalyzer::isSemicolon (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' letra minuscula (a-z)
	@return: true or false
 */
bool LexAnalyzer::isLetraMi (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' letra maiuscula (A-Z)
	@return: true or false
 */
bool LexAnalyzer::isLetraMa (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' sublinhado (_)
	@return: true or false
 */
bool LexAnalyzer::isSublinhado (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' dois pontos (:)
	@return: true or false
 */
bool LexAnalyzer::isDoisPonto (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' abre colchete ([)
	@return: true or false
 */
bool LexAnalyzer::isAColc (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' fecha colchete (])
	@return: true or false
 */
bool LexAnalyzer::isFColc (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' apostrofo (')
	@return: true or false
 */
bool LexAnalyzer::isApost (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' sinal de exclamacao (!)
	@return: true or false
 */
bool LexAnalyzer::isExclam (char ch){
	return true;
}//end isAtrib



/*
	metodo que verifica se char e' sinal de interrogacao (?)
	@return: true or false
 */
bool LexAnalyzer::isQuestion (char ch){
	return true;
}//end isAtrib