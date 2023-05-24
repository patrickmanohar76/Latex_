#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"    

int main()
{
    double c = 9;
    double a = 6;
    double theta = M_PI * 1 / 4;

    double **A, **B, **D, **C, **e1;
    double **m_1, **m_2, **n_1, **n_2;
    double m1, m2, n1, n2;
    double dot_product_m, dot_product_n;
    double angADB, angACB;

    A = loadtxt("a.dat",2, 1);
    e1 = loadtxt("e1.dat",2, 1);
    
    	B = createMat(2,1);
	B = scalar_mul(e1, 2, 1, c);
    
    double cosine = cos(M_PI/2 - theta);
    double sine = sin(theta);
    
    D = createMat(2,1);
    D[0][0]=cosine;
    D[1][0]=sine;

    D = scalar_mul(D, 2, 1, c);

    C = createMat(2,1);
    C[0][0]=cosine;
    C[1][0]=-sine;

    C = scalar_mul(C, 2, 1, c);
    
    m_1 = linalg_sub(D, A, 2, 1);
    m_2 = linalg_sub(D, B, 2, 1);
    n_1 = linalg_sub(C, A, 2, 1);
    n_2 = linalg_sub(C, B, 2, 1);

    m1 = linalg_norm(m_1, 2);
    m2 = linalg_norm(m_2, 2);
    n1 = linalg_norm(n_1, 2);
    n2 = linalg_norm(n_2, 2);

    dot_product_m = matmul(transpose(m_1,2,1),m_2,1,2,1);
	angACB = acos(dot_product_m / (m1*m2))*(180/M_PI);
	dot_product_n = matmul(transpose(n_1,2,1),n_2,1,2,1);
	angACB = acos(dot_product_n / (n1*n2))*(180/M_PI);

    if(round(angADB) == round(angACB))
    {
        printf("âˆ  ADB = âˆ  ACB\n");
    }

    return 0;
}
