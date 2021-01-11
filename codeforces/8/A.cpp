#include <iostream>
#include <string>
#include<algorithm>

using namespace std;

int main(){
    string s,flags_1,flags_2,rev_s;
    cin >> s;
    cin >> flags_1;
    cin >> flags_2;
    rev_s = s;
    reverse(rev_s.begin(),rev_s.end());

    bool a_b=true;
    bool b_a=true;

    if(s.find(flags_1) != string::npos && s.find(flags_2) != string::npos){
            int first = s.find(flags_1) + flags_1.length();
            s.replace(0,first,"");
            first --;
            int second = s.find(flags_2) + first + 1;
            if(first >= second) a_b = false;
    }
    else a_b=false;


    if(rev_s.find(flags_1) != string::npos && rev_s.find(flags_2) != string::npos){
            int first = rev_s.find(flags_1) + flags_1.length();
            rev_s.replace(0,first,"");
            first --;
            int second = rev_s.find(flags_2) + first + 1;
            if(first >= second) b_a = false;
    }
    else b_a = false;


    if(a_b && !(b_a)) cout << "forward";
    else if(b_a && !(a_b)) cout << "backward";
    else if(a_b && b_a) cout << "both";
    else cout << "fantasy";

}