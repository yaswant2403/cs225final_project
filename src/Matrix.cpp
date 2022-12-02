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
Matrix Matrix::operator+(Matrix& other){

}
Matrix Matrix::operator-(Matrix& other){

}
Matrix Matrix::operator*(Matrix& other){

}
double& Matrix::operator()(const unsigned &row, const unsigned &col){
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