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
    inicialize();
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
	insert('L', "TRUE");
	insert('L', "FALSE");
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
	insert('K', ";");
	insert('C', "+");
	insert('C', "-");
	insert('C', "*");
	insert('C', "/");
	insert('D', "{");
	insert('E', "}");
	insert('G', "const");
	insert ('P', "then");
}// end inicialize()


/**
 *  Metodo que recebe um token encontrado pelo analisador Lexico
 *  e o insere na tabela de simbolos e registro lexico
 *//*
 void SymbTab::input(byte cod, std::string lexema){
     SymbolNode * symbol = insert(cod, lexema);     // Insere o token na tabela de simbolos
     addToken(symbol);                              // Insere o token no registro lexico
 }*/


/**
*   Metodo que insere um token na tabela de simbolos
*/
SymbolNode * SymbTab::insert(byte cod, std::string lexema){

	int line = spreading(lexema); 	                // Armazena a posicao na tabela de simbolos
	SymbolNode *symbol;                     		// Simbolo a ser inserido na tabela de simbolos


	symbol = search(lexema);                        // Verifica se o lexema ja existe na tabela de simbolo

	if(symbol == NULL){ // token nao existe na tabela de simbolo

        symbol = new SymbolNode;
        symbol->cod = cod;
        symbol->lexema = lexema;
        symbol->next = NULL;

        SymbolNode * node = tabSimb[line].next;	// Auxiliar para caminhar na lista
        if(node == NULL){	// tabela vazia
            tabSimb[line].next = symbol;        // insere o token na primeira posição válida
        } else {
            while(node->next != NULL){
				node = node->next;              //caminha ate encontrar o ultimo
            }
            node->next = symbol;                // insere o token no fim da lista
            symbol = node->next;                // armazena endereço de inserção para retorno
        }
        node = NULL;
    }
	return symbol;
} // end insert()


/**
*   Metodo que define a posicao de um lexema na tabela de simbolos
*   Funcao de espalhamento
*/
int SymbTab::spreading(std::string lexema){
    int term = 0;

    for(int i = 0; i < (int)lexema.length(); i++){
        term += lexema.at(i);
    }
    return term % SIZE;
} // end spreading()

/**
 *  Metodo que verifica a existência de um lexema na tabela de simbolos e o retorna
 */
 SymbolNode * SymbTab::search(std::string lexema){

     SymbolNode * resposta = NULL;
     SymbolNode * node = tabSimb[spreading(lexema)].next;

     while(node != NULL){
            if(lexema.compare(node->lexema) == 0){
                return node;
            }
            node = node->next;
		}
     return resposta;
 }

/**
*   Funcao para testar
*/
void SymbTab::exibir (){

    cout << "\n\nquant\tidToken\tlexema\n";
    int quantidade = 0;
    for (int i =0; i < SIZE; i++){

        struct SymbolNode * node = tabSimb[i].next;
        while(node != NULL){
            cout << ++quantidade << "\t" << node->cod << "\t" << node->lexema << "\n";
            node = node->next;
        } // end while
    }// end for
}// end exibir()



