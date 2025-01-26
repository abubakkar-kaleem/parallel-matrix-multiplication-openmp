#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

// Define the number of threads for OpenMP
#define NUM_THREADS 1

// Function prototypes
double generate_random(int *seed);
void matrix_multiplication(int l, int m, int n);

// Main function to start matrix multiplication
int main(int argc, char *argv[])
{
    printf("\n\n-----------------------------------------PDC Project-------------------------\n");
    printf("\n----------------------Matrix multiplication in-parallel using OpenMP---------\n");

    // Declare variables for number of processors and threads
    printf("\n");
    printf(" Number of processors available = %d\n", omp_get_num_procs());
    printf(" Max number of threads = %d\n", omp_get_max_threads());

    // Call matrix multiplication with sample dimensions
    matrix_multiplication(100, 100, 100);

    return 0;
}

// Function to perform matrix multiplication
void matrix_multiplication(int l, int m, int n)
{
    // Declare pointers for matrices A, B, and C
    double *A, *B, *C;
    int i, j, k, ops, seed;
    double rate;
    double time_begin, funcTime, time_elapsed, time_stop;

    // Allocate memory for matrices A, B, and C
    A = (double *)malloc(l * n * sizeof(double));
    B = (double *)malloc(l * m * sizeof(double));
    C = (double *)malloc(m * n * sizeof(double));

    // Initialize the seed for random number generation
    seed = 123456789;

    // Fill matrices B and C with random values
    for (k = 0; k < l * m; k++) {
        B[k] = generate_random(&seed);
    }
    for (k = 0; k < m * n; k++) {
        C[k] = generate_random(&seed);
    }

    // Start timing the matrix multiplication process
    funcTime = omp_get_wtime();
    time_begin = omp_get_wtime();
    omp_set_num_threads(NUM_THREADS);  // Set the number of OpenMP threads

    // Parallelized matrix multiplication
    #pragma omp parallel shared(A, B, C, l, m, n) private(i, j, k)
    {
        // Loop through the matrix multiplication operations
        #pragma omp for
        for (j = 0; j < n; j++) {
            for (i = 0; i < l; i++) {
                A[i + j * l] = 0.0;
                for (k = 0; k < m; k++) {
                    A[i + j * l] += B[i + k * l] * C[k + j * m];  // Accumulate the product
                }
            }
        }
    }

    // Stop the timer
    time_stop = omp_get_wtime();

    // Calculate floating point operations and execution time
    ops = l * n * (2 * m);
    time_elapsed = time_stop - time_begin - (time_begin - funcTime);
    rate = (double)(ops) / time_elapsed / 1000000.0;  // Rate in Mega FLOPS

    // Print the results
    printf("\n");
    printf("Matrix multiplication timing:\n");
    printf(" A = B * C\n");
    printf(" L = %d\n", l);
    printf(" M = %d\n", m);
    printf(" N = %d\n", n);
    printf(" Floating point operations: %d\n", ops);
    printf(" Time of execution = %f seconds\n", time_elapsed);
    printf(" Rate = FLOPS / dT = %f MFLOPS\n", rate);

    // Free allocated memory for matrices
    free(A);
    free(B);
    free(C);
    return;
}

// Random number generator based on a seed
double generate_random(int *seed)
{
    int k;
    double r;

    // Implement the random number generation algorithm
    k = *seed / 127773;
    *seed = 16807 * (*seed - k * 127773) - k * 2836;
    if (*seed < 0) {
        *seed = *seed + 2147483647;
    }
    
    // Return a random number between 0 and 1
    r = (double)(*seed) * 4.656612875E-10;
    return r;
}
