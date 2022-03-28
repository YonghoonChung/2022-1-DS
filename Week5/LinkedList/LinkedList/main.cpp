//
//  main.cpp
//  LinkedList
//
//  Created by Yonghoon Chung on 2022/03/28.
//

#include <iostream>
using namespace std;

class node{
public:
    string name;
    double score;
    node *link;
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
    double score_sum();
    double get_score(string t_name);
    int remove_a_node(string t_name);
};
my_list::my_list(){
    head = NULL;
    tail = NULL;
}
void my_list::add_to_head(node t){
    node *p;
    p = new node;
    *p = t;
    p->link = head;
    head = p;
    if(tail == NULL){
        tail = p;
    }
}
void my_list::add_to_tail(node t){
    node *p;
    p = new node;
    *p = t;
    p->link = NULL;
    if(tail!=NULL){
        tail->link = p;
    }else{
        head = p;
    }
    tail = p;
}
node my_list::delete_from_head(){
    node temp;
    node *t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if(head == NULL){
        tail=NULL;
    }
    return temp;
}
int my_list::num_nodes(){
    node *curr = head;
    int count = 0;
    while(curr!=NULL){
        count++;
        curr = curr->link;
    }
    return count;
}
bool my_list::list_empty(){
    return (head == NULL);
}
double my_list::score_sum(){
    node *curr=head;
    double sum =0;
    while(curr!=NULL){
        sum += curr->score;
        curr = curr ->link;
    }
    return sum;
}
double my_list::get_score(string t_name){
    node *curr = head;
    bool result = false;
    while(curr!= NULL){
        if(curr->name == t_name){
            result = true;
            break;
        }
        curr = curr->link;
   }
    if(!result){
        //cout<< "There is no "<<t_name<<"\n";
        return -999.999;
    }
    return curr->score;
}
int my_list::remove_a_node(string t_name){
    node* curr = head;
    node *prev = NULL;
    while(curr!=NULL && curr->name != t_name){
        prev = curr;
        curr = curr->link;
    }
    if(curr == NULL){
        return 0;
    }
    if(prev){//첫 노드가 아니라면
        prev->link = curr->link;
    }
    else{ // 첫 노드라면
        head = curr->link;
    }
    if(head == NULL){//노드가 한개 였다면
        tail = NULL;
    }
    if(curr->link == NULL){
        tail = prev;
    }
    delete curr;
    return 1;
}

int main(int argc, const char * argv[]) {
    my_list a;
    node tmp;
    
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    cout<<a.num_nodes()<<" : " << a.score_sum() << "\n";
    
    tmp.set_data("Park", 91.3);
    a.add_to_tail(tmp);
    cout<<a.num_nodes()<<" : " << a.score_sum() << "\n";
    
    tmp = a.delete_from_head();
    cout << tmp.name << " is deleted.\n";
    
    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);
    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp);
    cout<<a.num_nodes()<<" : " << a.score_sum() << "\n";
    cout<<"Park's score : " << a.get_score("Park") << "\n";
    
    //cout<<a.num_nodes()<<" : " << a.score_sum() << "\n";
     if(a.remove_a_node("Kim")==1){
        cout<<"Kim is deleted from the list.\n";
    }
    cout<<a.num_nodes()<<" : " << a.score_sum() << "\n";
    return 0;
    
}
