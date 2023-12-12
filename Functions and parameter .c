//
// Created by user on 12/12/2023.
//
#include<stdio.h>
int adding(int a , int b);
int subtracting(int a , int b);
int multiplying(int a , int b);
int dividing(int a , int b);
int main(){

    while('true') {

        int arr[2];
        printf("Welcome from Zane calculator\n");

        int opt = 0;
        printf("1 for adding\n2 for subtracting\n3 for multiplying\n4 for dividing\n5 for quitting\nEnter your desired option :");
        scanf("%d", &opt);

        if(opt == 5){
            break;
        }
        for(int i = 0; i<2 ; i++) {
            printf("Enter your numbers :");
            scanf("%d", &arr[i]);
        }

        if (opt == 1) {
            int result = 0;
            result = adding(arr[0],arr[1]);
            printf("This is result: %d\n",result);
        } else if(opt ==2){
            int result = 0;
            result = subtracting(arr[0],arr[1]);
            printf("This is result: %d\n",result);
        } else if(opt ==3){
            int result = 0;
            result = multiplying(arr[0],arr[1]);
            printf("This is result: %d\n",result);
        } else{
            int result = 0;
            result = dividing(arr[0],arr[1]);
            printf("This is result: %d\n",result);
        }
    }

    return 0;
}

int adding(int a , int b){

    int total = 0;
    total = a + b;

    return total;
}

int subtracting(int a , int b){

    int total = 0;
    total = a - b;

    return total;
}

int multiplying(int a , int b){

    int total = 0;
    total = a * b;

    return total;
}

int dividing(int a , int b){

    int total = 0;
    total = a / b;

    return total;
}