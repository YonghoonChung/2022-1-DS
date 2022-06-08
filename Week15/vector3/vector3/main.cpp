//
//  main.cpp
//  vector3
//
//  Created by Yonghoon Chung on 2022/06/08.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector <int> a;
    unsigned int k;
    
    a.push_back(3); a.push_back(4); a.push_back(7);
    
    vector <int> b(a);
    if(a == b)
        cout << "Yes\n";
    else
        cout << "No\n";
    
    b.push_back(8);
    if(a == b)
        cout << "Yes\n";
    else
        cout << "No\n";
    a.swap(b);
    
    for (k = 0; k< a.size(); k++)
        cout << a[k] << " : " ;
    cout << endl;
    
    for (k = 0; k<b.size(); k++)
        cout<<b[k]<< " : ";
    cout << endl;
}
