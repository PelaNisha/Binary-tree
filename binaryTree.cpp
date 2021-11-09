// binary search tree

#include<stdio.h>
#include<malloc.h>
struct bnode{
	int info;
	struct bnode *left;
	struct bnode *right;
};
typedef struct bnode node;
node *root = NULL;

// Create a new Node
 node *createNode(int value) 
 {
 	node *newNode;
	newNode = (node*)malloc(sizeof( node));
  newNode->info = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

node *search(int key, node *leaf)
{
	if(leaf!=0)
	{
		if(key == leaf->info)
		{
			printf("%d is present\n", leaf->info);
			return leaf;
		}else if(key<leaf->info)
		{
			return search(key, leaf->left);
		}else 
		{
			return search(key , leaf->right);
		}
		
	}
	return NULL;
}

node *insert(node *root, int x)
{
//	node *newnode;
//	newnode = (node*)malloc(sizeof(node));
	
	if(root==NULL)
	{
		return createNode(x);
	}
	if(root->info == x){
		
		node *root;
		root = (node*)malloc(sizeof(node));
		root->info = x;
		root->left = NULL;
		root->right= NULL;
//		root = nn;
		return root;
	}else
	if(root->info>x)
	{
		root->left = insert(root->left, x);
	}else
	
		if(root->info<x)
		{
			root->right = insert(root->right, x);
		}
	
	}


void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ", root->info);
		inorder(root->right);
	}else{
		return ;
	}
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d ", root->info);
		preorder(root->left);
		preorder(root->right);
	}else
	{
		return ;
	}
}

void postorder(node *root)
{
	if(root!=NULL)
	{	
		preorder(root->left);
		preorder(root->right);
		printf("%d ", root->info);
	}else
	{
		return ;
	}
}


int main()
{
	int a, i, b;
	node *root = NULL;
	do
	{
		printf("enter the options:\n1.insert\n2.preorder traverse\n3. post order\n4. in order\n5. search\n");
		scanf("%d", &a);

		switch(a){
			case 1:
				printf("enter the element\n");
				scanf("%d", &b);
				root = insert(root, b);
				break;
			case 2:
    			preorder(root);
    			printf("\n");
				break; 	
			case 3:
				postorder(root);
				printf("\n");
				break;	
			case 4:
				inorder(root);
				printf("\n");
				break;		
			case 5:
				int x;
				printf("enter the element to search\n");
				scanf("%d", &x);
				root = search(x, root);	
				break;
		}
	}while(i!=2);
}
