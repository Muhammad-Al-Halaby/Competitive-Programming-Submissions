#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int lower_case=0,upper_case=0;
    for(int i = 0;i < s.length();i++){
        if(islower(s[i])){
            lower_case++;
        }
        else{
            upper_case++;
        }
    }
    if(lower_case > upper_case){
        for(int i = 0;i < s.length();i++){
            s[i] = tolower(s[i]);
        }
        cout << s;
    }
    else if(upper_case > lower_case){
        for(int i = 0;i < s.length();i++){
            s[i] = toupper(s[i]);
        }
        cout << s;
    }
    else{
        for(int i = 0;i < s.length();i++){
            s[i] = tolower(s[i]);
        }
        cout << s;
    }
}
