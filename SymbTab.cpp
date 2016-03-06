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
	insert('5', "while");
	insert('3', "if");
	insert('4', "else");
	insert('J', "and");
	insert('J', "or");
	insert('J', "not");
	insert('6', "readln");
	insert('7', "write");
	insert('7', "writeln");
	insert('F', "true");
	insert('F', "false");
	insert('1', "=");
	insert('2', "integer");
	insert('2', "byte");
	insert('2', "string");
	insert('2', "boolean");
	insert('8', "(");
	insert('9', ")");
	insert('A', ">");
	insert('A', "<");
	insert('A', "<>");
	insert('A', ">=");
	insert('A', "<=");
	insert('A', "==");
	insert('B', ",");
	insert('B', ";");
	insert('C', "+");
	insert('C', "-");
	insert('C', "*");
	insert('C', "/");
	insert('D', "{");
	insert('E', "}");
	insert('G', "const");
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
