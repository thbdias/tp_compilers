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


//FALTA EDITAR
/*
	metodo que abre e ler arquivo
	@param arq: nome do arquivo que sera lido	
 */
void LexAnalyzer::lerArq(const char * arq){
	ifstream fin (arq); //abre arquivo para leitura
	char ch; //char que sera lido do arquivo

	if (isAlfbt('('))
		cout << "\n\nfuncionando\n\n";
	else
		cout << "\n\nNAO OK\n\n";

	//while (fin.get(ch)){ //le um char do arquivo
		//cout << ch; //imprimir na tela
	//}//end while

	fin.close();
}//end lerArq



/*
	metodo que verifica se um char pertence ao alfabeto
 */
bool LexAnalyzer::isAlfbt (char ch){
	bool resp = false;

	if (isIgual(ch))
		return true;
	else if (isAParent(ch))
			return true;
	else if (isFParent(ch))
			return true;
	else if (isMaior(ch))
			return true;
	else if (isMenor(ch))
			return true;
	else if (isVirgula(ch))
			return true;
	else if (isMais(ch))
			return true;
	else if (isMenos(ch))
			return true;
	else if (isMult(ch))
			return true;
	else if (isBarra(ch))
			return true;
	else if (isACha(ch))
			return true;
	else if (isFCha(ch))
			return true;
	else if (isAAspas(ch))
			return true;
	else if (isFAspas(ch))
			return true;
	else if (isNumero(ch))
			return true;
	else if (isSemicolon(ch))
			return true;
	else if (isLetraMi(ch))
			return true;
	else if (isLetraMa(ch))
			return true;
	else if (isSublinhado(ch))
			return true;
	else if (isDoisPonto(ch))
			return true;
	else if (isAColc(ch))
			return true;
	else if (isFColc(ch))
			return true;
	else if (isApost(ch))
			return true;
	else if (isExclam(ch))
			return true;
	else if (isQuestion(ch))
			return true;

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
	metodo que verifica se char e' sinal igual (=)
	@return: true or false
 */
bool LexAnalyzer::isIgual (char ch){
	return (ch == '=');
}//end isIgual



/*
	metodo que verifica se char e' abre parenteses '('
	@return: true or false
 */
bool LexAnalyzer::isAParent (char ch){
	return (ch == '(');
}//end isAParent



/*
	metodo que verifica se char e' fecha parenteses ')'
	@return: true or false
 */
bool LexAnalyzer::isFParent (char ch){
	return (ch == ')');
}//end isFParent



/*
	metodo que verifica se char e' sinal de maior (>)
	@return: true or false
 */
bool LexAnalyzer::isMaior (char ch){
	return (ch == '>');
}//end isMaior



/*
	metodo que verifica se char e' sinal de menor (<)
	@return: true or false
 */
bool LexAnalyzer::isMenor (char ch){
	return (ch == '<');
}//end isMenor



/*
	metodo que verifica se char e' virgula (,)
	@return: true or false
 */
bool LexAnalyzer::isVirgula (char ch){
	return (ch == ',');
}//end isVirgula



/*
	metodo que verifica se char e' sinal de mais (+)
	@return: true or false
 */
bool LexAnalyzer::isMais (char ch){
	return (ch == '+');
}//end isMais



/*
	metodo que verifica se char e' sinal de menos (-)
	@return: true or false
 */
bool LexAnalyzer::isMenos (char ch){
	return (ch == '-');
}//end isMenos



/*
	metodo que verifica se char e' sinal de multiplicacao (*)
	@return: true or false
 */
bool LexAnalyzer::isMult (char ch){
	return (ch == '*');
}//end isMult



/*
	metodo que verifica se char e' sinal de divisao (/)
	@return: true or false
 */
bool LexAnalyzer::isBarra (char ch){
	return (ch == '/');
}//end isBarra



/*
	metodo que verifica se char e' abre chaves ({)
	@return: true or false
 */
bool LexAnalyzer::isACha (char ch){
	return (ch == '{');
}//end isACha



/*
	metodo que verifica se char e' fecha chaves (})
	@return: true or false
 */
bool LexAnalyzer::isFCha (char ch){
	return (ch == '}');
}//end isFCha



/*
	metodo que verifica se char e' abre aspas (")
	@return: true or false
 */
bool LexAnalyzer::isAAspas (char ch){
	return (((int)ch == 34) || ((int)ch == 84) || ((int)ch == 93) || ((int)ch == 94));
}//end isAAspas



/*
	metodo que verifica se char e' fecha aspas (")
	@return: true or false
 */
bool LexAnalyzer::isFAspas (char ch){
	return (((int)ch == 34) || ((int)ch == 84) || ((int)ch == 93) || ((int)ch == 94));
}//end isFSspas



/*
	metodo que verifica se char e' numero (0-9)
	@return: true or false
 */
bool LexAnalyzer::isNumero (char ch){
	return (((int)ch >= 48) && ((int)ch <= 57));
}//end isNumero



/*
	metodo que verifica se char e' ponto e virgula (;)
	@return: true or false
 */
bool LexAnalyzer::isSemicolon (char ch){
	return (ch == ';');
}//end isSemicolon



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
	metodo que verifica se char e' sublinhado (_)
	@return: true or false
 */
bool LexAnalyzer::isSublinhado (char ch){
	return (ch == '_');
}//end isSublinhado



/*
	metodo que verifica se char e' dois pontos (:)
	@return: true or false
 */
bool LexAnalyzer::isDoisPonto (char ch){
	return (ch == ':');
}//end isDoisPont



/*
	metodo que verifica se char e' abre colchete ([)
	@return: true or false
 */
bool LexAnalyzer::isAColc (char ch){
	return (ch == '[');
}//end isAColc



/*
	metodo que verifica se char e' fecha colchete (])
	@return: true or false
 */
bool LexAnalyzer::isFColc (char ch){
	return (ch == ']');
}//end isFColc



/*
	metodo que verifica se char e' apostrofo (')
	@return: true or false
 */
bool LexAnalyzer::isApost (char ch){
	return (ch == '\'');
}//end isApost



/*
	metodo que verifica se char e' sinal de exclamacao (!)
	@return: true or false
 */
bool LexAnalyzer::isExclam (char ch){
	return (ch == '!');
}//end isExclam



/*
	metodo que verifica se char e' sinal de interrogacao (?)
	@return: true or false
 */
bool LexAnalyzer::isQuestion (char ch){
	return (ch == '?');
}//end isQuestion