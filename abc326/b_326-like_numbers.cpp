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

  while (N < 1000) {
    int hyaku = N / 100;
    int juu = (N / 10) % 10;
    int iti = N % 10;

    if (hyaku * juu == iti) {
      cout << N << endl;
      return 0;
    }
    N++;
  }
}
