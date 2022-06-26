#include <bits/stdc++.h>
using namespace std;

long A[21] {0};

void read(int n){ 
    for (int i = 0; i < n; ++i) cin >> A[i];
}

void solve(int n){
    long max_neg_numb {-1000000}, max_neg_index {0},
         min_pos_numb {1000000}, min_pos_index {0},
         numb_of_pos {1}, max_numb_of_pos {0},
         sum_of_neg {0}, max_sum_of_neg{-10000000}, numb_of_neg {1},
         best {0};
    for (int i = 0; i < n; ++i){
10        if (A[i] < 0){ 
            if (A[i] > max_neg_numb){
            max_neg_numb = A[i];
            max_neg_index = i;
            }
            numb_of_pos = 1;
            sum_of_neg += A[i];
            if (A[i + 1] < 0){
                sum_of_neg += A[i + 1];
                numb_of_neg++;
                if (sum_of_neg > max_sum_of_neg){
                    max_sum_of_neg = sum_of_neg;
                    best = numb_of_neg;
                }
            } 
            sum_of_neg = 0;
        } 
        if (A[i] > 0){
            if (A[i] < min_pos_numb){
                min_pos_numb = A[i];
                min_pos_index = i;
            }
            if (A[i + 1] > 0) numb_of_pos++;
            max_numb_of_pos = max(numb_of_pos, max_numb_of_pos);
            numb_of_neg = 1;
        } 
    }
    cout << max_neg_numb << " " << max_neg_index + 1 << "\n";
    cout << min_pos_numb << " " << min_pos_index + 1 << "\n";
    cout << max_numb_of_pos << "\n";
    cout <<best << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("BAI10.INP", "r", stdin);
    // freopen("BAI10.OUT", "w", stdout);
    int n; cin >> n;
    read(n); solve(n);
    return 0;
}