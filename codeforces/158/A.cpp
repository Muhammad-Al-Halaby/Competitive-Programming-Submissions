#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    if(k >= 1 && k <= n && n >= 1 && n <= 50){
        int temp,scores[n];
        for(int i=0;i<n;i++){
            cin >> temp;
            if (temp >= 0 && temp <= 100){
                scores[i]=temp;
            }
        }
        int high_score = scores[k-1];
        int next_round = 0;
        for(int i=0;i<n;i++){
                if(scores[i] > 0 && scores[i] >= high_score){
                    next_round++;
                }

        }
        cout << next_round << endl;
    }
}