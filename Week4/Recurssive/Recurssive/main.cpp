//
//  main.cpp
//  Fibonacci
//
//  Created by Yonghoon Chung on 2022/03/21.
//

#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return (fibonacci(n-1)+fibonacci(n-2));
}

int even_num(int n){
    if(n==1) return 0;
    else if(n%2==0) return n+even_num(n-1);
    else return even_num(n-1);
}

int factorial(int n){
    if(n==0) return 1;
    else
        return (n*factorial(n-1));
}

int array_sum(int a[], int n){
    if(n==0) return 0;
    return a[n-1] + array_sum(a, n-1);
}

int permutaiton(int n, int m){
    if(m==0) return 1;
    return n * permutaiton(n-1, m-1);
}

int gcd(int a ,int b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(int argc, const char * argv[]) {
    int k, input, a[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << "Start (1-3) \n";
    cin >> input;
    cout << "Val?\n";
    cin >> k;
    
    if(input == 1){
        cout << factorial(k)<<"\n";
    }
    else if(input == 2){
        cout<<fibonacci(k)<<"\n";
    }
    else if(input == 3){
        cout<<even_num(k)<<"\n";
    }else if(input == 4){
        cout << array_sum(a, k) << "\n";
    }else if(input == 5){
        int n = 3, m = 4;
        cout<<permutaiton(n, m)<<"\n";
    }else {
        cout << gcd(13, 26)<<"\n";
    }
    return 0;
}
