#include<stdio.h>
#include<malloc.h>
#include<math.h>

struct heap_struct{
 int capacity;
 int size;
 int *arr;
};

typedef struct heap_struct heap_struct;

#define SIZE 7

void printHeap(int *arr,int n){
 int i =0;
 for(i=0;i<n;i++){
  printf("%d ",arr[i]);
 }
 return;
}

int parent(int i){
 return floor((i-1)/2);
}

void insert(heap_struct *heap,int num){
 if(heap->size==0){
 heap->arr[0]=num;
 heap->size+=1;
 return;
 }
 if(heap->size==heap->capacity)
 {
  printf("\nArray Full\n");
  return;
 }
 heap->size++;
 int i=heap->size-1,temp;
 heap->arr[i]=num;
 while(i!=0 && heap->arr[parent(i)]>num){
  temp=heap->arr[i];
  heap->arr[i]=heap->arr[parent(i)];
  heap->arr[parent(i)]=temp;
  i=parent(i);
 }
}

int main()
{
 heap_struct *heap=(heap_struct*)malloc(sizeof(heap_struct));
 heap->arr=(int*)malloc(sizeof(int));
 heap->size=0;
 heap->capacity=SIZE;
 int i=0,num;
 for(i=0;i<SIZE;i++){
  printf("\nEnter Element: ");
  scanf("%d",&num);
  heap->arr[i]=num;
  insert(heap,num);
  printHeap(heap->arr,heap->size);
 }
 printf("\n");
 return 0;
}
