#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int replace_num=0;
    replace_num = s.find("{");
    s.replace(replace_num,1,"");
    replace_num = s.find("}");
    s.replace(replace_num,1,"");
    s.erase(remove(s.begin(), s.end(), ','), s.end());
    s.erase(remove(s.begin(), s.end(), ' '), s.end());

    for(int i = 0;i<s.length();i++){
        for(int j = i+1;j<s.length();j++){
                if(s[i] == s[j]){
                        s.replace(j,1,"");
                        j--;
                }

        }
    }

    cout << s.length();

}