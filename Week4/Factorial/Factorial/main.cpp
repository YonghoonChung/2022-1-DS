//
//  main.cpp
//  Factorial
//
//  Created by Yonghoon Chung on 2022/03/21.
//

#include <iostream>
using namespace std;

int factorial(int n){
    if(n==0) return 1;
    else
        return (n*factorial(n-1));
}
int main(int argc, const char * argv[]) {
    int k;
    
    cin >> k;
    int x = factorial(k);
    cout << x << "\n";
    return 0;
}
