/*
arquivo para testar o programa
*/

#include "SymbTab.h"
#include "LexAnalyzer.h"
#include "SintAnalyzer.h"
#include <string.h>
#include <fstream>  //tratar arquivos
using namespace std;

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
	void teste2 (char *arq){
		LexAnalyzer lex;
		lex.testeLex();
		lex.lerArq(arq);		
	}

	//teste analisador lexico
	//void testeArq(){
	//	LexAnalyzer lex;
	//	lex.abrirFonte("exemplo.l");
	//	lex.proxToken();
	//}

	//teste2 analisador lexico
	//void teste2al(){
		//LexAnalyzer lex;
		//lex.testeLex();
		//lex.lerArq("exemplo.l");
		//lex.isAlfab('a');
	//}
	
	//teste do analisador sintatico
	void teste3(char *arq){
		SintAnalyzer sint;
		LexAnalyzer lex;		
		//lex.lerArq(arq);
		//sint.teste();
		sint.principal(arq);
	}
};

int main(int argc, char *argv[])
{
	Teste teste;
	//teste.teste1();
	//teste.teste2();
	//teste.testeArq();
	//teste.teste2al();
	//teste.teste3();

	//correto
	if (argc != 2)
		cout << "\n\nErro! Inicializacao incorreta!\n";	
	else{
			//cout << "\n\nnome do arquivo a ser testado: " << argv[1] << endl;
			teste.teste3(argv[1]);
		}
	
	return 0;
}//end main
