#include "receiver.h"

void receive(message_t* message_ptr, mailbox_t* mailbox_ptr){
    sem_t *sem_A = sem_open("/sem_A", 0);  // 只打開，不創建
    sem_t *sem_B = sem_open("/sem_B", 0);
    while (1) {
        sem_wait(sem_B);
        sem_t *sem_A = sem_open("/sem_A", 0);  // 只打開，不創建
        if(sem_A == SEM_FAILED)
        {
            break;
        }
        printf("%s", message_ptr->data);  // 打印讀取到的每一行
        sem_post(sem_A);
    }
    sem_unlink(sem_B);
    /*  TODO: 
        1. Use flag to determine the communication method
        2. According to the communication method, receive the message
    */
}

int main(){
    // 創建唯一 key
    key_t key = ftok("shmfile", 65);

    // 創建共享記憶體段，大小為 1024 bytes
    int shmid = shmget(key, sizeof(message_t), 0666 | IPC_CREAT);

    // 將共享記憶體段附加到進程的地址空間
    message_t *str = (message_t*) shmat(shmid, (void*)0, 0);
    receive(str, str->mailbox);
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