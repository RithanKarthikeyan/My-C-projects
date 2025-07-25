#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define FILE_NAME "accounts.txt"

typedef struct
{
    int accno;
    char name[50];
    float acc_bln;
}Account;

void create_account(){
    Account acc ;
    FILE *fp = fopen(FILE_NAME , "ab");
    printf("Enter account number : ");
    scanf("%d",&acc.accno);
    printf("Enter your name : ");
    scanf(" %[^\n]",&acc.name);
    printf("Enter your balance : ");
    scanf("%f",&acc.acc_bln);

    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);

    printf("Account created sucessfully ");



}
void display_account()
{
    Account acc;
    FILE *fp = fopen(FILE_NAME,"rb");
    while(fread(&acc,sizeof(Account),1,fp)){
    printf("Account number : %d \n",acc.accno);
    printf("Account NAME : %s\n",acc.name);
    printf("Account Balance %f ",acc.acc_bln);
    }
    fclose(fp);
}
void deposit()
{
    int acc_no, found =0;
    float amount ;
    Account acc;
    FILE *fp=fopen(FILE_NAME,"rb+");
    printf("Enter your acc no. : ");
    scanf("%d",&acc_no);
    while (fread(&acc,sizeof(Account),1,fp))
        {
            if(acc.accno==acc_no){
        printf("The amount you want to deposit : ");
        scanf("%f",&amount);
        acc.acc_bln+=amount;

        fseek(fp,-sizeof(Account),SEEK_CUR);
        fwrite(&acc,sizeof(Account),1,fp);
        printf("The amount is deposited sucessfully ");
        found = 1;
        break;

        }
        if(!found){
            printf("Account not found :(");
        }
        fclose(fp);


    }
}
void withdraw()
{
    int acc_no, found = 0;
    float withdraw_amm;
    Account acc;
    FILE *fp=fopen(FILE_NAME,"rb+");
    printf("Enter your acc no. : ");
    scanf("%d",&acc_no);

    while (fread(&acc,sizeof(Account),1,fp)){
        if(acc.accno==acc_no){
            printf("Enter the ammount you want to withdraw : ");
            scanf("%f",&withdraw_amm);
            if(withdraw_amm > acc.acc_bln){
                printf("INSUFFICIENT BALANCE :( ");

            }else{
                acc.acc_bln-=withdraw_amm;
                fseek(fp,-sizeof(Account),SEEK_CUR);
                fwrite(&acc,sizeof(Account),1,fp);
                printf("The amount is withdrewn :) ");


            }
            found=1;
            break;
        }
    }
        if(!found){
            printf("Account not found :( ");
        }
        fclose(fp);
}
void check_balance(){

    int acc_no, found = 0;
    Account acc ;
    FILE *fp = fopen(FILE_NAME,"rb");
    printf("Enter the Account no. : ");
    scanf("%d",&acc_no);

    while(fread(&acc,sizeof(Account),1,fp)){
        if(acc.accno==acc_no){
            printf("Your balance is : %f",acc.acc_bln);
            found = 1;
            break;
        }

    }
    if(!found){
        printf("Account not found :( ");
    }

}
int main(){

    int choice;
    do{
        printf("\n===== Simple Banking System =====\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Check Balance\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){

            case 1 : create_account(); break;
            case 2 : display_account();break;
            case 3 : deposit();break;
            case 4 : withdraw();break;
            case 5 : check_balance();break;
            case 6 : printf("EXIT");break;
            default: printf("INVALID INPUT");

        }

    }while(choice!=6);

    return 0;
}
