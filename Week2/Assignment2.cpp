//
//  main.cpp
//  Assignment2
//
//  Created by Yonghoon Chung on 2022/03/08.
//

#include <iostream>
using namespace std;

class Weight{
private:
    int weight_kg;
    int weight_gram;

public:
    void set_weight(int kg, int gram);
    int get_weight();
    Weight add_weight(Weight w1, Weight w2);
    bool less_than(Weight w1, Weight w2);
};

void Weight::set_weight(int kg, int gram){
    weight_kg = kg;
    weight_gram = gram;
}

int Weight::get_weight(){
    return (weight_kg*1000+weight_gram);
}

Weight add_weight(Weight w1, Weight w2){
    Weight new_Weight;
    int total;
    total = w1.get_weight()+w2.get_weight();
    new_Weight.set_weight(total/1000, total%1000);
    return new_Weight;
}

bool less_than(Weight w1, Weight w2){
    if(w1.get_weight()<w2.get_weight()){
        return true;
    }
    else{
        return false;
    }
}

int main(int argc, const char * argv[]) {
    Weight w1, w2, w3;
    w1.set_weight(3,400);
    w2.set_weight(5,700);
    w3 = add_weight(w1,w2);
    cout<<w3.get_weight()<<" grams\n";
    if(less_than(w1,w2)){
        cout<<"yes.\n";
    }else{
        cout<<"no\n";
    }
    return 0;
}
