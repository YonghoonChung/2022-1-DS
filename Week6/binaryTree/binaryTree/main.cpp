//
//  main.cpp
//  binaryTree
//
//  Created by Yonghoon Chung on 2022/04/06.
//

#include <iostream>
using namespace std;

class node{
    string name;
    double score;
//    node *left, *right;

public:
    node *left, *right;
    string get_name();
    double get_score();
};

string node::get_name(){
    return name;
}
double node::get_score(){
    return score;
}

void inorder_traverse(node *p);
void preorder_traverse(node *p);
void postorder_traverse(node *p);


int main(int argc, const char * argv[]) {
    
    return 0;
}

void inorder_traverse(node *p){
    if(p==NULL) return;
    inorder_traverse(p->left);
    cout << p->get_name()<<" : "<<p->get_score()<<"\n";
    inorder_traverse(p->right);
}

void preorder_traverse(node *p){
    if(p==NULL) return;
    cout << p->get_name()<<" : "<<p->get_score()<<"\n";
    preorder_traverse(p->left);
    preorder_traverse(p->right);
}

void postorder_traverse(node *p){
    if(p==NULL) return;
    postorder_traverse(p->left);
    postorder_traverse(p->right);
    cout << p->get_name()<<" : "<<p->get_score()<<"\n";
}
