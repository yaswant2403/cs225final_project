#include "Matrix.h"
//Constructors 

Matrix::Matrix(unsigned row, unsigned col, double init) {
    rows = row;
    cols = col;
    matrix = vector<vector<double>>(row, vector<double>(col, init));
}

// Operator functions

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

Matrix Matrix::operator*(double& scalar) {
    Matrix m(rows, cols, 0);
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            m(i, j) = matrix.at(i).at(j) * scalar;
        }
    }
    return m;
}

Matrix operator*(double& scalar, const Matrix& other) {
    Matrix m(other.rows, other.cols, 0);
    for (unsigned i = 0; i < other.rows; i++) {
        for (unsigned j = 0; j < other.cols; j++) {
            m(i, j) = other.matrix.at(i).at(j) * scalar;
        }
    }
    return m;
}

Matrix Matrix::operator+(Matrix& other) {
    if (cols != other.getCols() || rows != other.getRows()) {
        throw invalid_argument("Make sure matrices are both the same dimiesion");
    }
    Matrix m(rows, cols, 0);
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            m(i, j) = matrix.at(i).at(j) + other(i, j);
        }
    }
    return m;
}

Matrix Matrix::operator-(Matrix& other) {
    if (cols != other.getCols() || rows != other.getRows()) {
        throw invalid_argument("Make sure matrices are both the same dimiesion");
    }
    Matrix m(rows, cols, 0);
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            m(i, j) = matrix.at(i).at(j) - other(i, j);
        }
    }
    return m;
}

double& Matrix::operator()(const unsigned &row, const unsigned &col) {
    return matrix.at(row).at(col);
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

//Other funtions 

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
