/*
	Membros do grupo:
	Herbert Alves Batista
	Luiz Gustavo Avelino Mendes
	Thiago Henrique Balbino Dias
*/

//----------------------------------
// BIBLIOTECAS
//----------------------------------


#include <stdio.h>
#include <iostream>
#include <string>
#include "SintAnalyzer.h"
#include "SymbTab.h"
#include "RegLexico.h"
#include "LexAnalyzer.h"
using namespace std;

/**
*   Construtor
*/
SintAnalyzer::SintAnalyzer(){ 
	
}// end construtor()


/**
*   Destrutor
*/
SintAnalyzer::~SintAnalyzer(){
}//end destrutor()


void SintAnalyzer::teste(){
	cout << "\n\nteste ok\n\n";
}//end teste


/**
 * metodo que inicia a analise da gramatica
 */
void SintAnalyzer::principal(const char *arq){
	registroLexico = lex.lerArq(arq);

	//registroLexico.exibir();
	currentToken = registroLexico.getFirstToken();
	cout << "\n\nteste: " << currentToken->cod << "\n\n";
	cout << "\n\nteste: " << currentToken->lexema << "\n\n";

	cout << "\n\nteste: " << currentToken->next->cod << "\n\n";	
}//end principal


/**
 * metodo do nao terminal S
 */
void SintAnalyzer::S(){	
	
}//end S

