#include <signal.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    double y;
    sigset_t intmask;
    int i, repeat_factor;
    
    if(argc != 2) {
        fprintf(stderr, "Usage: %s repeat_factor\n\a", argv[0]);
        exit(1);
    }

    if((repeat_factor = atoi(argv[1])) < 1) {
        repeat_factor = 10;
    }

    sigemptyset(&intmask);
    sigaddset(&intmask, SIGINT);

    while(1) {
        //block signal
        /*sigprocmask(SIG_BLOCK, &intmask, NULL);
        fprintf(stderr, "SIGINT signal blocked\n");

        for(int i = 0; i < repeat_factor; i++) {
            y = sin((double) i);
        }
        fprintf(stderr, "Blocked calculation is finished\n");
        */
        //cancel block
        
        sigprocmask(SIG_UNBLOCK, &intmask, NULL);
        fprintf(stderr, "SIGINT signal unblocked\n");

        for(int i = 0; i < repeat_factor; i++) {
            y = sin((double) i);
        }
        fprintf(stderr, "Unblocked calculation is finished\n");
        
    }

    exit(0);
}
