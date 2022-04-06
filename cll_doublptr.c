#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link; 
};

void Display(struct node **);
void cll_create(struct node **);
void check_cll_sll(struct  node**);

int main()
{
	struct node *head=NULL;

		 	cll_create(&head);
			check_cll_sll(&head);
			Display(&head);
}

void cll_create(struct node **head)
{
	struct node *newnode,*temp=NULL;
	int i,l;
	printf("Enter the no of node in the list: \n");
	scanf("%d",&l);
	for(i=1;i<=l;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data %d\n",i);
	 	scanf("%d",&newnode->data);
		newnode->link=NULL;

		if((*head)==NULL)//check null condition
		{
			(*head)=temp=newnode;
		}
		else
		{
			temp->link=newnode;
			temp=newnode;
		}
		temp->link=(*head);//to make circular link list
	}
}

void check_cll_sll(struct node **head)
{
	if((*head)==NULL)
	{
		printf("Circular list is empty\n");
        }
	else
	{
       		struct node *temp_node=(*head);
      		while(temp_node->link!=(*head))
       		{
	   		printf("%d\t",temp_node->data);
	                temp_node=temp_node->link;
	         }
		printf("%d\n",temp_node->data);
		if((temp_node)->link==(*head))
		{
			printf("List is a Circular single list*************************\n");
	      	}
		else
    		{
			printf("List is not a Circular single list\n");
		}
	}
	
}
void Display(struct node **head)
{
	struct node *ptr=NULL;
 	ptr=*head;
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while((ptr->link)!=*head)
		{
 			printf("%d\t",ptr->data);
                         ptr=ptr->link;
 		}
		printf("%d\n",ptr->data);
	}

}


