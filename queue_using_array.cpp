#include<iostream>
using namespace std;

class queue{
    public:
    int *arr;
    int front;
    int rear;
    int size=10;

        queue(){
            arr=new int[size];
            front=0;
            rear=0;

    }
    
void enqueue(int d){
    if(rear==size){
        cout<<"full"<<endl;
        return;
    }
    else{
        
        arr[rear]=d;
        rear++;
    }
}

int printfront(){
    cout<<arr[front];
}

void dequeue(){
    if(rear==front){
        cout<<"empty";
        return;
    }
    else{
        arr[front]=-1;
        front++;
        if(front==rear){
            front=0;
            rear=0;
        }
        // front++;
    }
}

bool is_empty(){
    if(rear==0){
        return true;
    }
    else{
        return false;
    }
}


};
int main(){
    queue q;
    q.enqueue(5);
    q.enqueue(9);
    q.enqueue(8);
    // q.dequeue();
    // q.printfront();
    
    while(!q.is_empty()){
        q.printfront();cout<<endl;
        q.dequeue();
    }


}