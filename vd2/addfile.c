#include<stdio.h>
#include"copyfile.c"
#include"diskutils.h"


void addfile(FILE *vdfp,char* filename){

	unsigned int filesize = getFileSize(filename);
	unsigned char buffer[4] = {0};
        fread(buffer,4,1,vdfp);
	unsigned int offset = convertByteArrToUnInt(buffer);
	fread(buffer,4,1,vdfp);
	unsigned int poffset = convertByteArrToUnInt(buffer);
	

	
        printf("\n Before Value : %u",offset);
	offset = offset - filesize;

        printf("\nAfter Value : %u",offset);

	fseek(vdfp,offset,SEEK_SET);
	copyfile(vdfp,filename);
	updatefpp(vdfp,offset);

}
