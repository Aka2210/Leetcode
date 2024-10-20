#include "sender.h"

FILE *file;
struct timespec start, end;
double time_taken = 0;
void send(message_t message, mailbox_t* mailbox_ptr)
{
    sem_t *sem_A = sem_open("/sem_A", O_CREAT, 0666, 1);  // A 起始信號量設為 1，讓 A 先執行
    sem_t *sem_B = sem_open("/sem_B", O_CREAT, 0666, 0);  // B 初始設為 0，等待 A 給信號
    sem_t *final_A = sem_open("/final", O_CREAT, 0666, 0);
    
    while (1) {
        sem_wait(sem_A);//10
        //00
        if(mailbox_ptr->flag == 2)
        {
            clock_gettime(CLOCK_MONOTONIC, &start);
            message = *((message_t*) shmat(mailbox_ptr->storage.msqid, (void*)0, 0));
            clock_gettime(CLOCK_MONOTONIC, &end);
            time_taken += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
        }

        if(fgets(message.data, sizeof(message.data), file) == NULL)
        {
            break;
        }
        else
        {
            printf("%s", message.data);  // 打印讀取到的每一行
        }
        if(mailbox_ptr->flag == 1)
        {
            clock_gettime(CLOCK_MONOTONIC, &start);
            msgsnd(mailbox_ptr->storage.msqid, &message, sizeof(message_t), 0);
            clock_gettime(CLOCK_MONOTONIC, &end);
            time_taken += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
        }
        sem_post(sem_B);//01
    }
    printf("\n%lf\n", time_taken);
    sem_unlink("/final");
    sem_post(sem_B);
}

int main(int argc, char *argv[]){
    mailbox_t mailbox;
    mailbox.flag = atoi(argv[1]);

    // 取得第二個參數，這是一個檔案名稱
    char *filename = argv[2];
    //printf("Input file: %s\n", filename);

    file = fopen(filename, "r");

    message_t str;
    if(mailbox.flag == 2)
    {
        // 創建唯一 key
        key_t key = ftok("shmfile", 65);

        // 創建共享記憶體段，大小為 1024 bytes
        clock_gettime(CLOCK_MONOTONIC, &start);
        mailbox.storage.msqid = shmget(key, sizeof(message_t), 0666 | IPC_CREAT);
        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
    }
    else
    {
        key_t key = ftok("progfile", 65);  // 生成唯一鍵值
        clock_gettime(CLOCK_MONOTONIC, &start);
        int msqid = msgget(key, 0666 | IPC_CREAT);  // 創建或獲取消息隊列
        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
        mailbox.storage.msqid = msqid;
    }

    str.mailbox = mailbox;
    send(str, &(str.mailbox));
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
