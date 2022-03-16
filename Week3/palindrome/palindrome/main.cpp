//
//  main.cpp
//  palindrome
//
//  Created by Yonghoon Chung on 2022/03/15.
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

void palindromeCheck(string input){
    Stack s1;
    int i;
    int len = (int)input.size();
    for (i = 0; i<len/2; i++) {
        s1.push(input[i]);
    }
    if(len%2 == 0) i= len/2;
    else i = len/2 + 1;
    
    while (!s1.empty()) {
        if(s1.pop()!= input[i]){
            cout << "No, it's not a palindrome.\n";
            return;
        }
        i++;
    }
        cout << "Yes, it's a palindrome.\n";
}

int main(int argc, const char * argv[]) {
    string input;
    char buff[100];
//    bool correct = true;
    
    cin.getline(buff, 80);
    input = buff;
    input.erase(remove(input.begin(),input.end(),' '),input.end());
    
//    cout << input<<"\n";
    palindromeCheck(input);

    return 0;
}
