//
//  main.cpp
//  Assignment3_linkedList
//
//  Created by Yonghoon Chung on 2022/04/16.
//

#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* link;
    void set_num(int n);
//    int get_num();
};

void node::set_num(int n){
    data = n;
}
//int get_num(){
//    int num;
//    return num = data;
//}

class my_stack{
    node *top;
public:
    my_stack();
    void push(int num);
    int pop();
    bool stack_empty();
};

my_stack::my_stack(){
    top = NULL;
}

void my_stack::push(int num){
    node* p = new node;
    p->set_num(num);
    p->link = top;
    top = p;
}
int my_stack::pop(){
    int tmp=-9999;
    node* t;
    if(stack_empty())
        return tmp;
    t = top;
    tmp = t->data;
    top = top->link;
    delete t;
    return tmp;
}
bool my_stack::stack_empty(){
    return (top == NULL);
}

int main(int argc, const char * argv[]) {
    my_stack s1;
    int list[5] = {32,123,27,131,242},i,x;
    
    //s1.init();
    for(i=0;i<5; i++){
        if(list[i]>100){
            s1.push(list[i]);
        }
    }
    while(!s1.stack_empty()){
        x = s1.pop();
        cout<<x<<endl;
    }
    return 0;
}
