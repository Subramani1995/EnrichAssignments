//
//  main.c
//  enrich
//
//  Created by R.M.D. Engineering College  on 20/02/16.
//  Copyright © 2016 R.M.D. Engineering College . All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, const char * argv[]) {
 
    char exp[]="2*(((38+(5*8)+9)+7)+85)";
    char fix[16]={'\0'};
    int i,len,k=0,j;
    len=strlen(exp);
    for(i=0;i<len;i++)
    {
        if((exp[i]!='+')&&(exp[i]!='-')&&(exp[i]!='*')&&(exp[i]!='/')&&(exp[i]!='(')&&(exp[i]!=')'))
        {
        fix[k]=exp[i];
        exp[i]=0;
        k++;
        }
        else if(exp[i]==')')
        {
            exp[i]=0;
            for(j=i-1;j>=0;j--)
            {
                if(exp[j]=='(')
                {
                    exp[j]=0;
                    if((exp[j-1]!='(')&&(exp[j-1]!=')'))
                    {
                        fix[k]=exp[j-1];
                        k++;
                        exp[j-1]=0;
                    }
                    
                    break;
                }
                else if(exp[j]!=0)
                {
                    fix[k]=exp[j];
                    k++;
                    exp[j]=0;
                }
            }
        }
    }
    printf("%s\n",exp);
    for(i=0;i<k;i++)
    {
        printf("%c",fix[i]);
    }
    printf("\n");
    return 0;

}
