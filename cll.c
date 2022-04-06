#include<stdio.h>
#include<stdlib.h>

void create_node();
void check_circular();
void free_node();


struct node
{
        int data;
        struct node* adr;
};

struct node *head=NULL;

void main()
{
create_node();
check_circular();
//display();
}

void create_node()
{
        struct node *prev=NULL,*curr=NULL;
        int i=0,n;
        printf("Enter the no of node\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                        curr=(struct node*)malloc(sizeof(struct node));
                        if(curr==NULL)
                        {
                        printf("memory is not allocated\n");
                        exit(0);
                        }
                        printf("Enter the data\n");
                        scanf("%d",&curr->data);
                        curr->adr=NULL;

                if(head==NULL)
                        head=prev=curr;

                else
                {
                prev->adr=curr;
                prev=prev->adr;
                }

                prev->adr=head;//to create circular list
                }
}

void check_circular()
{
        struct node *cir;
        cir=head;
        cir=cir->adr;
        while(cir->adr!=head)
                cir=cir->adr;
        if((cir->adr)==head)
                printf("list is circular\n");
        else
                printf("list is not circular\n");
}

void free_node()
{
        struct node *temp;
        while(head!=NULL)
        {
                temp=head;
                head=head->adr;
                free(temp);
        }
}

