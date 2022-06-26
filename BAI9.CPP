#include <bits/stdc++.h>
using namespace std;

long A[21], best {0}, k {2}, first {0};
vector <int> p;

void read(int n){ 
    for (int i = 0; i < n; ++i) cin >> A[i];
}

void solve(int n){
    for (int i = 1; i <= n; ++i){
        if ((A[i] < 0 && A[i-1] > 0)||(A[i] > 0 && A[i-1] < 0)){
            best = max(k, best);
            if (!first) first = i;
            k++;
        }
        else{
            k = 1;
            if (first){
                p.push_back(first - 1);
                first = 0;
            } 
        }
    }
    cout << best << "\n";
    for (auto i: p){
        if (i + best <= n)
            for (int j = 0; j < best; ++j)
                 cout << A[j + i] << " ";
        cout << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("BAI9.INP", "r", stdin);
    // freopen("BAI9.OUT", "w", stdout);
    int n; cin >> n;
    read(n); solve(n);
    return 0;
}