#include <iostream>
#include <vector>
using namespace std;

class MatrixType {
private:
    vector<vector<int>> matrix;
    int rows, cols;

public:
    MatrixType(int r = 0, int c = 0) : rows(r), cols(c) {
        matrix.resize(rows, vector<int>(cols, 0));
    }
    friend istream &operator>>(istream &in, MatrixType &m) {
        cout << "Enter elements for " << m.rows << "x" << m.cols << " matrix:\n";
        for (int i = 0; i < m.rows; ++i)
            for (int j = 0; j < m.cols; ++j)
                in >> m.matrix[i][j];
        return in;
    }
    friend ostream &operator<<(ostream &out, const MatrixType &m) {
        for (const auto &row : m.matrix) {
            for (int val : row)
                out << val << " ";
            out << endl;
        }
        return out;
    }
    MatrixType operator+(const MatrixType &m) const {
        if (rows != m.rows || cols != m.cols) {
            cout << "Matrix addition not possible (size mismatch).\n";
            return *this;
        }
        MatrixType result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        return result;
    }
    MatrixType operator-(const MatrixType &m) const {
        if (rows != m.rows || cols != m.cols) {
            cout << "Matrix subtraction not possible (size mismatch).\n";
            return *this;
        }
        MatrixType result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
        return result;
    }
    MatrixType operator*(const MatrixType &m) const {
        if (cols != m.rows) {
            cout << "Matrix multiplication not possible (dimension mismatch).\n";
            return *this;
        }
        MatrixType result(rows, m.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < m.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
        return result;
    }
};

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    MatrixType m1(r1, c1);
    cin >> m1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;
    MatrixType m2(r2, c2);
    cin >> m2;
    
    cout << "\nMatrix 1:\n" << m1;
    cout << "Matrix 2:\n" << m2;
    if (r1 == r2 && c1 == c2)
        cout << "\nAddition Result:\n" << (m1 + m2);
    else
        cout << "\nAddition not possible due to size mismatch.\n";
    if (r1 == r2 && c1 == c2)
        cout << "\nSubtraction Result:\n" << (m1 - m2);
    else
        cout << "\nSubtraction not possible due to size mismatch.\n";
    if (c1 == r2)
        cout << "\nMultiplication Result:\n" << (m1 * m2);
    else
        cout << "\nMultiplication not possible due to dimension mismatch.\n";
    
    return 0;
}