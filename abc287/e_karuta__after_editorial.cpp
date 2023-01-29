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

  vector<pair<string,int>> vec(N);
  rep(i,0,N) {
    string s;
    cin >> s;
    vec.at(i) = make_pair(s, i);
  }

  sort(vec.begin(), vec.end());

  vector<int> ans(N);
  rep(i,0,N-1) {
    string s1 = vec.at(i).first;
    int i1 = vec.at(i).second;
    string s2 = vec.at(i+1).first;
    int i2 = vec.at(i+1).second;

    int tmp = 0;
    rep(i,0,min(s1.size(), s2.size())) {
      if (s1.at(i) != s2.at(i)) break;
      tmp++;
    }
    chmax(ans.at(i1), tmp);
    chmax(ans.at(i2), tmp);
  }

  rep(i,0,N) {
    cout << ans.at(i) << endl;
  }
}
