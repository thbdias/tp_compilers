// Exemplo de Programa na linguagem L

integer n;
string nome;
boolean naoTerminou;
const MAXITER=9;

// Bloco Principal

{
  write,"Digite seu nome: ";
  readln,nome;
  naoTerminou=TRUE;
  n=-1;
  while naoTerminou {
    writeln,"Ola' ",nome;
    n=n+1;
    naoTerminou=n<MAXITER;
  }
}