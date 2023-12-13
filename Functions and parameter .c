//This is more advanced calculator program!!
// Created by user on 12/12/2023.
//
#include<stdio.h>
int adding(int a , int b);
int subtracting(int a , int b);
int multiplying(int a , int b);
int dividing(int a , int b);
int calculation_again(int p_result);
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
            printf("This is your adding final result: %d\n",result);

        } else if(opt ==2){
            int result = 0;
            result = subtracting(arr[0],arr[1]);
            printf("This is your subtracting final result: %d\n",result);
        } else if(opt ==3){
            int result = 0;
            result = multiplying(arr[0],arr[1]);
            printf("This is your multiplying final result: %d\n",result);
        } else{
            int result = 0;
            result = dividing(arr[0],arr[1]);
            printf("This is your dividing final result: %d\n",result);
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
    int t_opt = 0;
    printf("Press 1 to clear\nPress 2 to calculate more\nEnter here:");
    scanf("%d",&t_opt);
    if(t_opt==2){
        int t_number = 0;
        int tt_opt = 0;
        printf("Enter your another number:");
        scanf("%d",&t_number);
        printf("1 for adding\n2 for subtracting\n3 for multiplying\n4 for dividing\nEnter your desired option:");
        scanf("%d",&tt_opt);
        if(tt_opt == 1){
            p_result = adding(p_result,t_number);
        }else if(tt_opt == 2){
            p_result = subtracting(p_result,t_number);
        }else if(tt_opt == 3){
            p_result = multiplying(p_result,t_number);
        }else{
            p_result = dividing(p_result,t_number);
        }
    }
        return p_result;

}

//clear error with recursive function
//check paint
