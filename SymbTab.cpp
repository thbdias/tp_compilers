#include <stdio.h>
#include <iostream>
#include <string>

class SymbTab{
	public:
		SymbTab(){}//construtor
		~SymbTab(){}//destrutor

		inicialize(){			
		}


	private:
		int linhas = 500;
		int colunas = 2; //1-cod do identificador ---- 2-lexema
		string tabSimb [linhas][colunas];
	
};//end class



int main(int argc, char const *argv[])
{
	SymbTab symbTab;

	symbTab.inicialize();
	
	return 0;
}//end main