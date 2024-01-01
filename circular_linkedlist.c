#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
	
};
struct node* head,*newnode,*temp;

int main()
{ int choice;
	head=0;
do
	{
	
	newnode=(struct node*)malloc(sizeof(struct node));

    printf("enter data");
    scanf("%d",&newnode->data);
    if(head==0)
    {head=temp=newnode;
	}
	else
	{ temp->next=newnode;
	temp=newnode;
		
	}
	temp->next=head;
	printf("do you want to add new node 0 for no, 1 for yes");
	scanf("%d",&choice);
}while(choice==1);
temp=head;
while(temp->next!=head)
{
	printf("%d",temp->data);
	temp=temp->next;
}
printf("%d\t",temp->data);
	
}