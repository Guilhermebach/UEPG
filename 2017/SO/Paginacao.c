#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PAG 1024
#define INTERVAL_NUM 4194303
#define COL_MTR 5

int tbpg[256][2];

int mapeiapag();
int menu();
int sorteiaNum(int matriz[][COL_MTR], int n);
int convertebinvirtual(int pag, int desloc);
int convertebinreal(int pag, int desloc);
int taxaAcErr(int matriz[][COL_MTR], int num);

int main(){
	int num;

	num = menu();

	mapeiapag();

	int tbnum[num][COL_MTR];

	sorteiaNum(tbnum, num);	

	taxaAcErr(tbnum, num);
}

int mapeiapag()
{
    srand( (unsigned)time(NULL) );
    int i;
	for(i=0 ; i < 256 ; i++){
        tbpg[i][1] = i;
		tbpg[i][2] = rand() % PAG - 1;
		printf("[%d] [%d]\n",tbpg[i][1], tbpg[i][2]);
	}
	
}

int menu(){
	int n = 0;
	printf("==============================================================================================================\n");
	printf("                                         Paginação                                                            \n");
	printf("==============================================================================================================\n");
	printf("\n");
	printf("Escolha um numero para n:");
	scanf("%d", &n);

	if(n <= (INTERVAL_NUM + 1))	{
		return n;
	}else{
		printf("Deve ser digitado um numero entre 1 e 4194306");
		return 0;
	}
}

int sorteiaNum(int matriz[][COL_MTR], int n){
	int i = 0;
	int deslocamento = 0;

	srand( (unsigned)time(NULL) );

	for (i = 0; i < n; ++i)
		{
			matriz[i][1] = rand() % INTERVAL_NUM;
			matriz[i][2] = 0;
			int j = 1;
			while(matriz[i][2] == 0){
				if(matriz[i][1] < ((j * 4096) - 1)){
					matriz[i][2] = j - 1;
				}
				j++;
			}
			deslocamento = (matriz[i][1]) - (matriz[i][2] * 4096);
			matriz[i][3] = deslocamento;
			matriz[i][5] = deslocamento;
			int p = 0;
			matriz[i][4] = 256;
			do{
				if(matriz[i][2] == tbpg[p][2]){
					matriz[i][4] = tbpg[p][1];
				}
				p++;
			}while(matriz[i][2] != tbpg[p][2] && p < 256);

			printf("[%d] [%d] ",matriz[i][1], matriz[i][2]);
			printf("[");
			convertebinvirtual(matriz[i][2], matriz[i][3]);
			printf("] ");
			if(matriz[i][4] == 256){
				printf("[PAGE FAULTS] ");
			}else{
				printf("[%d] ",matriz[i][4]);
			}
			if(matriz[i][4] == 256){
				printf("[PAGE FAULTS] \n");
			}else{
				printf("[");
				convertebinreal(matriz[i][4], matriz[i][5]);
				printf("]\n");
			}

		}	

}

int convertebinvirtual(int pag, int desloc) {

	int vetorpag[10];
	int vetordesloc[12];
	 
 for(int i = (9); i >= 0; i--) {     
    if(pag >= 2) {
        vetorpag[i] = pag % 2;
        pag = pag / 2;
    } else {
        vetorpag[i] = pag;
        pag = 0;
    }

 }
 for(int i = (11); i >= 0; i--) {     
    if(desloc >= 2) {
        vetordesloc[i] = desloc % 2;
        desloc = desloc / 2;
    } else {
        vetordesloc[i] = desloc;
        desloc = 0;
    }

 }
 for (int i = 0; i < 10; ++i)
 {
 	printf("%d", vetorpag[i]);
 }
 printf(" ");
 for (int i = 0; i < 12; ++i)
 {
 	printf("%d", vetordesloc[i]);
 }
 return 0;
}

int convertebinreal(int pag, int desloc) {

	int vetorpag[8];
	int vetordesloc[12];
	 
 for(int i = (7); i >= 0; i--) {     
    if(pag >= 2) {
        vetorpag[i] = pag % 2;
        pag = pag / 2;
    } else {
        vetorpag[i] = pag;
        pag = 0;
    }

 }
 for(int i = (11); i >= 0; i--) {     
    if(desloc >= 2) {
        vetordesloc[i] = desloc % 2;
        desloc = desloc / 2;
    } else {
        vetordesloc[i] = desloc;
        desloc = 0;
    }

 }
 for (int i = 0; i < 8; ++i)
 {
 	printf("%d", vetorpag[i]);
 }
 printf(" ");
 for (int i = 0; i < 12; ++i)
 {
 	printf("%d", vetordesloc[i]);
 }
 return 0;
}

int taxaAcErr(int matriz[][COL_MTR], int num){
	int contacertos = 0, contaerros = 0, i;

	for (i = 0; i < num; ++i)
	{
		if(matriz[i][4] == 256){
			contaerros++;
		}else{
			contacertos++;
		}
	}
	contaerros = (contaerros* 100)/ num;
	contacertos = 100 - contaerros;
	printf("acerto(em porcentagem): %d , erros(em porcentagem): %d \n", contacertos, contaerros);

}
