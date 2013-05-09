#ifndef SLAE_H
#define SLAE_H



#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
//*******************************************************************

double* methodGauss02(const double* pA,	//Matrix of system: n*n
											const double* pB,	//Vector of free terms: n*1
											int n	//n
											);


//*******************************************************************
//*******************************************************************
//*******************************************************************
/////////////////////////////////////////////////////////////////////
double*methodGauss02(const double* pA,	//A = A[n][n]
										 const double* pB,	//B = B[n][1]
										 int n	//n - number of rows and columns
										 )
{
	static const char* methodGauss02 = "methodGauss02!";
	static const char* nullPointer = "Null-pointer!";
	static const char* noMemory = "No-memory!";
	static const char* nEquals0 = "n = 0!";

	double* X = NULL;

	if(!pA || !pB)
		printf("\n%s: %s\n", methodGauss02, nullPointer);
	else if(!n)
		printf("\n%s: %s\n", methodGauss02, nEquals0);
	else
	{
		double** A = NULL;	//A[0] -> A[0][0]
		double* B = NULL;	//
		int* ci = NULL;	//current row indexes
		int* cj = NULL; //current column indexes

		if(!(A = (double**)malloc(sizeof(double*)*n)) ||
			 !(B = (double*)malloc(sizeof(double)*n)) ||
			 !(ci = (int*)malloc(sizeof(int)*n)) ||
			 !(cj = (int*)malloc(sizeof(int)*n)) ||
			 !(A[0] = (double*)malloc(sizeof(double)*n*n))
			 )
			 printf("\n%s: %s\n", methodGauss02, noMemory);
		else
		{
			if(!(X = (double*)malloc(sizeof(double)*n)))
				printf("\n%s: %s\n", methodGauss02, noMemory);
			else
			{
				int i;	//row index
				int j;	//column index
				int k;	//row index
				int imax;	//row index of maximum element
				int jmax;	//colon index of maximum element
				int temp;
				double R;	//R = A[i+1][i] / A[i][i]
				double S;	//Si = A[i][i+1] * X[i+1] + A[i][i+2] * X[i+2] -...

				for(i = 1; i < n; i++)
					A[i] = &A[0][i*n];

				for(i = 0; i < n; i++)
				{
					ci[i] = i;
					cj[i] = i;
				}

				//Copying pA to A and B to B
				for(i = 0; i < n*n; i++)
					A[0][i] = pA[i];
				for(i = 0; i < n; i++)
					B[i] = pB[i];

				//Making A triangle
				for(i = 0; i < n-1; i++)
				{
					//Seeking for maximum element
					imax = i;
					jmax = i;
					for(k = i; k < n; k++)
						for(j = i; j < n; j++)
							if(fabs(A[ci[k]][cj[j]]) > fabs(A[ci[imax]][cj[jmax]]))
							{
								imax = k;
								jmax = j;
							}

					//if imax != i then exchanging A[i] and A[imax] rows
					if(imax != i)
					{
						temp = ci[i];
						ci[i] = ci[imax];
						ci[imax] = temp;
					}
					if(jmax != i)
					{
						temp = cj[i];
						cj[i] = cj[jmax];
						cj[jmax] = temp;
					}

					//Making 0s in i column from i+1 row to n-1 row
					for(k = i+1; k < n; k++)
					{
						R = A[ci[k]][cj[i]] / A[ci[i]][cj[i]];

						// for(j = i+1!!!...)
						for(j = i; j < n; j++)
							A[ci[k]][cj[j]] = A[ci[k]][cj[j]] - R * A[ci[i]][cj[j]];
						B[ci[k]] = B[ci[k]] - R * B[ci[i]];
					}
				}

				//Calculating X
				B[ci[n-1]] = B[ci[n-1]] / A[ci[n-1]][cj[n-1]];
				for(k = n-2; k >= 0; k--)
				{
					S = 0;
					for(j = k+1; j < n; j++)
						S = S + A[ci[k]][cj[j]] * B[ci[j]];
					B[ci[k]] = (B[ci[k]] - S) / A[ci[k]][cj[k]];
				}

				for(i = 0; i < n; i++)
					X[cj[i]] = B[ci[i]];
			}
			free(A[0]);
		}

		free(A);
		free(B);
		free(ci);
		free(cj);
	}

	return X;
}
/////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////
//LU transformation

#endif