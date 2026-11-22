#include <iostream>
using namespace std;

class Matrix {
    int a[2][2];

public:
    Matrix() {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                a[i][j] = 0;
    }

    void read() {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                cin >> a[i][j];
    }

    Matrix operator+(const Matrix& m) const {
        Matrix result;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.a[i][j] = a[i][j] + m.a[i][j];

        return result;
    }

    void display() const {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                cout << a[i][j] << " ";

            cout << endl;
        }
    }
};

int main() {
    Matrix m1, m2, sum;

    cout << "Enter 4 elements for first 2x2 matrix:\n";
    m1.read();

    cout << "Enter 4 elements for second 2x2 matrix:\n";
    m2.read();

    sum = m1 + m2;

    cout << "Sum of matrices:\n";
    sum.display();

    return 0;
}