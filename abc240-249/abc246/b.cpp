#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int A,B;
  cin >> A >> B;
  double x, y;
  
  x = A / sqrt(A*A + B*B);
  y = B / sqrt(A*A + B*B);
  
  cout << fixed << setprecision(11) << x;
  cout << " ";
  cout << fixed << setprecision(11) << y;
}
