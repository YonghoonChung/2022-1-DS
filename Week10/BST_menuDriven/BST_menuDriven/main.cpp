//
//  main.cpp
//  BST_menuDriven
//
//  Created by Yonghoon Chung on 2022/05/03.
//

#include <iostream>
using namespace std;

class bst_node{
public:
    string phoneNo;
    string bDate;
    string name;
    bst_node* left, * right;
    bst_node();
    bst_node(string s1, string s2, string s3); // 솔직히 이거 왜 있는지 모르겠다.
    void set_data(string s1, string s2, string s3);
};
bst_node::bst_node(){
    phoneNo = "00000000";
    bDate = "999999";
    name = "Yonghoon Chung";
}
bst_node::bst_node(string s1, string s2, string s3){
    set_data(s1, s2, s3);
}

void bst_node::set_data(string s1, string s2, string s3){
    phoneNo = s1;
    bDate = s2;
    name = s3;
}

class bst_tree{
    bst_node* root;
    int csize;
public:
    bst_tree();
    void insert_node(bst_node t);
    void show_inorder();
    bst_node search(string tid);
    int size();
    void empty();
    friend void inorder_print(bst_tree* t);
};

bst_tree::bst_tree(){
    root = NULL;
    csize = 0;
}
void bst_tree::insert_node(bst_node t){
    bst_node* p;
    bst_node* tmp;
    
    tmp = new bst_node;
    *tmp = t;
    tmp -> left = NULL; // leaf 노드이기 때문에 둘다 포인터가 널이다.
    tmp -> right = NULL;
    
    if(root == NULL){
        root = tmp;
        return;
    }
    
    p = root;
    while(1){
        if(p -> phoneNo == t.phoneNo){ // 같은 키값의 데이터가 존재하면 fail
            cout << "Insertion Failed : the Key " << t.phoneNo << " already exist." << endl;
            return;
        }
        if(p->phoneNo < t.phoneNo){
            if(p->right == NULL){
                p->right = tmp;
                return;
            }
            else
                p = p->right;
        }
        else{
            if(p->left == NULL){
                p -> left = tmp;
                return;
            }
            else
                p = p->left;
        }
    }
}

void inorder_print(bst_node* p){
    if(p == NULL)
        return;
    inorder_print(p->left);
    cout << p->phoneNo << " : " << p->bDate << " : " << p->name << "\n";
    inorder_print(p->right);
}

void bst_tree::show_inorder(){
    inorder_print(root);
}

bst_node bst_tree::search(string tid){
    bst_node* p;
    p = root;
    if(root == NULL){
        bst_node tmp;
        tmp.set_data("00000000", "999999", "Yonghoon Chung"); // 근데 이거 없이 윗 코드로만으로도 가능할 듯;;;;
        cout << "The list is empty.\n";
        return tmp;
    }
    while(1){
        if(p->phoneNo == tid)
            return (*p);
        if(p->phoneNo < tid){
            if(p->right == NULL){
                bst_node tmp;
                tmp.set_data("00000000", "999999", "No Name"); // 근데 이거 없이 윗 코드로만으로도 가능할 듯;;;;
                cout << "The key "<<tid<<" does not exist.\n";
                return tmp;
            }
            else
                p = p->right;
        }
        else{
            if(p->left == NULL){
                bst_node tmp;
                tmp.set_data("00000000", "999999", "Yonghoon Chung"); // 근데 이거 없이 윗 코드로만으로도 가능할 듯;;;;
                cout << "The key "<<tid<<" does not exist.\n";
                return tmp;
            }
            else
                p = p -> left;
        }
    }
}

int show_menu(){
    int choice;
    cout << "---------------------\n";
    cout << "| 1. 새로운 원소 추가\t|\n";
    cout << "| 2. 원소 조회\t\t\t|\n";
    cout << "| 3. 전체 목록 보기\t\t|\n";
    cout << "| 4. 종료\t\t\t\t|\n";
    cout << "\t\t명령 선택 : ";
    cin >> choice;
    cout << "---------------------\n";
    return choice;
}
void insert_new_node(bst_tree* t){
    bst_node temp;
    string phoneNo;
    string bDate;
    string name;
    cout << "전화번호 입력해주세요 ('-' 없이 입력해주세요)\n";
    cin >> phoneNo;
    cout << "생일을 입력해주세요 (YYMMDD 형식으로 입력해주세요)\n";
    cin >> bDate;
    cout << "이름을 입력해주세요 (영어로만 가능)\n";
    cin >> name;
    temp.set_data(phoneNo, bDate, name);
    t->insert_node(temp);
}

void search_by_name(bst_tree* t){
    bst_node temp;
    string search;
    cout << "검색할 전화번호를 검색하세요\n";
    cin >> search;
    
    temp = t->search(search);
    
    cout << "\n -- " << search << "'s record ---" << endl;
    cout << " Student's Phone Number : " << temp.phoneNo << endl;
    cout << " Student's Birth Date : " << temp.bDate << endl;
    cout << " Student's Name : " << temp.name << endl;
    return;
}

void inorder_print(bst_tree* t){
    bst_node* p;
    p = t->root; // 이거 friend 함수 만들기
    if(p == NULL){
        cout << "The list is empty. Please add new elements\n";
        return;
    }
    inorder_print(p->left);
    cout << p->phoneNo << " : " << p->bDate << " : " << p->name << "\n";
    inorder_print(p->right);
}

int main(int argc, const char * argv[]) {
    bst_tree t1;
    int choice = 0;
    cout << "🥳어서오세요🥳\n";
    while(choice != 4){
        choice = show_menu();
        if(choice == 1){
            insert_new_node(&t1);
        }
        if(choice == 2){
            search_by_name(&t1);
        }
        if(choice == 3){
            inorder_print(&t1);
        }else{
            cout << "다시 입력하세요!\n";
        }
        
    }
    cout << "😊감사합니다!😊\n";
    return 0;
}
