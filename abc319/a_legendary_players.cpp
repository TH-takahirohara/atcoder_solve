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

  vector<vector<string>> vec = {
    {"tourist", "3858"},
    {"ksun48", "3679"},
    {"Benq", "3658"},
    {"Um_nik", "3648"},
    {"apiad", "3638"},
    {"Stonefeang", "3630"},
    {"ecnerwala", "3613"},
    {"mnbvmar", "3555"},
    {"newbiedmy", "3516"},
    {"semiexp", "3481"}
  };
  
  rep(i,0,vec.size()) {
    if (S == vec.at(i).at(0)) {
      cout << vec.at(i).at(1) << endl;
      return 0;
    }
  }
}
