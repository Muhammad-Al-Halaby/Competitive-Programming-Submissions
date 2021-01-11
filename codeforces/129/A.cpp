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
   int n;
   cin >> n;
   int bags[n];
   int sum = 0;
   int ways=0;
   for(int i = 0;i<n;i++){int num; cin >> num; bags[i] = num;sum += num;}
   for(int i = 0;i<n;i++){
        if((sum - bags[i]) % 2 == 0) ways++;
   }
   cout << ways;
}