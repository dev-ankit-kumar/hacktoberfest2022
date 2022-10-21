#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;

        node(int d){
            this->data=d;
            this->next=NULL;
            this->prev=NULL;
            }
};

void push(node*&head,int d){
    node*temp=new node(d);
    node*temp2=head;

    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;



}

void print(node*head){
    if(head==NULL){
        cout<<"empty"<<endl;

    }
    else{
        node*temp=head;
        while(temp!=NULL){
        
        cout<<temp->data<<endl;
        temp=temp->next;
        }
        

    }
}

void pop(node*&head){
     node*temp=head;
     head=head->next;
     delete temp;


}
int main(){
    node*node1=new node(5);
    node*head=node1;
    push(head,6);
    push(head,7);
    push(head,8);
    pop(head);
    pop(head);
    print(head);


}