#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * infinite_while - Runs an infinite loop that sleeps for 1 second each time.
 *
 * Return: Always 0.
 */
int infinite_while(void)
{
	while (1)
	{
	sleep(1);
	}
	return (0);
}

/**
 * main - Creates 5 zombie processes.
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t pid;
	int i;

	for (i = 0; i < 5; i++)
	{
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
	return (1);
	}
	else if (pid == 0)
	{
	/* Child process exits immediately to become a zombie */
	exit(0);
	}
	else
	{
	/* Parent process logs the creation of the zombie */
		printf("Zombie process created, PID: %d\n", pid);
	}
	}

    /* Keep the parent process running indefinitely */
	infinite_while();

	return (0);
}
