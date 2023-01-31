#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

string make_number(int P, int x) {
  string strp = to_string(P);
  string strx = to_string(x);
  string addzerop = "", addzerox = "";
  rep(i,0,6 - strp.size()) addzerop += "0";
  rep(i,0,6 - strx.size()) addzerox += "0";
  return addzerop + strp + addzerox + strx;
}

int main() {
  int N,M;
  cin >> N >> M;
  vector<string> ans(M);
  vector<int> cnt(N+1);
  vector<pair<int,pair<int,int>>> vec(M);

  rep(i,0,M) {
    int p,y;
    cin >> p >> y;
    vec.at(i) = make_pair(y, make_pair(p,i));
  }

  sort(vec.begin(), vec.end());

  rep(i,0,M) {
    int p = vec.at(i).second.first;
    int idx = vec.at(i).second.second;
    cnt.at(p)++;
    ans.at(idx) = make_number(p,cnt.at(p));
  }

  rep(i,0,M) cout << ans.at(i) << endl;
}
