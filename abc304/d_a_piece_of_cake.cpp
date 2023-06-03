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
  int W, H;
  cin >> W >> H;
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  rep(i,0,N) cin >> X.at(i) >> Y.at(i);

  int A, B;
  // vector<int> a(A), b(B);
  cin >> A;
  vector<int> a(A);
  rep(i,0,A) cin >> a.at(i);
  cin >> B;
  vector<int> b(B);
  rep(i,0,B) cin >> b.at(i);

  // vector<vector<int>> ichi(B+1, vector<int>(A+1));
  map<pair<int,int>,int> mp;
  rep(i,0,N) {
    int numx = lower_bound(a.begin(), a.end(), X.at(i)) - a.begin();
    int numy = lower_bound(b.begin(), b.end(), Y.at(i)) - b.begin();
    // ichi.at(numy).at(numx)++;
    mp[make_pair(numx, numy)] += 1;
  }

  int min_v = 1e9;
  int max_v = 0;
  if (mp.size() < (A+1) * (B+1)) min_v = 0;
  for (auto p : mp) {
    auto key = p.first;
    auto val = p.second;
    max_v = max(max_v, val);
    min_v = min(min_v, val);
  }
  cout << min_v << " " << max_v << endl;
}
