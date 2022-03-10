#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int N, a, b;
vector<int> P, Q, jun;

int main() {
  cin >> N;
  P.assign(N, 0); Q.assign(N, 0);
  
  rep(i, 0, N) {
    cin >> P.at(i);
  }
  rep(i, 0, N) {
    cin >> Q.at(i);
  }
  
  // 順列全探索用配列の作成
  rep(i, 1, N+1) {
    jun.push_back(i);
  }
  
  int cnt = 0;
  do {
    bool pb = true;
    bool qb = true;
    rep(i, 0, N) {
      if (jun.at(i) != P.at(i)) pb = false;
      if (jun.at(i) != Q.at(i)) qb = false;
    }
    
    if (pb) a = cnt;
    if (qb) b = cnt;
    cnt++;
  } while(next_permutation(jun.begin(), jun.end()));
  
  cout << abs(a - b) << endl;
}
