#include<iostream>
#include<algorithm>

using namespace std;

char convert(char x){
    if(isupper(x)) return tolower(x);
    else return toupper(x);
}
int main(){
    string s;
    char c;
    int upper = 0,lower = 0;
    while(cin >> c){
        if(isupper(c)) upper++;
        else lower++;
        s += c;
    }
    bool first = islower(s[0]);
    if(lower == 0 || upper == s.length()-1 && first){
        transform(s.begin(),s.end(),s.begin(),convert);
    }
    cout << s;
}