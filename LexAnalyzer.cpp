/*
	Membros do grupo:
	Herbert Alves Batista
	Luiz Gustavo Avelino Mendes
	Thiago Henrique Balbino Dias
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "LexAnalyzer.h"
#include "SymbTab.h"
#include "RegLexico.h"
#include <fstream> //tratar arquivos
using namespace std;

/*
	construtor
 */
LexAnalyzer::LexAnalyzer(){
    ESTADO = 0;
    parado = false;
    lexema = "";
}//construtor

/*
	destrutor
 */
LexAnalyzer::~LexAnalyzer(){
}//destrutor

//teste
void LexAnalyzer::testeLex(){
	//cout << "\n\nteste lexico ok.";
	//tabelaSimbolo.exibir(); //funcionando
	//char ch = '\'';
	//if (isApost(ch))
	//	cout << "\n\nE igual!\n"<< (int)ch << "\n";
	//else
	//	cout << "\n\nNao e igual\n"<< (int)ch << "\n";

}//end teste


//ESTE METODO ESTA TESTANDO AS OUTRAS FUNCIONALIDADES DO SISTEMA--------------------
/*
	metodo que abre e le arquivo
	@param arq: nome do arquivo que sera lido
 */
void LexAnalyzer::lerArq(const char * arq){

	ifstream fin (arq);                     //abre arquivo para leitura

	int lineNumber = 1;
	char ch;
    ch = fin.get();                         // lê o primeiro caractere
    bool endOfFile = false;

	while (ch != EOF || endOfFile){

        transition(ch);                     // Calcula transição do estado atual lendo ch

        if(!parado){                        // se a maquina não tiver parado na ultima transição
            ch = fin.get();                 // lê o próximo caractere
            if(ch == '\n' && ESTADO != 12){
                lineNumber++;
            }
        } else{                         // caso a maquina tenha parado na ultima transição
            switch(ESTADO){
                // tratar casos de erro lexico e comentario
            case 0:
                cout << lineNumber << ":caractere invalido\n";
            return;

            case 5:     // estado referente aos comentarios
                resetMachine();
                break;

            case 12:
                cout << lineNumber << ":caractere invalido\n";
                return;

            case 14:
                if(ch == '\n') lineNumber--;
                cout << lineNumber << ":lexema nao identificado [ " << lexema << " ]\n";
                return;

            case 18:
                if(ch == '\n') lineNumber--;
                cout << lineNumber << ":lexema nao identificado [ " << lexema << " ]\n";
                return;
            case 24:
                if(ch == '\n') lineNumber--;
                cout << lineNumber << ":lexema nao identificado [ " << lexema << " ]\n";
                return;

            default:
                // Inserir token na tabela de simbolo e no registro lexico
                registroLexico.addToken(tabelaSimbolo.insert(obterClassToken(ESTADO), lexema), lineNumber);
                resetMachine();
            }
        }


        if(ch == EOF && endOfFile) {    // mecanismo para encerramento
            endOfFile = false;
        } else if(ch == EOF){
            endOfFile = true;
        }

	}//end while


	fin.close();
	//tabelaSimbolo.exibir();
	//registroLexico.exibir();
}//end lerArq

/**
 * Metodo que retorna a maquina de estados para o estado inicial
 */
 void LexAnalyzer::resetMachine(){
    ESTADO = 0;
    lexema = "";
    parado = false;
 } // end resetMachine()

/**
 * Metodo que calcula a transição dados um estado atual e um caractere de entrada
 */
 void LexAnalyzer::transition(char c){

     string apostrofo = "'";

    switch(ESTADO){

    case 0: // estado q0 lendo c

        if(c == ' ' || c == '\t' || c == '\n'){
            break; // ignora
            } else {
                switch(c) {

                    case '"':
                        ESTADO = 12;
                        break;
                    case '{':
                        ESTADO = 1;
                        lexema = lexema+c;
                        break;
                    case '(':
                        ESTADO = 2;
                        lexema = lexema+c;
                        break;
                    case '=':
                        ESTADO = 3;
                        lexema = lexema+c;
                        break;
                    case '}':
                        ESTADO = 15;
                        lexema = lexema+c;
                        break;
                    case ')':
                        ESTADO = 16;
                        lexema = lexema+c;
                        break;
                    case '<':
                        ESTADO = 20;
                        lexema = lexema+c;
                        break;
                    case '>':
                        ESTADO = 21;
                        lexema = lexema+c;
                        break;
                    case ';':
                        ESTADO = 26;
                        lexema = lexema+c;
                        break;
                    case ',':
                        ESTADO = 23;
                        lexema = lexema+c;
                        break;
                    case '/':
                        ESTADO = 4;
                        lexema = lexema+c;
                        break;
                    case '-':
                        ESTADO = 27;
                        lexema = lexema+c;
                        break;
                    default:

                        if(c == '+' || c == '*'){
                            ESTADO = 22;
                            lexema = lexema+c;

                            } else if(isDigito(c)){
                                ESTADO = 6;
                                lexema = lexema+c;

                                } else if (c >= 'A' && c <= 'F'){
                                    ESTADO = 7;
                                    lexema = lexema+c;

                                    } else if (isLetraMi(c) || isLetraMa(c)){
                                        ESTADO = 17;
                                        lexema += c;

                                        } else if(c == '_' || c == '?' || c == '!' || c == '[' || c == ']' || c == '.' || c == ':' || c == apostrofo.at(0)){
                                            ESTADO = 18;
                                            lexema += c;

                                            } else parado = true;
                    }
                }
        break;

    case 1: // estado q1 lendo c
        parado = true;
        break;

    case 2: // estado q2 lendo c
        parado = true;
        break;

    case 3: // estado q3 lendo c
        if(c == '='){
            ESTADO = 19;
            lexema += c;

        } else parado = true;
        break;

    case 4: // estado q4 lendo c
        if(c == '/'){
            ESTADO = 5;

        } else parado = true;
        break;

    case 5: // estado q5 lendo c
        if(c == '\n' || c == EOF){
            parado = true;

        }
        break;

    case 6: // estado q6 lendo c
        if(isDigito(c)){
            ESTADO = 8;
            lexema += c;

        } else if(c >= 'A' && c <= 'F'){
            ESTADO = 24;
            lexema += c;

            } else if(c == 'h'){
                ESTADO = 11;
                lexema += c;

                } else parado = true;
        break;

    case 7: // estado q7 lendo c
        if(isDigito(c) || (c >= 'A' && c <= 'F')){
            ESTADO = 9;
            lexema += c;

        } else if(c == '_' || isLetraMi(c) || isLetraMa(c)){
                ESTADO = 17;
                lexema += c;

                } else parado = true;
        break;

    case 8: // estado q8 lendo c
        if(c == 'h'){
            ESTADO = 11;
            lexema += c;

        } else parado = true;
        break;

    case 9: // estado q9 lendo c
        if(c == 'h'){
            ESTADO = 25;
            lexema += c;

        } else if(isLetraMi(c) || isLetraMa(c) || isDigito(c) || c == '_'){
                ESTADO = 17;
                lexema += c;

                } else parado = true;
        break;

    case 10:    // estado q10 lendo c
        if(isDigito(c)){
            lexema += c;
        } else parado = true;
        break;

    case 11:    // estado q11 lendo c
        parado = true;
        break;

    case 12:    // estado q12 lendo c
        if(isLetraMi(c) || isLetraMa(c) || isDigito(c) || c == '.' || c == ':' ||
           c == ',' || c == ';' || c =='!' || c == '?' || c == '=' || c == '<' ||
           c == '>' || c == ' ' || c == '\t' || c == apostrofo.at(0) || c == '_' ||
           c == '+' || c == '-' || c == '*' || c == '/' || c == '[' || c == ']' ||
           c == '{' || c == '}' || c == '(' || c == ')'){

            lexema += c;

           } else if(c == '"'){
                ESTADO = 13;
                lexema += '$';

                } else if(c == '\n'){
                        ESTADO = 14;
                        lexema += c;

                        } else parado = true;
        break;

    case 13:    // estado q13 lendo c
        parado = true;
        break;

    case 14:    // estado q14 lendo c
        parado = true;
        break;

    case 15:    // estado q15 lendo c
        parado = true;
        break;

    case 16:    // estado q16 lendo c
        parado = true;
        break;

    case 17:    // estado q17 lendo c
        if(isLetraMi(c) || isLetraMa(c) || isDigito(c) || c == '_'){
            lexema += c;

        } else {parado = true; /*cout << "entrou" << parado << "\n";*/}
        break;

    case 18:    // estado q18 lendo c
        parado = true;
        break;

    case 19:    // estado q19 lendo c
        parado = true;
        break;

    case 20:    // estado q20 lendo c
        if(c == '=' || c == '>'){
            ESTADO = 19;
            lexema += c;

        } else parado = true;
        break;

    case 21:    // estado q21 lendo c
        if(c == '='){
            ESTADO = 19;
            lexema += c;

        } else parado = true;
        break;

    case 22:    // estado q22 lendo c
        parado = true;
        break;

    case 23:    // estado q23 lendo c
        parado = true;
        break;

    case 24:    // estado q24 lendo c
        if(c == 'h'){
            ESTADO = 11;

        } else parado = true;
        break;

    case 25:    // estado q25 lendo c
        parado = true;
        break;

    case 26:    // estado q26 lendo c
        parado = true;
        break;

    case 27:    // estado q27 lendo c
        if(isDigito(c)){
            ESTADO = 10;
            lexema += c;

        } else parado = true;
        break;
    }
 }

/*
	metodo que verifica se char e' numero (0-9)
	@return: true or false
 */
bool LexAnalyzer::isDigito (char ch){
	return (((int)ch >= 48) && ((int)ch <= 57));
}//end isDigito

/*
	metodo que verifica se char e' letra minuscula (a-z)
	@return: true or false
 */
bool LexAnalyzer::isLetraMi (char ch){
	return (((int)ch >= 97) && ((int)ch <= 122));
}//end isLetraMi

/*
	metodo que verifica se char e' letra maiuscula (A-Z)
	@return: true or false
 */
bool LexAnalyzer::isLetraMa (char ch){
	return (((int)ch >= 65) && ((int)ch <= 90));
}//end isLetraMa

/*
	funcao que verifica e retorna a classe de token dado um estado de aceitação
 */
char LexAnalyzer::obterClassToken (int estado){

	switch(estado){
        // Apenas estados finais e que reconhecem um lexema
        case 1:
            return 'D'; // abre chaves
        case 2:
            return '8'; // abre parenteses
        case 3:
            return '1'; // atribuicao
        case 4:
            return 'C'; // operador aritmetico
        case 6:
            return 'F'; // expressao decimal
        case 7:
            return 'H'; // identificador ou palavra chave
        case 8:
            return 'F'; // expressao decimal
        case 9:
            return 'H'; // identificador ou palavra chave
        case 10:
            return 'F'; // expressao decimal
        case 11:
            return 'M'; // expressao hexadecimal
        case 13:
            return 'N'; // expressao string
        case 15:
            return 'E'; // fecha chaves
        case 16:
            return '9'; // fecha parenteses
        case 17:
            return 'H'; // identificador ou palavra chave
        case 19:
            return 'A'; // operador relacional
        case 20:
            return 'A'; // operador relacional
        case 21:
            return 'A'; // operador relacional
        case 22:
            return 'C'; // operador aritmetico
        case 23:
            return 'B'; // separador
        case 25:
            return 'I'; // identificador ou hexadecimal
        case 26:
            return 'K'; // delimitador de comando
        case 27:
            return 'C'; // operador aritmetico
        default:
            return '0';
	}
}//end obterClassToken
