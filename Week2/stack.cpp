//
//  main.cpp
//  stack
//
//  Created by Yonghoon Chung on 2022/03/08.
//

#include <iostream>
using namespace std;
#define SIZE 100

class my_stack{
private:
    int s[SIZE];
    int top;
public:
    void init();
    void push(int num);
    int pop();
    bool stack_empty();
    bool stack_full();
};

void my_stack::init(){
    this->top = -1;
}
void my_stack::push(int num){
    this->s[++top]=num;
}
int my_stack::pop(){
    return this->s[top--];
}
bool my_stack::stack_empty(){
    if(this->s[top]==-1){
        return true;
    }
    else{
        return false;
    }
}
bool my_stack::stack_full(){
    if(this->s[top]>=SIZE-1){
        return true;
    }
    else{
        return false;
    }
}
void show();
int main(int argc, const char * argv[]) {
    my_stack s1;
    int list[5] = {32,123,27,131,242},i,x;
    
    s1.init();
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
