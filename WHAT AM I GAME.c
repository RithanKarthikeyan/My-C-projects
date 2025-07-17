#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int player=0,comp=0;

void rules()
{
    printf("\nRULES   : \n1.YOU WILL HAVE 3 CLUES \n2.IF YOU FIND ME CORRECTLY YOU HAVE 1POINT OR COMP WILL HAVE 1 POINT \n3.SPELL CORRECTLY");

}
void question()
{

    char ans[100];
    printf("\nclue no. 1 : iam black or red \nclue no.2 : i have antenna \nclue no.3 : i bite some times ");
    printf("\nYour ans : ");
    scanf("%s",ans);
    strlwr(ans);
    if (strcmp(ans,"ant")==0)
    {
        printf("\nYeah , you guessed corectly ! ");
        player++;

    }
    else
    {
        printf("\nWrong answer !!");
        comp++;
    }
    return;

}
void question2()
{
    char ans2[100];
    printf("\nclue no. 1 : iam yellow \nclue no.2 : monkey's love me \nclue no.3 : i grow in brunches ");
    printf("\nYour ans : ");
    scanf("%s",ans2);
    strlwr(ans2);
    if (strcmp(ans2,"banana")==0)
    {
        printf("\nYeah , you guessed corectly ! ");
        player++;

    }
    else
    {
        printf("\nWrong answer !!");
        comp++;
    }
    return;

}

int main()
{
    system("color F0");
    int ch;
    printf("Do you want to play the guessing game is yes press 1 : ");
    scanf("%d",&ch);
    while(getchar()!= '\n');
    if(ch==1)
    {
        printf("\nhii,Welcome to the game ");
        printf("\n");
        printf("\n");
        rules();
        printf("\n");
        printf("\n");
        question();
        question2();
        printf("\n---FINAL SCORES----\n");
        printf("\nPLAYER : %d",player);
        printf("\nCOMPUTER : %d",comp);
    }
    else
    {
        printf("BYE.....\n");
    }
    printf("\nEnter to exit ");

    getchar();
    return 0;
}
