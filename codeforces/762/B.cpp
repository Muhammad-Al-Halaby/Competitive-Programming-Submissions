#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,m, num=0;
    long long cost=0;
    cin >> a >> b >> c >> m;
    multimap<int, string> mouses;
    for(int i = 0;i<m;i++){
        int x;
        string s;
        cin >> x >> s;
        mouses.insert(pair<int,string>(x,s));
    }
    multimap<int, string>::iterator it = mouses.begin();
    for(it; it != mouses.end();it++){
        if(it->second == "USB" && a){
            a--;
            cost += it->first;
            num++;
        }
        else if(it->second == "PS/2" && b){
            b--;
            cost += it->first;
            num++;
        }
        else if(c){
            c--;
            cost += it->first;
            num++;
        }
    }
    cout << num << " " << cost;
}