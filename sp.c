/*
CHinmay Pingle
Roll no.:-203771
Batch:-G4

Problem statement:-C program for sparse matrix realization and operations on it- Transpose,Fast Transpose.  
*/

#include<stdio.h>
typedef struct Sparse
{
int row,col,value;
}Sparse;

void Create(int A[5][5],int r, int c)
{
int i,j;
printf("\nCreate a %d x %d matrix:\n",r,c);
for(i=0; i<r; i++)
	{
	printf("Enter elements for row %d: ",i+1);
	for(j=0; j<c; j++)
		scanf("%d",&A[i][j]);
	}
}

void Display(int A[5][5],int r, int c)
{
int i,j;
printf("\nThe %d x %d is: \n",r,c);
for(i=0; i<r; i++)
	{
	for(j=0; j<c; j++)
		printf("%d ",A[i][j]);
	printf("\n");
	}
}

void MakeSparse(Sparse S[],int A[5][5],int r,int c)
{
int i,j,cnt=0;
S[0].row=r;
S[0].col=c;
S[0].value=0;
for(i=0; i<r; i++)
	{
	for(j=0; j<c; j++)
		{
		if(A[i][j]!=0)
			{
			cnt++;
			S[cnt].row=i;
			S[cnt].col=j;
			S[cnt].value=A[i][j];
			S[0].value++;
			}
		}
	}
}

void DisplaySparse(Sparse S[])
{
int i;
printf("\n\t Row \t Column  Value");
for(i=0;i<=S[0].value;i++)
	{
	printf("\nS[%d]\t %d \t %d \t %d",i,S[i].row,S[i].col,S[i].value);
	}
}

void Simple_Transpose(Sparse A[],Sparse B[])
{//A is original & B is Transpose
int n,i,j,CurrentB;
n=A[0].value;
B[0].col=A[0].row;
B[0].row=A[0].col;
B[0].value=n;
if(n>0)
{
CurrentB=1;
for(i=0;i<A[0].col;i++)
	{
	for(j=1;j<=n;j++)
		{
		if(A[j].col==i)		//Element is in current column
			{
			B[CurrentB].row=A[j].col;
			B[CurrentB].col=A[j].row;
			B[CurrentB].value=A[j].value;
			CurrentB++;
			}
		//CurrentB++;
		}
	//CurrentB++;
	}
}
printf("\nAfter Transpose:-");
DisplaySparse(B);
}

void Fast_Transpose(Sparse A[],Sparse B[])
{
            int row_terms[100],start_pos[100];
            int i,j,p;       

            int n = A[0].value;
            int numCols = A[0].col;
             
            B[0].row = numCols;
            B[0].col = A[0].row;
            B[0].value = n;
            if(n>0)
            {
                        for(i =0; i<numCols; i++)
                                                row_terms[i] = 0;

                        for(i=1; i<=n; i++)
                                                row_terms[A[i].col]++;

                        start_pos[0]=1;

                        for(i=1; i<numCols; i++)
                                                start_pos[i] = start_pos[i-1] + row_terms[i-1];

                        for(i=1; i<=n; i++)
                        {
                                                j = start_pos[A[i].col]++;
                                    		B[j].row = A[i].col;
                                                B[j].col = A[i].row;
                                       		B[j].value = A[i].value;
                        }
             }
            printf("\nThe Fast Transpose sparse matrix is:\n");
            printf("\nRow\tColumn\tValue\n");
            for(p=0; p<=A[0].value; p++)
            {
                        printf("%d\t", B[p].row);
                        printf("%d\t", B[p].col);
                        printf("%d\n", B[p].value);
            }
}

int main()
{
int choice,r,c,arr[5][5];
char ch;
Sparse S[6], ST[6];
printf("\nEnter number of rows: ");
scanf("%d",&r);
printf("\nEnter number of columns: ");
scanf("%d",&c);
do{
printf("\nChoose an option: \n1.Enter Matrix. \n2.Display Matrix and Compact Form \n3.Simple Transpose \n4.fast transpose");
printf("\nEnter Your Choice:");
scanf("%d",&choice);
switch(choice)
{
case 1: Create(arr,r,c);
		break;
case 2: Display(arr,r,c);
		MakeSparse(S,arr,r,c);
		printf("\nCompact Form-");
		DisplaySparse(S);
		break;
case 3: Simple_Transpose(S,ST);
		break;
case 4: Fast_Transpose(S,ST);
		break;
default:printf("\nWrong Choice Entered");
}
printf("\nDo you want to continue? Press y or n to continue.");
scanf(" %c",&ch);
}while(ch=='y'||ch=='Y');
return 0;
}

/*


mitwpu@c04l0914A:~$ ./a.out

Enter number of rows: 2

Enter number of columns: 2

Choose an option: 
1.Enter Matrix. 
2.Display Matrix and Compact Form 
3.Simple Transpose 
4.fast transpose
Enter Your Choice:1

Create a 2 x 2 matrix:
Enter elements for row 1: 1
2
Enter elements for row 2: 3
4

Do you want to continue? Press y or Y to continue.y

Choose an option: 
1.Enter Matrix. 
2.Display Matrix and Compact Form 
3.Simple Transpose 
4.fast transpose
Enter Your Choice:2

The 2 x 2 is: 
1 2 
3 4 

Compact Form-
	 Row 	 Column  Value
S[0]	 2 	 2 	 4
S[1]	 0 	 0 	 1
S[2]	 0 	 1 	 2
S[3]	 1 	 0 	 3
S[4]	 1 	 1 	 4
Do you want to continue? Press y or Y to continue.y

Choose an option: 
1.Enter Matrix. 
2.Display Matrix and Compact Form 
3.Simple Transpose 
4.fast transpose
Enter Your Choice:3

After Transpose:-
	 Row 	 Column  Value
S[0]	 2 	 2 	 4
S[1]	 0 	 0 	 1
S[2]	 0 	 1 	 3
S[3]	 1 	 0 	 2
S[4]	 1 	 1 	 4
Do you want to continue? Press y or Y to continue.y

Choose an option: 
1.Enter Matrix. 
2.Display Matrix and Compact Form 
3.Simple Transpose 
4.fast transpose
Enter Your Choice:4

The Fast Transpose sparse matrix is:

Row	Column	Value
2	2	4
0	0	1
0	1	3
1	0	2
1	1	4

Do you want to continue? Press y or Y to continue.^C
*/

