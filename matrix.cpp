/*
Name: EECS 348 Lab 8
Description: Implementation of matrix operations
Inputs: Test file labeled input.txt
Outputs: Matrix operations results
Collaborators: ChatGpt
Other sources: ChatGpt
Author: Mahin Rehman
Creation date: 04/02/2025
*/
//include the header file for the Matrix class
#include "matrix.hpp"
#include <iomanip>

//use the standard namespace
using namespace std;

//constructor that initializes an empty NxN matrix
Matrix::Matrix(size_t N) {
    // set the matrix size
    size = N;

    //resize the matrix to N rows
    data.resize(size);

    //loop through each row
    for (size_t i = 0; i < size; ++i) {
        // resize each row to have N columns
        data[i].resize(size);
    }
}

//constructor that reads matrix data from a file stream
Matrix::Matrix(ifstream &input) {
    // read the matrix size from the file
    if (size == 0) {
        input >> size;
    }
    

    //resize the matrix to N rows
    data.resize(size);

    //loop through each row
    for (size_t i = 0; i < size; ++i) {
        //resize each row to have N columns
        data[i].resize(size);

        //oop through each column in this row
        for (size_t j = 0; j < size; ++j) {
            // read each element into the matrix
            input >> data[i][j];
        }
    }
}

//function to print the matrix with formatting
void Matrix::print_matrix() const {
    //loop through each row
    for (size_t i = 0; i < size; ++i) {
        //loop through each column
        for (size_t j = 0; j < size; ++j) {
            //print each number with width 4 for alignment
            cout << setw(4) << data[i][j];
        }
        //go to the next line after each row
        cout << endl;
    }
}

//function to add two matrices and return the result
Matrix Matrix::add_matrix(const Matrix &other) const {
    //create a new matrix to store the result
    Matrix result(size);

    //loop through each row
    for (size_t i = 0; i < size; ++i) {
        //loop through each column
        for (size_t j = 0; j < size; ++j) {
            //add corresponding elements from both matrices
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    //return the resulting matrix
    return result;
}

//function to multiply two matrices and return the result
Matrix Matrix::multiply_matrix(const Matrix &other) const {
    //create a new matrix to store the result
    Matrix result(size);

    //loop through rows of this matrix
    for (size_t i = 0; i < size; ++i) {
        //loop through columns of other matrix
        for (size_t j = 0; j < size; ++j) {
            //initialize the result cell to 0
            result.data[i][j] = 0;

            //compute the dot product for cell [i][j]
            for (size_t k = 0; k < size; ++k) {
                // multiply and add to result
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    //return the resulting matrix
    return result;
}

//function to calculate the sum of both diagonals
int Matrix::diagonal_sum() const {
    //initialize the sum
    int sum = 0;

    //loop through the matrix indices
    for (size_t i = 0; i < size; ++i) {
        //add element from the main diagonal
        sum += data[i][i];

        //add element from the secondary diagonal
        sum += data[i][size - i - 1];
    }

    //if matrix has odd size, subtract the center 
    if (size % 2 == 1) {
        //subtract the middle element once
        sum -= data[size / 2][size / 2];
    }

    //return the final sum
    return sum;
}

//function to swap two rows in the matrix
void Matrix::swap_rows(size_t row1, size_t row2) {
    //check if both row indices are valid
    if (row1 < size && row2 < size) {
        //swap the entire rows using standard swap
        swap(data[row1], data[row2]);
    }
}

//function to swap two columns in the matrix
void Matrix::swap_columns(size_t col1, size_t col2) {
    //check if both column indices are valid
    if (col1 < size && col2 < size) {
        //loop through each row
        for (size_t i = 0; i < size; ++i) {
            // swap the two column elements
            swap(data[i][col1], data[i][col2]);
        }
    }
}

//function to update an element at a given row and column
void Matrix::update_element(size_t row, size_t col, int value) {
    //check if both indices are within bounds
    if (row < size && col < size) {
        //set the new value at the specified location
        data[row][col] = value;
    }
}

//construct matrix from a 2D vector
Matrix::Matrix(const std::vector<std::vector<int>>& input) {
    //set the matrix size to the number of rows
    size = input.size();

    //assign the input data to the matrix
    data = input;
}

//get the value at a specific position in the matrix
int Matrix::get_value(size_t row, size_t col) const {
    //return the value at the given row and column
    return data.at(row).at(col);
}

//set the value at a specific position in the matrix
void Matrix::set_value(size_t row, size_t col, int value) {
    // set the value at the specified row and column
    data.at(row).at(col) = value;
}

//return the size of the matrix
size_t Matrix::get_size() const {
    // return the number of rows or columns
    return size;
}

//overload + operator to add two matrices
Matrix Matrix::operator+(const Matrix& other) const {
    // create a new matrix with the same size
    Matrix result(size);

    //add corresponding elements
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    //return the result matrix
    return result;
}

//overload * operator to multiply two matrices
Matrix Matrix::operator*(const Matrix& other) const {
    //create a new matrix with the same size
    Matrix result(size);

    //perform matrix multiplication
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result.data[i][j] = 0;
            for (size_t k = 0; k < size; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    //return the result matrix
    return result;
}

//get the sum of the major diagonal
int Matrix::sum_diagonal_major() const {
    // initialize sum
    int sum = 0;

    //loop through major diagonal
    for (size_t i = 0; i < size; ++i) {
        //add diagonal element
        sum += data[i][i];
    }

    //return total
    return sum;
}

//get the sum of the minor diagonal
int Matrix::sum_diagonal_minor() const {
    //initialize sum
    int sum = 0;

    //loop through minor diagonal
    for (size_t i = 0; i < size; ++i) {
        //add diagonal element from top-right to bottom left
        sum += data[i][size - 1 - i];
    }

    //return total
    return sum;
}

//alias for swap_columns 
void Matrix::swap_cols(size_t col1, size_t col2) {
    //use existing swap_columns function
    swap_columns(col1, col2);
}
