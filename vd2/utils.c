#include<stdio.h>
#include"utils.h"
#include<stdlib.h>

int getbit(unsigned char *in,unsigned int n){
	unsigned char mask[] ={128,64,32,16,8,4,2,1};
	return (in[(n/8)] & mask[n%8]) == 0 ? 0 : 1;
}

void setbit(unsigned char *out,unsigned int n, int k){
	unsigned char mask[] ={128,64,32,16,8,4,2,1};
	if(k == 0) 
		out[(n/8)] = (out[(n/8)] & (~mask[(n%8)]));
	else 
		out[(n/8)] = (out[(n/8)] | mask[(n%8)]);
}

unsigned char* convertUnIntToByteArr(unsigned int number,unsigned char *arr){
	if(arr == NULL){
		arr = malloc(sizeof(unsigned int));
	}

	for(int i=0;i<4;i++){
		arr[i] =((unsigned char) (number >> ((3-i)*8))) & 0xFF;
//		printf("%b",arr[i]);
	}

	return arr;
}

unsigned int convertByteArrToUnInt(unsigned char *arr){	
	unsigned int number = 0;
	for(int i=0;i<4;i++){	
		number = number | (((unsigned int) arr[i]) << ((3-i)*8));
	}
	
	printf("%d ",number);
	return number;
}
