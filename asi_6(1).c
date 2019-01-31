
#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
};

int n=0;

int create_ll(struct node *h)
{

 char ch;
 struct node *ptr,*last;
 last=h;
 n=0;
 do
 {
 ptr=(struct node *)malloc(sizeof(struct node*));
 ptr->next=NULL;
 printf("\nEnter data in the node:");
 scanf("%d",&ptr->data);
 last->next=ptr;
 last=ptr;
 printf("Do you want to add more nodes(n/y):");
 scanf(" %c",&ch);
 n++;
 }while(ch=='y');
 return n;
}

void display_ll(struct node *h)
{
 printf("\nData in the Link List is:\n");
 struct node *ptr;
 if(h->next==NULL)
   printf("\nLink list is empty");
 else
 {
  ptr=h->next;
  while(ptr!=NULL)
  {
   printf("%d-->",ptr->data);
   ptr=ptr->next;
  }
 }
 printf("\n");
}

void add_node(struct node *h)
{
 int cnt=1,pos,f=1;
 struct node *ptr,*temp;
 ptr=(struct node *)malloc(sizeof(struct node*));
  printf("\nEnter Position to add node in between linklist:");
 scanf("%d",&pos);
 printf("\nEnter data in the node:");
 scanf("%d",&ptr->data);

 while(ptr!=NULL)
 {
  if(cnt==pos)
  {
   f=0;
   ptr->next=temp->next;
   temp->next=ptr;
   break;
  }
  else
  {
   temp=temp->next;
   cnt++;
  }
 }
 if(f==1)
 {printf("\nNo Node found\n");}
}

void rev_ll(struct node *h)
{
  struct node *p,*q,*r,*temp;
  p=NULL;
  q=h->next;
  while(q!=NULL)
  {
   r=q->next;
   q->next=p;
   p=q;
   q=r;
  }
  h->next=p;
}

void del_node(struct node *h)
{
 int cnt=1,f=1,pos;
 struct node *prev,*temp;
 printf("\nEnter Position to delete from linklist:");
 scanf("%d",&pos);
 temp=h->next;
 while(temp!=NULL)
 {
  if(cnt==pos)
  {
  f=0;
  prev->next=temp->next;
  temp->next=NULL;
  free(temp);
  break;
  }
  else
  {
   prev=temp;
   temp=temp->next;
   cnt++;
  }
 }
  if(f==1)
 {printf("\nNo Node found to delete\n");}
}

void sort_ll(struct node *h,int a)
{
 int i,j;
 n=a;
 struct node *prev,*curr,*temp;
 for(i=0;i<n;i++)
 {
  prev=h;
  curr=h->next;
  for(j=0;j<n-i-1;j++)
  {
   temp=curr->next;
   if(curr->data>temp->data)
   {
    prev->next=temp;
    curr->next=temp->next;
    temp->next=curr;
    prev=temp;
   }
   else
   {
    prev=curr;
    curr=curr->next;
   }
  }
 }
}

void merge_LL(struct node *h1,struct node *h2)
{
printf("Inside merge");
 struct node *h3,*t1,*t2,*t3;
 h3=(struct node *)malloc(sizeof(struct node*));
 h3->next=NULL;
 t1=h1->next;
 t2=h2->next;
 t3=h3;
 while(t1!=NULL&&t2!=NULL)
 {
   if(t1->data<t2->data)
   {
    t3->next=t1;
    t1=t1->next;
    t3=t3->next;
   }
   else
   {
    t3->next=t2;
    t2=t2->next;
    t3=t3->next;
   }
 }
 if(t1!=NULL)
   t3->next=t1;
 if(t2!=NULL)
   t3->next=t2;

 printf("\n1st linklist:\n");
 display_ll(h1);
 printf("\n2ed linklist:\n");
 display_ll(h2);
 printf("\nMerged linklist:\n");
 display_ll(h3);
}


int main()
{
 struct node *h,*h2;
 int ch,l1,l2;
 h=(struct node *)malloc(sizeof(struct node*));
 h->next=NULL;
 h2=(struct node *)malloc(sizeof(struct node*));
 h2->next=NULL;
 do
 {
 printf("\nEnter choice to perform operations on singly LinkList:");
 printf("\n1.Create LinkList");
 printf("\n2.Display LinkList");
 printf("\n3.Add in LinkList");
 printf("\n4.Delete from LinkList");
 printf("\n5.Reverse LinkList");
 printf("\n6.Sort LinkList");
 printf("\n7.Merge 2 LinkList");
 printf("\n8.Exit");
 printf("\nChoice:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:l1=create_ll(h);
         break;
  case 2:display_ll(h);
         break;
  case 3:add_node(h);
	 display_ll(h);
         break;
  case 4:del_node(h);
	 display_ll(h);
         break;
  case 5:rev_ll(h);
	 display_ll(h);
         break;
  case 6:sort_ll(h,l1);
	 display_ll(h);
         break;
  case 7:sort_ll(h,l1);
	 display_ll(h);
         printf("\nEnter second linklist:\n");
         l2=create_ll(h2);
	 display_ll(h2);
         sort_ll(h2,l2);
	 display_ll(h2);
         merge_LL(h,h2);
         break;
  case 8:break;
  default:printf("\nPls Enter correct choice!!!");
 }
 }
 while(ch!=8);
 return 0;
 }


/*output




Enter choice to perform operations on singly LinkList:
1.Create LinkList
2.Display LinkList
3.Add in LinkList
4.Delete from LinkList
5.Reverse LinkList
6.Sort LinkList
7.Merge 2 LinkList
8.Exit
Choice:1

Enter data in the node:1
Do you want to add more nodes(n/y):y

Enter data in the node:2
Do you want to add more nodes(n/y):y

Enter data in the node:3
Do you want to add more nodes(n/y):y

Enter data in the node:4
Do you want to add more nodes(n/y):n

Enter choice to perform operations on singly LinkList:
1.Create LinkList
2.Display LinkList
3.Add in LinkList
4.Delete from LinkList
5.Reverse LinkList
6.Sort LinkList
7.Merge 2 LinkList
8.Exit
Choice:2

Data in the Link List is:
1-->2-->3-->4-->

Enter choice to perform operations on singly LinkList:
1.Create LinkList
2.Display LinkList
3.Add in LinkList
4.Delete from LinkList
5.Reverse LinkList
6.Sort LinkList
7.Merge 2 LinkList
8.Exit
Choice:3

Enter Position to add node in between linklist:2

Enter data in the node:6

Data in the Link List is:
1-->6-->2-->3-->4-->

Enter choice to perform operations on singly LinkList:
1.Create LinkList
2.Display LinkList
3.Add in LinkList
4.Delete from LinkList
5.Reverse LinkList
6.Sort LinkList
7.Merge 2 LinkList
8.Exit
Choice:4

Enter Position to delete from linklist:1

Data in the Link List is:
6-->2-->3-->4-->

Enter choice to perform operations on singly LinkList:
1.Create LinkList
2.Display LinkList
3.Add in LinkList
4.Delete from LinkList
5.Reverse LinkList
6.Sort LinkList
7.Merge 2 LinkList
8.Exit
Choice:5

Data in the Link List is:
4-->3-->2-->6-->

Enter choice to perform operations on singly LinkList:
1.Create LinkList
2.Display LinkList
3.Add in LinkList
4.Delete from LinkList
5.Reverse LinkList
6.Sort LinkList
7.Merge 2 LinkList
8.Exit
Choice:6

Data in the Link List is:
2-->3-->4-->6-->

Enter choice to perform operations on singly LinkList:
1.Create LinkList
2.Display LinkList
3.Add in LinkList
4.Delete from LinkList
5.Reverse LinkList
6.Sort LinkList
7.Merge 2 LinkList
8.Exit
Choice:7

Data in the Link List is:
2-->3-->4-->6-->

Enter second linklist:

Enter data in the node:9
Do you want to add more nodes(n/y):y

Enter data in the node:10
Do you want to add more nodes(n/y):y

Enter data in the node:11
Do you want to add more nodes(n/y):y

Enter data in the node:12
Do you want to add more nodes(n/y):n

Data in the Link List is:
9-->10-->11-->12-->

Data in the Link List is:
9-->10-->11-->12-->
Inside merge
1st linklist:

Data in the Link List is:
2-->3-->4-->6-->9-->10-->11-->12-->

2ed linklist:

Data in the Link List is:
9-->10-->11-->12-->

Merged linklist:

Data in the Link List is:
2-->3-->4-->6-->9-->10-->11-->12-->

Enter choice to perform operations on singly LinkList:
1.Create LinkList
2.Display LinkList
3.Add in LinkList
4.Delete from LinkList
5.Reverse LinkList
6.Sort LinkList
7.Merge 2 LinkList
8.Exit
Choice:8


 */
