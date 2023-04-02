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
  int N, K;
  cin >> N >> K;

  vector<string> vec(N);
  vector<string> vec2;
  rep(i,0,N) {
    cin >> vec.at(i);
  }

  rep(i,0,K) {
    vec2.push_back(vec.at(i));
  }

  sort(vec2.begin(), vec2.end());

  rep(i,0,K) {
    cout << vec2.at(i) << endl;
  }
}
