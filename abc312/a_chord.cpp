#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  string S;
  cin >> S;
  if (S == "ACE" || S == "BDF" || S == "CEG" || S == "DFA" || S == "EGB" || S == "FAC" || S == "GBD") {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
