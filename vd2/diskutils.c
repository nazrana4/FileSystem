#include<stdio.h>
#include"diskutils.h"
#include"utils.h"

void updatefpp(FILE *vdfp,unsigned int val){
	unsigned char buffer[4] = {0};
	fseek(vdfp,0,SEEK_SET);
	convertUnIntToByteArr(val,buffer);
	fwrite(buffer,4,1,vdfp);

}
