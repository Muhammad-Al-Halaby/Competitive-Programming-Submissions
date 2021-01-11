#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int main(){
    int n,big=0,counter=0;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        arr[x]++;
        if(x == big){
            counter++;
        }
        else if(x > big){
            counter = 1;
            big = x;
        }
    }
    if(counter % 2 != 0){
            cout << "Conan";
            return 0;
    }
    else{
        for(int i = 0;i<100001;i++){
            if(arr[i] % 2 != 0){
                cout << "Conan";
                return 0;
            }
        }
    }
    cout << "Agasa";
}
