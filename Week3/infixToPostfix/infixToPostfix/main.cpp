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
    return (s[top-1]);
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
    if((op=='$')||(op==')'))
        return 0;
    else if((op=='+')||(op=='-'))
        return 1;
    if((op=='*')||(op=='/')||(op=='%'))
        return 2;
    return 0;
}
int main(int argc, const char * argv[]) {
    string input, output;
    op_stack stack1;
    cout<<"Input an infix expression to convert: ";
    cin>>input;
    int len = (int)input.size();
    input += EOS;
    
    for(int i=0; i< len;i++){
        if(is_operand(input[i])){ // 숫자라면
            output += input[i];
        }
        else{
            if(input[i] == '('){ // 여는 소괄호
                stack1.push(input[i]);
            }
            else if(input[i] != ')'){ // 닫는 소괄호
                while(stack1.top_element() == '('){
                    output += stack1.pop();
                }
                stack1.pop();
            }else{
                while(!stack1.empty()&& get_precedence(input[i])<=get_precedence(stack1.top_element())){
                    output += stack1.pop();
                }
            }
        }
    }
    while(!stack1.empty()){
        output += stack1.pop();
    }
    cout << output;
    return 0;
}
