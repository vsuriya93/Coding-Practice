#include<iostream>

using namespace std;

class List
{
 int num;
 class List *next,*head;
 public:
  List()
  {
   next=head=NULL;
  }
  void insert(int num)
  {
   class List *element=head;
   if(head==NULL)
   {
    this->num=num;
    head=this;
    return;
   }
   class List *newElement=new class List;
   newElement->num=num;
   newElement->next=head;
   head=newElement;
  }
  void print()
  {
   class List *element=head;
   while(element)
   {
    cout<<element->num<<"->";
    element=element->next;
   }
   return;
  }

};

int main()
{
 List *root=new List;
 for(int i=0;i<100;++i)
	root->insert(i);	
 root->print();
}
