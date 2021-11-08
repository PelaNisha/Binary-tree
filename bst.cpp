// binary search tree
#include<stdio.h>
#include<malloc.h>

struct bstnode{
	int info;
	struct bstnode *left;
	struct bstnode *right;
};

typedef struct bstnode node;
//node *root = NULL;

node *getnode(int item)
{
	node *nn;
		 nn= (node*)malloc(sizeof(node));
		 nn->info = item;
		nn->left =NULL;
		nn->right = NULL;
		return nn;
}
node *insert(node *root,int item)
{
	if(root==NULL)
	{
		return getnode(item);
		
		printf("Added in root null\n");
		
	}else
	{
		if(item<root->info)
		{
			root->left = insert(root->left, item);
		}else
		{
			root->right = insert(root->right, item);
		}
	}
	return root;
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d  ", root->info);
		inorder(root->right);
	}
	
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d ", root->info);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->info);
	}
}
int main()
{
	int i , a;
	node *root = NULL;
//	root = insert(root, 10);
//	root = insert(root, 20);
//	root = insert(root, 5);
//	 inorder(root);
	do{
		printf("enter the option\n1.insert\n2.inorder traversal\n3.Preorder traversal\n4.postorder traversal\n");
		scanf("%d", &a);
		
		switch(a){
			case 1:
				int x;
				printf("Enter the number\n");
				scanf("%d", &x);
				root = insert(root, x);
				break;
			case 2:
				inorder(root);
				printf("\n");
				break;
			
			case 3:
				preorder(root);
				printf("\n");
				break;
			case 4:
				postorder(root);
				printf("\n");
				break;
						
					
		}
	}while(i !=2);
}
