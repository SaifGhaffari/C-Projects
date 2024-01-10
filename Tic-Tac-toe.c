#include<stdio.h>
void printBoard(char [9]);
int checkWin(char [9]);
int checkWinner(char [9]);
int checkVoid(char [9]);
int main()
{
    char name1[10],name2[10],c,d;
    char a[9]={' ', ' ', ' ',
               ' ', ' ', ' ',
               ' ', ' ', ' '};
    int x,y,z,w;
    printf("\n   Welcome to Tic-Tac-Toe   \n");
    printf("\n   Player1 choose your name:");
    scanf(" %s",&name1);
    printf("\n   %s, x or o: ",name1);
    scanf("%c");
    scanf("%c",&c);
    while(c!='x' && c!='o')
    {
        printf("   choose x or o :   ");
        scanf("%c");
        scanf("%c",&c);
    }
    printf("\n   Player2 choose your name:");
    scanf("%s",&name2);
    if(c=='x'){
        d='o';
    }
    if(c=='o'){
        d='x';
    }
    do
    {
        for(int i=0;i<4;i++){
            if(checkWin(a)==1){
                break;
            }else if(checkVoid(a)==1){
                break;
            }else{
                printBoard(a);
                printf("%s choose a number between 1 and 9: ",name1);
                scanf("%d",&x);
                printf("%s choose a number between 1 and 9: ",name2);
                scanf("%d",&y);
                while(x==y){
                    printf("%s choose a number between 1 and 9: ",name1);
                    scanf("%d",&x);
                    printf("%s choose a number between 1 and 9: ",name2);
                    scanf("%d",&y);
                }
                x--;
                y--;
                a[x]=c;
                if(checkWin(a)==1 && checkWinner(a)==1){
                    break;
                }else{
                    a[y]=d;
                }
            }
        }
    } while (checkWin(a)==0 && checkVoid(a)!=1);
    printBoard(a);
    if(checkWinner(a)==1){
        if(c=='x'){
            printf("   congratulations, %s, you have won!   ",name1);
        }if(d=='x'){
            printf("   congratulations %s, you have won!   ",name2);
        }
    }else if(checkWinner(a)==0){
        if(c=='o'){
            printf("   congratulations %s, you have won!   ",name1);
        }if(d=='o'){
            printf("   congratulations %s, you have won!   ",name2);
        }
    }else{
        printf("   It's a draw   ");
    }
    return 0;
}
void printBoard(char a[9])
{
    printf(" %c | %c | %c \n",a[0],a[1],a[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n",a[3],a[4],a[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n",a[6],a[7],a[8]);
}
int checkWin(char a[9])
{
    if(a[0]==a[1] && a[0]==a[2] && a[0]!=' '){
        return 1;
    }else if(a[3]==a[4] && a[3]==a[5] && a[3]!=' '){
        return 1;
    }else if(a[6]==a[7] && a[6]==a[8] && a[6]!=' '){
        return 1;
    }else if(a[0]==a[4] && a[0]==a[8] && a[0]!=' '){
        return 1;
    }else if(a[2]==a[4] && a[2]==a[6] && a[2]!=' '){
        return 1;
    }else if(a[0]==a[3] && a[0]==a[6] && a[0]!=' '){
        return 1;
    }else if(a[1]==a[4] && a[1]==a[7] && a[1]!=' '){
        return 1;
    }else if(a[2]==a[5] && a[2]==a[8] && a[2]!=' '){
        return 1;
    }
    return 0;
}
int checkWinner(char a[9])
{
    int y;
    if(a[0]==a[1] && a[0]==a[2] && a[0]=='x'){
        y=1;
    }else if(a[3]==a[4] && a[3]==a[5] && a[3]=='x'){
        y=1;
    }else if(a[6]==a[7] && a[6]==a[8] && a[6]=='x'){
        y=1;
    }else if(a[0]==a[4] && a[0]==a[8] && a[0]=='x'){
        y=1;
    }else if(a[2]==a[4] && a[2]==a[6] && a[2]=='x'){
        y=1;
    }else if(a[0]==a[3] && a[0]==a[6] && a[0]=='x'){
        y=1;
    }else if(a[1]==a[4] && a[1]==a[7] && a[1]=='x'){
        y=1;
    }else if(a[2]==a[5] && a[2]==a[8] && a[2]=='x'){
        y=1;
    }else if(a[0]==a[1] && a[0]==a[2] && a[0]=='o'){
        y=0;
    }else if(a[3]==a[4] && a[3]==a[5] && a[3]=='o'){
        y=0;
    }else if(a[6]==a[7] && a[6]==a[8] && a[6]=='o'){
        y=0;
    }else if(a[0]==a[4] && a[0]==a[8] && a[0]=='o'){
        y=0;
    }else if(a[2]==a[4] && a[2]==a[6] && a[2]=='o'){
        y=0;
    }else if(a[0]==a[3] && a[0]==a[6] && a[0]=='o'){
        y=0;
    }else if(a[1]==a[4] && a[1]==a[7] && a[1]=='o'){
        y=0;
    }else if(a[2]==a[5] && a[2]==a[8] && a[2]=='o'){
        y=0;
    }
    return y;
}
int checkVoid(char a[9])
{
    int i,c=0;
    for(i=0;i<9;i++){
        if(a[i]==' '){
            c++;
        }
    }
    return c;
}
