// include the header file for the Matrix class
#include "matrix.hpp"

// include standard library for command-line arguments
#include <cstdlib>

// include standard input/output stream
#include <iostream>

// include file stream for reading matrix data
#include <fstream>

// use the standard namespace
using namespace std;

// main function - program entry point
int main(int argc, char *argv[]) {
    // check if the user provided a file name as argument
    if (argc < 2) {
        // print an error message if not enough arguments
        cout << "Usage: " << argv[0] << " <input_file>" << endl;

        // exit the program with error code
        return 1;
    }

    // get the filename from the command line arguments
    string filename = argv[1];

    // open the input file
    ifstream input(filename);

    // check if file was successfully opened
    if (!input) {
        // print error message
        cout << "Error: Cannot open file " << filename << endl;

        // exit the program with error code
        return 1;
    }

    // read matrix size once
    size_t N;
    input >> N;

    // create matrix A
    Matrix A(N);

    // fill matrix A with values
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            int val;
            input >> val;
            A.update_element(i, j, val);
        }
    }

    // create matrix B
    Matrix B(N);

    // fill matrix B with values
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            int val;
            input >> val;
            B.update_element(i, j, val);
        }
    }


    // print the first matrix
    cout << "Matrix A:" << endl;
    A.print_matrix();

    // print the second matrix
    cout << endl << "Matrix B:" << endl;
    B.print_matrix();

    // perform addition of matrices
    Matrix sum = A.add_matrix(B);

    // print the result of addition
    cout << endl << "A + B:" << endl;
    sum.print_matrix();

    // perform multiplication of matrices
    Matrix product = A.multiply_matrix(B);

    // print the result of multiplication
    cout << endl << "A * B:" << endl;
    product.print_matrix();

    // calculate and print the diagonal sums of Matrix A
    cout << endl << "Sum of diagonals of Matrix A: ";
    cout << A.diagonal_sum() << endl;

    // demonstrate swapping rows
    A.swap_rows(0, 1);
    cout << endl << "Matrix A after swapping row 0 and row 1:" << endl;
    A.print_matrix();

    // demonstrate swapping columns
    A.swap_columns(0, 1);
    cout << endl << "Matrix A after swapping column 0 and column 1:" << endl;
    A.print_matrix();

    // update an element in Matrix A
    A.update_element(2, 2, 999);
    cout << endl << "Matrix A after updating element at (2, 2) to 999:" << endl;
    A.print_matrix();

    // return success code
    return 0;
}
