#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node * prev;
struct node * next;
}*head, *last;

void createList(int n);
void displayList();
void insertAtBeginning(int data);
void delete_beginning();
void search_element(int data);

int main()
{
int n, data, choice=1;
head = NULL;
last = NULL;
printf("\nEnter the total number of nodes in list : "); // Input the number of nodes
scanf("%d", &n);
createList(n);
displayList();
printf("\n\nEnter data of first node : ");
scanf("%d", &data);
insertAtBeginning(data);
displayList();
delete_beginning();
printf("\n\nAFTER DELETION, THE DOUBLY LINKED LIST IS :\n\n");
displayList();
printf("\n\nEnter the element you want to search : ");
scanf("%d",&data);
search_element(data);
return 0;
}

void createList(int n)
{
int i, data;
struct node *newNode;
if(n >= 1)
{
head = (struct node *)malloc(sizeof(struct node));
printf("\nEnter data of node 1 : ");
scanf("%d", &data);
head->data = data;
head->prev = NULL;
head->next = NULL;
last = head;
for(i=2; i<=n; i++)
{
newNode = (struct node *)malloc(sizeof(struct node));
printf("\nEnter data of node %d : ", i);
scanf("%d", &data);
newNode->data = data;
newNode->prev = last;
newNode->next = NULL;
last->next = newNode;
last = newNode;
}}}

void displayList()
{
struct node * temp;
int n = 1;
if(head == NULL)
{
printf("\nList is empty.\n");
}
else
{
temp = head;
printf("\nTHE DOUBLY LINKED LIST IS :\n\n");

while(temp != NULL)
{
printf("%d\t", temp->data);
n++;

temp = temp->next;
}}}


void insertAtBeginning(int data)
{
struct node * newNode;
if(head == NULL)
{
printf("Error, List is Empty!\n");
}
else
{
newNode = (struct node *)malloc(sizeof(struct node));
newNode->data = data;
newNode->next = head;
newNode->prev = NULL;

head->prev = newNode;

head = newNode;
}
}
void delete_beginning()
{
struct node * temp;
temp = head;
head = head -> next;
head -> prev == NULL;
free(temp);
}
void search_element(int data)
{
struct node * temp = (struct node *)malloc(sizeof(struct node));
temp = head;
int pos = 0;
while(temp != NULL)
{
if(temp -> data == data)
{
printf("\n\nThe element %d is at index %d in the list", data,pos);
exit(0);
}
else
{
temp = temp ->next;
pos++;
}
}
printf("\n\nThe element %d is not found in the list",data);
}
