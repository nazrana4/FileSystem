#include<stdio.h>
#include"copyfile.c"

int main(){
	FILE *fp = fopen("vdisk.bin","rb+");
	copyfile(fp,"example.txt");
	return 0;
}
