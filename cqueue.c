   #include <stdio.h>
    #define MAX 5
    int q_arr[MAX];
    int rear = - 1;
    int front = - 1;


  int main()
  {
    int choice;
     while (1)
        {
            printf("1.insert an element to queue \n");
            printf("2.delete element from queue \n");
            printf("3.display all elements of queue \n");
            printf("4.exit \n");
            printf("enter the choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                insert();
                break;
                case 2:
                delete();
                break;
                case 3:
                display();
                break;
                case 4:
                exit(1);
                default:
                printf("Wrong choice \n");
            } 
        } 
    } 
    
    
    
  int isfull()
 {
 if((rear +1 ) % MAX == front)
    {   
     printf("Queue is full \n");
    }
  }
    
int isempty()
{
 if(front==rear)
  {
 printf("queue is empty")
  ;}
 }   
    
    int insert()
    {
        int add_item;
        if((rear +1 ) % MAX == front)
        printf("Queue is full \n");
        else
        {
            if (front == - 1)
            front = 0;
            printf("Inset the element in queue : ");
            scanf("%d", &add_item);
            rear = (rear + 1) % MAX;
            q_arr[rear] = add_item;
        }
    } 
     
   void delete()
    {
         int rem_item;
        if(front==rear)
        {
            printf("Queue empty \n");
            return ;
        }
        else
        {
           
            front = (front + 1) % MAX;
            rem_item = q_arr[front];
            return rem_item;
    
            printf("Element deleted from queue is : %d\n", q_arr[front]);
        }
    }
    int display()
    {
        int i;
        if (front == - 1)
            printf("Queue is empty \n");
        else
        {
            printf("Queue is : \n");

            for (i = front; i <= rear; i++)
                printf("%d ", q_arr[i]);
            printf("\n");
        }
    }
