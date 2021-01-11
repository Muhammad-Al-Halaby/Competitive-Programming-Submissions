#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 100 + 10, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc = 0){
    int n;  cin >> n;

    string s;   cin >> s;

    set<int> ones;
    set<int> zeros;

    for(int i = 0;i < n;i++){
        if(s[i] == '0') zeros.insert(i);
        else ones.insert(i);
    }

    int done[n], num = 1;
    for(int i = 0;i < n;i++){
        if(ones.empty()){
            while(zeros.size()){
                auto it = zeros.begin();
                done[*it] = num++;
                zeros.erase(it);
            }
            break;
        }
        else if(zeros.empty()){
            while(ones.size()){
                auto it = ones.begin();
                done[*it] = num++;
                ones.erase(it);
            }
            break;
        }



        auto it1 = zeros.begin();
        auto it2 = ones.begin();

        int prev = *it1 < *it2;
        int previdx = -1;
        while(true){
            if(prev == 0){
                if(ones.empty()){
                    num++;
                    break;
                }
                auto it = ones.lower_bound(previdx);
                if(it == ones.end()){
                    num++;
                    break;
                }
                done[*it] = num;
                previdx = *it;
                ones.erase(it);
                prev = 1;
            }
            else{
                if(zeros.empty()){
                    num++;
                    break;
                }
                auto it = zeros.lower_bound(previdx);
                if(it == zeros.end()){
                    num++;
                    break;
                }
                done[*it] = num;
                previdx = *it;
                zeros.erase(it);
                prev = 0;
            }
        }
    }
//
//    int done[n];
//    int i = 0, j = 0, state = 1, prev = -1, prevIdx = -1, num = 1;
//
//
//
//    while(i < zeros.size() || j < ones.size()){
//        if(state == 0){
//            if(prev == 0){
//                if(j == ones.size()){
//                    num++;
//                    state = 1;
//                }
//                else if(ones[j] < prevIdx){
//
//                }
//                else{
//                    done[ones[j]] = num;
//                    prev = 1;
//                    prevIdx = ones[j];
//                    j++;
//                }
//            }
//            else{
//                if(i == zeros.size() || zeros[i] < prevIdx){
//                    num++;
//                    state = 1;
//                }
//                else{
//                    done[zeros[i]] = num;
//                    prev = 0;
//                    prevIdx = zeros[i];
//                    i++;
//                }
//            }
//        }
//
//        //starting new subsequence
//        else{
//            if(i == zeros.size()){
//                while(j < ones.size()){
//                    done[ones[j]] = num++;
//                    j++;
//                }
//            }
//            else if(j == ones.size()){
//                while(i < zeros.size()){
//                    done[zeros[i]] = num++;
//                    i++;
//                }
//            }
//            else{
//                if(zeros[i] < ones[j]){
//                    done[zeros[i]] = num;
//                    prev = 0;
//                    prevIdx = zeros[i];
//                    state = 0;
//                    i++;
//                }
//                else{
//                    done[ones[j]] = num;
//                    prev = 1;
//                    prevIdx = ones[j];
//                    state = 0;
//                    j++;
//                }
//            }
//        }
//    }
//
    cout << *max_element(done, done + n) << '\n';
    for(int i = 0;i < n;i++)
        cout << done[i] << " ";
    cout << '\n';
}


int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
   cin >> t;
    while(t--)
        go(tc++);
}