#include<iostream>

using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int ins = (n <= m) ? n:m;
    if(ins % 2 == 0) cout << "Malvika";
    else cout << "Akshat";
}