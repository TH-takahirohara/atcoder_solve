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
  ll K;
  cin >> K;
  
  string str = "";
  while (K>0) {
    if (K % 2 == 1) str = "1" + str;
    else str = "0" + str;
    K /= 2;
  }
  
  rep(i,0,str.size()) {
    if (str.at(i) == '1') str.at(i) = '2';
  }
  
  cout << str << endl;
}

