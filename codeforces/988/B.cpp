#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool cmp(string s1, string s2){
    if(s1.length() < s2.length())
        return 1;
    return 0;
}
int main(){
    int n;
    cin >> n;
    string arr[n];
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n,[&] (const string &s, const string &t) {
		return s.size() < t.size();});
    for(int i = n-1;i>0;i--){
        if(!strstr(arr[i].c_str(),arr[i-1].c_str())){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0;i<n;i++){
        cout << arr[i] << endl;
    }
}
