/*
	Membros do grupo:
	Herbert Alves Batista
	Luiz Gustavo Avelino Mendes
	Thiago Henrique Balbino Dias
*/

#include <stdio.h>
#include <iostream>
#include <string>

class SymbTab{
	private:		
		//1-cod do identificador ---- 2-lexema
		string tabSimb [500][2]; //tabela de simbolos


	public:
		SymbTab(){}//construtor
		~SymbTab(){}//destrutor

		/*
			metodo que inicializa a tabela de simbolos com
			os codigos de cada token, e os lexemas.
		*/
		inicialize(){	
			//deve alterar o metodo de insercao aki para o metodo
			//que o herbert esta fazendo. A priore, para teste,
			//a insercao e' manual.
			tabSimb[ 0][0] = "1";	tabSimb[ 0][1] = "const";
			tabSimb[ 1][0] = "1";	tabSimb[ 1][1] = "integer";
			tabSimb[ 2][0] = "1";	tabSimb[ 2][1] = "byte";
			tabSimb[ 3][0] = "1";	tabSimb[ 3][1] = "string";
			tabSimb[ 4][0] = "1";	tabSimb[ 4][1] = "while";
			tabSimb[ 5][0] = "1";	tabSimb[ 5][1] = "if";
			tabSimb[ 6][0] = "1";	tabSimb[ 6][1] = "else";
			tabSimb[ 7][0] = "1";	tabSimb[ 7][1] = "and";
			tabSimb[ 8][0] = "1";	tabSimb[ 8][1] = "or";
			tabSimb[ 9][0] = "1";	tabSimb[ 9][1] = "not";
			tabSimb[10][0] = "1";	tabSimb[10][1] = "readln";
			tabSimb[11][0] = "1";	tabSimb[11][1] = "write";
			tabSimb[12][0] = "1";	tabSimb[12][1] = "writeln";
			tabSimb[13][0] = "1";	tabSimb[13][1] = "true";
			tabSimb[14][0] = "1";	tabSimb[14][1] = "false";
			tabSimb[15][0] = "1";	tabSimb[15][1] = "boolean";

			//teste
			/*
			for (int i =0; i < 16; i++){				
				cout << "\n" << (i+1);
				for (int j = 0; j < 2; j++){
					cout << "\t" << tabSimb[i][j];
				}
			}*/
			//end teste
			
		}//end inicialize				
	
};//end class



int main(int argc, char const *argv[])
{
	SymbTab symbTab;

	symbTab.inicialize();
	
	return 0;
}//end main