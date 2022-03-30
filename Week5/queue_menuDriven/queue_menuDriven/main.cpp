//
//  main.cpp
//  queue_menuDriven
//
//  Created by Yonghoon Chung on 2022/03/30.
//

#include <iostream>
#define INSERT 1
#define DELETE 2
#define SHOW_FRONT 3
#define QUIT 4
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

class my_queue{
private:
    node *front, *rear;
    int len;
public:
    my_queue();
    void insert_q(node t);
    node delete_q();
    bool q_empty(); // 비어있을시 1 리턴
    node front_element();
};
void my_queue::insert_q(node t){
    node *p;
    p = new node;
    *p = t;
    p->link = NULL;
    if(q_empty()){
        front = p;
        rear = p;
    }else{
        rear->link = p;
        rear = p;
    }
    len ++;
}
node my_queue::delete_q(){
    node temp; // 값을 받고 리턴하기 위한 변수
    node *t; // 삭제할 것을 가리키기 위한 변수
    t = front; // 삭제 할 것 가리킴
    temp = *front; // 리턴 값 받음
    front = front -> link;
    delete t;
    len--;
    return temp;
}
bool my_queue::q_empty(){
    return front == NULL;
}

my_queue::my_queue(){
    front = NULL;
    rear = NULL;
    len = 0;
}

node my_queue::front_element(){
    node tmp;
    if(!q_empty())
        return (*front);
    else{
        cout << "ERROR : queue empty\n\n";
        return tmp;
    }
}

int get_a_cmd(){
    int n;
    cout << "1. Insert a node\n";
    cout << "2. Delete a node\n";
    cout << "3. Show the front element\n";
    cout << "4. Quit\n";
    cout << "\t\tSelect a command : ";
    cin >> n;

    return n;
}

void node_insert(my_queue &a){
    node tmp;
    string tname;
    double tscore;
    cout << "---------------------\n";
    cout<<"| Name : ";
    cin >> tname;
    cout << "| Score : ";
    cin >> tscore;
    cout << "---------------------\n";
    tmp.set_data(tname, tscore);
    a.insert_q(tmp);
}
void node_delete(my_queue &a){
    node tmp;
    if(a.q_empty()){
        cout << "---------------------\n";
        cout<<"The queue is empty.\n";
        cout << "---------------------\n";
        return;
    }
    tmp = a.delete_q();
    cout << "---------------------\n";
    cout << "|The node deleted :|\n";
    cout << "|" <<tmp.name << ":" << tmp.score << "|\n";
    cout << "---------------------\n";
}
void show_front(my_queue &a){
    node tmp;
    if(a.q_empty()){
        cout << "---------------------\n";
        cout << "The queue is empty.\n";
        cout << "---------------------\n";
        return;
    }
    tmp = a.front_element();
    cout << "---------------------\n";
    cout <<"The front element :\n";
    cout << tmp.name << ":" << tmp.score << "\n";
    cout << "---------------------\n";
}
int main(int argc, const char * argv[]) {
    my_queue a;
    int cmd;
    do{
        cmd = get_a_cmd();
        switch(cmd){
            case INSERT: node_insert(a);
                break;
            case DELETE: node_delete(a);
                break;
            case SHOW_FRONT: show_front(a);
                break;
            case QUIT:
                cout << "---------\n";
                cout << "Bye!!\n";
                cout << "---------\n";
        }
    }while(cmd!=QUIT);
    return 0;
}
