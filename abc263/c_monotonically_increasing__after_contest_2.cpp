// bit全探索とソートの組み合わせ
#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N,M;

int main() {
  cin >> N >> M;
  
  vector<vector<int>> vec;
  
  for (int i=0; i < (1<<M); i++) {
    if (__builtin_popcount(i) != N) continue;
    vector<int> vectmp;
    rep(j,0,M) {
      if (i & (1<<j)) vectmp.push_back(j+1);
    }
    vec.push_back(vectmp);
  }
  sort(vec.begin(), vec.end());
  
  rep(i,0,vec.size()) {
    rep(j,0,N) {
      cout << vec.at(i).at(j) << " ";
    }
    cout << endl;
  }
}

