#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int dp[1000000];
int dp2[1000000];
int INF = 100000000;

int main() {
  int tetra[183];
  rep(i,1,183) {
    tetra[i] = i*(i+1)*(i+2)/6;
  }
  
  rep(i,0,1000001) {
    dp[i] = i;
    dp2[i] = i;
  }
  dp[0] = 0; dp[1] = 1;
  dp2[0] = 0; dp2[1] = 1;

  rep(i,0,1000001) {
    for (int j=2; tetra[j] <= i; j++) {

      if (i-tetra[j] >= 0) {
        dp[i] = min(dp[i], dp[i-tetra[j]]+1);
        if (tetra[j] % 2 == 1) {
          dp2[i] = min(dp2[i], dp2[i-tetra[j]]+1);
        }
      }
    }
  }
  
  while (true) {
    int num;
    cin >> num;
    if (num==0) break;
    
    cout << dp[num] << " " << dp2[num] << endl;
  }
  return 0;
}
