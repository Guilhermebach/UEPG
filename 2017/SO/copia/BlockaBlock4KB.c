#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	char block[4096];
	int in, out;
	int nread;
	struct timeval tempo1, tempo2;
	struct timezone tzp;
	double tempo;

	in = open("file4KB.in", O_RDONLY);
	out = open("file4KB.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	gettimeofday(&tempo1,&tzp);

	while((nread = read(in,block,sizeof(block))) > 0){
		write(out,block,nread);
	}

	gettimeofday(&tempo2,&tzp);

	tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

	printf("==============================================\n");
	printf("O tempo de copia do file4KB é de: %f\n", tempo);
	printf("==============================================\n");

	return 0;

}