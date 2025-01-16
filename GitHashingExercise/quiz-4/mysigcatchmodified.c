#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int sigint_count = 0;

void custom_handler(int sig) {
    sigint_count++;
    printf("SIGINT caught! Signal number: %d\n", sig);
    if (sigint_count >= 2) {
        printf("Restoring default SIGINT behavior. Terminating on next SIGINT.\n");
        signal(SIGINT, SIG_DFL);
    }
}

int main() {
    signal(SIGINT, custom_handler);
    while (1) {
        printf("Running... Press Ctrl+C to send SIGINT.\n");
        sleep(1);
    }
    return 0;
}
