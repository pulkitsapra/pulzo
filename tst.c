#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
}*front =NULL, *rear=NULL, *temp=NULL;

void push(int data);
int pop();
void display();

int count =0;

void main()
{
    int no, i , k, elts,buf ,counter=1 ;
    printf("Please enter the values on n and i: ");
    scanf("%d%d",&no,&i);
    int m=i;
    
    printf("\nThe removal of sequence is as follows -\n");
    
    
    
    
    for(i=0;i<no;++i)
        {
          push(i+1);
        }

    elts=number_of_elts();
     
    while(count>1)
    {
       for(k=1;k<m;++k){
         buf=pop();
         count--;
         push(buf);
    }
     
       
       
       
       printf("\n");
       
       if(count==no)
          printf("[%d].Firstly,the person at position %d is removed", counter++, pop());
       else if (count==1)
          printf("[%d].Finally,the person at position %d is removed", counter, pop());
       else
          printf("[%d].Then,the person at position %d is removed",counter++, pop());
                
       count--; 
          
        
     }       
    
    printf("\n\nHence the person at position %d surives",front->info);
    

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
    count++;
    
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
int pop()
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
       //count--;
       rear=front=NULL;
       //printf("list emptied\n");
       return;
    } 
    else {
        front=front->ptr;
        temp->ptr=NULL;
        //count--;
        return(temp->info);
        //printf("\n Popped value : %d", temp->info);
        free(temp);
     }   
    
    
}

int number_of_elts(){
 return count;
}
 




 

