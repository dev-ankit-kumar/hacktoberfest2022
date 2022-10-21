#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int d){
        this->data=d;
        this->next=NULL;
    }
};

void insert(node*&tail,int element,int d){
    if(tail==NULL){
        node*x=new node(d);
        tail=x;
        x->next=x;

        }

        else{
        node*curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        //element found
        node*temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
        }

}

void print(node*tail){
    node*temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail !=temp);
    cout<<endl;
}

void delet(node* &tail,int value){
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return ;
    }
    else{
        //non empty linked list
        node *prev=tail;
        node * curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(curr==prev){
            tail==NULL;
        }
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;  
    }
}

int main(){
    node*tail=NULL;
    insert(tail,5,3);
    print(tail);
    insert(tail,3,4);
    print(tail);
    insert(tail,4,5);
    print(tail);
    insert(tail,3,6);
    print(tail);
    insert(tail,6,7);
    print(tail);
    delet(tail,3);
    print(tail);
}