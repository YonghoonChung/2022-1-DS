//
//  main.cpp
//  Assignment7_linkedList
//
//  Created by Yonghoon Chung on 2022/04/16.
//

#include <iostream>
using namespace std;
#define Q_SIZE 10

class element{
public:
    string s_title;
    int npages;
    int price;
    element* link;
    void set_data(string s, int n1, int n2);
};

void element::set_data(string s, int n1, int n2){
    s_title = s;
    npages = n1;
    price = n2;
}

class linked_queue{
private:
    element* front;
    element* rear;
public:
    linked_queue();
    void insert_q(element t);
    element delete_q();
    bool empty();
};

linked_queue::linked_queue(){
    front = NULL;
    rear = NULL;
}

void linked_queue::insert_q(element t){
    element* p = new element;
    *p = t;
    p->link = NULL;
    if(front == NULL)
        front = p;
    else
        rear->link = p;
    rear = p;
}
element linked_queue::delete_q(){
    element* t;
    element tmp;
    if(empty())
        return tmp;
    t = front;
    tmp = *front;
    front = front->link;
    delete t;
    return tmp;
}
bool linked_queue::empty(){
    return (front == NULL);
}
int main(int argc, const char * argv[]) {
    linked_queue a;
    
    element tmp;

    tmp.set_data("C++ Programming", 534, 35000);
    a.insert_q(tmp);
    
    tmp.set_data("Data Structure", 621, 42000);
    a.insert_q(tmp);
    
    tmp.set_data("JAVA Programming", 485, 38000);
    a.insert_q(tmp);
    
    tmp.set_data("Logic Design", 532, 44000);
    a.insert_q(tmp);

    while (!a.empty() ) {
        tmp = a.delete_q();
        cout << tmp.s_title << " : " << tmp.npages  << " : " << tmp.price << "\n";
    }
    return 0;
}

