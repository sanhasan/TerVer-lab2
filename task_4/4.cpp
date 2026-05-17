#include <bits/stdc++.h>

using namespace std;

#define int long long

const double PI = acos(-1);
const int ITER = 302205;
const int C = pow(PI, 1.5) / 2.0;

mt19937 rnd(2026);
normal_distribution<double> normal_x(0.0, sqrt(0.5));
normal_distribution<double> normal_yz(0.0, sqrt(0.25));

signed main() {
    freopen("task_4/4_table.txt", "w", stdout);
    double sum = 0.0;

    for (int i = 0; i < ITER; ++i) {
        double x = normal_x(rnd);
        double y = normal_yz(rnd);
        double z = normal_yz(rnd);

        sum += cos(abs(x * x + y * z + x + sin(z)));
    }

    double integral = C * sum / ITER;

    cout << setprecision(9) << fixed;
    cout << integral;
    // Тут если в тупую генерить точки, то можно часто промахиваться, поэтому воспользуемся
    // аналитическим решением и сведём к поиску мат ожиданию
}

