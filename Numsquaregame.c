# EnrichAssignments

THE GAME OF NUMBERS


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void print();
int main()
{
    int a[50][50]={0},x=3,y=3,count=0;
    a[1][1]=1;a[1][2]=5;a[1][3]=2;
    a[2][1]=4;a[2][2]=8;a[2][3]=3;
    a[3][1]=7;a[3][2]=6;a[3][3]=0;
    int i,j;
    printf("\n U-UP  D-DOWN  R-RIGHT  L-LEFT  Q-QUIT(pls use caps)\n");
    printf("\n WARNING:\nsince there is only one empty space, in each step,\n U can move only in 2 directions(options)\nIf u give a wrong direction the game will\n crash.. Be careful!\n");

    for(i=1;i<=3;i++)
    {
        printf("--------------\n");
        for(j=1;j<=3;j++)
        {
            if(a[i][j]==0)
            {
            printf("   | ");
            }
            else
            {
            printf(" %d | ",a[i][j]);
            }
        }
        printf("\n");
    }
    printf("--------------\n");
    char option;
    int flag=0;
    count=0;
    do
    {
        count++;
        scanf("%c",&option);
        switch(option)
        {

        case 'U':
        swap(&a[x][y],&a[x+1][y]);
        print(a);
        flag=sort(a);
        x++;
        break;

        case 'D':
        swap(&a[x][y],&a[x-1][y]);
        print(a);
        flag=sort(a);
        x--;
        break;

        case 'R':
        swap(&a[x][y],&a[x][y-1]);
        print(a);
        flag=sort(a);
        y--;
        break;

        case 'L':
        swap(&a[x][y],&a[x][y+1]);
        print(a);
        flag=sort(a);
        y++;
        break;

        default:
        break;

        }

        if(flag==1)
        {
            break;
        }
    }while(option!='Q');

    if(option=='Q')
    {
        printf("\nSORRY YOU GAVE UP :-( \n");
    }
    if(flag==1)
    {
        printf("\nYOU HAVE SUCCESSFULLY SORTED:-)\n");
        printf("YOU TOOK %d STEPS TO FINISH OFF.. GREAT JOB!!\n",(count/2)+1);
    }
return 0;
}
int swap(int *e,int *f)
{
    int temp;
    temp=*e;
    *e=*f;
    *f=temp;
    return 0;
}
void print(int p[][50])
{
    int i,j;
    system("cls");
    printf("\n U-UP  D-DOWN  R-RIGHT  L-LEFT  Q-QUIT(pls use caps)\n");

    for(i=1;i<=3;i++)
    {
        printf("--------------\n");
        for(j=1;j<=3;j++)
        {
            if(p[i][j]==0)
            {
                printf("   | ");
            }
            else
            {
                printf(" %d | ",p[i][j]);
            }
        }
        printf("\n");
    }
    printf("--------------\n");
}

int sort(int a[][50])
{
    int i,j,k=1,flag=0,x,y;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            if(a[i][j]==1)
            {
              x=i;
              y=j;
              break;
            }
        }
    }

    for(i=x;i<=3;i++)
    {
        for(j=y;j<=3;j++)
        {
            if(a[i][j]==k)
            {

                flag=1;
                k++;
                if(k==9)
                break;
            }
            else
            {
                flag=0;
                break;
            }
        }
     }
     return flag;
}



