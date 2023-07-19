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
  int N;
  cin >> N;

  int ten = N / 16;
  int ichi = N % 16;
  auto f = [](int x) {
    if (x >= 0 && x <= 9) return char(x + '0');
    else return char(x - 10 + 'A');
  };

  string s = "";
  s += f(ten);
  s += f(ichi);
  cout << s << endl;
}
