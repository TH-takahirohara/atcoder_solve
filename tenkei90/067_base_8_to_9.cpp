// 067 N進法展開を理解しよう
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

string ch8to9(string x) {
  string revx = x;
  reverse(revx.begin(), revx.end());
  ll ten = 0;
  ll kake = 1;
  rep(i,0,(int)revx.size()) {
    ten += kake * int(revx.at(i) - '0');
    kake *= 8;
  }

  ll cnt = 0;
  ll tmp = ten;
  while (tmp > 0) {
    tmp /= 9;
    if (tmp == 0) break;
    cnt++;
  }
  
  string str = "";
  for (int i=cnt; i >= 0; i--) {
    ll div = 1;
    for (int j=0; j<i; j++) {
      div *= 9;
    }
    ll shou = ten / div;
    if (shou == 8) str += "5";
    else str += to_string(shou);
    ten -= shou*div;
  }
  
  return str;
}

int main() {
  string N;
  int K;
  cin>>N>>K;
  
  string ans = N;
  rep(i,0,K) {
    ans = ch8to9(ans);
  }
  cout << ans << endl;
}

