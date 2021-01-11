#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n,status = 0;
    cin >> n;
    vector<int> Xs,Ys;

    for(int i = 0;i<n*2;i++){
        int num;
        cin >> num;
        if(status == 0){
            Xs.push_back(num);
            status = 1;
        }
        else{
            Ys.push_back(num);
            status = 0;
        }
    }
    long long avx = *max_element(Xs.begin(),Xs.end()) - *min_element(Xs.begin(),Xs.end());
    long long avy = *max_element(Ys.begin(),Ys.end()) - *min_element(Ys.begin(),Ys.end());
    if(avx >= avy) cout << avx*avx;
    else cout << avy*avy;
}
