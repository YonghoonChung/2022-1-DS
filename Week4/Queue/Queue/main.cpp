//
//  main.cpp
//  Queue
//
//  Created by Yonghoon Chung on 2022/03/21.
//

#include <iostream>
using namespace std;
#define Q_SIZE 10

class my_queue{
private:
    int q[Q_SIZE];
    int front, rear;
public:
    my_queue();
    void insert_q(int x);
    int delete_q();
    bool queue_full();
    bool queue_empty();
};

my_queue:: my_queue(){
    front = 0;
    rear = 0;
}

void my_queue::insert_q(int x){
    if(!queue_full()){
        q[rear] = x;
        rear = (rear+1)%Q_SIZE;
    }
    return;
}

int my_queue::delete_q(){
    int tmp;
    if(!queue_empty()){
        tmp = q[front];
        front = (front + 1) % Q_SIZE;
        return(tmp);
    }
    return 0;
}

bool my_queue::queue_full(){
    if((rear + 1)%Q_SIZE == front)
        return true;
    else
        return false;
}

bool my_queue::queue_empty(){
    if(rear == front)
        return true;
    else
        return false;
}

int main(int argc, const char * argv[]) {
    my_queue a;
    int t;
    
    a.insert_q(1);
    a.insert_q(2);
    a.insert_q(3);
    
    t = a.delete_q();
    t = a.delete_q();
    
    a.insert_q(4);
    a.insert_q(5);
    
    while(!a.queue_empty()){
        t = a.delete_q();
        cout << t << "\n";
    }
    return 0;
}
