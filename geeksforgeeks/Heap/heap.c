#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>

struct heap
{
 int size,capacity;
 int *arr;
};

typedef struct heap heap;

heap * create_heap()
{
 heap *H = (heap*)malloc(sizeof(heap));
 H->size=0;
 printf("\nEnter Heap-Size: ");
 scanf("%d",&(H->capacity));
 H->arr=(int*)malloc(H->capacity*sizeof(int));
 return H;
}

void printHeap(heap *H)
{
 int i=0;
 while(i<H->size)
  printf("%d ",H->arr[i++]);
 return ;
}

bool isFull(const heap const*H)
{ 
  if(H->size==H->capacity)
   return true;
  else
   return false;
}

int parent(const int const i)
{
 return floor((i-1)/2);
}

void swap(int *a,int *b)
{
 int temp=*a;
 *a=*b;
 *b=temp;
}

void insert(heap *H,int num)
{
 if(isFull(H)){
  printf("\n Heap Full!\n\n");
  return;
 }
 int i=H->size++;
 H->arr[i]=num;
 while(i!=0 && H->arr[parent(i)]>num){
  swap(&(H->arr[i]),&(H->arr[parent(i)]));
  i=parent(i);
 }
}

void heapify(heap *H)
{
 int pos=0,left_child,right_child;
 while(pos<H->size-1)
 {
 left_child=2*pos+1;
 right_child=2*pos+2;
  if(left_child>H->size || right_child>H->size){
   break;
  }
  if(H->arr[pos]>=H->arr[left_child] && H->arr[left_child]<H->arr[right_child])
  {
   swap(&(H->arr[pos]),&(H->arr[left_child]));
   pos=left_child;
  }
  else if(H->arr[pos]>=H->arr[right_child])
  {
  swap(&(H->arr[pos]),&(H->arr[right_child]));
  pos=right_child;
  }
  else
  {
   break;
  }
 }

}

int  extractMin(heap *H)
{ 
 if(H->size==0)
 {
  printf("\nHeap Empty\n");
  return INT_MAX;
 }
 else if (H->size==1){
  H->size--;
  return H->arr[0];
 }
 else{
  H->size--;
  int element=H->arr[0];
  H->arr[0]=H->arr[H->size];
  heapify(H);
  return element;
 }
}

int main()
{
 heap *H = create_heap();
 int i,temp;
 for(i=0;i<H->capacity;i++){
 	printf("\nEnter number: ");
	scanf("%d",&temp);
 	insert(H,temp);

 }
 printHeap(H);
 int tem=H->size;
 for(i=0;i < tem ; i++){
  printf("\n");
 // printHeap(H);
  printf(" Min: %d",extractMin(H));
  }
 printf("\n");
 return 0;
}
