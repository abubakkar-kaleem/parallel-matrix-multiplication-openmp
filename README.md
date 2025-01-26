### Project Title: **Parallel Matrix Multiplication using OpenMP**

---

### Project Overview:

This project demonstrates the power of parallel processing for accelerating matrix multiplication, a critical operation in linear algebra, using the **OpenMP (Open Multi-Processing)** framework. The primary goal of the project is to implement matrix multiplication in parallel, where two matrices (of random values) are multiplied to produce a result matrix. The OpenMP framework leverages shared-memory systems, where multiple threads can access the same memory space, ensuring that the computations are performed simultaneously, reducing overall execution time.

### Objective:

Matrix multiplication is a fundamental operation in various fields, including computer graphics, machine learning, and scientific computing. This project aims to optimize matrix multiplication by using parallel processing. The implementation is done using **OpenMP**, which allows multiple processing units (threads) to divide the work and perform matrix multiplication faster than traditional sequential methods.

By utilizing OpenMP, the project achieves parallelism on multicore systems, where multiple threads work concurrently on different portions of the matrix multiplication task. The use of multiple processing units is essential for handling larger matrices efficiently, as the size and complexity of matrix multiplication grow rapidly.

### Project Details:

The project uses OpenMP to perform parallel matrix multiplication. The key function `matrix_multiplication(int l, int m, int n)` performs the main multiplication task. Matrices A, B, and C are created dynamically, filled with random values, and then multiplied using parallel loops, ensuring efficient usage of the available processing cores.

Here’s a summary of the code:

- **Matrix Initialization**: Random values are generated and assigned to matrices B and C. Matrix A will store the resulting product.
- **Parallel Matrix Multiplication**: The matrix multiplication is parallelized using OpenMP directives. The outer loop is divided among available threads to perform concurrent computations.
- **Time Measurement**: The time taken for matrix multiplication is recorded using `omp_get_wtime()` to evaluate the performance and speedup achieved with parallelization.
- **Optimized Memory Usage**: To enhance performance, a 1D array is used to store matrices, leveraging better memory locality and cache optimization.

### Key OpenMP Directives Used:
- **`#pragma omp parallel`**: Used to specify the parallel region where the computations are divided among threads.
- **`#pragma omp for`**: Parallelizes the for-loop, dividing iterations across threads.
- **`omp_set_num_threads(NUM_THREADS)`**: Sets the number of threads used in the parallel region.
- **`omp_get_num_procs()`**: Returns the number of available processors.
- **`omp_get_max_threads()`**: Returns the maximum number of threads that can be used.

### Performance Insights:

- **Speedup**: The program's speedup increases as the number of threads grows, although the speedup is not linear due to overheads and synchronization between threads.
- **Efficiency**: As the number of threads increases, the efficiency tends to decrease. This is because the computational workload is divided, but the overhead associated with thread management and communication can become significant.
- **Matrix Size Impact**: Smaller matrix sizes (e.g., 100x100) show minimal differences in runtime across different thread configurations. However, larger matrices benefit more significantly from parallelism, showing reduced execution time as more threads are used.

### Conclusion:

This project demonstrates the benefits and challenges of using parallel processing in scientific computations like matrix multiplication. While parallelism offers significant performance improvements, the overhead of managing multiple threads can reduce efficiency as the number of threads increases. However, OpenMP provides a powerful and relatively easy-to-implement way of parallelizing computationally expensive tasks like matrix multiplication.

---

### Author:

**Muhammad Abubakkar Kaleem**  
BSCS, FAST-NUCES (2018–2022)  
This project was created as part of the **Parallel and Distributed Computing** course.
