#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

template <typename T_container, typename T_value>
void insert_sorted(T_container& v, T_value value) {
    v.insert(upper_bound(v.begin(), v.end(), value), value);
}

void analog_signal(vector<double>& vec) {
    generate(vec.begin(), vec.end(), [t = 0]() mutable {
            return 220 * cos(t++ * (2 * M_PI/60) + (M_PI / 2)); });
}

double signalError(vector<double>& analogUm, vector<int>& digitalUm) {
    return inner_product(analogUm.begin(), analogUm.end(), digitalUm.begin(), 0.0,
        plus<double>{}, [](double a, int b) { return pow(a - b, 2); });
}

int main() {
    //Task 1
    vector<int> v { 2, 6, 7, 9, 10, 1, 8, 3, 4, 5 };
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>{cout, " "});
    cout << endl;
    insert_sorted(v, 4);
    copy(v.begin(), v.end(), ostream_iterator<int>{cout, " "});
    cout << endl;

    //Task 2
    vector<double> analogUm(100);
    vector<int> digitalUm(100);
    analog_signal(analogUm);
    copy(analogUm.begin(), analogUm.end(), digitalUm.begin());
    cout << "Analog signal:" << endl;
    copy(analogUm.begin(), analogUm.end(), ostream_iterator<double>{cout, " "});
    cout << "Digital signal:" << endl;
    copy(digitalUm.begin(), digitalUm.end(), ostream_iterator<int>{cout, " "});
    cout << endl;
    cout << "Erroe is: ";
    cout << signalError(analogUm, digitalUm) << endl;
    return 0;
}
