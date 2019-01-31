/*
 Name:- Chinmay MAdhav Pingle
 Roll:- 203771
 Div :- G
 Ass :- 3
*/

/*
 Q) Write a C program to create student database using array of structures. Apply-
    Searching (linear and binary) and Sorting (bubble, insertion, selection) techniques.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
	int rollno;
	char name[25];
	char division;
	float percentage;
}stud;
void accept(struct student s[50],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
        printf("Enter the name of the student:-\n");
		scanf("%s",s[i].name);
		printf("Enter the roll no of the student:-\n");
		scanf("%d",&s[i].rollno);
		printf("Enter the division of the student:-\n");
	    scanf(" %c",&s[i].division);
	    printf("Enter the percentage of the student:-\n");
	    scanf("%f",&s[i].percentage);
	}
}
void display(struct student s[50],int n)
{
	int i;
	printf("Rollno\tName\tDivision\tPercentage\n");
	for(i=0;i<n;i++)
	{
		 printf("%d",s[i].rollno);
		 printf("\t");
		 printf("%s",s[i].name);
		 printf("\t");
		 printf(" %c",s[i].division);
		 printf("\t\t");
		 printf("%0.2f",s[i].percentage);
		 printf("\n");
	}
}
void linear(struct student s[50],int n,int num)
{
	int i;
	for(i=0;i<n;i++)
	{
	    if(s[i].rollno==num)
	    {
		  printf("\n %d is present at location %d. \n", num, i+1);
		break;
	    }
	}
	if(i==n)
	{
		printf("\n %d is not present \n",num);
	}
}
void binary(struct student s[50],int n,int num)
{
	int start,end,middle;
	start=0;
	end=n-1;
	middle=(start+end)/2;
	while(num!=s[middle].rollno && start <= end)
	{
		if(num > s[middle].rollno)
			start=middle+1;
		else
			end=middle-1;
		middle=(start+end)/2;
	}
	if(num==s[middle].rollno)
	printf("%d found at position %d\n",num,middle+1);
	if(start>end)
	printf("%d not found \n",num);
}
void bubble(struct student s[50],int n)
{
	int i,j;
	struct student temp;
	for (i = 0; i < n - 1; i++)
	{
		printf("\n");
		for (j = 0; j < n- i - 1; j++)
		{
			if (s[j].rollno > s[j + 1].rollno)
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}
void selection(struct student s[50],int n)
{
	int i=0, j=0, min=0;
	stud temp;
	for (i=0;i<(n-1);i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(s[min].rollno>s[j].rollno)
			{
				min=j;
			}
		}
		if(min!=i)
		{
			temp=s[i];
			s[i]=s[min];
			s[min]=temp;
		}
	}

}
void insertion(struct student s[50],int n)
{
	int i,j;
	struct student temp;
    for (i=1; i<n; i++)
    {
    	temp = s[i];
	    for(j=i-1 ; s[j].rollno > temp.rollno && j >= 0;j--)
	    {
	    	s[j + 1] = s[j];
	    }
	     s[j + 1] = temp;
	  }
}
int main()
{
	int n,num,c,c1;
	struct student s[50];
	printf("\n Enter the number of Students:-\n");
	scanf("%d",&n);
	accept(s,n);
	display(s,n);
	do{
	printf("\n\nEnter your choice:\n1.linear search\n2.Binary search\n"
			"3.Bubble sort\n4.Selection sort\n5.Insertion sort\n6.Exit\n\n");
	scanf("%d",&c);
	switch(c)
	{
	case 1:
		printf("\nEnter the roll number to search:");
		scanf("%d", &num);
		linear(s,n,num);
		break;

	case 2:
		printf("\nEnter the roll number to search:");
		scanf("%d", &num);
		bubble(s,n);
		binary(s,n,num);
		break;
	case 3:
		bubble(s,n);
		display(s,n);
		break;
	case 4:
		selection(s,n);
		display(s,n);
		break;
	case 5:
		insertion(s,n);
		display(s,n);
		break;
	case 6:
		break;
	}
	printf("\nDo you want to continue(Y=1/N=0)\n");
	scanf("%d",&c1);
	}while(c1!=0);
    return 0;
}


/*
o/p-



 Enter the number of Students:-
3
Enter the name of the student:-
abc
Enter the roll no of the student:-
1
Enter the division of the student:-
a
Enter the percentage of the student:-
88
Enter the name of the student:-
hhh
Enter the roll no of the student:-
3
Enter the division of the student:-
c
Enter the percentage of the student:-
66
Enter the name of the student:-
www
Enter the roll no of the student:-
2
Enter the division of the student:-
b
Enter the percentage of the student:-
77
Rollno	Name	Division	Percentage
1	abc	 a		88.00
3	hhh	 c		66.00
2	www	 b		77.00


Enter your choice:
1.linear search
2.Binary search
3.Bubble sort
4.Selection sort
5.Insertion sort
6.Exit

1

Enter the roll number to search:2

 2 is present at location 3. 

Do you want to continue(Y=1/N=0)
1


Enter your choice:
1.linear search
2.Binary search
3.Bubble sort
4.Selection sort
5.Insertion sort
6.Exit

2

Enter the roll number to search:1


1 found at position 1

Do you want to continue(Y=1/N=0)
1


Enter your choice:
1.linear search
2.Binary search
3.Bubble sort
4.Selection sort
5.Insertion sort
6.Exit

3


Rollno	Name	Division	Percentage
1	abc	 a		88.00
2	www	 b		77.00
3	hhh	 c		66.00

Do you want to continue(Y=1/N=0)
1


Enter your choice:
1.linear search
2.Binary search
3.Bubble sort
4.Selection sort
5.Insertion sort
6.Exit

4


Rollno	Name	Division	Percentage
1	abc	 a		88.00
2	www	 b		77.00
3	hhh	 c		66.00

Do you want to continue(Y=1/N=0)
1


Enter your choice:
1.linear search
2.Binary search
3.Bubble sort
4.Selection sort
5.Insertion sort
6.Exit

5


Rollno	Name	Division	Percentage
1	abc	 a		88.00
2	www	 b		77.00
3	hhh	 c		66.00


*/

