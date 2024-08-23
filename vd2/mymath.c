#include<stdio.h>
#include"utils.h"

unsigned int myPow(unsigned int x, unsigned int y){
	if(y==0) return 1;
	if(y==1) return x;

	return x*myPow(x,y-1);
}
