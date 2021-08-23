#include<iostream>
using namespace std;

class List;
 class node{
 private:
  int data;

public:
  node*next;
node(int d):data(d),next(NULL){}
int getData(){
  return data;
}
friend class List;
~node(){
if(next!=NULL){
  delete next;
 }
}
};

class List{

private:
  node*head;
  node*tail;
  int searchHelp(node*start,int key){
    if(start==NULL){
      return -1;
    }
    if(start->data==key){
      return 0; 
  }
  int subIndx =  searchHelp(start->next,key);
  if(subIndx==-1){
    return -1;
  }
  return subIndx+1;
  }
public:
  List():head(NULL),tail(NULL){}
  node *begin(){
    return head;
  }
  void push_front(int data){
if(head == NULL){
  node*n = new node(data);
  head = tail = n;
  }
  else{
    node*n = new node(data);
n->next = head;
head = n;
  }
}
void push_back(int data){
if(head == NULL){
  node*n = new node(data);
  head = tail = n;
  }
  else{
    node*n = new node(data);
tail->next = n;
tail = n;
  }
}
void insert(int data,int pos){
  if(pos==0){
    push_front(data);
    return;
  }
  node *temp = head;
  for(int i = 0;i<pos;i++){
    temp = temp->next;
  }
  node*n = new node(data);
  n->next = temp->next;
  temp->next = n;
}
int  search(int key){
  node*temp = head;
  int ptr = 0;
  while(temp!=NULL){
    if(temp->data==key){
return ptr;
    }
    temp = temp->next;
    ptr++;
  }
  return -1;
}
int recursiveSearch(int key){
  int index = searchHelp(head,key);
  return index;
}
void pop_front(){
  node*temp = head;
  head = head->next;
  temp->next=NULL;
  delete temp;
}
void reverse(){
  node*curr = head;
  node*prev = NULL;
  node*temp;
  while(curr!=NULL){
    temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  head = prev;
}
void print(){
  node* temp = head;
  while(temp!=NULL){
    cout<<temp->getData()<<"->";
    temp = temp->next;
  }
}
~List(){
  if(head!=NULL){
  delete head;
}
}
};
