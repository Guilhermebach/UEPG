#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PG 1024
#define INTRVL_NUM 4194303
#define COLUMS 4
#define COLUMS2 5

int TBPGS[PG][COLUMS];

int criapgs();
int escolhenumeros(int matriz[][COLUMS2], int num);
int cvtbin(int pag, int desloc, int base);
int taxa(int matriz[][COLUMS2], int num);

int main()
{
	int i;

	criapgs();

	int n = 0;
	printf("==============================================================================================================\n");
	printf("                                      Guilherme Bach && Jose Lucas                                            \n");
	printf("==============================================================================================================\n");
	printf("Escolha um numero para n:");
	scanf("%d", &n);

	int MtrNum[n][COLUMS2];

	for(i=0 ; i < PG ; i++){
		if(TBPGS[i][0] != -1){
        	printf("[%d] [%d] \n",TBPGS[i][0], TBPGS[i][1]);
    	}
	}
	

	escolhenumeros(MtrNum, n);

	taxa(MtrNum, n);

	/*for(i=0 ; i < PG ; i++){
		if(TBPGS[i][0] != -1){
        	printf("[%d] [%d] \n",TBPGS[i][0], TBPGS[i][1]);
    	}
	}*/
	return 0;
}

int criapgs(){
	srand( (unsigned)time(NULL) );
    int i;
    for(i=0 ; i < PG ; i++){
		TBPGS[i][1] = i;
		TBPGS[i][0] = -1;
		TBPGS[i][2] = i * 4096;
		TBPGS[i][3] = TBPGS[i][2] + 4095;
	}
	for(i=0 ; i < 256 ; i++){
		int p = rand() % PG - 1;
        TBPGS[p][0] = i;
	}
	return 0;
}

int escolhenumeros(int matriz[][COLUMS2], int num){
	int i = 0;
	int deslocamento = 0;

	srand( (unsigned)time(NULL) );

	for (i = 0; i < num; ++i)
		{
			matriz[i][0] = rand() % INTRVL_NUM;
			matriz[i][1] = 0;
			int j = 0;
			while(matriz[i][1] == 0){
				if(matriz[i][0] < TBPGS[j][3]){
					matriz[i][1] = j;
				}
				j++;
			}
			matriz[i][2] = matriz[i][0] - TBPGS[matriz[i][1]][2];
			matriz[i][4] = matriz[i][0] - TBPGS[matriz[i][1]][2];
			matriz[i][3] = TBPGS[matriz[i][1]][0];
		}

	for (i = 0; i < num; ++i)
		{
			printf("[%d] [%d] ", matriz[i][0], matriz[i][1]);
			printf("[");
			cvtbin(matriz[i][1], matriz[i][2], 10);
			printf("] ");
			if(matriz[i][3] == -1){
				printf("[PAGE FAULTS] ");
			}else{
				printf("[%d] ", (matriz[i][3] * 4096) + matriz[i][4]);
			}
			
			if(matriz[i][3] == -1){
				printf("[PAGE FAULTS] ");
			}else{
				printf("[%d] ",matriz[i][3]);
			}
			if(matriz[i][3] == -1){
				printf("[PAGE FAULTS] \n");
			}else{
				printf("[");
				cvtbin(matriz[i][3], matriz[i][4], 8);
				printf("]\n");
			}
		}

}

int cvtbin(int pag, int desloc, int base) {

	int vetorpag[base];
	int vetordesloc[12];
	 
 for(int i = (base - 1); i >= 0; i--) {     
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
 for (int i = 0; i < base; ++i)
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

int taxa(int matriz[][COLUMS2], int num){
	int contacertos = 0, contaerros = 0, i;

	for (i = 0; i < num; ++i)
	{
		if(matriz[i][3] == -1){
			contaerros++;
		}else{
			contacertos++;
		}
	}
	contaerros = (contaerros* 100)/ num;
	contacertos = 100 - contaerros;
	printf("Acerto(em porcentagem): %d , Erros(em porcentagem): %d \n", contacertos, contaerros);

}