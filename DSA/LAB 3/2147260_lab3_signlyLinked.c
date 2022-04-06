#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head;
struct node *last;

void insert_at_head();
void insert_at_last();
void insert_at_middle();
void delete_from_head();
void delete_from_last();
void delete_pos();
void peek();
void search_item();

int main()
{
	int choice , value;
	printf("\t\t\t\t******WELCOME TO SINGLY LINKED LIST PROGRAM******\n");
	while(1)
	{
		printf("\n Press 1 to insert at head\n");
		printf("Press 2 to insert at last\n");
		printf("Press 3 to insert in middle\n");
		printf("Press 4 to delete from head\n");
		printf("Press 5 to delete from last\n");
		printf("Press 6 to delete from middle\n");
		printf("Press 7 Display\n");
		printf("Press 8 search\n");
		printf("Your choice : ");
		scanf("%d" , &choice);
		switch(choice)
		{
			case 1:
				insert_at_head();
				break;
			case 2:
				insert_at_last();
				break;
			case 3:
				printf("Enter the number you want to enter : ");
				scanf("%d" , &value);
				insert_at_middle(value);
				break;
			case 4:
				delete_from_head();
				break;
			case 5:
				delete_from_last();
				break;
			case 6:
				delete_pos();
				break;
			case 7:
				peek();
				break;
			
			case 8:
				printf("\nEnter an item to search it from List\n");
    			scanf("%d", &value);
   			    search_item(value);
				break;
			default:
				printf("***OK BYE***");
				break;
		}
	}
}

void insert_at_middle(int value)
{
	printf("value : %d\n" , value);
	int i , position;
	struct node *node1 = (struct node*)malloc(sizeof(struct node));
	struct node *temp = head;
	struct node *p;
	//node1 = head;
	printf("\nEnter the position :\n ");
	scanf("%d" , &position);
	for(i = 0 ; i < position - 1  ; i++)
	{
		temp = temp->next;
	}
	p = temp->next;
	temp->next = node1;
	node1->next = p;
	node1->data = value;
}

void insert_at_head()
{
	int value;
	struct node *node1 = (struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		
		printf("\nEnter number : \t");
	    scanf("%d" , &value);
		node1->data = value;
		node1->next = NULL;
		head = node1;
		last = node1;
		printf("ITEM ADDED \t\n");
		
	}
	else
	{
		printf("Enter number : \t");
	    scanf("%d" , &value);
		node1->data = value;
		node1->next = head;
		head = node1;
		printf(" ITEM ADDED \t\n");
		printf("%d \t" , head->data);
		printf("%d \n" , last->data);
	}
}

void insert_at_last()
{
	int value;
	struct node *node1 = (struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("Enter number : \t");
	    scanf("%d" , &value);
		node1->data = value;
		node1->next = NULL;
		head = node1;
		last = node1;
		printf("\n\t ITEM ADDED \t\n");
	}
	else
	{
		printf("Enter number : \t");
	    scanf("%d" , &value);
	    last->next = node1;
		node1->data = value;
		node1->next = NULL;
		last = node1;
		printf("\n\t ITEM ADDED \t\n");
		printf("%d" , head->data);
		printf("%d" , last->data);
	}
}

void delete_from_head()
{
	struct node *t;
	if(head == NULL)
	{
		printf("\n*****UNDERFLOW*****\n");
	}
	else
	{
		t = head;
		head = head->next;
		free(t);
		printf("\n****ITEM REMOVED****\n");
		
	}
	
}

void delete_from_last()
{
	struct node *t;
	struct node *f;
	if(head == NULL)
	{
		printf("\n*****UNDERFLOW*****\n");
	}
	else
	{
		t = head;
		while(t->next->next != NULL)
		{
			t = t->next;
		}
		f = t->next;
		t->next = NULL;
		last = t;
		free(f);
		printf("\n****ITEM REMOVED****\n");
	}
	
}
void delete_pos()
{
       int i,pos;
       struct node *temp,*ptr;
       if(head==NULL)
       {
               printf("nThe List is Empty:n");
               exit(0);
       }
       else
       {
               printf("nEnter the position of the node to be deleted:t");
               scanf("%d",&pos);
               if(pos==0)
               {
                       ptr=head;
                       head=head->next ;
                       printf("nThe deleted element is:%dt",ptr->data  );
                       free(ptr);
               }
               else
               {
                       ptr=head;
                       for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                               if(ptr==NULL)
                               {
                                       printf("nPosition not Found:n");
                                       return;
                               }
                       }
                       temp->next =ptr->next ;
                       printf("nThe deleted element is:%dt",ptr->data );
                       free(ptr);
               }
       }
}


void peek()
{
	struct node *node1 = head;
	if(node1 == NULL)
	{
		printf("\n\t***LINKED LIST IS EMPTY***\t\n");
	}
	printf("The linked list is : ");
	while(node1 != NULL)
	{
		printf("%d->" , node1->data);
		node1 = node1->next;
	}
	printf("\n");
}

void search_item(int value)
{
    struct node *searchNode = head;
    int flag = 0;

    while(searchNode!=NULL)
    {
        if(searchNode->data==value)
        {
            printf("%d is present in this list.\n", value, searchNode);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }

    if(flag==0)
        printf("Item not found\n");

}
