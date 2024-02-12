#include "makeUpSmoothMatrix.hpp"

double* shabalin::makeUpSmoothMatrix(const int* matrix, double* smooth, size_t rows, size_t cols)
{
    for (size_t i = 0; i < cols * rows; ++i)
    {
        double sum = 0.0;
        size_t count = 0;
        for (size_t j = -1; j <= 1; ++j)
        {
            for (size_t d = -1; d <= 1; ++d)
            {
                if (!((j == 0) && (d == 0)))
                {
                    size_t currentRow = (i / cols) + j;
                    size_t currentColumn = (i % cols) + d;
                    if ((currentRow < rows) && (currentColumn < cols) && (currentRow > 0) && (currentColumn >0))
                    {
                        size_t newPosition = currentRow * i + currentColumn;
                        sum += matrix[newPosition];
                        count++;
                    }
                }
            }
        }
        smooth[i] = sum / count;
    }
    return smooth;
};
