#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int e = 0, o = 0,nums[n];
    for(int i = 0;i<n;i++){
            cin >> nums[i];
            if(nums[i] % 2 == 0) e++;
            else o++;
    }

    for(int i = 0;i<n;i++){
            if(o > e && nums[i] % 2 == 0){ cout << i+1; break;}
            else if(e > o && nums[i] % 2 != 0){ cout << i+1; break;}
    }

}