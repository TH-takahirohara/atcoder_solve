#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> X(M), Y(M);
  rep(i, 0, M) {
    int xtmp, ytmp;
    cin >> xtmp >> ytmp;
    xtmp--; ytmp--;
    X.at(i) = xtmp; Y.at(i) = ytmp;
  }
  
  int ans = 0;
  rep(i, 0, (1 << N)) {
    int cnt = 0;
    rep(j, 0, M) {
      if ((i & (1 << X.at(j))) && (i & (1 << Y.at(j)))) cnt++;
    }
    int num1 = __builtin_popcount(i);
    if (num1*(num1-1)/2 == cnt) ans = max(ans, num1);
  }
  
  cout << ans << endl;
}
