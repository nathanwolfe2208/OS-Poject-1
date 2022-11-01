#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>

int main() {
    struct tbl {
        sem_t mutex;
        int size[2];
    };

    //Declaring needed variables
    int shm_fd;

    const char * label = "shm_fd";

    //Creating the shared memory
    shm_fd = shm_open(label, O_CREAT | O_RDWR, 0666);

    ftruncate(shm_fd, sizeof(int));

    //Mapping the shared memory
    struct tbl *table = mmap(0, sizeof(int), PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);

    //Set to run 5 times
    int loop = 5;

    sem_init(&table->mutex,1 ,1);
    table->size[0] = 0;
    table->size[1] = 0;
    //index variable
    int i = 0;
    while(loop--){
        sem_wait(&table->mutex);
        printf("Producing\n");
        if(table->size[i] == 0){
            table->size[i] = 0;
            i++;
        } else{
            printf("Table slot number %d is filled\n", i + 1);
        }
        if (i > 1){
            i = 0;
        }
        sem_post(&table->mutex);
        sleep(rand()%2+1);

        
    }

    //Closing shared memory
    munmap(table, sizeof(int));
    close(shm_fd);



    return 0;
}





