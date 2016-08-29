#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
}*front =NULL, *rear=NULL, *temp=NULL;

void push(int data);
void pop();
void display();


void main()
{
    int no, ch, e;
 
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    
 
  
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            push(no);
            rear->ptr=front;
            break;
        case 2:
            pop();
            break;
        
        case 5:
            exit(0);
        case 6:
            display();
            break;
        
        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}

void push(int data)
{
    if (front == NULL)
    {
       //front =(struct node *)malloc(1*sizeof(struct node)); 
       rear=(struct node *)malloc(1*sizeof(struct node));
       rear->ptr = NULL;
       rear->info = data;
       front =rear;
        
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        rear->ptr=temp;
        temp->ptr = NULL;
        temp->info = data;
        
        rear = temp;
    }
    
}
 
/* Display stack elements */
void display()
{
    struct node* tmp;
    tmp=front;
 
    if((rear == NULL)&&(front==NULL))
          return;
    
 
    while(tmp!= rear)
    {
        printf("%d ",tmp->info);
      tmp = tmp->ptr;
    }
    
    if(tmp == rear)
        printf("%d",tmp->info);
}
 
/* Pop Operation on stack */
void pop()
{
    temp=front;
 
    if (front == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    
    else if (front==rear) 
    {
       free(temp);
       rear=front=NULL;
       printf("list emptied\n");
       
    } 
    else {
        front=front->ptr;
        rear->ptr=front;
        temp->ptr=NULL;
        printf("\n Popped value : %d", temp->info);
        free(temp);
     }   
    
}
 




 

