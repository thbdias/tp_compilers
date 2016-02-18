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
		//o tamanho da matriz foi arbitrário
		//necessário discussão do grupo	
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
			tabSimb[ 0][0] = "1";	tabSimb[ 0][1] = "while";
			tabSimb[ 1][0] = "1";	tabSimb[ 1][1] = "if";
			tabSimb[ 2][0] = "1";	tabSimb[ 2][1] = "else";
			tabSimb[ 3][0] = "1";	tabSimb[ 3][1] = "and";
			tabSimb[ 4][0] = "1";	tabSimb[ 4][1] = "or";
			tabSimb[ 5][0] = "1";	tabSimb[ 5][1] = "not";
			tabSimb[ 6][0] = "1";	tabSimb[ 6][1] = "readln";
			tabSimb[ 7][0] = "1";	tabSimb[ 7][1] = "write";
			tabSimb[ 8][0] = "1";	tabSimb[ 8][1] = "writeln";
			tabSimb[ 9][0] = "1";	tabSimb[ 9][1] = "true";
			tabSimb[10][0] = "1";	tabSimb[10][1] = "false";
			tabSimb[11][0] = "2";	tabSimb[11][1] = "=";
			tabSimb[12][0] = "3";	tabSimb[12][1] = "integer";
			tabSimb[13][0] = "3";	tabSimb[13][1] = "byte";
			tabSimb[14][0] = "3";	tabSimb[14][1] = "string";
			tabSimb[15][0] = "3";	tabSimb[15][1] = "boolean";
			tabSimb[16][0] = "4";	tabSimb[16][1] = "(";
			tabSimb[17][0] = "5";	tabSimb[17][1] = ")";
			tabSimb[18][0] = "6";	tabSimb[18][1] = ">";
			tabSimb[19][0] = "6";	tabSimb[19][1] = "<";
			tabSimb[20][0] = "6";	tabSimb[20][1] = "<>";
			tabSimb[21][0] = "6";	tabSimb[21][1] = ">=";
			tabSimb[22][0] = "6";	tabSimb[22][1] = "<=";
			tabSimb[23][0] = "6";	tabSimb[23][1] = "==";
			tabSimb[24][0] = "7";	tabSimb[24][1] = ",";
			tabSimb[25][0] = "7";	tabSimb[25][1] = ";";
			tabSimb[26][0] = "8";	tabSimb[26][1] = "+";
			tabSimb[27][0] = "8";	tabSimb[27][1] = "-";
			tabSimb[28][0] = "8";	tabSimb[28][1] = "*";
			tabSimb[29][0] = "8";	tabSimb[29][1] = "/";			
			tabSimb[30][0] = "9";	tabSimb[30][1] = "{";
			tabSimb[31][0] = "10";	tabSimb[31][1] = "}";
			tabSimb[32][0] = "11";	tabSimb[32][1] = "const";			
			
		}//end inicialize				
	
};//end class