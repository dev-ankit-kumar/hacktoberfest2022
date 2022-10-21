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

void inserthead(node* &head,int d){
    node*temp=new node(d);
    temp->next=head;
    head=temp;    
}

void print(node* temp){
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertend(node* &tail,int d){
    node*temp=new node(d);
    tail->next=temp;
    tail=temp;
    
}

void insertatposition(node* &head,node*&tail,int position ,int d){

    if(position==1){
        inserthead(head,d);
        return;
    }
    node*temp=head;
    int cnt=0;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    } 

    if(temp->next==NULL){
        insertend(tail,d);
        return;
    }
    node *nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;


} 

void deletenode(node* &head,int position){
    if(position==1){
        node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    else{
        node*curr=head;
        node*prev=NULL;

        int cnt=1;
        while(cnt<position){
           prev=curr;
           curr=curr->next;
           cnt++;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        }
}

int getlength(node*head){
    int len=0;
    node*temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

node* findmiddle(node*head){
    int len=getlength(head);
    int ans=len/2;
    node*temp=head;
    int cnt=0;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp;
    cout<<temp->data;
}

node* reverse(node*head){
   node*prev=head;
   node*curr=head->next;
   head->next=NULL;
   while(curr!=NULL){
    node*temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
   }
    return prev;
}

node*reversek(node*head,int k){
    if(head==NULL){
        return NULL;
    }
    node*next=NULL;
    node*prev=NULL;
    node*curr=head;
    int cnt=0;
    while(curr!=NULL && cnt<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }

    if(next!=NULL){
        head->next=reversek(next,k);
    }
    return prev;
}

int main(){
    node*node1=new node(10);
    // cout<<node1->data;
    node*head=node1;
    node*tail=node1;

    // inserthead(head,7);
    print(head);

    insertend(tail,12);

    print(head);

    insertend(tail,15);
    print(head);
    insertend(tail,23);
    print(head);
    insertend(tail,98);
    print(head);

    // insertend(tail,10);
    // insertatposition(head,1,4);
    // insertatposition(head,tail,2,22);

    // print(head);
    // deletenode(head,3);
    // print(head);
    
    // print(reverse(head));
    // findmiddle(head);
    print(reversek(head,2));
}