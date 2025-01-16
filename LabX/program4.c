#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    FILE *file = fopen("pid_file.txt", "w");

    if (file == NULL) {
        perror("File open failed");
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        // Child process
        fprintf(file, "Child PID: %d\n", getpid());
    } else if (pid > 0) {
        // Parent process
        fprintf(file, "Parent PID: %d\n", getpid());
    } else {
        perror("Fork failed");
    }

    fclose(file);
    return 0;
}
