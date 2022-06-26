#include <bits/stdc++.h>
using namespace std;

int A[20]; long k;
vector <int> p;

void read(int n){ 
    for (int i = 0; i < n; ++i) cin >> A[i];
}

void solve(int n){
    int best {0}, sum;
    for (int i = 0; i < n; ++i){
        k = 1;
        sum = A[i];
        for (int j = i + 1; j <= n; ++j){
            if (sum == 0){
                if (k > best){
                    best = k;
                    p.clear();
                    p.push_back(i+1);
                }
                else if (k == best) p.push_back(i+1);
            }
            k++;
            sum += A[j];
        }
    }
    if (best){
        cout << best << "\n";
        for (auto i: p) cout << i << " ";
    }
    else cout << "NO";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("BAI8.INP", "r", stdin);
    // freopen("BAI8.out", "w", stdout);
    int n; cin >> n;
    read(n); solve(n);
    return 0;
}