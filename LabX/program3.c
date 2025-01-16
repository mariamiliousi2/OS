#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int sig) {
    printf("Child received signal %d\n", sig);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        signal(SIGUSR1, signal_handler);
        pause(); // Wait for signal
    } else if (pid > 0) {
        // Parent process
        sleep(1); // Give time for child to setup signal handler
        kill(pid, SIGUSR1);
    } else {
        perror("Fork failed");
    }
    return 0;
}
