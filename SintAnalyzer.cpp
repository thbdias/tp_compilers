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
void SintAnalyzer::principal(){
	//pegar primeiro registro
	//currentToken = registroLexico.getFirstToken();
	//cout << "\n\nexemplo: " << currentToken->cod << "\n\n";
	//
}//end principal


/**
 * metodo do nao terminal S
 */
void SintAnalyzer::S(){
	if(currentToken->cod == 'G' || currentToken->cod == '2'){
		DECL();
	}
	BLOCO();
}//end S

