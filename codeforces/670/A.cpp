#include<bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   int f,x=0;
   f=2*(n/7);
   if(n%7 == 1)x=1;
   else if(n%7 > 1)x=2;
   cout << f+((n%7 == 6)?1:0) << " " << f+x;
}