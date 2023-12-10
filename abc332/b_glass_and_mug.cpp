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
  int K, G, M;
  cin >> K >> G >> M;

  int g_now = 0;
  int m_now = 0;

  rep(i,0,K) {
    if (g_now == G) {
      g_now = 0;
    } else if (m_now == 0) {
      m_now = M;
    } else {
      int utusu = min(G - g_now, m_now);
      g_now += utusu;
      m_now -= utusu;
    }
  }

  cout << g_now << " " << m_now << endl;
}
