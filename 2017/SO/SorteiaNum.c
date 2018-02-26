#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//4194305// intervalo de numeros
#define INTERVAL_RAND 4096

int tbpg[256][2];

int geranum();

int main()
{
	geranum();

}

int geranum()
{
    srand( (unsigned)time(NULL) );
    int i;
	for(i=0 ; i < 256 ; i++){
        tbpg[i][1] = i;
		tbpg[i][2] = rand() % INTERVAL_RAND;
		printf("[%d] [%d]\n",tbpg[i][1], tbpg[i][2]);
	}
	
}
