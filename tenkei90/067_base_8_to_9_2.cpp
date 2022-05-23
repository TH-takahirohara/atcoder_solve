// 067 N進法展開を理解しよう
// 一応解けたが、解説を見た後、そのやり方を参考に解き直したもの。
// 10進数を9進数に変換するところで、「N mod 9の値を文字列の先頭に加える」「Nを9で割る」処理を行うことでスッキリ書ける。
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
  
  string str = "";
  while (ten > 0) {
    int n = ten % 9;
    if (n == 8) str = '5' + str;
    else str = to_string(n) + str;
    ten /= 9;
  }
  
  if (str == "") return "0";
  else return str;
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

