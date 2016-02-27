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
#include "SymbTab.h"
using namespace std;

//----------------------------------
// IMPLEMENTACAO CLASSE SYMBTAB
//----------------------------------

/**
*   Construtor
*/
SymbTab::SymbTab(){
    tabSimb = new SymbolNode[SIZE];
    for(int i = 0; i < SIZE; i++){
        tabSimb[i].cod = 0;
        tabSimb[i].lexema = "";
		tabSimb[i].next = NULL;
    }
}// end construtor()


/**
*   Destrutor
*/
SymbTab::~SymbTab(){	
}//end destrutor()


/**
*	Metodo que inicializa a tabela de simbolos com
*	os codigos de cada token, e os lexemas das palavras reservadas.
*/
void SymbTab::inicialize(){
	insert('1', "while");
	insert('1', "if");
	insert('1', "else");
	insert('1', "and");
	insert('1', "or");
	insert('1', "not");
	insert('1', "readln");
	insert('1', "write");
	insert('1', "writeln");
	insert('1', "true");
	insert('1', "false");
	insert('2', "=");
	insert('3', "integer");
	insert('3', "byte");
	insert('3', "string");
	insert('3', "boolean");
	insert('4', "(");
	insert('5', ")");
	insert('6', ">");
	insert('6', "<");
	insert('6', "<>");
	insert('6', ">=");
	insert('6', "<=");
	insert('6', "==");
	insert('7', ",");
	insert('7', ";");
	insert('8', "+");
	insert('8', "-");
	insert('8', "*");
	insert('8', "/");
	insert('9', "{");
	insert('A', "}");
	insert('B', "const");
}// end inicialize()


/**
*   Metodo que insere um token na tabela de simbolos
*/
int *SymbTab::insert(byte cod, std::string lexema){

	int *result = new int[2];
	int line = spreading(lexema); 	    // Armazena a posicao na tabela de simbolos
	int column = 1;						// Armazena a posicao na lista

	struct SymbolNode *symbol = new SymbolNode;		// Simbolo a ser inserido na tabela de simbolos
	symbol->cod = cod;
	symbol->lexema = lexema;
	symbol->next = NULL;

	struct SymbolNode *node = tabSimb[line].next;	// Auxiliar para caminhar na lista

	if(node == NULL){	// tabela vazia
		tabSimb[line].next = symbol;
	} else {
		column++;
		while(node->next != NULL){
				node = node->next;
				column++;
		}
		node->next = symbol;
	}
	result[0] = line;
	result[1] = column;
	node = NULL;
	return result;
} // end insert()


/**
*   Metodo que define a posicao de um lexema na tabela de simbolos
*   Funcao de espalhamento
*/
int SymbTab::spreading(std::string lexema){
    return 0;
} // end spreading()



/**
*   Funcao para testar
*/
void SymbTab::exibir (){

    cout << "\n\nquant\tidToken\tlexema\n";

    for (int i =0; i < SIZE; i++){
        int quantidade = 0;
        struct SymbolNode * node = tabSimb[i].next;
        while(node != NULL){
            cout << ++quantidade << "\t" << node->cod << "\t" << node->lexema << "\n";
            node = node->next;
        } // end while
    }// end for
}// end exibir()
