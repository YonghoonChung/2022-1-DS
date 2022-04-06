//
//  main.cpp
//  invert_listEqual()
//
//  Created by Yonghoon Chung on 2022/04/06.
//

#include <iostream>
using namespace std;

class node{
public:
    string name;
    double score;
    node* link;
    void set_data(string s, double n);
};

void node::set_data(string s, double n){
    name = s;
    score = n;
}

class my_list{
    node *head, *tail;
public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    void invert();
    friend bool list_equal(my_list a, my_list b);
};
my_list::my_list(){
    head = NULL;
    tail = NULL;
}
void my_list::add_to_head(node t){
    node *a;
    a = new node;
    *a = t;
    a->link = head;
    if(head == NULL){
        tail = a;
    }
    head = a;
}
void my_list::add_to_tail(node t){
    node *a;
    a = new node;
    *a = t;
    a->link = NULL;
    if(head == NULL){
        head = a;
    }
    else{
        tail->link = a;
    }
    tail = a;
}

node my_list::delete_from_head(){
    node tmp;
    node *t;
    
    t = head;
    tmp = *t;
    head = head->link;
    delete t;
    
    if(head == NULL){
        tail = NULL;
    }
    return tmp;
}

int my_list::num_nodes(){
    node *t = head;
    int count = 0;
    while(t!=NULL){
        count++;
        t=t->link;
    }
    return count;
}
bool my_list::list_empty(){
    return (head == NULL);
}
void my_list::invert(){
    node *newhead = NULL, *oldhead = head;
    node *tmp;
    
    while(oldhead!=NULL){
        tmp = newhead;
        newhead = oldhead;
        oldhead = oldhead->link;
        newhead->link = tmp;
    }
    tail = head;
    head = newhead;
}


bool equal_data(node t1, node t2){
    if(t1.name != t2.name)
        return false;
    if(t1.score!= t2.score)
        return false;
    return true;
}

bool is_equal(node* p1, node *p2){
    if((p1 == NULL)&&(p2 == NULL))
        return true;
    if((p1 == NULL)||(p2 == NULL))
        return false;
    if(equal_data(*p1, *p2))
        return(is_equal(p1->link, p2->link));
    else
        return false;
}
bool list_equal(my_list a, my_list b){
    return is_equal(a.head,b.head);
}



int main(int argc, const char * argv[]) {
    my_list a ,b;
    node tmp;
    
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 85.1);
    a.add_to_head(tmp);
    
    tmp.set_data("Choi", 85.1);
    b.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    b.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    b.add_to_head(tmp);
    tmp.set_data("Kim", 83.5);
    b.add_to_head(tmp);
    
    b.invert();
    if (list_equal(a, b))
        cout << "Yes, the two lists are identical. \n";
    else
        cout << "No, They are not identical.\n";
    tmp = b.delete_from_head();
    cout << tmp.name << " : " << tmp.score << "\n";
    
    return 0;
}
