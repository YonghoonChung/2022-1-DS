//
//  main.cpp
//  Queue_app_subject
//
//  Created by Yonghoon Chung on 2022/03/24.
//

//
//  main.cpp
//  Queue_app
//
//  Created by Yonghoon Chung on 2022/03/21.
//

#include <iostream>
using namespace std;
#define Q_SIZE 10

class element{
public:
    string s_title;
    int npages;
    int price;
    void set_data(string s1, int n1, int n2);
};

class my_queue{
private:
    element q[Q_SIZE];
    int front, rear;
public:
    my_queue();
    void insert_q(element x);
    element delete_q();
    bool queue_full();
    bool empty();
};

void element::set_data(string s1, int n1, int n2){
    s_title= s1;
    npages = n1;
    price = n2;
}

my_queue:: my_queue(){
    front = 0;
    rear = 0;
}

void my_queue::insert_q(element x){
    if(!queue_full()){
        q[rear] = x;
        rear = (rear+1)%Q_SIZE;
    }
    return;
}

element my_queue::delete_q(){
    element tmp;
    element nope;
    if(!empty()){
        tmp = q[front];
        front = (front + 1) % Q_SIZE;
        return(tmp);
    }
    return nope;
}

bool my_queue::queue_full(){
    if((rear + 1)%Q_SIZE == front)
        return true;
    else
        return false;
}

bool my_queue::empty(){
    if(rear == front)
        return true;
    else
        return false;
}

int main(int argc, const char * argv[]) {
    my_queue a;
    
    element tmp;

    tmp.set_data("C++ Programming", 534, 35000);
    a.insert_q(tmp);
    
    tmp.set_data("Data Structure", 621, 42000);
    a.insert_q(tmp);
    
    tmp.set_data("JAVA Programming", 485, 38000);
    a.insert_q(tmp);
    
    tmp.set_data("Logic Design", 532, 44000);
    a.insert_q(tmp);

    while (!a.empty() ) {
        tmp = a.delete_q();
        cout << tmp.s_title << " : " << tmp.npages  << " : " << tmp.price << "\n";
    }
    return 0;
}
