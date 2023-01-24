#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

char turn(char c) {
  if (c == 'p') return 'd';
  else return 'p';
}

int main() {
  int N;
  string S;
  cin >> N >> S;

  int st = -1;
  rep(i,0,N) {
    if (S.at(i) == 'p') {
      st = i;
      break;
    }
  }

  if (st == -1) {
    cout << S << endl;
    return 0;
  }

  vector<string> vec = {S};
  rep(i,st,N) {
    string ns = "";
    rep(j,0,st) {
      ns += S.at(j);
    }
    rep(j,st,i+1) {
      
      ns += turn(S.at(st + (i - j)));
    }
    rep(j,i+1,N) {
      ns += S.at(j);
    }
    vec.push_back(ns);
  }

  sort(vec.begin(), vec.end());
  cout << vec.at(0) << endl;
}
