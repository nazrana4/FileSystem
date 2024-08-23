#include<stdio.h>
#include<sys/stat.h>
#include"fileutils.h"

unsigned int getFileSize(char *name){
        struct stat fileStat;
        if (stat(name,&fileStat) == 0){
                return (long long)fileStat.st_size;
        }
        perror("stat");
        return 0;
}
void copyfile(FILE *dest, char *src)
 {
         FILE *source = fopen(src,"rb+");
         if(source == NULL)
         {
                 printf("\nCan't open file");
                 return;
        }
        unsigned char buffer[64];
        size_t bytes;

        // bytes stores the number of bytes read by fread function 
        while( (bytes = fread(buffer,1,sizeof(buffer),source)) > 0 ){
                fwrite(buffer,1,bytes,dest);
        }

}

