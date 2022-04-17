//
//  main.cpp
//  Assignment4_linkedList
//
//  Created by Yonghoon Chung on 2022/04/16.
//

#include <iostream>
#include <string>
using namespace std;
#define EOS '$'

class node{
public:
    char s;
    node* link;
    void set_char(char x);
};

void node::set_char(char x){
    s = x;
}

class op_linkedList{
    node* top;
public:
    op_linkedList();
    void push(char x);
    char pop();
    char top_element();
    bool empty();
};

op_linkedList::op_linkedList(){
    top = NULL;
}

void op_linkedList::push(char x){
    node* p = new node;
    p->set_char(x);
    p->link = top;
    top = p;
}

char op_linkedList::pop(){
    node* t;
    char tmp='\0';
    if(empty())
        return tmp;
    t = top;
    tmp = top->s;
    top = top->link;
    delete t;
    return tmp;
}
bool op_linkedList::empty(){
    return (top == NULL);
}

char op_linkedList::top_element(){
    return top->s;
}
bool is_operand(char ch){
    if((ch=='(')||(ch==')')||
       (ch=='+')||(ch=='-')||
       (ch=='*')||(ch=='/')||
       (ch=='%')||(ch=='$'))
        return false;
    else
        return true; // 숫자라면
}
int get_precedence(char op){
    switch (op) {
        case '$':
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        default:
            return -1;
    }
}
string infixToPostfix(string input){
    op_linkedList stack;
    string output;
    input += EOS;
    int len = (int)input.size();
    
    for(int i=0; i< len;i++){
        if(is_operand(input[i])){ // 숫자라면
            output += input[i];
        }
        else if(input[i] == '('){ // 여는 소괄호
                stack.push(input[i]);
        }
        else if(input[i] == ')'){ // 닫는 소괄호
            while(stack.top_element() != '('){
                output += stack.top_element();
                stack.pop();
            }
            stack.pop();
        }
        else{
            while(!stack.empty()&& get_precedence(input[i])<=get_precedence(stack.top_element())){
                output += stack.top_element();
                stack.pop();
            }
            stack.push(input[i]);
        }
    }
    while(!stack.empty()){
        output += stack.top_element();
        stack.pop();
    }
    
    return output;
}

int main(int argc, const char * argv[]) {
    string input, output;
    char buff[100];
    cout<<"Input an infix expression to convert: ";
    cin.getline(buff, 80);
    input = buff;
    input.erase(remove(input.begin(),input.end(),' '),input.end());
    output = infixToPostfix(input);
   
    cout << output<<"\n";
    return 0;
}

