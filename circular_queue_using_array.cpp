#include<iostream>
using namespace std;
class cqueue{
    public:
    int *arr;
    int front;
    int rear;
    int size=5;

    cqueue(){
        arr=new int[size];
        front=-1;
        rear=-1;

    }
bool empty(){
    if(rear==-1 && front ==-1){
        return true;
    }
    return false;
}



void enqueue(int d){
   if(rear==size){
    rear=0;
    arr[(rear+1)%size]=d;
    rear++;
   }
   else{
    arr[rear]=d;
    rear++;

   }     
}

void dequeue(){
    if(rear==front){
        cout<<"empty";
        return;
    }
    
       else{ arr[front]=-1;
        front++;
        if(front==rear){
            front=-1;
            rear=-1;
        }
        // front++;
}
}

void peek(){
    cout<<arr[front];
    cout<<endl;
}



};
int main(){
    cqueue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(9);
    q.enqueue(21);
    q.enqueue(45);
    q.enqueue(63);
    q.enqueue(99);
    // q.peek();

    while(!q.empty()){
        q.peek();cout<<endl;
        q.dequeue();
    }
}