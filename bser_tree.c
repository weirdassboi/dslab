#include<stdio.h>
#include<stdlib.h>
typedef enum{false,true} boolean;
struct node
{
int data;
struct node* llink;
struct node* rlink;
};
typedef struct node* treeptr;
void insert(treeptr* root,int d)
{
        if((*root)==NULL)
        {
                *root=(treeptr)malloc(sizeof(struct node));
                (*root)->data=d;
                (*root)->llink=NULL;
                (*root)->rlink=NULL;
        return;
        }
        else if(d>((*root)->data))
        {
                insert(&((*root)->rlink),d);
        }
                else if(d<((*root)->data))
        {
                insert(&((*root)->llink),d);
        }
}
boolean search(treeptr root,int d)
{
        if(root==NULL)
                return false;
        else if(root->data==d)
                return true;
        else if(d>((root)->data))
                return search((root)->rlink,d);
        else if(d<((root)->data))
                return search(((root)->llink),d);
}
void inOrder(treeptr ptr)
{
        if(ptr)
        {
                inOrder(ptr->llink);
                printf("%d\t",ptr->data);
                inOrder(ptr->rlink);
        }
}
treeptr queue[10];
int front,rear;
void addq(treeptr ptr)
{
        queue[rear++]=ptr;
}
treeptr deleteq()
{
        if(front!=rear)
        return queue[front++];
        return NULL;
}
int main()
{
        treeptr root;
        root=NULL;
        int choice,data;
        while(1)
        {
		printf("\nEnter your choice :\n"); 
                printf("1.Insert\n2.InOrder Traversal\n3.Search\n4.Exit\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:printf("Enter data to be inserted: ");
                                scanf("%d",&data);
                                insert(&root,data);
                                break;
                        case 2:inOrder(root);
                                printf("\n");
                                break;
                        case 3:printf("Enter data to be searched for: ");
                                scanf("%d",&data);
                                if(search(root,data))
                                printf("Data found!\n");
                                else printf("Data not found!\n");
                                break;
                        case 4:exit(0);
                                default:printf("Invalid entry\n");
                }
        }
}

