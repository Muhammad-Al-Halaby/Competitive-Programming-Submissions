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
    int k,n,w;
    long long cost=0;
    cin >> k >> n >> w;
    for(int i = 1;i<=w;i++){
        cost+=k*i;
    }
    if(cost > n)cout << cost-n;
    else cout << 0;
}