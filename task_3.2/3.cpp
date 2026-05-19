#include <bits/stdc++.h>

using namespace std;

#define int long long

const double EPSILON = 0.01;
const double DELTA = 0.05;
const double LAMBDA = 10.0;
const int NUM = 100;

const vector<string> methods = {"Чебышев", "Чернов", "ЦПТ"};
const vector<int> n_res = {2000000, 737776, 390457};

mt19937 rnd(2026);
poisson_distribution<int> poisson(LAMBDA);

signed main() {
    freopen("task_3.2/3_table.txt", "w", stdout);
    vector<double> res(n_res.size());
    for (size_t i = 0; i < methods.size(); ++i) {
        int n = n_res[i];
        int cnt = 0;

        for (int t = 0; t < NUM; ++t) {
            cerr << "Метод: " << methods[i] << ", iter = " << t+1 << endl;
            double sum = 0.0;

            for (int k = 0; k < n; ++k) {
                sum += poisson(rnd);
            }

            if (abs((sum / n) - LAMBDA) <= EPSILON) {
                ++cnt;
            }
        }
        res[i] = double(cnt) / NUM;
    }

    cout << fixed << setprecision(4);

    cout << left  << setw(12) << "Метод"
         << right << setw(12) << "n"
         << setw(12) << "Доля" << "\n";
    cout << string(48, '-') << "\n";

    for (size_t i = 0; i < methods.size(); ++i) {
        cout << left  << setw(12) << methods[i]
             << right << setw(12) << n_res[i]
             << setw(12) << res[i] << "\n";
    }

    cout << string(48, '-') << "\n";
    cout << "Теоретическая гарантия >= " << (1.0 - DELTA) << "\n";
    return 0;
}

