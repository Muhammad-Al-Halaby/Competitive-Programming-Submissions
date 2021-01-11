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
    int n1,n2,k1,k2;
    cin >> n1 >> n2 >> k1 >> k2;
    if(n1 > n2) cout << "First";
    else if(n2 > n1 || n1 == n2) cout << "Second";
}