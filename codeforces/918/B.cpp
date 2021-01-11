#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    map<string, string> servers;
    while(n--){
        string x,y;
        cin >> x >> y;
        y+=';';
        servers[y] = x;
    }
    while(m--){
        string x,y,z;
        cin >> x >> y;
        map<string, string>::iterator it;
        for(it = servers.begin();it!=servers.end();it++)
            if((*it).first == y){
                z = (*it).second;
                break;
            }
        cout << x << " " << y << " #" << z << endl;
    }
}