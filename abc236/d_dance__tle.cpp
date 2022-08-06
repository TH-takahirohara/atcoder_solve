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
  int N;
  cin >> N;
  
  vector<vector<int>> vec(2*N);
  rep(i,0,2*N-1) {
    rep(j,0,2*N-1-i) {
      int tmp;
      cin >> tmp;
      vec.at(i).push_back(tmp);
    }
  }
  
  int ans = 0;
  for (int i=0; i < (1<<2*N); i++) {
    if (__builtin_popcount(i) != N) continue;
    vector<int> ones, zeros;
    rep(j,0,2*N) {
      if (i & (1<<j)) ones.push_back(j);
      if (!(i & (1<<j))) zeros.push_back(j);
    }
    
    if (ones.size() != N || zeros.size() != N) {
      cout << i << endl;
      cout << ones.size() << " " << zeros.size() << endl;
      cout << "error" << endl;
      return 0;
    }
    
    do {
      int tmp = -1;
      rep(k,0,N) {
        int fir = ones.at(k); int sec = zeros.at(k);
        if (fir > sec) swap(fir, sec);
        if (tmp == -1) tmp = vec.at(fir).at(sec - fir - 1);
        else tmp ^= vec.at(fir).at(sec - fir -1);
      }
      
      ans = max(ans, tmp);
    } while (next_permutation(zeros.begin(), zeros.end()));
  }
  cout << ans << endl;
}

