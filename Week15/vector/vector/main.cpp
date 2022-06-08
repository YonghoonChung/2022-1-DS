//
//  main.cpp
//  vector
//
//  Created by Yonghoon Chung on 2022/06/08.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector <int> a;
    
    a.push_back(2);
    a.push_back(4);
    a.push_back(6);
    
    cout << a.size()<< endl;
    cout << a[1] << endl;
    
    a.pop_back();
    a.push_back(8);
    
    cout << a.front() << endl;
    cout << a.back() << endl;
}
