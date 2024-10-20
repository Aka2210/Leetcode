#include "receiver.h"

double time_taken = 0;
struct timespec start, end;
void receive(message_t* message_ptr, mailbox_t* mailbox_ptr){
    sem_t *sem_A = sem_open("/sem_A", 0);  // 只打開，不創建
    sem_t *sem_B = sem_open("/sem_B", 0);
    printf("flag1: %d\n", mailbox_ptr->flag);
    while (1) {
        printf("test1\n");
        sem_wait(sem_B);
        sem_t *final = sem_open("/final", 0);  // 只打開，不創建
        if(final == SEM_FAILED)
        {
            printf("test2\n");
            break;
        }
        printf("flag2: %d\n", mailbox_ptr->flag);
        if(mailbox_ptr->flag == 1)
        {
            printf("test3\n");
            clock_gettime(CLOCK_MONOTONIC, &start);
            msgrcv(mailbox_ptr->storage.msqid, message_ptr, sizeof(message_t), 0, 0);
            printf("test4\n");
            clock_gettime(CLOCK_MONOTONIC, &end);
            mailbox_ptr = &(message_ptr->mailbox);
            time_taken += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
        }
        printf("test5\n");
        printf("%s", message_ptr->data);  // 打印讀取到的每一行
        printf("test6\n");
        sem_post(sem_A);
    }
    printf("test7\n");
    printf("\n%lf\n", time_taken);
    printf("test8\n");
    sem_unlink("/sem_A");
    sem_unlink("/sem_B");
    /*  TODO: 
        1. Use flag to determine the communication method
        2. According to the communication method, receive the message
    */
}

int main(){
    // 創建唯一 key
    key_t key = ftok("shmfile", 65);
    // 創建共享記憶體段，大小為 1024 bytes
    clock_gettime(CLOCK_MONOTONIC, &start);
    int shmid = shmget(key, sizeof(message_t), 0666);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
    message_t *str;
    mailbox_t mailbox;
    if(shmid == -1)
    {
        time_taken = 0;
        key = ftok("progfile", 66);
        str = (message_t *)malloc(sizeof(message_t));
        mailbox.flag = 1;
        clock_gettime(CLOCK_MONOTONIC, &start);
        mailbox.storage.msqid = msgget(key, 0666 | IPC_CREAT);
        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
        printf("main flag1: %d", str->mailbox.flag);
        str->mailbox = mailbox;
        printf("main flag2: %d", str->mailbox.flag);
    }
    else
    {
        mailbox.flag = 2;
        // 將共享記憶體段附加到進程的地址空間
        clock_gettime(CLOCK_MONOTONIC, &start);
        str = (message_t*) shmat(shmid, (void*)0, 0);
        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
    }
    printf("main flag3: %d", str->mailbox.flag);
    receive(str, &(str->mailbox));
    printf("main flag4: %d", str->mailbox.flag);
    if(str->mailbox.flag == 1)
    {
        clock_gettime(CLOCK_MONOTONIC, &start);
        msgctl(str->mailbox.storage.msqid, IPC_RMID, NULL);
        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
    }
    else
    {
        clock_gettime(CLOCK_MONOTONIC, &start);
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
    }
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
