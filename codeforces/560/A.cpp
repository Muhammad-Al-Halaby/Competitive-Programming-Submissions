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
   int arr[n];
   for(int i = 0;i<n;i++) cin >> arr[i];
   sort(arr,arr+n);
   if(arr[0] == 1)cout << -1;
   else cout << 1;
}