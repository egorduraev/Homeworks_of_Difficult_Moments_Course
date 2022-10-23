#include <iostream>
#include <list>
#include <array>
#include <vector>
#include <math.h>
#include <forward_list>

using namespace std;

void printList(const list<int> &numbers) {
    for (auto n : numbers) {
        cout << n << " ";
    }
    cout << endl;
}

void Average(list<int> &numbers) {
    int sum = 0;
    for (auto n : numbers) {
        sum += n;
    }
    int average = sum / static_cast<int>(numbers.size());
    numbers.push_back(average);
}

class Matrix {
private:
    int size_m;
    vector<vector<int>> matrix_m;

public:
    Matrix(int size) {
        size_m = size;
        matrix_m.resize(size_m, vector<int>(size_m));
        for (int i = 0; i < size_m; i++) {
            for (int j = 0; j < size_m; j++) {
                matrix_m[i][j] = (rand() % 10);
            }
        }
    }

    vector<vector<int>> getMatrix() {
        return matrix_m;
    }

    int getSize() {
        return size_m;
    }

    void printMatrix() {
        for (int i = 0; i < size_m; i++) {
            for (auto it = matrix_m[i].begin();
                it != matrix_m[i].end(); it++) {
                cout << *it << ' ';
            }
        cout << endl;
        }
    }

    void GetMatr(vector<vector<int>> &mas, vector<vector<int>> &p, int i, int j, int m) {
        int ki, kj, di, dj;
        di = 0;
        for (ki = 0; ki < m - 1; ki++) {
            if (ki == i) di = 1;
            dj = 0;
            for (kj = 0; kj < m - 1; kj++) {
                if (kj == j) dj = 1;
                p[ki][kj] = mas[ki + di][kj + dj];
            }
        }
    }

    int determinant(vector<vector<int>> mas, int m) {
        int i, j, d, k, n;
        vector<vector<int>> p(m, vector<int>(m));
        j = 0; d = 0;
        k = 1;
        n = m - 1;
        if (m < 1) cout << "Can't find the determinant!";
        if (m == 1) return mas[0][0];
        if (m == 2) return mas[0][0]*mas[1][1] - mas[0][1]*mas[1][0];
        else {
            for (int i = 0; i < m; i++) {
                GetMatr(mas, p, i, 0, m);
                d = d + k * mas[i][0] * determinant(p, n);
                k = -k;
            }
            return d;
        }
    }
};


template<typename T>
class MyIterator {
private:
    const T* const m_range;
    typename T::ValueType m_value;

public:
    MyIterator(const T* const range, typename T::ValueType startValue)
        : m_range(range), m_value(startValue)
    {};

    operator typename T::ValueType() const {
        return m_value;
    }
    typename T::ValueType operator*() const {
        return m_value;
    }
    MyIterator<T>& operator++() {
        m_value += m_range->step();
        return *this;
    }
    MyIterator<T> operator++(int) {
        MyIterator<T> tempIt(*this);
        ++(*this);
        return tempIt;
    }
    bool operator!= (const MyIterator<T>& right)  {
        return !(*this == right);
    }
};

template <typename T>
class Range {
private:
    T min_m, max_m, step_m;

public:
    typedef T ValueType;

    Range(T min, T max, T step = T(1))
        : min_m(min), max_m(max), step_m(step)
    {};

    T operator[](T& i) const {
        return (min_m + (i * step_m));
    }
    size_t size() {
        return static_cast<size_t>((max_m - min_m) / step_m);
    }
    ValueType step() const {
        return step_m;
    }
    MyIterator<Range<T>> begin() {
        return MyIterator<Range<T>>(this, min_m);
    }
    MyIterator<Range<T>> end() {
        return MyIterator<Range<T>>(this, min_m + size() * step_m);
    }
};


int main() {
    //Task 1
    list<int> numbers{ 5, 3, 4, 2, 5, 9, 2, 4};
    printList(numbers);
    Average(numbers);
    printList(numbers);
    //Task 2
    Matrix matrix1(1);
    matrix1.printMatrix();
    cout << "determinant: " << matrix1.determinant(matrix1.getMatrix(), matrix1.getSize()) << endl;
    Matrix matrix2(2);
    matrix2.printMatrix();
    cout << "determinant: " << matrix2.determinant(matrix2.getMatrix(), matrix2.getSize()) << endl;
    Matrix matrix3(3);
    matrix3.printMatrix();
    cout << "determinant: " << matrix3.determinant(matrix3.getMatrix(), matrix3.getSize()) << endl;
    Matrix matrix4(6);
    matrix4.printMatrix();
    cout << "determinant: " << matrix4.determinant(matrix4.getMatrix(), matrix4.getSize()) << endl;
    //Task 3
    for (auto n : Range<int>(5, 15))
    cout << n << " ";
    cout << endl;
    for (auto n : Range<double>(5, 10, 0.25))
    cout << n << " ";
    cout << endl;
    return 0;
}
