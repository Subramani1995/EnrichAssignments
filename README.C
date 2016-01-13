# EnrichAssignments
program using SLEEP


#include<stdio.h>
#include<unistd.h>
#include<Windows.h>
int main()
{
int i;
char a[12]={'H','A','P','P','Y',' ','P','O','N','G','A','L'};
for(i=0;i<=11;i++)
  {
    Sleep(500);
    printf("%c",a[i]);
  }
return 0;
}
