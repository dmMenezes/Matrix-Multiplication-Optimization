// refer to readme.md for explanation.

#include <iostream>
#include <vector>
#include <chrono> // for timimg the tasks

const int dim = 1000; // matrix dimensions

// regular multiplication of matrices using 3 nested loops. C = A.B
void regularMultiplyMatrices(
    // A is a immutable reference of type vector(vector(int))
    const std::vector<std::vector<int>>& A,
    // B is a immutable reference of type vector(vector(int))
    const std::vector<std::vector<int>>& B,
    // C is a reference of type vector(vector(int))
    std::vector<std::vector<int>>& C) {
    // i and j are iterators for rows and columns
    // k is iterator to perform dot multiplication of row of A and column of B
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            C[i][j] = 0;
            for (int k = 0; k < dim; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/*  optimized multiplication of matrices using pointers. *C = *A.*B
    nested loops are used still but for only iterators and not for
    looping elements 
*/
void optimisedMultiplyMatrices(int* A, int* B, int* C) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            *(C + i * dim + j) = 0;
            for (int k = 0; k < dim; k++) {
                *(C + i * dim + j) += *(A + i * dim + k) * *(B + k * dim + j);
            }
        }
    }
}

int main() {
    std::cout << "Multiplying matrices... " << std::endl;
    // initialise matrices A and B with 1's. dimensions are (dim, dim)
    // initialise matrix C with 0's. dimensions are (dim, dim)
    std::vector<std::vector<int>> A(dim, std::vector<int>(dim, 1));
    std::vector<std::vector<int>> B(dim, std::vector<int>(dim, 1));
    std::vector<std::vector<int>> C(dim, std::vector<int>(dim, 0));
    
    // dynamic pointers to matrices
    int* A_ptr = new int[dim * dim];
    int* B_ptr = new int[dim * dim];
    int* C_ptr = new int[dim * dim]();  //initialise with 0's

    // initialise A and B with 1's
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            A_ptr[i * dim + j] = 1;
            B_ptr[i * dim + j] = 1;
        }
    }

    // measure performance

    // regular multiplication
    auto startRegular = std::chrono::high_resolution_clock::now();
    regularMultiplyMatrices(A, B, C);
    auto endRegular = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> regularDuration = endRegular - startRegular;

    // optimized multiplication
    auto startOptimized = std::chrono::high_resolution_clock::now();
    optimisedMultiplyMatrices(A_ptr, B_ptr, C_ptr);
    auto endOptimized = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> optimisedDuration = endOptimized - startOptimized;

    // output the time taken to perform multiplication for both
    std::cout << "Regular Matrix Multiplication Time: " << regularDuration.count() << " seconds" << std::endl;
    std::cout << "Optimized Matrix Multiplication Time: " << optimisedDuration.count() << " seconds" << std::endl;

    // clear memory to avoid leakage
    delete[] A_ptr;
    delete[] B_ptr;
    delete[] C_ptr;

    return 0;
}
