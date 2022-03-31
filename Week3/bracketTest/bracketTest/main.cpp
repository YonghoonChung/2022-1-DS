//
//  main.cpp
//  bracketTest
//
//  Created by Yonghoon Chung on 2022/03/16.
//

#include <iostream>
#include <string>
#define SIZE 100
using namespace std;


class Stack{
private:
    char s[SIZE];
    int top;
public:
    Stack(); // constructor
    void push(char x);
    char pop();
    bool empty();
};
Stack::Stack(){
    top = 0;
}
void Stack::push(char x){
    s[top++] = x;
}
char Stack::pop(){
    return s[--top];
}
bool Stack::empty(){
    return (top == 0);
}

bool bracketTest(string input){
    Stack s;
    int len = (int)input.size();
    int i;
    string correction = " ";
    char check;
    for (i =0; i<len; i++) {
        if(input[i] =='(' ||input[i] == '{'||input[i] == '['){
            s.push(input[i]);
        }
        else if(input[i] ==')' ||input[i] == '}'||input[i] == ']'){
            if(s.empty()) {
                cout<<"Error: An extra parenthesis '"<< input[i] <<"' is found.(여는 괄호 부족)\n";
                return false;
            }
            check = s.pop();
            if((check == '(' && input[i]!=')')||
               (check == '{' && input[i]!='}')||
               (check == '[' && input[i]!=']')){
                if(check == '(') correction = ')';
                if(check == '{') correction = '}';
                if(check == '[') correction = ']';
                cout << "Error : mis-matched parenthesis, '" << correction << "' is expected(여는 괄호 부족)\n";
                return false;
            }
        }
    }
    if(!s.empty()){
        check = s.pop();
        if(check == '(') correction = ')';
        if(check == '{') correction = '}';
        if(check == '[') correction = ']';
        cout<<"Error: Closing parenthesis '"<< correction <<"' is missing.(닫는 괄호 부족)\n";
        return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    string input;
    char buff[100];     cin.getline(buff, 80);
    input = buff;
    input.erase(remove(input.begin(),input.end(),' '),input.end());//공백을 지워주는 코드
    //cout<<input<<"\n";
    if(bracketTest(input))cout<<"It's a normal expression\n";
    return 0;
}
