#include "receiver.h"

void receive(message_t* message_ptr, mailbox_t* mailbox_ptr){
    printf("test\n");
    sem_t *sem_A = sem_open("/sem_A", 0);  // 只打開，不創建
    sem_t *sem_B = sem_open("/sem_B", 0);
    struct timespec start, end;
    double time_taken = 0;
    printf("test\n");
    while (1) {
        printf("test\n");
        sem_wait(sem_B);
        printf("test\n");
        sem_t *final = sem_open("/final", 0);  // 只打開，不創建
        if(final == SEM_FAILED)
        {
            break;
        }
        if(mailbox_ptr->flag == 1)
        {
            clock_gettime(CLOCK_MONOTONIC, &start);
            msgrcv(mailbox_ptr->storage.msqid, message_ptr, sizeof(message_t), 1, 0);
            clock_gettime(CLOCK_MONOTONIC, &end);
            time_taken += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
        }
        clock_gettime(CLOCK_MONOTONIC, &start);
        printf("%s", message_ptr->data);  // 打印讀取到的每一行
        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
        sem_post(sem_A);
    }
    printf("\n%lf\n", time_taken);
    sem_unlink("/sem_A");
    sem_unlink("/sem_B");
    /*  TODO: 
        1. Use flag to determine the communication method
        2. According to the communication method, receive the message
    */
}

int main(){
    printf("test\n");
    // 創建唯一 key
    key_t key = ftok("shmfile", 65);
    printf("test\n");
    // 創建共享記憶體段，大小為 1024 bytes
    int shmid = shmget(key, sizeof(message_t), 0666);
    printf("test\n");
    message_t *str;
    if(shmid == -1)
    {
        
        key = ftok("progfile", 65);
        str = (message_t *)malloc(sizeof(message_t));
        mailbox_t mailbox;
        mailbox.flag = 1;
        mailbox.storage.msqid = msgget(key, 0666 | IPC_CREAT);
        str->mailbox = &mailbox;
    }
    else
    {
        printf("test\n");
        // 將共享記憶體段附加到進程的地址空間
        str = (message_t*) shmat(shmid, (void*)0, 0);
        printf("test\n");
    }
    receive(str, str->mailbox);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
    /*  TODO: 
        1) Call receive(&message, &mailbox) according to the flow in slide 4
        2) Measure the total receiving time
        3) Get the mechanism from command line arguments
            • e.g. ./receiver 1
        4) Print information on the console according to the output format
        5) If the exit message is received, print the total receiving time and terminate the receiver.c
    */
}
