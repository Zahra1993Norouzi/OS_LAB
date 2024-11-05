#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    shmctl(shmid, IPC_RMID, NULL);  

    printf("Shared memory segment deleted.\n");
    return 0;
}
