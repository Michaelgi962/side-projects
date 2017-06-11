/* purpose: matrix and vector operations */

#include <math.h>
#include <vector>

#include "matvecops.hpp"

/* function that returns the norm of a vector (a copy of the vector
 is passed to the function) */
double norm(std::vector<double> v)
{
    double L2norm=0;
    for (int i=0; i < (int)v.size(); i++)
        L2norm += v[i]*v[i];
    L2norm = sqrt(L2norm);
    return L2norm;
}


/* a function that computes the sum of two vectors
 a copy of the vectors is passed to the fucntion */
std::vector<double> vec_sum(std::vector<double> v1,
                            std::vector<double> v2)
{
    std::vector<double> sum(v1.size(),0);
    for (int i=0; i < (int)v1.size(); i++)
        sum[i] = v1[i]+v2[i];
    return sum;
}


/* a function that computes the difference of two vectors;
 a copy of the vectors is passes to the function */
std::vector<double> vec_diff(std::vector<double> v1,
                             std::vector<double> v2)
{
    std::vector<double> diff(v1.size(),0);
    for (int i=0; i < (int)v1.size(); i++)
        diff[i] = v1[i]-v2[i];
    return diff;
}


/* a function that multiplies a vector by a scalar;
 a copy of the vector is passed to the function */
std::vector<double> scalar_mult(double scalar,
                                std::vector<double> v)
{
    std::vector<double> y(v.size(),0);
    for (int i=0; i < (int)v.size(); i++)
        y[i] = scalar*v[i];
    return y;
}

/* a function that multiplies two vectors of the form
 vT * v; it is a assumed that the the dimensions of
 the vectors match up for multipliation: (1 x n) * (n x 1);
 copies of the vectors are passed to the function */
double vec_mult(std::vector<double> v1,
                std::vector<double> v2)
{
    double scalar=0;
    for (int i=0; i < (int)v1.size(); i++)
        scalar += v1[i]*v2[i];
    return scalar;
}
