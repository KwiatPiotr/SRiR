# 32 bit default optimalization
gcc matrix.c -o matrix_32_0 -O0 -m32 -fopenmp

# 64 bit default optimalization
gcc matrix.c -o matrix_64_0 -O0 -fopenmp

# 32 bit hard time optimalization
gcc matrix.c -o matrix_32_3 -O3 -m32 -fopenmp

# 64 bit hard time optimalization
gcc matrix.c -o matrix_64_3 -O3 -fopenmp

