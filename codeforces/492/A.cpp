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
    int n,h=0,sum = 1,sum_count=1,total_sum=0;
    cin >> n;
        while(total_sum <= n){
            total_sum+=sum;
            sum_count++;
            sum+=sum_count;
            if(total_sum <= n)h++;
        }
        cout << h;
}