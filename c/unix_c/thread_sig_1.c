#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

int         quitflag; /* set nonzero by thread */
sigset_t    mask;

pthread_mutex_t   lock = PTHREAD_MUTEX_INITIALIZER; // what is this?
pthread_cond_t waitloc = PTHREAD_COND_INITIALIZER; // what is this?

void *
thr_fn() {
    int err, signo;

    for (;;) {
        err = sigwait(&mask, &signo);
        if (err != 0) {
            printf("sigwait failed");
            exit (-1);
        }

        switch (signo) {
            case SIGINT:
                printf("\n interrupt \n");
                break;
            case SIGQUIT:
                pthread_mutex_lock(&lock);
                quitflag = 1;
                pthread_mutex_unlock(&lock);
                pthread_cond_signal(&waitloc);
                return (0);
            default:
                printf("unexpected signal &d\n", signo);
                exit(1);
        }
    }
}

int 
main(void) {
    int         err;
    sigset_t    oldmask;
    pthread_t   tid;

    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGQUIT);
    if ((err = pthread_sigmask(SIG_BLOCK, &mask, &oldmask)) != 0) {
        printf(err, "SIG_BLOCK error");
        exit (-1);
    }

    err = pthread_create(&tid, NULL, thr_fn, 0);
    err = pthread_create(&tid, NULL, thr_fn, 0);
    if (err != 0) {
        printf(err, "can't create thread");
        exit (-1);
    }

    pthread_mutex_lock(&lock); // what is this?
    while (quitflag == 0) {
        pthread_cond_wait(&waitloc, &lock);
    }
    pthread_mutex_unlock(&lock);
    
    /* SIGQUIT has been caught and is now blocked, do whatever */
    quitflag = 0;

    /* reset signal mask which blocks SIGQUIT */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        printf(err, "SIG_SETMASK error");
        exit (-1);
    }
    exit (0);
}

