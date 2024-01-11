#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
int checkwin(char, char);
char computerchoise(int );
void winner(char, char);
int main()
{
    int s;
    char choise1,choise2;
    printf("\n   Welcome to Rock-Paper-Scissors   \n");
    printf("\n   R for rock, P for paper, S for scissors   \n");
    printf("\n   Player, your choise:  ");
    scanf("%c",&choise1);
    choise1=toupper(choise1);
    while(choise1 != 'R' && choise1 != 'P' && choise1 != 'S'){
        printf("   Player, choose again: ");
        scanf("%c",&choise1);
    }
    srand(time(0));
    s=(rand()%3)+1;
    choise2=computerchoise(s);
    printf("\n");
    printf("  Computer's choise: %c  ",choise2);
    if(checkwin(choise1,choise2)==0){
        printf("\n");
        printf("  Draw !  ");
    }else{
        printf("\n");
        winner(choise1,choise2);
    }
    return 0;
}
int checkwin(char choise1, char choise2)
{
    if(choise1==choise2){
        return 0;
    }else{
        return 1;
    }
}
char computerchoise(int s)
{
    char c;
    if(s==1){
        c='R';
    }
    if(s==2){
        c='P';
    }
    if(s==3){
        c='S';
    }
    return c;
}
void winner(char choise1, char choise2)
{
    if(choise1=='R'){
        if(choise2=='P'){
            printf("\n");
            printf("  Computer has won!  ");
        }
        if(choise2=='S'){
            printf("\n");
            printf("  Player has won!  ");
        }
    }
    if(choise1=='P'){
        if(choise2=='R'){
            printf("\n");
            printf("  Player have won!  ");
        }
        if(choise2=='S'){
            printf("\n");
            printf("  Computer have won!  ");
        }
    }
    if(choise1=='S'){
        if(choise2=='R'){
            printf("\n");
            printf("  Computer have won!  ");
        }
        if(choise2=='P'){
            printf("\n");
            printf("  Player have won!  ");
        }
    }
}
