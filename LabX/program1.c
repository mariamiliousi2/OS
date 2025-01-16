#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            printf("Child PID: %d\n", getpid());
            return 0;
        } else if (pid > 0) {
            // Parent process
            printf("Parent PID: %d\n", getpid());
        } else {
            perror("Fork failed");
        }
    }
    return 0;
}
