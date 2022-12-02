#pragma once

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * Very Basic Matrix class for use in PageRank
*/
class Matrix 
{
public:
    /**
     * Matrix constructor, takes in rows & columns for the size of the matrix
     * and a double value to initialize entries in the Matrix
    */
    Matrix(unsigned row, unsigned col, double init=0);

    /**
     * Copy constructor
    */
    Matrix(const Matrix& other);

    /**
     * Matrix Addition operator, adds two matrices together
    */
    Matrix operator+(Matrix& other);

    /**
     * Matrix Subtraction operator, subtracts two matrices
    */
    Matrix operator-(Matrix& other);

    /**
     * Matrix Multiplication operator, 
    */
    Matrix operator*(Matrix& other);

    /**
     * Use for element access in the matrix, for example Matrix(9, 9) will return 
     * the entry at row 9 column 9
    */
    double& operator()(const unsigned &row, const unsigned &col);

    /**
     * Prints the Matrix, used for testing 
    */
    void print() const;
    
private:
    unsigned rows;
    unsigned cols;
    vector<vector<double>> matrix;
};

