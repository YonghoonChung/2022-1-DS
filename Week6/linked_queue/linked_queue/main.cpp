//
//  main.cpp
//  linked_queue
//
//  Created by Yonghoon Chung on 2022/04/06.
//

#include <iostream>
using namespace std;

class node{
public:
    string name;
    double score;
    node *link;
    void set_data(string s, double n);
};
void node::set_data(string s, double n){
    name = s;
    score = n;
}

class my_queue{
    node *front, *rear; // front 삭제, rear 추가
public:
    my_queue();
    void insert_queue(node t);
    node delete_queue();
    bool queue_empty();
};

my_queue::my_queue(){
    front = NULL;
    rear = NULL;
}

void my_queue::insert_queue(node t){
    node *p;
    p = new node;
    *p = t;
    p->link = NULL;
    if(front == NULL){
        front = p;
    }
    else{
        rear->link = p;
    }
    rear = p;

}

node my_queue::delete_queue(){
    node tmp;
    node *p;
    
    if(queue_empty()){
        return tmp;
    }
    p = front;
    tmp = *front;
    front = p->link;
    delete p;
    return tmp;
}

bool my_queue::queue_empty(){
    if(front == NULL){
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    my_queue a;
    node tmp;
    
    tmp.set_data("Kim", 22.2);
    a.insert_queue(tmp);
    tmp.set_data("Lee", 33.3);
    a.insert_queue(tmp);
    tmp.set_data("Park", 44.4);
    a.insert_queue(tmp);
    tmp.set_data("Choi", 55.5);
    a.insert_queue(tmp);
    
    tmp = a.delete_queue();
    cout << tmp.name<< " : " << tmp.score << "\n";
    tmp = a.delete_queue();
    cout << tmp.name<< " : " << tmp.score << "\n";
    return 0;
}
