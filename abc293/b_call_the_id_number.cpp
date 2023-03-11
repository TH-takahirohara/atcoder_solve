#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} else return false;}
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,0,N) {
    int a;
    cin >> a;
    a--;
    A.at(i) = a;
  }

  vector<bool> called(N);
  rep(i,0,N) {
    if (called.at(i)) continue;
    called.at(A.at(i)) = true;
  }

  vector<int> ans;
  rep(i,0,N) {
    if (!called.at(i)) ans.push_back(i+1);
  }

  cout << ans.size() << endl;
  rep(i,0,ans.size()) {
    cout << ans.at(i) << " ";
  }
  cout << endl;
}
