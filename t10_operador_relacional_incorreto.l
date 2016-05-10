// Exemplo de Programa na linguagem L

integer n;
string nome;
boolean naoTerminou;
const MAXITER=10;

// Bloco Principal

{
  write,"Digite seu nome: ";
  readln,nome;
  naoTerminou= 2 ? 3;
  n=0;
  while naoTerminou {
    writeln,"Ola' ",nome;
    n=n+1;
    naoTerminou=n<MAXITER;
  }
}