#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

// include vector container
#include <vector>

// include input/output library
#include <iostream>

// include file stream library
#include <fstream>

// include string library
#include <string>

// include standard library for size_t
#include <cstddef>

class Matrix {
private:
    // store matrix data in 2D vector
    std::vector<std::vector<int>> data;

    // size of the matrix (N x N)
    size_t size;

public:
    // constructor that sets matrix size
    Matrix(size_t N);

    // constructor that loads matrix from file
    Matrix(std::ifstream &input);

    // function to print matrix to console
    void print_matrix() const;

    // function to add another matrix
    Matrix add_matrix(const Matrix &other) const;

    // function to multiply another matrix
    Matrix multiply_matrix(const Matrix &other) const;

    // function to return the sum of both diagonals
    int diagonal_sum() const;

    // function to swap two rows
    void swap_rows(size_t row1, size_t row2);

    // function to swap two columns
    void swap_columns(size_t col1, size_t col2);

    // function to update a specific cell
    void update_element(size_t row, size_t col, int value);
};

#endif