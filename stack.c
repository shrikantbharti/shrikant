#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 100
int top=-1;
int top1=-1;
char st[max];
char s1[max][max];
int isempty()
{
      if(top==-1)
            return 1;
      else
            return 0;
}

int isfull()
{
      if(top==max-1)
            return 1;
      else
            return 0;
}

void push(char item)
{
      if(isfull()==0)
      {
            top++;
            st[top]=item;
      }
      else
      {
            printf("\nStack Overflow");
      }
}

char pop()
{
      char e;
      if(isempty()==0)
      {
            e=st[top];
            top--;
            return e;
      }
      else
      {
            return 'x';
      }

}

void display()
{
      int i;
      for(i=top;i>=0;i--)
      {
            printf(" %c",st[i]);
            printf("\n");
      }
}
int isp(char ch1)
{
      if(ch1=='^')
      {
            return 3;
      }
       if(ch1=='*'||ch1=='/')
      {
            return 2;
      }
       if(ch1=='+'||ch1=='-')
      {
            return 1;
      }
       if(ch1=='(')
      {
            return 0;
      }
}
int icp(char ch)
{
      if(ch=='^')
      {
            return 4;
      }
       if(ch=='*'||ch=='/')
      {
            return 2;
      }
       if(ch=='+'||ch=='-')
      {
            return 1;
      }
       if(ch=='(')
            return 5;
}

void postfix(char inexp[max])
{
      int j,k;
      char token,postexp[max];
      j=0;
      k=0;
      token=inexp[j];

      while(token!='\0')
      {
            if(isalnum(token))
            {
                  postexp[k]=inexp[j];
                  k++;
            }
            else if (token=='(')
            {
                  push('(');
            }
            else if(token==')')
            {
                  while((token=pop())!='(')
                  {
                        postexp[k]=token;
                        k++;
                  }
            }
            else if(!isalpha(token))
            {
            	push(token);
            }
            else
            {
                  while(isempty()==1 && isp(st[top])>=icp(token))
                  {
                        postexp[k]=pop();
                        k++;
                  }
            }
          j++;
          token=inexp[j];
        }
        while(isempty()!=1)
        {
            postexp[k]=pop();
            k++;
        }
        postexp[k]='\0';
        printf("%s",postexp);
}
void push1(char s2[max])
{
	if(top1==(max-1))
		printf("Stack is full");
	else
	{
		top1++;
		strcpy(s1[top1],s2);
	}
}
void pop1(char temp[max])
{
	if(top1==-1)
		printf("Stack is empty");
	else
	{
		strcpy(temp,s1[top1]);
		top1--;
	}
}
void prefix(char pexp[max])
{
	int i;
	char temp[max],op1[max],op2[max],pre[max];
	for(i=0;pexp[i]!='\0';i++)
	{
		//printf("in for");
		if(isalpha(pexp[i]))
		{
			temp[0]=pexp[i];
			temp[1]='\0';
			push1(temp);
		//printf("in if");
		}
		else
		{
		//	printf("in else");
			pop1(op1);
			pop1(op2);
			temp[0]=pexp[i];
			temp[1]='\0';
			strcpy(pre,temp);
			strcat(pre,op2);
			strcat(pre,op1);
		
		}
	}
	//printf("out for");
	printf("\n Ans:%s",pre);
}
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
    int ch,l;
    char it,poped,exp[max];
    printf("Menu:");
    printf("\n1.Push the element into stack\n2.Pop the element\n"
    		  "3.Display stack\n4.Infix to Postfix\n"
    		  "5.Postfix to prefix\n6.exit");
    do{
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("Enter the element to be pushed");
            scanf(" %c",&it);
            push(it);
        break;

        case 2:
            poped=pop();
            if(poped!='x')
            {
            printf("Element poped is:%c",poped);
            }
            else
            {
             printf("\nStack Underflow");
            }
        break;

        case 3:
            display();
        break;

        case 4:
            printf("Enter the infix expression");
            scanf("%s",exp);
            postfix(exp);
        break;

        case 5:
            printf("Enter the postfix expression:");
            scanf("%s",exp);
            prefix(exp);
        break;

        case 6:
            printf("Thank you for using stack!!!");
        break;
      }
      }while(ch!=6);

return 0;
}
