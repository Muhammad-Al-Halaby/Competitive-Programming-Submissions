#include <iostream>
#include <algorithm>
#include<vector>
#include<math.h>
#include<iomanip>
#include<utility>
#include<numeric>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    int current = 0,arr[n];
    for(int i = 0;i<n;i++){
        int exit,enter;
        cin >> exit >> enter;
        current = current - exit + enter;
        arr[i] = current;
    }
    cout << *max_element(arr,arr+n);
}