//
//  main.cpp
//  infixToPostfix
//
//  Created by Yonghoon Chung on 2022/03/14.
//

#include <iostream>
#include <string>
#define SIZE 100
#define EOS '$'
using namespace std;

class op_stack{
private:
    char s[SIZE];
    int top;
public:
    op_stack(); // constructor
    void push(char x);
    char pop();
    bool empty();
    char top_element();
};
op_stack::op_stack(){
    top = 0;
}
void op_stack::push(char x){
    s[top] = x;
    top++;
}
char op_stack::pop(){
    top--;
    return(s[top]);
}
bool op_stack::empty(){
    return (top == 0);
}
char op_stack::top_element(){
    return s[top-1];
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
    op_stack stack;
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
