#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n,k1,k2,fight = 0;
    queue<int> p1;
    queue<int> p2;
    cin >> n >> k1;
    for(int i = 0;i<k1;i++){
        int x;
        cin >> x;
        p1.push(x);
    }
    cin >> k2;

    for(int i = 0;i<k2;i++){
        int x;
        cin >> x;
        p2.push(x);
    }

    while(!p1.empty() && !p2.empty() && fight < 200){
        if(p1.front() > p2.front()){
            p1.push(p2.front());
            p1.push(p1.front());
            p1.pop();
            p2.pop();
        }
        else{
            p2.push(p1.front());
            p2.push(p2.front());
            p1.pop();
            p2.pop();
        }
        fight++;

    }
    if(p1.empty())
        cout << fight << " " << 2;
    else if(p2.empty())
        cout << fight << " " << 1;
    else
        cout << -1;
}