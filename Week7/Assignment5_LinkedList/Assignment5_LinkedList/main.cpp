//
//  main.cpp
//  Assignment5_LinkedList
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

class linkedStack{
public:
    node* top;
    linkedStack();
    void push(char x);
    char pop();
    bool empty();
};

linkedStack::linkedStack(){
    top = NULL;
}

void linkedStack::push(char x){
    node* p = new node;
    p->set_s(x);
    p->link = top;
    top = p;
}

char linkedStack::pop(){
    node* t;
    char tmp='\0';
    if(empty())
        return tmp;
    t = top;
    top = top -> link;
    tmp = t->s;
    delete t;
    return tmp;
}

bool linkedStack::empty(){
    return (top == NULL);
}

bool bracketTest(string input){
    linkedStack s;
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
    char buff[100];
    cin.getline(buff, 80);
    input = buff;
    input.erase(remove(input.begin(),input.end(),' '),input.end());//공백을 지워주는 코드
    //cout<<input<<"\n";
    if(bracketTest(input))cout<<"It's a normal expression\n";
    return 0;
}
