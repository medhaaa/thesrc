
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
 * We have two special characters. The first character can be represented 
 * by one bit 0. The second character can be represented by two bits (10 or 11).
 * Now given a string represented by several bits. Return whether the last 
 * character must be a one-bit character or not. The given string will always 
 * end with a zero.
 */ 

bool isOneBitCharacter(int* bits, int bitsSize);

int main() {
   int bits1[5]={1,1,1,0,0};
   int bits2[11]={1,1,1,0,0,0,0,0,0,1,0};
   bool b=0;
   b=isOneBitCharacter(bits1,5);
   printf("b=%d\n", b);
   b=isOneBitCharacter(bits2,11);
   printf("b=%d\n", b);
}

bool isOneBitCharacter(int* bits, int bitsSize) {
     bool oneBit = 0;
     int i=0;
     if(bitsSize>=1 && bitsSize<=1000){
         while (i < bitsSize) {
             if(bits[i]) {
                 i=i+2;
                 oneBit=0;
             }
             else {
                 i++;
                 oneBit=1;
             }
         }
     }
     return oneBit;
}
