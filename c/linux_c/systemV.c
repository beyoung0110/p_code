#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define PERMS S_IRUSR | S_IWUSR
void init_semaphore_struct(struct sembuf *sem, int semnum, int semop, int semflg) {
    sem->sem_num = semnum;
    sem->sem_op = semop;
    sem->sem_flg = semflg;
}

int del_semaphore(int semid) {
    #if 1
    //int semctl(int sem_id, int sem_num, int command, ...);
    /***
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    }
    ***/
    return semctl(semid, 0, IPC_RMID);
    #endif
}

int main(int argc, char **argv) {
    char buffer[MAX_CANON], *c;
    int i, n;
    int semid, semop_ret, status;
    pid_t childpid;
    /***
    struct sembuf {
        short sem_num; //which semaphore
        short sem_op;
        short sem_flg;
    }
    ***/
    struct sembuf semwait, semsignal;
    if((argc != 2) || (n = atoi(argv[1])) < 1) {
        fprintf(stderr,"Usage : %s number \n\a", argv[0]);
        exit(1);
    }
    
    if((semid = semget(IPC_PRIVATE, 1, PERMS)) == 1) { // create a semaphore, int semget(key_t key, int nsems, int semflg)
        fprintf(stderr, "[%d]: Access Semaphore Error: %s\n\a", getpid(), strerror(errno));
        exit(1);
    }

    init_semaphore_struct(&semwait, 0, -1, 0);
    init_semaphore_struct(&semsignal, 0, 1, 0);

    if(semop(semid, &semsignal, 1) == -1) { //the option of a semaphore, int semop(int semid, struct sembuf *spos, int nspos)
        fprintf(stderr, "[%d]: Increment Semaphore Error: %s\n\a", getpid(), strerror(errno));
        if(del_semaphore(semid) == -1) { // semctl(semid, 0, IPC_RMID)
            fprintf(stderr, "[%d]: Destory Semaphore Error: %s\n\a", getpid(), strerror(errno));
        }
        exit(1);
    }

    for(i = 0; i < n; i++) {
        if(childpid == fork()) break;
        sprintf(buffer, "[i = %d]-->;[Process = %d]-->;[Parent = %d]-->;[Child = %d]\n", i, getpid(), getppid(), childpid);

        c = buffer;
        while((( semop_ret = semop(semid, &semwait, 1)) == -1) && (errno == EINTR));

        if(semop_ret == -1) {
            fprintf(stderr, "[%d]: Decrement Semaphore Error: %s\n\a", getpid(), strerror(errno));
        } else {
            while( *c != '\0') fputc(*c++, stderr);
            while(((semop_ret = semop(semid, &semsignal, 1)) == -1) && (errno == EINTR));
         
            if(semop_ret == -1) {
                fprintf(stderr, "[%d]: Increment Semaphore Error: %s\n\a", getpid(), strerror(errno));
            }
        }   

        while((wait(&status) == -1) && (errno == EINTR));

        if(i == 1) {
            if(del_semaphore(semid) == -1) {
                fprintf(stderr, "[%d]: Destory Semaphore Error: %s\n\a", getpid(), strerror(errno));
             }
        }
    }
    exit(0);
}
