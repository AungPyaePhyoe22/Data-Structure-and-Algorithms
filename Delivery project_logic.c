//
// Created by user on 1/1/2024.
//
#include"stdio.h"
#include"stdlib.h"
#include "time.h"
struct trans{
    char tran_record[200];
};
typedef struct{
    char c_feed_back[500];
    char a_feed_back[500];
}interact;
typedef struct{
    char reasons_delete[500];
    int word_counter;
}delete;
typedef struct{

    int u_id;
    char u_name[30];
    char u_password[30];
    char u_email[30];
    unsigned long long int u_phone;
    unsigned int u_point;
    int u_massage;
    struct trans records[100];
    interact texts[50];

}data;
struct format{

    char mail_format[20];

};
struct my_time{
    char c_time[25];

};

struct my_time Ctime[1];
data db[10];
struct format fm[5];
delete d_accounts[100];

int l_checking = -1;
int user_count = 0;
int count = -1;
int review_no = -1;

char int_to_char_array_data[10];
int tran_record_array[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int review_counter[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
char nothing[100];

void declaration(); //1
void login();//1
void registration();//4
void my_privilege();//5
int compare_two_char_array(char origin_data[30] , char test_data[30]);//3
void copy_two_char_array(char first[30] , char second[30]);//3
int size_of_array(char test_array[30]);//3
int gmail_checking(char test_gmail[30]);//2
int password_checking(char test_password[30]);//2
int gmail_validation(char valid_gmail[30]);//2
int strong_password(char test_password[30]);//2
void transfer_money();//5
void admin_pov();//5
void record_data();//4
void loading_data();//4
void print_data();//4
void transaction_recording (int sender_id,int receiver_id,unsigned int amount);//5
void integer_to_char(unsigned int value);//3
int charCounting(char toCount[50]);//3
void t_record_counting();//3
void review_record_counting();//3
void admin_functions(int admin_id);//5
void ID_arrangement(int d_user_id);//5
void Sorting_Deleting(int d_user_id);//5
void get_time();//3
int Counting(unsigned long long int Count);//3
int phone_validation(unsigned long long int Ph);//2
int main(){
    t_record_counting();
    review_record_counting();
    printf("%d\n",review_no);
    loading_data();
    print_data();
    declaration();

    return 0;
}

void declaration(){

    int option = 0;
    printf("This is Zane Delivery Service!\n");
    printf("Press 1 to Login\nPress 2 to Register\nPress 3 to Quit");
    scanf("%d",&option);

    if(option == 1){

        login();

    }else if(option == 2){

        registration();
        declaration();

    }else if(option == 3){

        printf("Thank you for using!!");
        record_data();
        print_data();

    }else{

      printf("Wrong option\n");
      declaration();
    }

}

void login(){

    char l_email[30];
    char l_password[30];
    int l1 = -1;
    int l2 = -1;
    int l3 = 0;
    printf("Welcome!\nPlease enter your email:");
    scanf(" %[^\n]",&l_email[0]);
    printf("Please enter your password:");
    scanf(" %[^\n]",&l_password[0]);
    for(int i =0; i<user_count; i++){
//        printf("\n%s\n",db[i].u_email);
       l1 = compare_two_char_array(db[i].u_email,l_email);
       l2 = compare_two_char_array(db[i].u_password,l_password);
       if(l1 == 1 && l2 ==1) {
           l_checking = i;
           l3 = -1;
           break;
       }else if(l1 == 1 && l2 ==0){
           l3 = 1;
       }else if(l1 == 0 && l2 ==1){
           l3 = 2;
       }
    }
    if(l3 == 1){
        printf("Wrong password!\n");
        login();
    }else if(l3 == 2){
        printf("Wrong email!\n");
        login();
    }else if(l3 == 0){
        printf("User not found!\n");
        login();
    }else if(l_checking == 0 || l_checking == 1 || l_checking == 2){
        printf("Login Success!\nYou are an admin %d\n",l_checking);
        admin_functions(l_checking);
    }else{
        if(db[l_checking].u_massage == 0) {
            printf("Login Success!\n");
//        db[l_checking].u_id = l_checking + 1;
            printf("Welcome %s. This is your id %d\n", db[l_checking].u_name, db[l_checking].u_id);
            my_privilege();
        }else{
            int choice = 0;
            printf("Login failed\nYour account has been suspended for the following reason\n");
            printf("%s\n",db[l_checking].texts[(db[l_checking].u_massage)-1].c_feed_back);
            while(choice == 0) {
                printf("Press 1 to go back to declaration\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    declaration();
                } else {
                    printf("Wrong option\n");
                    choice = 0;
                }
            }
        }
    }

}

int compare_two_char_array(char origin_data[30] , char test_data[30]){

    int same_count = 0;
    int size_1 = size_of_array(origin_data);
    int size_2 = size_of_array(test_data);
    if(size_1 == size_2){
        for(int i = 0; i<size_1; i++){
            if(origin_data[i] == test_data[i]){
                same_count++;
            }else{
                break;
            }
        }
        if(same_count == size_1){
            return 1;
        }
    }
    return 0;
}
int size_of_array(char test_array[30]){
    int size = 0;
    for (int i =0; i<30; i++){
        if(test_array[i] != '\0'){
            size++;
        }else{
            break;
        }
    }
    return size;
}
void registration(){

    int g_check = 0;
    int p_check = 0;
    int phone_check = -1;
    if(user_count == 10){
        printf("limit reached!\nYou can't register anymore!!");
    }else {
        char r_email[30];
        char r_password[30];
        char r_name[30];
        printf("Welcome from registration!\n");
        while(g_check != -1) {
            printf("Enter your email:");
            scanf(" %[^\n]", r_email);
            g_check = gmail_checking(r_email);
            if(g_check == -1){
                g_check = gmail_validation(r_email);
            }else{
                printf("This gmail is already taken!!\n");
            }
        }
        copy_two_char_array(db[user_count].u_email, r_email);
        while(p_check == 0) {
            printf("Enter your password:");
            scanf(" %[^\n]", r_password);
            p_check = password_checking(r_password);
            if(p_check == 1){
                p_check = strong_password(r_password);
            }
        }
        copy_two_char_array(db[user_count].u_password, r_password);
        printf("Enter your name:");
        scanf(" %[^\n]", r_name);
        copy_two_char_array(db[user_count].u_name, r_name);
        while(phone_check == -1) {
            printf("Enter your phone number:");
            scanf("%llu", &db[user_count].u_phone);
            int index = phone_validation(db[user_count].u_phone);
            if(index > -1){
                printf("Your phone number is already taken\n");
            }else{
                phone_check = 0;
                printf("Success\n");
            }
        }

        printf("Registration success!\nYou have obtained 500 points!\n");
        db[user_count].u_point = 500;
        db[user_count].u_massage = 0;
        db[user_count].u_id = user_count + 1;
        printf("This is your id %d\n",db[user_count].u_id);
        user_count++;
    }
}

void copy_two_char_array(char first[30] , char second[30]){

    for(int i = 0; i<30; i++){
        if(second[i] == '\0'){
            break;
        }
        first[i] = second[i];
    }
}
void my_privilege(){
    int p_option = 0;
    printf("Welcome from user option section!!\n");
    printf("These are our options!\n");
    printf("Press 0 to log out!\nPress 1 to transfer money!\nPress 2 to view your information!\nPress 3 to go to admin pov!!\nPress 4 to deactivate your account!\n");
    scanf("%d",&p_option);
    if(p_option == 0){
        printf("You have been log out!!\n");
        l_checking = -1;
        declaration();
    }else if(p_option == 1){
        printf("This is transfer money sector!\n");
        transfer_money();
    }else if(p_option == 2){
        int opt = -1;
        printf("These are your information!\n");
        printf("ID : %d\n",db[l_checking].u_id);
        printf("Name : %s\n",db[l_checking].u_name);
        printf("Email : %s\n",db[l_checking].u_email);
        printf("Point : %d\n",db[l_checking].u_point);
        while(opt !=0) {
            printf("Press 0 to go back!\n");
            scanf("%d", &opt);
            if (opt == 0) {
                my_privilege();
            }else{
                printf("Wrong Option!\n");
            }
        }
    }else if(p_option == 3){
        int opt = -1;
        admin_pov();
        while(opt !=0) {
            printf("Press 0 to go back!\n");
            scanf("%d", &opt);
            if (opt == 0) {
                my_privilege();
            }else{
                printf("Wrong Option!\n");
            }
        }
    }else if(p_option == 4) {
        int d_id = 0;
        char d_pass[30];
        int d_p_count = 0;
        int r_count = 0;
        int r_test = 0;
        char c_array[3] = {'?', 'C', 'u'};
        char test_array_for_review[500];
        integer_to_char(db[l_checking].u_id);
        int ID_S = charCounting(int_to_char_array_data);
        printf("This is deactivating account section\n");
        printf("Once you deactivate your account, all of your data will be lost and your account will be deleted from our server!\n");
        printf("Tell us the reason you want to deactivate - \n");
        for (int i = 0; i < 100; i++) {
            if (d_accounts[i].reasons_delete[0] == '?') {
                r_count++;
            }
        }
        review_no = r_count;
//        review_counter[l_checking] = r_count;
        scanf(" %[^\n]", test_array_for_review);
//        printf("%s\n",test_array_for_review);
        for (int j = 0; j < 3; j++) {
            d_accounts[r_count].reasons_delete[j] = c_array[j];
            r_test++;
        }
//        printf("%d\n",ID_S);
        for (int i = 0; i < ID_S; i++) {
            d_accounts[r_count].reasons_delete[r_test] = int_to_char_array_data[i];
            r_test++;
        }

        for (int i = r_test; i < 500; i++) {
            d_accounts[r_count].reasons_delete[i] = test_array_for_review[i - r_test];
        }

        d_accounts[r_count].word_counter = charCounting(d_accounts[r_count].reasons_delete);
        for (int a = 0; a <= r_count; a++) {
            printf("%d %s", d_accounts[a].word_counter,d_accounts[a].reasons_delete);
        }
        printf("Enter your id and password to continue the process...\n");
        //tu 1
        while(db[l_checking].u_id != d_id){
            printf("Id : \n");
            scanf("%d",&d_id);
            if(db[l_checking].u_id == d_id) {
                while(d_p_count == 0){
                    printf("Password : \n");
                    scanf(" %[^\n]", d_pass);
                    d_p_count = compare_two_char_array(d_pass,db[l_checking].u_password);
                    if(d_p_count == 1){
                        printf("Success!!\nGood_Bye\n");

                    }else{
                        printf("Wrong password!\n");
                    }
                }
            }else{
                printf("Wrong id!\n");
            }
        }
        ID_arrangement(db[l_checking].u_id);
        Sorting_Deleting(db[l_checking].u_id);
//        printf("%d\n",user_count);
//        print_data();
        l_checking = -1;
        record_data();
//        t_record_counting();
//        review_record_counting();
        user_count = 0;
        loading_data();
        print_data();
        declaration();

    }else{
            printf("Wrong Option!\n");
            my_privilege();

    }
}
int gmail_checking(char test_gmail[30]){
//phyoe@gmail.com
    int g_count = 0;
    for(int i =0; i<30; i++){
        if(test_gmail[i] == '@'){
            break;
        }
        g_count++;
    }
//    printf("Count %d\n",count);
    for(int i = 0; i<user_count; i++){
        int o_count = 0;
        int s_count = 0;
        for(int j = 0; j<30; j++){
            if(db[i].u_email[j] == '@'){
                break;
            }
            o_count++;
        }
//        printf("O Count %d\n",o_count);
        if(o_count == g_count){
            for(int s =0; s<g_count; s++){
                if(db[i].u_email[s] == test_gmail[s]){
                    s_count++;
                }
            }
//            printf("S Count %d\n",s_count);
            if(s_count == g_count){
                return i;
            }
        }
    }
    return -1;
}
int password_checking(char test_password[30]){

    int t_number = size_of_array(test_password);
    int s_count = 0;
    for(int i =0; i<user_count; i++){
        int o_number = size_of_array(db[i].u_password);
        if(t_number == o_number){
            for(int j = 0; j<t_number;j++){
//                printf("%c %c\n",db[i].u_password[j],test_password[j]);
                if(db[i].u_password[j] == test_password[j]){
                    s_count++;
                }
            }
            if(s_count == t_number){
                printf("This password is already taken!\n");
                return 0;
            }else{
                s_count = 0;
            }
        }
    }
//
    return 1;
}
int gmail_validation(char valid_gmail[30]){
//phyoe@gmail.com
    int check = 0;
    int e_point = 0;
    int s_check = 0;
    char format0[20] = {'@','g','m','a','i','l','.','c','o','m'};
    char format1[20] = {'@','y','a','h','o','o','.','c','o','m'};
    char format2[20] = {'@','o','u','t','l','o','o','k','.','c','o','m'};
    char format3[20] = {'@','a','p','p','l','e','.','c','o','m'};
    char format4[20] = {'@','z','a','n','e','.','c','o','m',};

    copy_two_char_array(fm[0].mail_format,format0);
    copy_two_char_array(fm[1].mail_format,format1);
    copy_two_char_array(fm[2].mail_format,format2);
    copy_two_char_array(fm[3].mail_format,format3);
    copy_two_char_array(fm[4].mail_format,format4);

    for(int i = 0; i<30; i++){
        if(valid_gmail[i] == '@'){
            check = i;
        }
        if(valid_gmail[i] == '\0'){
            e_point = i;
            break;
        }
    }
    if(check <= 4){
        printf("Your gmail is too short!\n");
        return 0;
    }else{
        int valid = 0;
        for(int i = 0; i<check ; i++){
            if((valid_gmail[i]>=48 && valid_gmail[i]<=57) || (valid_gmail[i]>=97 && valid_gmail[i]<=122)){
                valid ++;
            }
        }
        if(valid != check){
            printf("Your email is not in the right format!!\n");
            return 0;
        }
    }

    for(int j = 0; j<5 ; j++) {
        for (int i = check; i < e_point; i++) {
//            printf("%d\n",e_point);
            printf("%c",fm[j].mail_format[i - check]);
            if (valid_gmail[i] == fm[j].mail_format[i - check]) {
                s_check++;
            }
        }
        printf("\n%d %d\n",s_check,j);
        if(s_check == 10 && (j == 0 || j == 1 || j == 3)){
            printf("Your gmail is valid!\n");
            return -1;
        }
        if(s_check == 12 && j == 2){
            printf("Your gmail is valid!\n");
            return -1;
        }
        if(s_check == 9 && j == 4){
            printf("Your gmail is valid!\n");
            return -1;
        }
        s_check = 0;
    }

    printf("Your gmail is invalid!\n");
    return 0;
}
int strong_password(char test_password[30]){

    int size = size_of_array(test_password);
    int s_character = 0;
    int numbers = 0;
    int small_character = 0;
    int cap_character = 0;
    if(size <=6 ){
        printf("Your password is too short!\n");
        return 0;
    }
    for(int i = 0; i<size ; i++){
        if(test_password[i]>=33 && test_password[i]<=47){
            s_character++;
        }
        if(test_password[i]>=48 && test_password[i]<=57){
            numbers++;
        }
        if(test_password[i]>=64 && test_password[i]<=90){
            cap_character++;
        }
        if(test_password[i]>=97 && test_password[i]<=122){
            small_character++;
        }
    }
    if(cap_character<1){
        printf("It must contain at least one Capital letter!\n");
        return 0;
    }else if(small_character<1){
        printf("It must contain at least one small letter!\n");
        return 0;
    }else if(s_character<1){
        printf("It must contain at least one special character!\n");
        return 0;
    }else if(numbers<1){
        printf("It must contain at least one number!\n");
        return 0;
    }else {
        return 1;
    }
}
void transfer_money(){
    int r_test = -1;
    int p_test = 0;
    char receive_mail[30];
    char my_pass[30];
    unsigned int money = -1;
    int opt = -1;
    printf("This is transfer money sector!!\n");
    printf("This is your point %d\n",db[l_checking].u_point);
    while(r_test == -1 || r_test == l_checking) {
        printf("Please enter the email for the user you wish to transfer:");
        scanf(" %[^\n]", &receive_mail[0]);
        r_test = gmail_checking(receive_mail);
//        printf("%d\n",r_test);
//        printf("%d\n",l_checking);
        if(r_test == l_checking){

            printf("You can't send money to yourself:)\n");

        }else if(r_test != -1) {
            while(money == -1) {
                printf("Enter your desired amount:");
                scanf("%d", &money);
                if(money<=db[l_checking].u_point){

                    while(p_test == 0) {
                        printf("Type your password to proceed transaction!\n");
                        scanf(" %[^\n]", &my_pass[0]);
                        p_test = compare_two_char_array(db[l_checking].u_password,my_pass);
                        if(p_test == 1) {
                            db[l_checking].u_point = db[l_checking].u_point - money;
                            db[r_test].u_point = db[r_test].u_point + money;
                            printf("Transaction success!\n");
                            transaction_recording(l_checking,r_test,money);
//                            printf("%d",count);
                            record_data();
                            count = -1;
                        }else {
                            printf("Wrong password!\n");
                        }
                    }
                    while(opt !=0) {
                        printf("Press 0 to go back!\n");
                        scanf("%d", &opt);
                        if (opt == 0) {
                            my_privilege();
                        }else{
                            printf("Wrong Option!\n");
                        }
                    }
                }else{
                    printf("Insufficient amount!\n");
                    money = -1;
                }
            }
        }else{
            printf("Wrong email!\n");
        }
    }
}
void admin_pov(){

    printf("This is admin pov!\n");
    for (int i = 0; i<user_count; i++){
        printf("This is point for %s(user id %d) : %d\n",db[i].u_name,db[i].u_id,db[i].u_point);
    }

}

void record_data(){

    FILE *fptr;

    fptr = fopen("Database.txt","w");

    if(fptr == NULL){
        perror("Error creating file\n");
    }
    for(int i = 0; i<user_count ; i++){

        fprintf(fptr,"%d%c%s%c%s%c%s%c%llu%c%d%c%d",db[i].u_id,' ',db[i].u_email,' ',db[i].u_password,' ',db[i].u_name,' ',db[i].u_phone,' ',db[i].u_point,' ',db[i].u_massage);

//        printf("%d%s%s%s%d",db[i].u_id,db[i].u_email,db[i].u_password,db[i].u_name,db[i].u_point);
//            for (int z = 0; z <=tran_record_array[i]; z++)
//
//                for (int j = 0; j < 200; j++) {
//
//                fprintf(fptr, "%c", db[i].records[z].tran_record[j]);
//                if (db[i].records[z].tran_record[j] == '*') {
//                    break;
//                }
//
//            }
//
//        }
        for (int z = 0; z <=tran_record_array[i]; z++) {

            fprintf(fptr, "%s", db[i].records[z].tran_record);
        }

        fprintf(fptr,"%c",'\n');
    }
    fprintf(fptr, "Users feedbacks!%c",'\n');

        if (review_no > -1) {
        for (int s = 0; s <= review_no; s++) {
//            printf("%d\n",review_no);
            int p = 0;
            fprintf(fptr, "%d%c",d_accounts[s].word_counter , ' ');
            fprintf(fptr, "%s", d_accounts[s].reasons_delete);
            for(int i = 0 ; i<d_accounts[s].word_counter+1 ; i++){
                if(d_accounts[s].reasons_delete[i] == '\n') {
                    p = i;
//                    printf("This is p %d\n",p);
                    break;
                }
            }
            if(p == 0) {
                fprintf(fptr, "%c", '\n');
//                printf("%d\n", s);
            }
//            printf("%s",d_accounts[s].reasons_delete);
        }
    }
    fclose(fptr);
    printf("Success!\n");
}

void loading_data(){
    FILE *fptr;
    fptr = fopen("Database.txt","r");
    if(!fptr){
        perror("Can't load file\n");
    }
    int s = 0;
    for( s = 0; s<10; s++ ){
//        printf("\n%d\n",s);
        fscanf(fptr, "%d%s%s%s%llu%d%d", &db[s].u_id,&db[s].u_email[0],&db[s].u_password[0],&db[s].u_name[0],&db[s].u_phone,&db[s].u_point,&db[s].u_massage);

        for (int z = 0; z <=tran_record_array[s]; z++) {

            for (int j = 0; j < 200; j++) {

                fscanf(fptr, "%c", &db[s].records[z].tran_record[j]);
                if (db[s].records[z].tran_record[j] == '*') {
                    break;
                }

            }
//            printf("%s\n",db[s].records[z].tran_record);

        }
//        printf("%s",db[s].u_password);
//        printf("\n%d\n",tran_record_array[s]);
        if(db[s].u_point == 0){
            break;
        }
//        printf("\n%d\n",s);
        user_count++;
    }
    fgets(nothing, 500, fptr);
        for(int a = 0 ; a<=review_no ; a++ ) {
            fscanf(fptr, "%d",&d_accounts[a].word_counter);
            char c = fgetc(fptr);
            fgets(d_accounts[a].reasons_delete, d_accounts[a].word_counter+2, fptr);
            printf("%s",d_accounts[a].reasons_delete);
        }

    fclose(fptr);
}
void print_data(){
    printf("\nUsers: %d\n",user_count);
    for(int i = 0; i<user_count;i++){
        printf("%d%c%s%c%s%c%s%c%llu%c%d%c%d%c",db[i].u_id,'-',db[i].u_email,'-',db[i].u_password,'-',db[i].u_name,'-',db[i].u_phone,'-',db[i].u_point,'-',db[i].u_massage,'\n');
        for (int z = 0; z <=tran_record_array[i]; z++) {

            printf( "User %d - %s\n",i+1 , db[i].records[z].tran_record);
        }

    }
        for(int s = 0 ; s<=review_no ; s++) {
//            printf("C\n");
            printf("%d %s", d_accounts[s].word_counter , d_accounts[s].reasons_delete);

        }
    printf("%s",nothing);

}
void transaction_recording (int sender_id,int receiver_id,unsigned int amount){

    char send[5] = {'F','r','o','m','_'};
    char receive[4] = {'_','T','o','_'};
    char did[6] = {'_','s','e','n','t','_'};
    integer_to_char(amount);
    int amount_counter = charCounting(int_to_char_array_data);
    int send_name_counter = charCounting(db[sender_id].u_name);
    int receive_name_counter = charCounting(db[receiver_id].u_name);
    int i_count = 0;
    count = 0;
    for(int i = 0; i<100; i++){

        if(db[sender_id].records[i].tran_record[0] == 'F' || db[sender_id].records[i].tran_record[0] == 'R'){
            count++;
        }
    }
    tran_record_array[sender_id] = count;
    for(int i = 0; i<5 ; i++){
        db[sender_id].records[count].tran_record[i] = send[i];
        i_count++;
    }
    for(int i = 0; i<send_name_counter ; i++){
        db[sender_id].records[count].tran_record[i_count] = db[sender_id].u_name[i];
        i_count++;
    }
    for(int i = 0; i<4 ; i++){
        db[sender_id].records[count].tran_record[i_count] = receive[i];
        i_count++;
    }
    for(int i = 0; i<receive_name_counter ; i++){
        db[sender_id].records[count].tran_record[i_count] = db[receiver_id].u_name[i];
        i_count++;
    }
    for(int i = 0; i<6 ; i++){
        db[sender_id].records[count].tran_record[i_count] = did[i];
        i_count++;
    }
    for(int i = 0; i<amount_counter ; i++){
        db[sender_id].records[count].tran_record[i_count] = int_to_char_array_data[i];
        i_count++;
    }
    db[sender_id].records[count].tran_record[i_count] = '$';
    i_count++;
    get_time();
    for(int s = 0 ; s < 25 ; s++){
        db[sender_id].records[count].tran_record[i_count] = Ctime[0].c_time[s];
        i_count++;
    }
    db[sender_id].records[count].tran_record[i_count] = '*';
}

void integer_to_char(unsigned int value){

    FILE *fptr = fopen("100.txt","w");

    if(fptr==NULL){
        printf("file opening error at integer_to_char:\n");
    } else{
        fprintf(fptr,"%u",value);
    }
    fclose(fptr);

    FILE *fptr2 = fopen("100.txt","r");
    fscanf(fptr2,"%s",&int_to_char_array_data[0]);


}

int charCounting(char toCount[500]){
    int charCount = 0;
    for(int gcc=0; gcc<500 ; gcc++){

        if( toCount[gcc] == '\0'){
            break;
        } else{
            charCount++;
        }
    }
    return charCount;
}

void t_record_counting(){
    FILE *fptr = fopen("Database.txt","r");
    if(!fptr){
        perror("Error opening file\n");
    }
    char c = fgetc(fptr);
    int index = 0;

    while(!feof(fptr)){
        if( c != '\n'){
            if(c == '*'){
                tran_record_array[index]+=1;
            }
            c = fgetc(fptr);
        }else{
            index++;
            c = fgetc(fptr);
        }
    }
}
void review_record_counting(){
    FILE *fptr = fopen("Database.txt","r");
    if(!fptr){
        perror("Error opening file\n");
    }
    char c = fgetc(fptr);
    int index = 0;

    while(!feof(fptr)){
            if(c == '?'){
                review_no++;
            }
            c = fgetc(fptr);
    }
}
void admin_functions(int admin_id) {
    int opt = -1;
    printf("Welcome from admin functions!\n");
    if(db[admin_id].u_massage>0) {
        printf("You have got %d massages!\n", db[admin_id].u_massage);
    }

    while (opt == -1) {
    printf("Press 0 to get out!\nPress 1 to suspend and control users!\nPress 2 to view your massages\n");
    scanf("%d", &opt);
    if (opt == 0) {
        l_checking = -1;
        declaration();
    }else if(opt == 1){
        int number = -1;
        int choice = -1;
//        char test[10] = {'D','e','a','r',' ','u','s','e','r','-'};
        printf("This is users manipulation sector\n");
        printf("These are users' data\n");
        admin_pov();
        while(choice == -1) {
            printf("Press 0 to suspend users!\n");
            scanf("%d", &choice);
            if (choice == 0) {
                printf("Choose the id number of the user you want to suspend - ");
                scanf("%d", &number);
                printf("Enter your reasons of suspend\n");
                scanf(" %[^\n]", db[number - 1].texts[(db[number - 1].u_massage)].c_feed_back);
                db[number - 1].u_massage++;
            } else {
                printf("Wrong option!\n");
                choice = -1;
            }
        }

        int choice1 = 0;
        while (choice1 != 1){
            printf("Click 1 to go  back :");
            scanf("%d", &choice1);
            if (choice1 == 1) {
                admin_functions(admin_id);
            } else {
                printf("Try again!\n");
            }
        }

    }else if(opt == 2) {

        if (db[admin_id].u_massage == 0) {
            printf("You have no massage\n");
        } else {
        int point = (review_no + 1) - db[admin_id].u_massage;
        printf("%d users have deactivated their accounts for following reasons!\n", db[admin_id].u_massage);
        for (int s = point; s <= review_no; s++) {
            printf("%s", d_accounts[s].reasons_delete);
        }
            db[admin_id].u_massage = 0;
    }

        int choice = 0;
        while (choice != 1){
            printf("Click 1 to go  back :");
            scanf("%d", &choice);
            if (choice == 1) {
                admin_functions(admin_id);
            } else {
                printf("Try again!\n");
            }
        }
    }else {
        printf("Wrong option\n");
        opt = -1;
    }
    }
}
void ID_arrangement(int d_user_id){
    for(int i = d_user_id ; i<user_count ; i++){
        db[i].u_id = i;
    }
}

void Sorting_Deleting(int d_user_id){
    for(int i = d_user_id ; i<user_count ; i++){
        db[i-1].u_id = db[i].u_id;
        for(int j = 0 ; j<30 ; j++){
            db[i-1].u_email[j] = db[i].u_email[j];
        }
        for(int j = 0 ; j<30 ; j++){
            db[i-1].u_password[j] = db[i].u_password[j];
        }
        for(int j = 0 ; j<30 ; j++){
            db[i-1].u_name[j] = db[i].u_name[j];
        }
        db[i-1].u_phone = db[i].u_phone;
        db[i-1].u_point = db[i].u_point;
//        printf("%d ",tran_record_array[i-1]);
        tran_record_array[i-1] = tran_record_array[i];
//        printf("%d \n",tran_record_array[i-1]);
        for(int s = 0; s<=tran_record_array[i-1] ; s++){
            for(int o = 0 ; o<200 ; o++) {
                db[i - 1].records[s].tran_record[o] = db[i].records[s].tran_record[o];
            }
        }
//        review_counter[i-1] = review_counter[i];
//        for(int s = 0; s<=review_counter[i-1] ; s++){
//            for(int o = 0 ; o<500 ; o++) {
//                db[i - 1].reviews[s].complains[o] = db[i].reviews[s].complains[o];
//            }
//        }
    }
    printf("%d\n",db[user_count-1].u_point);
//    printf("U_count %d\n",user_count);
    db[user_count-1].u_point = 0;
    user_count--;
    for(int i = 0 ; i < 3 ; i ++){
        db[i].u_massage++;
    }
}
void get_time(){
    time_t tm;
    time(&tm);

    printf("Current time =%s\n", ctime(&tm));

    FILE *fptr = fopen("myTime.txt","w");
    fprintf(fptr,"%s", ctime(&tm));

    fclose(fptr);

    int index=0;
    int time_space_counter=0;

    Ctime[0].c_time[index]='_';
    index++;

    FILE *fptr2 = fopen("myTime.txt","r");
    char c = fgetc(fptr2);

    while (!feof(fptr2)){

        if( c==' '){

            time_space_counter++;

            if(time_space_counter == 1){
                Ctime[0].c_time[index]='!';
                c = fgetc(fptr2);
                index++;
            } else if(time_space_counter==4){
                Ctime[0].c_time[index]='@';
                c = fgetc(fptr2);
                index++;
            } else{
                Ctime[0].c_time[index]='_';
                c = fgetc(fptr2);
                index++;
            }

        } else{

            Ctime[0].c_time[index]=c;
            c = fgetc(fptr2);
            index++;

        }
    }
}
int Counting(unsigned long long int Count){
    int c = 0;
    while(Count != 0){
        Count /= 10;
        c ++;
    }
    return c;

}

int phone_validation(unsigned long long int Ph) {
    unsigned int standard = 959;
    int C = Counting(Ph);

    if (C == 12) {
        unsigned long long int first_three_digits = (Ph / 1000000000);
        unsigned long long int ninth_digit = (Ph / 100000000) % 10;

        if (first_three_digits == standard) {

            if (ninth_digit == 4 || ninth_digit == 7 || ninth_digit == 9) {
                printf("Valid\n");

            } else {
                printf("Not Valid\n");

                return 0;
            }

        } else {
            printf("Digits aren't valid:\n");
            return 0;
        }
    }
//9595010203
    if (C == 10) {
        unsigned long long int first_three_digit = (Ph / 10000000);
        unsigned long long int seventh_digit = (Ph / 1000000) % 10;

        if (first_three_digit == standard) {

            if (seventh_digit == 5) {
                printf("Valid\n");

            } else {
                printf("Not Valid\n");

                return 0;
            }

        } else {
            printf("Digits aren't valid:\n");
            return 0;
        }
    }
    if(C != 10 && C != 12){
        printf("Your phone number is nonsense\n");
        return 0;
    }

    int phone_counter = 0;
    for (int i = 0; i < user_count; i++) {

        if (Ph != db[i].u_phone) {

            phone_counter++;
        } else {
            return phone_counter;
            break;
        }

    }
    if (phone_counter == user_count) {
        return -1;
    }
return 0;
}