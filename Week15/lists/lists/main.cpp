//
//  main.cpp
//  lists
//
//  Created by Yonghoon Chung on 2022/06/08.
//

#include <iostream>
#include <list>
using namespace std;

int main(int argc, const char * argv[]) {
    list <int> a;
    list <int> ::iterator p;
    
    a.push_back(25);
    a.push_back(17);
    a.push_back(33);
    a.push_back(19);
    
    a.sort();
    
    for (p = a.begin(); p!= a.end(); p++)
        cout << *p << " : ";
    cout << endl;
}
