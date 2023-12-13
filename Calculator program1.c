//
// Created by user on 12/12/2023.
//
#include<stdio.h>
int adding(int a , int b);
int subtracting(int a , int b);
int multiplying(int a , int b);
int dividing(int a , int b);
int calculation_again(int p_result);
void history();
int processing(int number1 , int number2);
int arr1[100];
char arr2[100];
int arr3[100];
int arr4[100];
int h = 0;
int main(){

    while('true') {
        h = 0;
        for (int i = 0; i < 100 ; i++){
            arr1[i] = 0;
            arr2[i] = '0';
            arr3[i] = 0;
            arr4[i] = 0;
        }
        int arr[2];
        printf("Welcome from Zane calculator\n");

        int opt = 0;
        printf("1 for adding\n2 for subtracting\n3 for multiplying\n4 for dividing\n5 for quitting\nEnter your desired option :");
        scanf("%d", &opt);

        if(opt == 5){
            printf("Thank you very much for using!!");
            break;
        }
        for(int i = 0; i<2 ; i++) {
            printf("Enter your numbers :");
            scanf("%d", &arr[i]);
        }
        arr1[h] = arr[0];
        arr3[h] = arr[1];

        if (opt == 1) {
            arr2[h] = '+';
            int result = 0;
            result = adding(arr[0],arr[1]);
            printf("This is your final result: %d\n",result);

        } else if(opt ==2){
            arr2[h] = '-';
            int result = 0;
            result = subtracting(arr[0],arr[1]);
            printf("This is your final result: %d\n",result);
        } else if(opt ==3){
            arr2[h] = '*';
            int result = 0;
            result = multiplying(arr[0],arr[1]);
            printf("This is your final result: %d\n",result);
        } else{
            arr2[h] = '/';
            int result = 0;
            result = dividing(arr[0],arr[1]);
            printf("This is your final result: %d\n",result);
        }
    }

    return 0;
}

int adding(int a , int b){

    int total = 0;
    int f_total = 0;
    total = a + b;
    printf("This is result: %d\n",total);
    f_total = calculation_again(total);
//    printf("F test%d\n",f_total);

    return f_total;
}

int subtracting(int a , int b){

    int total = 0;
    int f_total = 0;
    total = a - b;
    printf("This is result: %d\n",total);
    f_total = calculation_again(total);
//    printf("%d",f_total);

    return f_total;
}

int multiplying(int a , int b){

    int total = 0;
    int f_total = 0;
    total = a * b;
    printf("This is result: %d\n",total);
    f_total = calculation_again(total);

    return f_total;
}

int dividing(int a , int b){

    int total = 0;
    int f_total = 0;
    total = a / b;
    printf("This is result: %d\n",total);
    f_total = calculation_again(total);

    return f_total;
}

int calculation_again(int p_result){
//    printf("P test%d\n",p_result);

    arr4[h] = p_result;

    int t_opt = 0;
    printf("Press 1 to clear\nPress 2 to calculate with recent result\nPress 3 to calculate more\nPress 4 to see history\nEnter here:");
    scanf("%d",&t_opt);
    if(t_opt==2){
        h++;
        int t_number = 0;
        printf("Enter your another number:");
        scanf("%d",&t_number);
        arr1[h] = p_result;
        arr3[h] = t_number;
        p_result = processing(p_result,t_number);
    }else if(t_opt == 4){
        history();
        p_result = calculation_again(p_result);
    }else if(t_opt == 3){
        h++;
        int t_number[2];
        for (int i = 0; i<2; i++){
            printf("Enter your numbers:");
            scanf("%d",&t_number[i]);
        }
        arr1[h] = t_number[0];
        arr3[h] = t_number[1];
        p_result = processing(t_number[0],t_number[1]);
    }

    return p_result;

}
void history(){

    printf("This is your history\n");
    for (int i = 0; i<=h; i++){
        printf("%d %c %d = %d\n",arr1[i],arr2[i],arr3[i],arr4[i]);
    }

}

int processing(int number1 , int number2){

    int tt_opt = 0;
    int total_number = 0;
    printf("1 for adding\n2 for subtracting\n3 for multiplying\n4 for dividing\nEnter your desired option:");
    scanf("%d",&tt_opt);
    if(tt_opt == 1){
        arr2[h] = '+';
        total_number = adding(number1,number2);
//            printf("This is h %d and result %d \n", h ,p_result);
    }else if(tt_opt == 2){
        arr2[h] = '-';
        total_number = subtracting(number1,number2);

    }else if(tt_opt == 3){
        arr2[h] = '*';
        total_number = multiplying(number1,number2);

    }else{
        arr2[h] = '/';
        total_number = dividing(number1,number2);

    }

    return total_number;
}
//clear error with recursive function
//check paint