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
    int n,counter=0;
    string s,s1;
    cin >> n >> s;
    transform(s.begin(),s.end(),s.begin(),::tolower);

    for(int i = 0;i<n;i++){
        if(find(s1.begin(),s1.end(),s[i]) == s1.end()){
            s1+=s[i];
            counter++;
        }
    }
    if(counter == 26)cout << "YES";
    else cout << "NO";
}