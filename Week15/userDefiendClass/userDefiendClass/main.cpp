//
//  main.cpp
//  userDefiendClass
//
//  Created by Yonghoon Chung on 2022/06/08.
//

#include <iostream>
#include <list>
using namespace std;

class s_record{
public:
    string s_id;
    string name;
    double score;
    void set_data(string s1, string s2, double n);
    bool operator< (const s_record & t) const{
        return (s_id < t.s_id);
    }
};
//bool s_record::operator<(const s_record & t){
//    return (s_id < t.s_id);
//}

int main(int argc, const char * argv[]) {
    list <s_record> a = {{"21900013", "Kim", 6.5},{"21900136", "Lee", 8.8},{"21900333", "Park", 9.2},
        {"21800442", "Choi", 7.1},{"21900375", "Ryu", 5.4},{"21700248", "Cho", 6.3},
        {"21700302", "Jung", 8.3},{"21800255", "Han", 6.9},{"21800369", "Kang", 6.3},
        {"21900401", "Yang", 9.1},{"21800123", "Moon", 8.1},{"21700678", "Seo", 7.9}};
    
    a.sort();
    
    list <s_record>::iterator p;
    for (p = a.begin(); p != a.end(); p++) {
        cout << p->s_id << endl;
    }
    
}
