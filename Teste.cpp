/*
arquivo para testar o programa
*/

#include "SymbTab.h"
#include "LexAnalyzer.h"
#include <fstream>  //tratar arquivos

class Teste{
	public:
		Teste(){}
		~Teste(){}

	//testar tabela de simbolos
	//funcionando
	//void teste1 (){
	//	SymbTab tabela;
	//	tabela.inicialize();
	//	tabela.exibir();
	//}

	//teste analisador lexico
	//funcionando
	//void teste2 (){
	//	LexAnalyzer lex;
	//	lex.testeLex();
	//}
	
	//teste analisador lexico
	//void testeArq(){
	//	LexAnalyzer lex;
	//	lex.abrirFonte("exemplo.l");
	//	lex.proxToken();
	//}
	
	//teste2 analisador lexico
	void teste2al(){
		LexAnalyzer lex;
		//lex.testeLex();
		lex.lerArq("exemplo.l");
	}
};

int main(int argc, char const *argv[])
{
	Teste teste;
	//teste.teste1(); 
	//teste.teste2();
	//teste.testeArq();
	teste.teste2al();
	return 0;
}