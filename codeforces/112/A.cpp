#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    transform(s2.begin(),s2.end(),s2.begin(),::tolower);
    bool equal = true;
    for(int i = 0;i < s1.length();i++){
        if(s1[i] < s2[i]){
            cout << -1;
            equal = false;
            break;
        }
        else if(s2[i] < s1[i]){
            cout << 1;
            equal = false;
            break;
        }
    }

    if(equal) cout << 0;
}