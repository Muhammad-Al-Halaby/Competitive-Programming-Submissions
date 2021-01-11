#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int freq[105];

char r = 'A';

void rev(){
    if(r == 'A')r = 'B';
    else r = 'A';
}

int main(){
    init();
    int n, nice = 0;
    cin >> n;
    int arr[n];
    char ans[n+1];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for(int i = 0;i<n;i++){
        if(freq[arr[i]] == 1)ans[i] = r, rev(), nice++;
        else ans[i] = 'A';
    }
    if(!(nice & 1)){

        cout << "YES" << '\n';
        for(int i = 0;i<n;i++)
            cout << ans[i];
        return 0;
    }
    int found = false;
    for(int i = 0;i<n;i++){
        if(freq[arr[i]] > 2){ans[i] = 'B';found = 1;break;}
    }


    if(found){
        cout << "YES" << '\n';
        for(int i = 0;i<n;i++)
            cout << ans[i];
        return 0;
    }
    cout << "NO";
}
