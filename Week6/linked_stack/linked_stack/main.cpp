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

class my_stack{
    node *top;
public:
    my_stack();
    void push(node t);
    node pop();
    bool stack_empty();
};

my_stack::my_stack(){
    top = NULL;
}
void my_stack::push(node t){
    node* p;
    p = new node;
    *p = t;
    if(top != NULL){
        p->link = top;
    }
    top = p;
}

node my_stack::pop(){
    node tmp;
    node *t;
    
    if(stack_empty()){
        return tmp;
    }
    
    t = top;
    tmp = *top;
    top = top->link;
    delete t;
    return tmp;
}

bool my_stack::stack_empty(){
    if(top == NULL){
        return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    my_stack a;
    node tmp;
    
    tmp.set_data("Kim", 22.2);
    a.push(tmp);
    tmp.set_data("Lee", 33.3);
    a.push(tmp);
    tmp.set_data("Park", 44.4);
    a.push(tmp);
    tmp.set_data("Choi", 55.5);
    a.push(tmp);
    
    tmp = a.pop();
    cout << tmp.name<< " : " << tmp.score << "\n";
    tmp = a.pop();
    cout << tmp.name<< " : " << tmp.score << "\n";
    return 0;
}
