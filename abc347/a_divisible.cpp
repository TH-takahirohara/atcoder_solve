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
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);
  vector<int> anses;
  rep(i,0,N) {
    if (A.at(i) % K == 0) {
      anses.push_back(A.at(i) / K);
    }
  }
  sort(anses.begin(), anses.end());
  rep(i,0,anses.size()) {
    cout << anses.at(i) << " ";
  }
  cout << endl;
}
