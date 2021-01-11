#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int worms[n];
    vector<int> sum;
    for(int i = 0;i<n;i++){
        cin >> worms[i];
    }

    for(int i = 0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum.push_back(worms[i] + worms[j]);
        }
    }


    int s = 0,index = 0;
    for(int i = 0;i<n;i++){
        if(find(sum.begin(),sum.end(),worms[i]) != sum.end()){
                index = i+1;
                s = worms[i];
                break;
        }
    }

    bool Finish = false;
    for(int i = 0;i<n;i++){
        Finish = false;
        for(int j=i+1;j<n;j++){
            if(worms[i] + worms[j] == s){
                cout << index << " " << max(i+1,j+1) << " " << min(i+1,j+1);
                Finish = true;
                break;
            }
        }
        if(Finish)break;
    }
    if(!Finish)cout << -1;

}