#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N, M;
vector<string> vec;
vector<string> strs;
int undmax;
vector<set<string>> sts(17);
bool flag = false;

void rec(string s, int num) {
  if (s.size() > 16) return;
  if (flag) return;
  if (num == (N-1)) {
    string tmp = s;
    tmp += vec.at(num);
    if (tmp.size() >= 3 && tmp.size() <= 16) {
      if (!sts.at(tmp.size()).count(tmp)) {
        cout << tmp << endl;
        flag = true;
      }
    }
    return;
  }

  rep(i,0,undmax-N+2) {
    string tmps = s;
    tmps += vec.at(num);
    rep(j,0,i+1) tmps += "_";
    rec(tmps, num+1);
  }
}

int main() {
  cin >> N >> M;
  vec.resize(N);
  rep(i,0,N) cin >> vec.at(i);

  rep(i,0,M) {
    string s; cin >> s;
    sts.at(s.size()).insert(s);
  }

  sort(vec.begin(), vec.end());

  int tmpsize = 0;
  rep(i,0,N) tmpsize += vec.at(i).size();
  if (tmpsize > (16 - (N - 1))) {
    cout << -1 << endl;
    return 0;
  }

  undmax = 16 - tmpsize;

  do {
    rec("", 0);
  } while (next_permutation(vec.begin(), vec.end()));

  if (!flag) cout << -1 << endl;
}
