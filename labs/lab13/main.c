#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signal_handler(int signal) {
    switch(signal) {
        case SIGABRT:
            printf("Received SIGABRT :-)\n");
        break;
        case SIGFPE:
            printf("Received SIGFPE :-)\n");
        break;
        case SIGILL:
            printf("Received SIGILL :-)\n");
        break;
        case SIGINT:
            printf("Received SIGINT :-)\n");
        break;
        case SIGSEGV:
            printf("Received SIGSEGV :-)\n");
        break;
        case SIGTERM:
            printf("Received SIGTERM :-)\n");
        break;

    }
}

int main() {
    signal(SIGABRT, signal_handler);
    signal(SIGFPE, signal_handler);
    signal(SIGILL, signal_handler);
    signal(SIGINT, signal_handler);
    signal(SIGSEGV, signal_handler);
    signal(SIGTERM, signal_handler);

    int con_input;
    printf("Enter number for raise signal(1-6):1-SIGABRT,2-SIGFPE,3-SIGILL,4-SIGINT,5-SIGSEGV, 6-SIGTERM:");
    scanf("%d", &con_input);

    switch(con_input) {
        case 1:
            raise(SIGABRT);
        break;
        case 2:
            raise(SIGFPE);
        break;
        case 3:
            raise(SIGILL);
        break;
        case 4:
            raise(SIGINT);
        break;
        case 5:
            raise(SIGSEGV);
        break;
        case 6:
            raise(SIGTERM);
        break;
        default:
            printf("Invalid input. Bye :-( \n");
        break;
    }

    return 0;
}
