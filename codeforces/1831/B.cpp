#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 9;

int freq[N];
int freq1[N];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n], b[n], p[n] = {1};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i && a[i] == a[i - 1]) {
                p[i] = p[i - 1] + 1;
            } else {
                p[i] = 1;
            }
            freq[a[i]] = max(freq[a[i]], p[i]);
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (i && b[i] == b[i - 1]) {
                p[i] = p[i - 1] + 1;
            } else {
                p[i] = 1;
            }
            freq1[b[i]] = max(freq1[b[i]], p[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, freq[a[i]] + freq1[a[i]]);
            ans = max(ans, freq[b[i]] + freq1[b[i]]);
        }
        
        for (int i = 0; i < n; i++)
            freq[a[i]] = 0;
        for (int i = 0; i < n; i++)
            freq1[b[i]] = 0;

        cout << ans << endl;
    }
}