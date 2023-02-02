#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N,K;
  cin >> N >> K;
  vector<string> S(N, "");
  rep(i,0,N) cin >> S.at(i);
  
  int ans = 0;
  for (int i=0; i < (1<<N); i++) {
    vector<int> alph(30,0);
    for (int j=0; j<N; j++) {
      if (i & (1<<j)) {
        string st = S.at(j);
        rep(k,0,st.size()) {
          int al = int(st.at(k) - 'a');
          alph.at(al) += 1;
        }
      }
    }
    int tmp = 0;
    rep(ite,0,30) {
      if (alph.at(ite) == K) tmp++;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
