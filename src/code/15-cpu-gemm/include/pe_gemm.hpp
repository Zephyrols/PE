#ifndef _PE_DGEMM_HPP_
#define _PE_DGEMM_HPP_
#include<cstdint>
#include"macro.hpp"

template <class T>
void pe_gemm(int64_t M, int64_t N, int64_t K, 
                T *A, int64_t lda, 
                T *B, int64_t ldb,
                T *C, int64_t ldc) {
  int64_t i, j, k;
  for(i = 0; i < M; i++) {
    for(j = 0; j < N; j++) {
      for(k = 0; k < K; k++) {
        COL_MAJOR(C, i, j, M, N) = 
          COL_MAJOR(A, i, M, k, K) * COL_MAJOR(B, j, K, k, N);
      }
    }
  }
}

void pe_dgemm(int64_t m, int64_t n, int64_t k, 
              double *a, int64_t lda, 
              double *b, int64_t ldb,
              double *c, int64_t ldc);
#endif