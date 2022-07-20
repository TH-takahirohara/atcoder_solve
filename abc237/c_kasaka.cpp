#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  string S;
  cin >> S;
  int N = S.size();
  
  int a_sentou = 0;
  rep(i,0,N) {
    if (S.at(i) == 'a') a_sentou++;
    else break;
  }
  
  int a_back = 0;
  rep(i,0,N) {
    if (S.at(N-i-1) == 'a') a_back++;
    else break;
  }
  
  if (a_sentou > a_back) {
    cout << "No" << endl;
    return 0;
  }
  
  int kai_len = N - a_back - a_sentou;
  string ns = S.substr(a_sentou, kai_len);
  
  string ans = "Yes";
  int ssize = ns.size();
  rep(i,0,ssize/2) {
    if (ns.at(i) != ns.at(ssize - i - 1)) ans = "No";
  }
  cout << ans << endl;
}

