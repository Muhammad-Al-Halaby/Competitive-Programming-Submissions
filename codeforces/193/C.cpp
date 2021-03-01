#include <bits/stdc++.h>

using namespace std;

#define modulo ll (1e9 + 7)
#define EPS double (1e-9)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int n;
vector<vector<double>> matrix; // [n * (n + 1)] matrix, has n equations (rows), each equation has n coefficients (LHS) and the constant (RHS) (columns)
vector<double> solution;

int gaussian_elimination() {    // returns the number of solutions
    // convert the linear system of equations into row echelon form
    for (int i = 0; i < n; i++) {
        int mx = i; // mx = index of a row that has the largest value at index i (looking for a non-zero)
        for (int j = i + 1; j < n; j++)
            if (fabs(matrix[mx][i]) < fabs(matrix[j][i]))
                mx = j;

        swap(matrix[i], matrix[mx]);

        // divide the whole row by matrix[i][i]
        for (int j = n; j >= i; j--)
            matrix[i][j] /= matrix[i][i];

        // convert the index i to a zero in the next rows
        for (int j = i + 1; j < n; j++)
            for (int k = n; k >= i; k--)
                matrix[j][k] += matrix[i][k] * -matrix[j][i];
    }

    // find the solution by back substitution
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n];
        for (int j = n - 1; j > i; j--) {
            solution[i] -= matrix[i][j] * solution[j];
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    n = 6;
    matrix.resize(n, vector<double>(n + 1));
    solution.resize(n);

    int h[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            cin >> h[i][j];
        }
    }

    for(int x1 = 0;x1 <= 1e5;x1++) {

        for (int i = 0, r = 0; i < 4; i++)
            for (int j = i + 1; j < 4; j++, r++)
                matrix[r][n] = h[i][j] - (i == 0 ? x1 : 0);


        for (int i = 2; i <= 7; i++)
            for (int j = 0, r = 0; j < 4; j++)
                for (int k = j + 1; k < 4; k++, r++)
                    matrix[r][i - 2] = ((i >> j) & 1) ^ ((i >> k) & 1);

        gaussian_elimination();

        int ok = 1;
        for (int i = 0; i < n; i++)
            if(int(solution[i]) != solution[i] || solution[i] < 0)
                ok = 0;

        if(ok){
            int j = 0, len = accumulate(solution.begin(), solution.end(), 0) + x1;

            cout << len << '\n';

            char sol[4][len];

            while(x1--){
                for(int k = 0;k < 4;k++){
                    sol[k][j] = (k == 0 ? 'a' : 'b');
                }
                j++;
            }

            for(int i = 0;i < n;i++){
                while(solution[i]--){
                    for(int k = 0;k < 4;k++){
                        sol[k][j] = ((((i + 2) >> k) & 1) ? 'a' : 'b');
                    }
                    j++;
                }
            }

            for(int i = 0;i < 4;i++) {
                for (int j = 0; j < len; j++)
                    cout << sol[i][j];
                cout << '\n';
            }

            return 0;
        }
    }

    cout << -1;
}