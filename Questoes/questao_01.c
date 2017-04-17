#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

	int main(int argc, const char * argv[]){
		write(open ("ola_mundo.txt", O_WRONLY | O_CREAT, S_IRWXU), "Ola mundo!\n", 11);
		return 0;
}
