#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m,sum = 0,num=0;
    cin >> n >> m;
    int ins[n],ins_copy[n];
    for(int i = 0;i<n;i++) cin >> ins[i];
    copy(ins,ins+n,ins_copy);
    vector<int> indexs;
    sort(ins,ins+n);

    for(int i = 0;i<n;i++){
        if(sum + ins[i] <= m){
            num++;
            sum += ins[i];
            int f = find(ins_copy, ins_copy+n, ins[i]) - ins_copy;
            ins_copy[f] = -1;
            indexs.push_back(f+1);
        }
    }
    cout << num << endl;
    for(int i = 0;i<num;i++){
        cout << indexs[i] << " ";
    }
}
