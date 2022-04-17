//
//  main.cpp
//  Assignment6_linkedList
//
//  Created by Yonghoon Chung on 2022/04/16.
//

#include <iostream>
#include <string>
#define SIZE 100
using namespace std;

class node{
public:
    char s;
    node* link;
    void set_s(char x);
};

void node::set_s(char x){
    s = x;
}

class LinkedStack{
public:
    node* top;
    LinkedStack();
    void push(char x);
    char pop();
    bool empty();
};

LinkedStack::LinkedStack(){
    top = NULL;
}
void LinkedStack::push(char x){
    node* p = new node;
    p -> set_s(x);
    p->link = top;
    top = p;
}
char LinkedStack::pop(){
    node* t;
    char tmp = '\0';
    if(empty())
        return tmp;
    t = top;
    top = top -> link;
    tmp = t->s;
    delete t;
    return tmp;
}
bool LinkedStack::empty(){
    return (top == NULL);
}
int main(int argc, const char * argv[]) {
    LinkedStack s1;
    string input;
    char buff[100];
    int i;
//    bool correct = true;
    
    cin.getline(buff, 80);
    input = buff;
    input.erase(remove(input.begin(),input.end(),' '),input.end());
    
//    cout << input<<"\n";
    int len = (int)input.size();
    for (i = 0; i<len/2; i++) {
        s1.push(input[i]);
    }
    if(len%2 == 0) i= len/2;
    else i = len/2 + 1;
    
    while (!s1.empty()) {
        if(s1.pop()!= input[i]){
            cout << "No, it's not a palindrome.\n";
            return 0;
        }
        i++;
    }
        cout << "Yes, it's a palindrome.\n";
    return 0;
}
