#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N,M,K;
  cin >> N >> M;
  
  vector<int> A(M), B(M);
  rep(i,0,M) cin >> A.at(i) >> B.at(i);
  
  cin >> K;
  vector<int> C(K), D(K);
  rep(i,0,K) cin >> C.at(i) >> D.at(i);
      
  int ans = 0;
  for (int i=0; i < (1<<K); i++) {
    vector<bool> can(N+1, false);
    rep(j,0,K) {
      if (i & (1<<j)) can.at(C.at(j)) = true;
      else can.at(D.at(j)) = true;
    }
    
    int tmp = 0;
    rep(j,0,M) {
      if (can.at(A.at(j)) && can.at(B.at(j))) tmp++;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}

