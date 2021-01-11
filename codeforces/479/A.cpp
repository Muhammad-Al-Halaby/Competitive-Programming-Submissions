#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    vector<int> nums;
    nums.push_back(a+b+c);
    nums.push_back(a*b*c);
    nums.push_back(a+b*c);
    nums.push_back(a*b+c);
    nums.push_back((a+b)*c);
    nums.push_back(a*(b+c));
    
    cout << *max_element(nums.begin(),nums.end()); 
}
