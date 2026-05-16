#include <iostream>
#include <stdexcept>
using namespace std;

// Template class for a Matrix
template <typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols]; {}
        }
    }
    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }
    T& operator()(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw out_of_range("Index out of bounds");
        return data[r][c];
    }
    Matrix<T> transpose() {
        Matrix<T> transposed(cols, rows);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                transposed(j, i) = data[i][j];
        return transposed;
    }
    void display() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};
int main() {
    try {
        Matrix<int> mat(3, 3);
        mat(0, 0) = 1; mat(0, 1) = 2; mat(0, 2) = 3;
        mat(1, 0) = 4; mat(1, 1) = 5; mat(1, 2) = 6;
        mat(2, 0) = 7; mat(2, 1) = 8; mat(2, 2) = 9;
        cout << "Original Matrix:\n";
        mat.display();
        Matrix<int> transposed = mat.transpose();
        cout << "\nTransposed Matrix:\n";
        transposed.display();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
