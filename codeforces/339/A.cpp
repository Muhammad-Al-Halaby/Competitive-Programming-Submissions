#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;


int main()
{
    int x=0;
    string s;
    cin>> s;
    const char c = '+';
    int nums[100];
   // string nums[100];
   // getline(s,s,c);
   int len = s.length();
   for(int i =0;i< len;i++)
    {
        if(s.find("+") != string::npos){
            nums[x] = atoi(s.substr(0,1).c_str());
            s.erase(0,2);
            x++;
            }
            else{
                nums[x] = atoi(s.substr(0,1).c_str());
            }
    }


    sort(nums,nums+x+1);
    for(int i =0;i <= x;i++){
        if(i != x){
        cout << nums[i] << "+";
        }
        else{
        cout << nums[i];
        }
    }

}