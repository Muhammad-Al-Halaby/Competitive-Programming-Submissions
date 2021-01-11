#include <iostream>

using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int dishes[n];
    int temp_dish,first_dish=0,second_dish=0,all=0;
    for(int i = 0;i < n;i++){
        cin >> temp_dish;
        if(temp_dish == 1){
            first_dish++;
        }
        else{
            second_dish++;
        }
    }

    if(first_dish > 0){
        m = m - first_dish;
        all = m;

    }
    if(second_dish > 0 && k-second_dish < 0){
        all = m + k;
        all = all - second_dish;
    }

    if(all >= 0){
        cout << 0 << endl;
    }
    else{
        cout << -all << endl;
    }


}