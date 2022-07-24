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
  int N;
  cin >> N;

  map<string,int> mp;
  rep(i,0,N) {
    string s;
    cin >> s;
    if (!mp.count(s)) {
      mp[s] = 1;
      cout << s << endl;
    } else {
      cout << s + "(" + to_string(mp.at(s)) + ")" << endl;
      mp.at(s) += 1;
    }
  }
}

