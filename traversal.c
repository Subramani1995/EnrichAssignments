#include <stdio.h>
#include <stdlib.h>
struct node
{
	int val;
	struct node *left;
	struct node *right;
};
struct node* create(int);
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);
void insert(int,int,struct node*);
int main()
{
	struct node *root=create(3);
	root->left=create(4);
	root->right=create(2);
	root->left->left=create(6);
	root->left->right=create(9);
	root->right->right=create(10);
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	int search,insert;
	printf("enter the value to be searched\n");
	scanf("%d",&search);
	printf("enter the value to be inserted:\n");
	scanf("%d",&insert);
	insert(search,insert,root);
	return 0;
}
struct node* create(int value)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->val=value;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->val);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{	
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->val);
	}	
}
void inorder(struct node *root)
{

	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}
}
void insert(int search,int insert,struct node *root)
{
	if(root!=NULL)
	{
		insert(search,insert,root->left);
		insert(search,insert,root->right);
		if(root->val==search)
		{
			if(root->left==NULL)
			{
				root->left->val=insert;
			}
			else
			{
				root->right->val=insert;
			}
		}
	}
}
