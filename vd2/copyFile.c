#include<stdio.h>

void transbin(unsigned char arr[],size_t n){
	for(size_t i=0;i<n;i++){
		arr[i] = (unsigned int) arr[i];
	}
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
//		transbin(buffer,bytes);
                fwrite(buffer ,1,bytes,dest);          
        }

}
