/**
	Membros do grupo:
	Herbert Alves Batista
	Luiz Gustavo Avelino Mendes
	Thiago Henrique Balbino Dias
 */

import java.util.Hashtable;

public class SymbTab{

	//a tabela de simbolos será estruturada em uma tabela hash
	public static Hashtable<String, String> tabelaSimb;	

	public static final byte CONST = 1;
	public static final byte INTEGER = 2;
	public static final byte BYTE = 3;
	public static final byte STRING = 4;
	public static final byte WHILE = 5;
	public static final byte IF = 6;
	public static final byte ELSE = 7;
	public static final byte AND = 8;
	public static final byte OR = 9;
	public static final byte NOT = 10;
	public static final byte EQUAL = 11; // sinal -> ==
	public static final byte ASSIG = 12; // sinal -> =
	public static final byte RPARENT = 13; // abre parenteses
	public static final byte LPARENT = 14; // fecha parenteses
	public static final byte MAIOR = 15; // sinal -> >
	public static final byte MENOR = 16; // sinal -> <
	public static final byte DIFERENTE = 17; // sinal -> <>
	public static final byte MAIORIGUAL = 18; // sinal -> >=
	public static final byte MENORIGUAL = 19; // sinal -> <=
	public static final byte COMMA = 20; //virgula
	public static final byte MAIS = 21; // sinal -> +
	public static final byte MENOS = 22; // sinal -> -
	public static final byte MULT = 23; // sinal -> *
	public static final byte DIV = 24; // sinal -> /
	public static final byte SEMICOLON = 25; // sinal -> ;
	public static final byte RCHAVE = 26; // sinal -> {
	public static final byte LCHAVE = 27; // sinal -> }
	public static final byte READLN = 28;
	public static final byte WRITE = 29;
	public static final byte WRITELN = 30;
	public static final byte TRUE = 31;
	public static final byte FALSE = 32;
	public static final byte BOOLEAN = 33;


	/**
      Funcao que transforma byte em string
      @param num: byte a ser alterado
      @return : valor alterado para string
    */
    private static String toString ( byte num ){
        return (num + "");
    }//end isNumber

    

    /**
     	funcao de testes
     */
    public static void main(String[] args) {    	

    	System.out.println("teste funcionando.");
    	
    }

}

//.ao finalizar a classe SymbTab.java retirar os campos static dos metodos