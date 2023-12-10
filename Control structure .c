//
// Created by user on 12/5/2023.
//
#include<stdio.h>

int main(){

    int i = 0;
    int j = 0;
    int z = 0;
    for(i=0; i<10; i++){

        for(z=1;z<10-i;z++){
            printf(" ");
        }

//        printf("*");

        for(j=0;j<=i*2;j++){
            printf("*");
        }
//        for(j=0;j<i;j++){
  //          printf("*");
    //    }
        for(z=1;z<19-i*2;z++){
            printf(" ");
        }
//        for(z=1;z<10-i;z++){
  //          printf(" ");
    //    }
//        printf("*");

        for(j=0;j<=i*2;j++){
            printf("*");
        }

        printf("\n");
    }
    return 0;
}