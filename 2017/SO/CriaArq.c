#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void)
{
	int out;
	out = open("file1B.in",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	for(int i = 0; i < 1; i++){
		write(out,"a",1);
	}
	
	out = open("file4KB.in",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	for(int i = 0; i < 4096; i++){
		write(out,"b",1);
	}

	out = open("file100KB.in",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	for(int i = 0; i < 102400; i++){
		write(out,"c",1);
	}

	out = open("file2MB.in",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	for(int i = 0; i < 2097152; i++){
		write(out,"d",1);
	}

	out = open("file1GB.in",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	for(int i = 0; i < 1073741824; i++){
		write(out,"e",1);
	}

	return(0);
}