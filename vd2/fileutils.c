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

