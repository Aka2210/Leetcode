#include "sender.h"

FILE *file;
void send(message_t* message, mailbox_t* mailbox_ptr)
{
    sem_t *sem_A = sem_open("/sem_A", O_CREAT, 0666, 1);  // A 起始信號量設為 1，讓 A 先執行
    sem_t *sem_B = sem_open("/sem_B", O_CREAT, 0666, 0);  // B 初始設為 0，等待 A 給信號
    while (1) {
        sem_wait(sem_A);//10
        //00
        if(fgets(message->data, sizeof(message->data), file) == NULL)
        {
            break;
        }
        else
        {
            printf("%s", message->data);  // 打印讀取到的每一行
        }
        sem_post(sem_B);//01
    }
    sem_unlink(sem_A);
    sem_post(sem_B);
}

int main(int argc, char *argv[]){
    mailbox_t mailbox;
    mailbox.flag = atoi(argv[1]);

    // 取得第二個參數，這是一個檔案名稱
    char *filename = argv[2];
    //printf("Input file: %s\n", filename);

    file = fopen(filename, "r");

    // 創建唯一 key
    key_t key = ftok("shmfile", 65);

    // 創建共享記憶體段，大小為 1024 bytes
    int shmid = shmget(key, sizeof(message_t), 0666 | IPC_CREAT);

    // 將共享記憶體段附加到進程的地址空間
    message_t *str = (message_t*) shmat(shmid, (void*)0, 0);
    mailbox.storage.shm_addr = str;
    str->mailbox = &mailbox;
    
    send(str, str->mailbox);

    // 關閉檔案
    fclose(file);
    return 0;

    /*  TODO: 
        1) Call send(message, &mailbox) according to the flow in slide 4
        2) Measure the total sending time
        3) Get the mechanism and the input file from command line arguments
            • e.g. ./sender 1 input.txt
                    (1 for Message Passing, 2 for Shared Memory)
        4) Get the messages to be sent from the input file
        5) Print information on the console according to the output format
        6) If the message form the input file is EOF, send an exit message to the receiver.c
        7) Print the total sending time and terminate the sender.c
    */
}