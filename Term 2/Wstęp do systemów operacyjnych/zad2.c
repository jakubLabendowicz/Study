#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv[]) {
	alarm(30);
	while(true)
	{
		system("ps -aux");
		sleep(argv[1]);
	}
}