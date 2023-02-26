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
  vector<int> X(5*N);
  rep(i,0,5*N) cin >> X.at(i);
  sort(X.begin(), X.end());

  int sum = 0;
  rep(i,N,4*N) {
    sum += X.at(i);
  }

  cout << fixed << setprecision(10) << double(sum) / double(3 * N) << endl;
}
