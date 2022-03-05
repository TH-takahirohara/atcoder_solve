#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  double pi = 3.141592653589793238;
  
  double T, L;
  double X, Y;
  int Q;
  cin >> T >> L >> X >> Y >> Q;
  
  for (int i=0; i<Q; i++) {
    double ei;
    cin >> ei;
    
    double z = L/2 + L * sin(2 * pi * ei / T - pi/2) / 2;
    double y = -L/2 * sin(2 * pi * ei / T);
    
    double kyori = sqrt(X * X + (Y - y) * (Y - y));
    cout << fixed << setprecision(10) << atan(z/kyori) * 180 / pi;
    cout << endl;
  }
}
