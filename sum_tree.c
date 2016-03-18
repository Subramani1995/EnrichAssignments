//to calculate the sum of all left leaves in a binary tree

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *left;
    struct node *right;
};
int lsum=0,rsum=0,k,sum=0;
struct node *root=NULL,*temp,*temp_right;
struct node *create(int);
int calculate(struct node*);
int sum_calc(struct node*);
int main()
{
    int i,ans,flag=0;
    struct node *root=create(38);
    int num=4;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=root;
    root->left=create(16);
    root->right=create(3);
    root->left->right=create(4);
    root->left->left=create(6);
    root->left->left->left=create(3);
    root->left->left->right=create(3);
    root->right->right=create(2);
    root->right->left=create(1);
    ans=calculate(temp);
    if(ans==0)
    {
        printf("not a sum tree");
    }
    else
    {
        printf("sum tree");
    }
}
struct node *create(int value)
{
    //allocation of memory for nodes
    root=(struct node*)malloc(sizeof(struct node));
    //inserting the values into node 
    root->val=value;
    root->left=NULL;
    root->right=NULL;
    return root;
}
int sum_calc(struct node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        return (sum_calc(node->left)+node->val+sum_calc(node->right));
    }
}
int calculate(struct node *node) 
{
    int left_sum,right_sum;
    if((node==NULL)||(node->left==NULL)||(node->right==NULL))
    {
        return 1;
    }
    left_sum=sum_calc(node->left);
    right_sum=sum_calc(node->right);
    if(node->val==(left_sum+right_sum))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
