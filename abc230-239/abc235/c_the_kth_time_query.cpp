#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef pair<int,int> P;

int main() {
  int N, Q;
  cin >> N >> Q;
  
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  map<int, vector<int>> mp;
  rep(i,0,N) {
    if (!mp.count(A.at(i))) {
      mp[A.at(i)] = {i+1};
    } else {
      mp.at(A.at(i)).push_back(i+1);
    }
  }
  
  rep(ite,0,Q) {
    int x,k;
    cin >> x >> k;
    
    if (!mp.count(x)) {
      cout << -1 << endl;
    } else if (mp.at(x).size() < k) {
      cout << -1 << endl;
    } else {
      cout << mp.at(x).at(k-1) << endl;
    }
  }
}

