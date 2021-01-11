#include <iostream>
#include <string>

using namespace std;


int main(){
    string s;
    cin >> s;
    int sum=0,h=0,e=0,l=0,o=0;
    for(int i = s.length()-1;i >= 0;i--){
        if(s[i] == 'o' && o == 0){
            o++;
        }
        else if(o > 0){
                if(s[i] == 'l' && l  <= 1){
                    l++;
                }
                else if(l == 2){
                    if(s[i] == 'e' && e == 0){
                        e++;
                    }
                    else if(e == 1){
                        if(s[i] == 'h' && h == 0){
                            h++;
                        }
                        else if (h == 1){
                            break;
                        }
                    }
                }
        }
    }
    sum = h + e + l + o;
    if(sum == 5){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
        }
}