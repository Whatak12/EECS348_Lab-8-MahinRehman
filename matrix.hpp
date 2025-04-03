/*
Name: EECS 348 Lab 8
Description: Declaration of the Matrix class and its operations
Inputs: Test file labeled input.txt
Outputs: Matrix operations results
Collaborators: ChatGpt
Other sources: ChatGpt
Author: Mahin Rehman
Creation date: 04/02/2025
*/
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

    // construct matrix from 2D vector
    Matrix(const std::vector<std::vector<int>>& input);

    // get value at specific cell
    int get_value(size_t row, size_t col) const;

    // set value at specific cell
    void set_value(size_t row, size_t col, int value);

    // return matrix size
    size_t get_size() const;

    // overload + operator for matrix addition
    Matrix operator+(const Matrix& other) const;

    // overload * operator for matrix multiplication
    Matrix operator*(const Matrix& other) const;

    // get the sum of the major diagonal
    int sum_diagonal_major() const;

    // get the sum of the minor diagonal
    int sum_diagonal_minor() const;

    // alias for swapping columns (for test compatibility)
    void swap_cols(size_t col1, size_t col2);

};

#endif