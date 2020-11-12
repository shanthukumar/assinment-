#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *newNode;

void createNode(int d)
{

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->next = NULL;
}

void InsertNode(int d)
{
    createNode(d);
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node* current = head;
        while(current->next != NULL)
        {
            current = current ->next;
        }

        current->next = newNode;
    }

}

void InsertAtFirst(int d)
{
    createNode(d);

    newNode->next = head;
    head = newNode;
}
void InsertAtPosition(int pos,int d)
{
    createNode(d);
    int count = 1;
    struct Node *current = head;
    while(count!= pos-1)
    {
        current = current->next;
        count++;
    }
    printf("\ncount :%d\n",count+1);
    newNode->next = current->next;
    current->next = newNode;

}

void InsertAtMid(int d)
{
    int CountFast = 1;
    int CountSlow = CountFast/2;
    struct Node *current = head;
    while(current->next != NULL)
    {
        current = current->next;
        CountFast++;
        CountSlow = CountFast/2;
    }
    InsertAtPosition(CountSlow+1,d);
}
struct Node* SearchNode(int d)
{
    struct Node *current = head;
    if(head == NULL)
    {
      printf("\nList is Empty\n");
      return NULL;
    }
    while(current->data != d)
    {
        if(current->next == NULL)
            return NULL;
        else
            current = current->next;
    }

    return current;

}
void DeleteFirst()
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
}
void DeleteLast()
{
    struct Node *current = head;
    struct Node *ptr = head;
    while(current->next != NULL)
    {
        ptr = current;
        current = current->next;
    }
    ptr->next = NULL;

    free(current);
}
void DeleteNode(int d)
{
    struct Node *pos = SearchNode(d);
    if(pos == NULL)
        printf("No such value is present\n");
    else
    {
        struct Node *current = head;
        struct Node *ptr=head;
        while(current != pos)
        {
            ptr = current;
            current = current->next;
        }
        ptr->next = current->next;
        free(current);
    }

}
void print(){

    struct Node *current = head;

    int count=0;

    while(current != NULL){
       current = current->next;
       count++;

    }

    printf("\n Total no. of nodes is %d",count);

}
void RemoveDuplicates(struct Node* head)
{

	if (head == NULL)
		return;

	struct Node* current = head;


	while (current->next != NULL)
	{
		if (current->data == current->next->data)
		{
			struct Node* nextNext = current->next->next;
			free(current->next);
			current->next = nextNext;
		}
		else {
			current = current->next;
		}
	}
}
int maximum()
{
    int maximum=head->data;
    struct Node *z=head;
    while(z!=NULL)
    {
        if(maximum<z->data)
        {
            maximum=z->data;
        }
        z=z->next;
    }
    return maximum;
}
int minimum()
{
    int minimum=head->data;
    struct Node *z=head;
    while(z!=NULL)
    {
        if(minimum>z->data)
        {
            minimum=z->data;
        }
        z=z->next;
    }
    return minimum;
}
static void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}


void TraverseList()
{
    struct Node *ptr;
    ptr = head;
    printf("\n [ ");
    while(ptr!= NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf(" ] ");
}
int main()
{

    printf("\n*** Inserting node ***\n");
    InsertNode(10);
    InsertNode(20);
    InsertNode(30);
    TraverseList();

    printf("\n****Inserting at first position ******\n");
    InsertAtFirst(40);
    InsertAtFirst(50);
    InsertAtFirst(50);
    TraverseList();
    printf("\n****deleting duplicate elements in list printing unique elements in list***\n ");
     RemoveDuplicates(head);
     TraverseList();

    printf("\n******inserting at Position ******\n");
    InsertAtPosition(3,60);
    TraverseList();
    InsertAtPosition(5,70);
    TraverseList();

    printf("\n***** Search node ******\n");
    struct Node *pos = SearchNode(60);
    if(pos != NULL)
        printf("\n  value is :%d is present\n",pos->data);

    else
        printf("\nValue is not find\n");





    //Deletion Operation

    printf("\n***** Delete First Node ***\n");
    DeleteFirst();
    TraverseList();
    printf("\n***** Delete Last Node *****\n");
    DeleteLast();
    TraverseList();
    printf("\n***** Delete Last Node *****\n");
    DeleteLast();
    TraverseList();

    printf("\n***** Delete First Node ***\n");
    DeleteFirst();
    TraverseList();

    printf("\n***** Delete particular Node ****\n");
    DeleteNode(100);
    TraverseList();

    DeleteNode(200);
    TraverseList();

    DeleteNode(10);
    TraverseList();
 printf("\nLargest element of the list is : %d",maximum());
 printf("\n\nSmallest element of the list is : %d\n",minimum());
    print();
    reverse(&head);
    printf("\n*****Reversed Linked list****** \n");
    TraverseList();

}
