//================================================================
// Descrição: Lê um número decimal e imprime a sua forma binária
//================================================================
//Criado por Guilherme Bach

// Libs
#include <stdio.h>
#include <stdlib.h>
  
int vetor[10];
// Função Main
int convertebin(int num, int bits);
int main() {

 int num, bits = 10; // Número de entrada
  
 // Lê o número
 printf("Digite o numero: ");
 scanf("%d", &num);
 convertebin(num, bits);

 for (int i = 0; i < bits; ++i)
 {
 	printf("%d", vetor[i]);
 }
}



//Função convertebin
int convertebin(int num, int bits) {
 
 // Utiliza um número de bits como base para a conversão.
 for(int i = (bits -1); i >= 0; i--) {     
    if(num >= 2) {
        vetor[i] = num % 2;
        num = num / 2;
    } else {
        vetor[i] = num;
        num = 0;
    }
 }
 return 0;
}