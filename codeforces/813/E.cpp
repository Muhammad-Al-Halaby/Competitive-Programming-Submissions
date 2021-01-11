#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 9, M = 1e6 + 9;

int n, k, q, last;

struct node;
extern node *emptyNode;

struct node{
    int value;
    node *left, *right;
    node(){
        value = 0;
        left = right = this;
    }

    node(int val){
        value = val;
        left = right = this;
    }

    node(node *l, node *r, int val){
        value = val;
        left = l;
        right = r;
    }
};

node *emptyNode = new node();

node* insert(node *root, int x, int s = 0, int e = M){
    if(x < s || x > e)  return root;

    if(s == e)
        return new node(root->value + 1);

    int mid = s + (e - s) / 2;

    node *left = insert(root->left, x, s, mid);
    node *right = insert(root->right, x, mid + 1, e);

    return new node(left, right, left->value + right->value);
}

int query(node *leftRoot, node *rightRoot, int l, int r, int s = 0, int e = M){
    if(l > s || r < s)  return 0;

    if(l <= s && r >= e)
        return rightRoot->value - leftRoot->value;

    int mid = s + (e - s) / 2;
    return query(leftRoot->left, rightRoot->left, l, r, s, mid) + query(leftRoot->right, rightRoot->right, l, r, mid + 1, e);
}

vector<int> idx[M];

int calc(int x){
    int sz = idx[x].size();
    return (sz < k ? 0 : idx[x][sz - k]);
}

node* roots[N];

int main(){

    cin >> n >> k;

    roots[0] = emptyNode;
    for(int i = 1;i <= n;i++){
        int x;  cin >> x;
        int prev = calc(x);
        roots[i] = insert(roots[i - 1], prev);
        idx[x].push_back(i);
    }

    cin >> q;
    for(int i = 0;i < q;i++){
        int x, y;   cin >> x >> y;
        int l = (x + last) % n + 1;
        int r = (y + last) % n + 1;
        if(l > r)   swap(l, r);
        last = query(roots[l - 1], roots[r], 0, l - 1);
        cout << last << '\n';
    }
}