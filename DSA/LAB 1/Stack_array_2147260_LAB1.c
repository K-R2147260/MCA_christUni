#include <stdio.h>
int top = -1,choice,stax[100],elem,i,ch; char ans;
void push(void);
void pop(void);
void display(void);


int main(void) {
  do{
  printf("\nEnter choice");
  printf("\n1. Push an element \n2. Pop an Element \n3. View Stack");
  scanf("%d",&choice);
  
  switch(choice){
    case 1:push(); break;
    case 2:pop(); break;
    case 3:display(); break;
    default:printf("\nInvalid choice");
  }
    printf("\nDo you want to continue? (y/n)");
    while ((ch = getchar()) != '\n' && ch != EOF);
    scanf("%c",&ans);  
  } while(ans=='y'||ans=='Y');
  return 0 ;
}


void push(){
  top++;
  if (top>100){
    printf("\nStack Overflow");
    return;
  }
  printf("\nEnter element to be added");
  scanf("%d",&elem);
  stax[top]=elem;
}

void pop(){
  top--;
  if (top<-1){
    printf("\nStack Underflow");
  }
}

void display(){
  if(top==-1){
    printf("\nEmpty array");
    return;
  }
  for(i=top;i>-1;i--){
    printf("%d ",stax[i]);
  }
}
