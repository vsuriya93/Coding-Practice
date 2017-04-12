#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct node{
    char brac;
    struct node *next;
};
  
typedef struct node node;

node *head=NULL;
    
node *createNode(char element)
{
    node *e=(node*)malloc(sizeof(node));
    e->brac=element;
    e->next=NULL;
    return e;
}
    
void push(char element){
    if(head==NULL)
        {
        head=createNode(element);
        return;
    }
        node *temp=createNode(element);
        temp->next=head;
        head=temp;
}

char pop(){
    if(head==NULL){;
        return '\0';}
    else{
        char element=head->brac;
        node *temp=head;
        head=head->next;
        free(temp);
        return element;
    }
}

int isEmptyStack(){
    if(head==NULL)
        return 1;
    return 0;
}

char map_brackets(char e)
    {
    if(e==')')
        return'(';
    else if(e==']')
        return '[';
    else
        return '{';
}

void printStack(){
    node *runner=head;
    while(runner){
        printf("%d->",runner->brac);
        runner=runner->next;
    }
}

bool is_balanced(char expression[]) {
    int i=0;
    while(expression[i]!='\0')
        {
        if(expression[i]=='{' || expression[i]=='(' || expression[i]=='['){
            //printf("%c",expression[i]);
            push(expression[i]);
            //printStack();
        }
        else
            {
            char top=pop();
            //printf("%c->%c\n",expression[i],top);
            if(top!=map_brackets(expression[i]))
                return false;
        }
        i++;    
    }
    if(isEmptyStack())
        return true;
    return false;
}

void emptyStack(){
    while(head)
        {
        node *temp=head;
        head=head->next;
        free(temp);           
    }
}

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        char* expression = (char *)malloc(512000 * sizeof(char));
        scanf("%s",expression);
         bool answer = is_balanced(expression);
         if(answer)
          printf("YES\n");
         else
          printf("NO\n");
        emptyStack();
    }
    return 0;
}
