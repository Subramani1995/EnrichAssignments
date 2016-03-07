//to add two numbers from linked list

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int value;
    struct node *next;
};
 struct node *first1=NULL,*first2=NULL,*ans_first=NULL;
 struct node *last1=NULL,*last2=NULL,*ans_last=NULL;
 struct node *ptr1,*ptr2,*ans_ptr;
int main()
{
    int num1,num2;
    scanf("%d%d",&num1,&num2);
    while(num1!=0)
    {
        struct node *ptr1=(struct node*)malloc(sizeof(struct node));
        ptr1->value=num1%10;
        if(first1==NULL)
        {
            first1=last1=ptr1;
            last1->next=NULL;
        }
        else
        {
            last1->next=ptr1;
            ptr1->next=NULL;
            last1=ptr1;
        }      
        num1=num1/10;
    }
    while(num2!=0)
    {
        struct node *ptr2=(struct node*)malloc(sizeof(struct node));
        ptr2->value=num2%10;
        if(first2==NULL)
        {
            first2=last2=ptr2;
            last2->next=NULL;
        }
        else
        {
            last2->next=ptr2;
            ptr2->next=NULL;
            last2=ptr2;
        }      
        num2=num2/10;
    }
    printf("answer in Linked List format\n");
    int a,carry=0,sum=0,k=0;
    ptr2=first2;
    for(ptr1=first1;ptr1!=last1;ptr1=ptr1->next)
    {
        struct node *ans_ptr=(struct node*)malloc(sizeof(struct node));
        a=(ptr1->value+ptr2->value);      
        ans_ptr->value=a%10+carry;
        sum=sum+(ans_ptr->value*(pow(10,k)));
        k++;
        carry=a/10;
       
        if(ans_first==NULL)
        {
            printf("%d-> ",ans_ptr->value);
            ans_first=ans_last=ans_ptr;
            ans_last->next=NULL;
        }
        else
        {
            printf("%d-> ",ans_ptr->value);
            ans_last->next=ans_ptr;
            ans_ptr->next=NULL;
            ans_last=ans_ptr;
        }
       
        ptr2=ptr2->next;
    }
    ans_last->value=last1->value+last2->value+carry;
    ans_last->next=NULL;  
    printf("%d\n",ans_last->value);
    sum=sum+(ans_last->value*(pow(10,k)));
    printf("sum is %d",sum);
    return 0;
}
