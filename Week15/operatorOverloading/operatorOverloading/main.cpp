//
//  main.cpp
//  operatorOverloading
//
//  Created by Yonghoon Chung on 2022/06/08.
//

#include <iostream>
using namespace std;

class weight{
public:
    int kg;
    int gram;
    weight operator+ (const weight & t);
};

weight weight::operator+(const weight &t){
    weight tmp;
    tmp.kg = kg + t.kg;
    tmp.gram = gram + t.gram;
    if (tmp.gram >= 1000){
        tmp.kg += tmp.gram/1000;
        tmp.gram = tmp.gram % 1000;
    }
    return tmp;
}

int main(int argc, const char * argv[]) {
    weight a, b, c;
    
    a.kg = 2;
    a.gram = 500;
    b.kg = 3l;
    b.gram = 700;
    
    c = a + b;
    
    cout << c.kg << "kg and " << c.gram << "grams. " << endl;
    return 0;
}
