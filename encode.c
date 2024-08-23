#include<stdio.h>
#include"utils.h"
#include"encode.h"

int encode(unsigned char* in, unsigned char* out,unsigned char n , unsigned char level){
        int pos;
	
	if(n==0){
	        setbit(out,0,0);
                setbit(out,1,0);
                pos = 2;
                if(level == 0) { setbit(out,pos,0); pos++; }
                return pos;


	}

        if(n==1){
                setbit(out,0,0);
                setbit(out,1,1);
                pos = 2;
                if(level == 0) { setbit(out,pos,0); pos++; }
                return pos;

        }

        else if(n==2){
                setbit(out,0,getbit(in,0));
                setbit(out,1,getbit(in,1));
                pos = 2;
                if(level == 0) { setbit(out,pos,0); pos++; }
                return pos;
        }

        unsigned char next_n = 8;
        unsigned char next_in = n;
        unsigned char i;

        while(next_in < 128) {
                next_in = next_in << 1;
                next_n--;
        }

        pos = encode(&next_in,out,next_n,level+1);

        for(i=0;i<n;i++) setbit(out,pos+i,getbit(in,i));

        pos = pos + n;

        if (level == 0 ) { setbit(out,pos,0); pos++; }

        return pos;
}

unsigned int decode(unsigned char* in) {

          unsigned int number = 0;
          unsigned int jump = 2;
          unsigned int elts = 0;
          unsigned int power;
          unsigned int i = 0;
  
          do{
                  power = myPow(2,(jump-1));
                  elts += jump;
                  number = 0;
                  for(int k=0 ; k<jump; k++) {
                          number += power * getbit(in,i);
                          i++;
                          power /= 2;
                  }
                  jump = number;
          }while(getbit(in,elts));
  
          return number;
}
  
