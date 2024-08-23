#include<stdio.h>
#include<stdlib.h>
#include"utils.h"
#include"diskutils.h"

//  =4B= |==4B== | =4B=  | ============= |		|====files=======|        
//   fp  | pend  | count | file pointers |              |  

FILE * createvd(unsigned int vdSize){
	FILE *fp = fopen("vdisk.bin","rb+");
	if(fp == NULL){
		// creating new v disk
		fp = fopen("vdisk.bin","wb");
		fclose(fp);
		fp = fopen("vdisk.bin","rb+");
	}
	
	// update this later
	unsigned char *buffer = (unsigned char *) malloc(vdSize);	
	// setting initial disk related data in buffer
	convertUnIntToByteArr(vdSize,buffer); // were writing at start of buffer
	convertUnIntToByteArr(13,buffer+4);				     
	// setting a byte with all zero indicating no file exists
	
	// writing buffer data in vdisk
	fwrite(buffer,vdSize,1,fp);	
	fseek(fp,0,SEEK_SET);
	return fp;
}
