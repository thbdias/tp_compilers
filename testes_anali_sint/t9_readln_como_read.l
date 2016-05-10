// Exemplo de Programa na linguagem L

integer n;
string nome;
boolean naoTerminou;
const MAXITER=10;

// Bloco Principal

{
  write,"Digite seu nome: ";
  read,nome;
  naoTerminou=TRUE;
  n=0;
  while naoTerminou {
    writeln,"Ola' ",nome;
    n=n+1;
    naoTerminou=n<MAXITER;
  }
}