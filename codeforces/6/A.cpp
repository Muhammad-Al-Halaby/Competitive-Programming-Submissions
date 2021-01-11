#include <iostream>
#include<algorithm>

using namespace std;

int main(){
    int nums[4];
    for(int i=0;i<4;i++){
        cin >> nums[i];
    }
    sort(nums,nums+4);
    int s=0;
    for(int i=0;i<4;i++){
        if(i+2 < 4 && nums[i] + nums[i+1] > nums[i+2]){
            s=1;
            break;
        }
    }
    if(s==0){
        for(int i=0;i<4;i++){

            if(i+2 < 4 && nums[i] + nums[i+1] == nums[i+2]){
                s=2;
            }
        }
    }

    if(s==0){
        s=3;
    }
    if(s==1)
        cout << "TRIANGLE";
    else if(s==2)
        cout << "SEGMENT";
    else if(s==3)
        cout << "IMPOSSIBLE";
}