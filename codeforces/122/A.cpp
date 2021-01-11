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
    if(n % 4 == 0 ||n % 44 == 0 ||n % 7 == 0 ||n % 77 == 0 ||n % 47 == 0
       ||n % 74 == 0 ||n % 444 == 0 ||n % 447 == 0 ||n % 477 == 0 || n % 474 == 0 ||n % 777 == 0 ||n % 774 == 0 ||n % 744 == 0 ||n % 747 == 0
       ||n % 4444 == 0 || n % 4447 == 0 || n % 4477 == 0 || n % 4777 == 0 || n % 4744 == 0 || n % 4474 == 0
       ||n % 7777 == 0 || n % 7774 == 0 || n % 4 == 7744 || n % 7444 == 0 || n % 7477 == 0 || n % 7747 == 0){
        cout << "YES";
       }
       else cout << "NO";
}