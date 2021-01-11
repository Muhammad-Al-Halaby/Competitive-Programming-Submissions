#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n >= 1 && n <= 100000){
        string magents[n];
        for(int i=0;i < n;i++){
            cin >> magents[i];
        }

    int groups_num=0;
    for(int i=0;i < n;i++){
            if(i+1 < n){
                if((magents[i])[1] != (magents[i+1])[0]){
                    continue;
                }
                else if((magents[i])[1] == (magents[i+1])[0]){
                        groups_num++;
                        continue;
                }
        }
    }
        cout << groups_num+1 << endl;
    }
}