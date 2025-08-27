// all answers are written in c programming
// Aksh Kaushik 1024030660
// 2c75
#include <stdio.h>
#include <stdbool.h>
#define N 5

int stack[N];
int top = -1;

void push()
{
  int x;
  printf("Enter number: ");
  scanf("%d", &x);
  if (top == N - 1)
  {
    printf("stack overflow");
  }
  else
  {
    top++;
    stack[top] = x;
  }
}
void pop()
{
  int item;
  if (top == -1)
  {
    printf("stack underflow");
  }
  else
  {
    stack[top] = item;
    top--;
    printf("%d", item);
  }
}
void peek()
{
  if (top == -1)
  {
    printf("Stack underflow");
  }
  else
  {
    printf("%d", stack[top]);
  }
}
void display()
{
  int i;
  printf("[");
  for (i = top; i >= 0; i--)
  {
    printf("%d  ", stack[i]);
  }
  printf("]");
}
bool isempty()
{
  if (top == -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
bool isfull()
{
  if (top == N - 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
int main()
{
  int ch;
  do
  {
    printf("\nEnter choice: 1--> PUSH \n2-->POP\n3-->PEEK\n4-->DISPLAY\n5-->EMPTY?\n6-->Full?\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      peek();
      break;
    case 4:
      display();
      break;
    case 5:
      printf("Is empty?\n %s\n", isempty() ? "true" : "false");
      break;
    case 6:
      printf("Is full? %d\n", isfull());
      break;
    default:
      printf("Invalid choice");
    }

  } while (ch != 0);
}

// ques2
#include <stdio.h>
#include <string.h>
#define N 100

char stack[N];
int top = -1;

void push(char c)
{
  if (top < N - 1)
  {
    stack[++top] = c;
  }
}

char pop()
{
  if (top >= 0)
  {
    return stack[top--];
  }
  return '\0';
}

int main()
{
  char str[N];
  int i;

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  for (i = 0; str[i] != '\0'; i++)
  {
    push(str[i]);
  }

  printf("Reversed string: ");
  while (top != -1)
  {
    printf("%c", pop());
  }

  printf("\n");
  return 0;
}
// ques 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

char stack[N];
int top = -1;

void push(char ch)
{
  if (top >= N - 1)
  {
    printf("Stack Overflow\n");
    exit(1);
  }
  stack[++top] = ch;
}

char pop()
{
  if (top == -1)
  {
    return '\0';
  }
  return stack[top--];
}

int isMatchingPair(char opening, char closing)
{
  return (opening == '(' && closing == ')') ||
         (opening == '{' && closing == '}') ||
         (opening == '[' && closing == ']');
}

int isBalanced(char *expr)
{
  for (int i = 0; expr[i] != '\0'; i++)
  {
    char ch = expr[i];

    if (ch == '(' || ch == '{' || ch == '[')
    {
      push(ch);
    }
    else if (ch == ')' || ch == '}' || ch == ']')
    {
      char topChar = pop();
      if (!isMatchingPair(topChar, ch))
      {
        return 0;
      }
    }
  }

  return (top == -1);
}

int main()
{
  char expr[N];

  printf("Enter an expression: ");
  fgets(expr, sizeof(expr), stdin);

  if (isBalanced(expr))
    printf("The expression has balanced parentheses.\n");
  else
    printf("The expression does NOT have balanced parentheses.\n");

  return 0;
}

// ques 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
  if (top == MAX - 1)
  {
    printf("Stack overflow\n");
    exit(1);
  }
  stack[++top] = c;
}

char pop()
{
  if (top == -1)
  {
    printf("Stack underflow\n");
    exit(1);
  }
  return stack[top--];
}

char peek()
{
  if (top == -1)
    return '\0';
  return stack[top];
}

int precedence(char op)
{
  switch (op)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}

int isRightAssociative(char op)
{

  return (op == '^');
}

void infixToPostfix(char *infix, char *postfix)
{
  int i, k = 0;
  char c, topOp;

  for (i = 0; infix[i] != '\0'; i++)
  {
    c = infix[i];

    if (isalnum(c))
    {
      postfix[k++] = c;
    }

    else if (c == '(')
    {
      push(c);
    }

    else if (c == ')')
    {
      while (top != -1 && peek() != '(')
      {
        postfix[k++] = pop();
      }
      if (top != -1 && peek() == '(')
        pop();
      else
      {
        printf("Invalid expression\n");
        exit(1);
      }
    }

    else
    {
      while (top != -1 && precedence(peek()) >= precedence(c))
      {

        if (isRightAssociative(c) && peek() == c)
          break;
        postfix[k++] = pop();
      }
      push(c);
    }
  }

  while (top != -1)
  {
    if (peek() == '(' || peek() == ')')
    {
      printf("Invalid expression\n");
      exit(1);
    }
    postfix[k++] = pop();
  }

  postfix[k] = '\0';
}

int main()
{
  char infix[MAX], postfix[MAX];

  printf("Enter an infix expression: ");
  fgets(infix, MAX, stdin);

  infixToPostfix(infix, postfix);

  printf("Postfix expression: %s\n", postfix);

  return 0;
}

// ques 5
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
  if (top == MAX - 1)
  {
    printf("Stack overflow\n");
    exit(1);
  }
  stack[++top] = val;
}

int pop()
{
  if (top == -1)
  {
    printf("Stack underflow\n");
    exit(1);
  }
  return stack[top--];
}

int isOperator(char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int evaluatePostfix(char *postfix)
{
  int i;
  int val1, val2;
  int result;
  int length = strlen(postfix);

  for (i = 0; i < length; i++)
  {
    char c = postfix[i];

    if (isspace(c))
    {

      continue;
    }

    if (isdigit(c))
    {

      push(c - '0');
    }
    else if (isOperator(c))
    {
      val2 = pop();
      val1 = pop();

      switch (c)
      {
      case '+':
        result = val1 + val2;
        break;
      case '-':
        result = val1 - val2;
        break;
      case '*':
        result = val1 * val2;
        break;
      case '/':
        if (val2 == 0)
        {
          printf("Division by zero error!\n");
          exit(1);
        }
        result = val1 / val2;
        break;
      case '^':
        result = (int)pow(val1, val2);
        break;
      default:
        printf("Unknown operator %c\n", c);
        exit(1);
      }
      push(result);
    }
    else
    {
      printf("Invalid character in expression: %c\n", c);
      exit(1);
    }
  }

  return pop();
}

int main()
{
  char postfix[MAX];

  printf("Enter a postfix expression (single-digit operands): ");
  fgets(postfix, MAX, stdin);

  int result = evaluatePostfix(postfix);

  printf("Result of postfix evaluation: %d\n", result);

  return 0;
}
