#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{

int c;
FILE *in, *out;
struct timeval tempo1, tempo2;
struct timezone tzp;
double tempo;
in = fopen("file100KB.in","r");
out = fopen("file100KB.out","w");

gettimeofday(&tempo1,&tzp);
while((c = fgetc(in)) != EOF)
{
	fputc(c,out);
}

gettimeofday(&tempo2,&tzp);

tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

printf("==============================================\n");
printf("O tempo de copia do file100KB é de: %f\n", tempo);
printf("==============================================\n");

return 0;

}