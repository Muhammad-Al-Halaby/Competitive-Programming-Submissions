#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,count_0 = 0,count_1 = 0;
    string s;
    cin >> n >> s;
    for(int i = 0;i<n;i++)if(s[i] == '0')count_0++; else count_1++;
    cout << abs(count_0-count_1);
    return 0;
}