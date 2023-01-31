#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i,0,N) cin >> H.at(i);

  string ans = "Yes";
  rep(i,1,N) {
    if (H.at(i) < H.at(i-1)) ans = "No";
    if (H.at(i) > H.at(i-1)) H.at(i)--;
  }
  cout << ans << endl;
}
