#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	pid_t pid_potomka;
	char*komunikat;
	int powtorzen;
	int pidRodzica = -1, pidAlive = -1;
	int myPid = getpid();
	printf("Na razie działa jeden proces\n");

	pid_potomka = fork();
	switch(pid_potomka) {
		case -1:
			printf("rozwidlenie procesu nie powiodło się\n");
			exit(1);
		case 0:
			komunikat = "Jestem potomkiem";
			pidAlive = getpid();
			powtorzen = 6;
			break;
		default:
			komunikat = "Jestem rodzicem";
			powtorzen = 5;
			break;
	}

	for(; powtorzen > 0; powtorzen--) {
		if(komunikat == "Jestem potomkiem")
		{
			if(pidRodzica!=-1 && pidRodzica==pidAlive)
				printf("PID rodzica %d \t ",pidRodzica);
			if(powtorzen==1){
				printf("Moj pid %d \t",myPid);
				system("ps -ef | grep zad4 ");
			}
		}
		sleep(1);
	}
}