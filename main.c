#include<stdio.h>
#include"encode.h"
#include"utils.h"
#include"diskutils.h"
#include"fileutils.h"

void testFile(FILE *vdFP){
	unsigned char buffer[4] = {0};
	fread(buffer,4,1,vdFP);
	printf("fend =>  %u \n" ,convertByteArrToUnInt(buffer));
	fread(buffer,4,1,vdFP);
	printf("pend =>   %u \n",convertByteArrToUnInt(buffer));	
	fread(buffer,4,1,vdFP);
	printf("count =>   %u  \n",convertByteArrToUnInt(buffer));
}


int main(){
	
	FILE* vdfp = createvd(1024*4);	
//	testFile(vdfp);
	fseek(vdfp,0,SEEK_SET);	
	addfile(vdfp,"example.txt");
	fseek(vdfp,0,SEEK_SET);	
	addfile(vdfp,"textfile.txt");	
	fseek(vdfp,4056,SEEK_SET);
	unsigned char buffer[4096-4056];
	fread(buffer,(4096 - 4056),1,vdfp);
	FILE* fp = fopen("output.txt","wb");
	fwrite(buffer,(4096-4056),1,fp);	
	return 0;	

}
