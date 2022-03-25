//
//  main.cpp
//  Recurssion_nMax
//
//  Created by Yonghoon Chung on 2022/03/24.
//

#include <iostream>
using namespace std;

int max(int x,int y){
    if(x>y){
        return x;
    }else{
        return y;
    }
}
int find_max(int arr[], int n){ // 이번 과제는 내가 인터넷을 보면서 답을 알았다. 하지만 이제는 이해를 완료했다
    // 비교 방법: 배열이 존재한다면 n-1번째 수와 n-2까지의 배열 중 제일 큰 수 와 비교한다.
    // 즉, 재귀를 사용하여 첫번째 배열까지 간 다음, 첫 번째 배열과 두번째 배열의 대소 비교후, 제일 큰 수와 3번재 배열과 비교를 한다.
    if(n == 1){
        return arr[0]; //2. 마지막 n == 1이 되었을 때 첫번째 배열을 리턴
    }
    int max = find_max(arr, n-1); // 1. find_max함수에 들어오면 이곳을 지나게 되고 n이 1까지 내려간다. 첫번쩨 배열을 max에 넣는다
    if(max > arr[n-1]) //3. 리턴 받은 값을 비교한다
        return max;
    else
        return arr[n-1];
        
//    }else{
//        return max(arr[n-1], find_max(arr, n-1));
//    }
}

int main(){
    int a[10] = {24, 12, 33, 27, 41, 15, 84, 52, 16, 72};

    int m;
    m = find_max(a, 10);
    cout << m << endl;

    return 0;
}


