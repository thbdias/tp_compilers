// Exemplo de Programa na linguagem L

integer n;
string nome;
boolean naoTerminou;
const MAXITER=10;

// Bloco Principal

{
  write,"Digite seu nome: ";
  readln,nome;
  naoTerminou=TRUE;
  n=0;
  
  if n == 0
     writeln,"n eh zero";
  while naoTerminou {
    writeln,"Ola' ",nome;
    n=n+1;
    naoTerminou=n<MAXITER;
  }
}