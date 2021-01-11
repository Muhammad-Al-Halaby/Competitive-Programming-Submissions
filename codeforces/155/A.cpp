#include <iostream>

using namespace std;
 
int main() {
    int n,counter=0;
    cin >> n;
    int perf[n];
    for(int i = 1;i<=n;i++){
        cin >> perf[i];
        int more = 0,less = 0;
        for(int j = i;j>0;j--){
            if(perf[i] > perf[j])more++;
            else if(perf[i] < perf[j])less++;
        }
        if(more == i - 1 && i != 1 || i != 1 && less == i - 1)counter++;
    }
    cout << counter;
}