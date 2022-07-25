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
  string S;
  int K;
  cin >> S >> K;
  int N = S.size();
  
  vector<int> adot(N);
  rep(i,0,N) if (S.at(i) == '.') adot.at(i) = 1;
  
  vector<int> sdot(N+1);
  rep(i,0,N) sdot.at(i+1) = sdot.at(i) + adot.at(i);
  
  int ans = 0;
  int r = 0;
  for (int l=0; l < N; l++) {
    while (r < N && sdot.at(r+1) - sdot.at(l) <= K) {
      r += 1;
    }
    ans = max(ans, r-l);
  }
  
  cout << ans << endl;
}

