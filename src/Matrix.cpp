#include "Matrix.h"

Matrix::Matrix(unsigned row, unsigned col, double init) {
    rows = row;
    cols = col;
    matrix = vector<vector<double>>(row, vector<double>(col, init));
}

Matrix::Matrix(const Matrix& other){
    rows = other.rows;
    cols = other.cols;
    matrix = vector<vector<double>>(rows, vector<double>(cols));
    copy(other.matrix.begin(), other.matrix.end(), matrix.begin());
}

Matrix Matrix::operator*(Matrix& other){
    Matrix m(rows, other.getCols(), 0);
    if (cols != other.getRows()) {
        throw invalid_argument("Make sure the other matrix's rows == the columns of this matrix");
    }
    double sum = 0.0;
    for (unsigned r = 0; r < rows; r++) {
        for (unsigned c = 0; c < other.getCols(); c++) {
            sum = 0.0;
            for (unsigned i = 0; i < cols; i++) {
                sum += matrix.at(r).at(i) * other(i, c);
            }
            m(r, c) = sum;
        }
    }
    return m;
}
double& Matrix::operator()(const unsigned &row, const unsigned &col) {
    return matrix.at(row).at(col);
}
void Matrix::print() const {
    cout << "Matrix:" << endl;
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            cout << "[" << matrix[i][j] << "] ";
        }
        cout << endl;
    }
}

unsigned Matrix::getCols() const {
    return cols;
}

unsigned Matrix::getRows() const  {
    return rows;
}

bool Matrix::operator==(const Matrix& rhs) const {
    if (cols != rhs.getCols() || rows != rhs.getRows()) {
        return false;
    }
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            if (matrix.at(i).at(j) != rhs.matrix.at(i).at(j)) {
                return false;
            }
        }
    }
    return true;
}