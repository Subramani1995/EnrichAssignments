//to calculate the sum of all left leaves in a binary tree

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *left;
    struct node *right;
};
int sum=0,k;
struct node *root;
struct node *create(int);
int calculate(struct node*,int);
int main()
{
    int i,ans;
    struct node *root=create(4);
    //creating root node and storing that value of root in variable K
    int k=root->val;
    //creating a binary tree
    root->left=create(3);
    root->right=create(5);
    root->left->right=create(9);
    root->left->left=create(2);
    root->right->right=create(10);
    root->left->left->left=create(10);
    ans=calculate(root,k);
    printf("sum of left leaves is %d\n",ans);
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
int calculate(struct node *node,int k)
{
     int flag;
     if (node == NULL)  //check for empty tree
     {
         return 0;
     }
          
     if((node->left==NULL)&&(node->right==NULL))
     {
         //calculating the sum of all left leaves
         sum=sum+(node->val);    
     }
     //calling the function recursively to traverse all the nodes of "left sub trees"
     calculate(node->left,k);  
     //no need to traverse "right sub tree" nodes--condition check_whether node value matches with root value-if yes no need to traverse
     if(node->val!=k)
     {
        calculate(node->right,k);
     }
     return sum;
}
