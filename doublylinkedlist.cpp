#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
}

void inserthead(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void inserttail(node *&head, node *&tail, int d)
{
    if (tail == NULL)
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertposition(node* &head, node* &tail, int position, int d)
{
    if (position == 1)
    {
        inserthead(head, tail, d);
        return;
    }

    // node *temp = new node(d);
    node*temp=head;
    int cnt = 1;
    while (cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        inserttail(head, tail, d);
        return;
    }

    node *nodetoinsert = new node(d);
    nodetoinsert ->next = temp -> next;

    temp -> next-> prev = nodetoinsert;

    temp -> next = nodetoinsert;

    nodetoinsert -> prev = temp;
}

void deletenode(int position ,node* & head){
    if(position==1){
        node *temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;

    }

    else{
        node * curr=head;
        node* prev=NULL;

        int cnt=1;
        while(cnt<position-1){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
}
}

// node* reverse(node*head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }

//     node*prev=NULL;
//     node*curr=head;
//     node*temp=NULL;
    
//     while(curr!=NULL){
//         temp=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=temp;
//     }
//     return prev;
// }


//function for reversing doubly linked list
node* reverse2(node*head){
    node*temp=head;
    node*curr=head->next;
    head->prev=curr;
    head->next=NULL;

    while(curr!=NULL){
        node*forward=curr->next;
        curr->next=temp;
        curr->prev=forward;
        temp=curr;
        curr=forward;

         }
         return temp;
}

int main(){
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    print(head);
    inserthead(head, tail, 6);
    print(head);
    
    inserttail(head, tail, 7);
    print(head);
    
    inserttail(head, tail, 3);
    print(head);
    
    inserttail(head, tail, 1);
    print(head);
    
    insertposition(head,tail,1,23);
    print(head);
    
    insertposition(head,tail,3,33);
    print(head);

    deletenode(3,head);
    print(head);
    
    // reverse(head);
    print(reverse2(head));
}