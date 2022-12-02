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
     * Matrix Multiplication operator, 
    */
    Matrix operator*(Matrix& other);

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
    unsigned rows;
    unsigned cols;
    vector<vector<double>> matrix;
};

