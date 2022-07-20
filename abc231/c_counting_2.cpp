#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N,Q;
  cin >> N >> Q;
  
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  sort(A.begin(), A.end());
  
  rep(i,0,Q) {
    int x;
    cin >> x;
    
    cout << N - (lower_bound(A.begin(), A.end(), x) - A.begin()) << endl;
  }
}

