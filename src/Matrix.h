#pragma once

#include <vector>
#include <cmath>
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
     * Matrix Addition Operator
    */
    Matrix operator+(Matrix& other);

    /**
     * Matrix Subtraction Operator
    */
    Matrix operator-(Matrix& other);

    /**
     * Matrix Multiplication operator
    */
    Matrix operator*(Matrix& other);

    /**
     * Matrix Scaling operator
     * Note scalar needs to be a named variable
    */
    Matrix operator*(double& scalar);

    /**
     * Other Matrix scaling operator 
    */
    friend Matrix operator*(double& scalar, const Matrix& other);

    /**
     * Use for element access in the matrix, for example Matrix(9, 9) will return 
     * the entry at row 9 column 9
    */
    double& operator()(const unsigned &row, const unsigned &col);

    /**
     * Operator == to help with testing, sees if all elements of matrix are the same 
    */
    bool operator==(const Matrix& rhs) const;

    /**
     * Gets cols from Matrix
    */
    unsigned getCols() const;

    /**
     * Get rows from matrix
    */
    unsigned getRows() const;

    /**
     * Prints the Matrix, used for testing 
    */
    void print() const;
    
private:
    //Number of rows in this matrix
    unsigned rows;
    //Number of cols in this matrix
    unsigned cols;
    //2D vector used to store the matrix values
    vector<vector<double>> matrix;
};


