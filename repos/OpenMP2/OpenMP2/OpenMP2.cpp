// OpenMP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
*Lab1: Multiply two matrices using OpenMP
*Student Name: Ismail Sheikh
*Course Name: EE8128 Parallel Computing
*Instructor Name: Dr. Nagi Mekhiel
*/

#include <cstdlib.h>
#include <iostream.h>
#include <omp.h>
#include <ctime.h>
#include <pch.h>
#include <math.h>
#include <tchar.h>

using namespace std;
/*
*Instance Variables of Matrix1, Matrix2 and Resultant Matrix
*Also, the length of the square matrix
*/
const int sizeOfMatrix = 1000;
int matrix1[sizeOfMatrix][sizeOfMatrix];
int matrix2[sizeOfMatrix][sizeOfMatrix];
int result[sizeOfMatrix][sizeOfMatrix];
/*
*Void Initailize()
*THis method initailizes both matrices (MATRIX1 and MATRIX2) with Math random values 0-9
*Update the values of both matrices, Matrix1 and Matrix2
*/
void initialize() {
	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			matrix1[i][j] = rand() % 100;
			matrix2[i][j] = rand() % 100;
		}
	}
}
/*
*Void MultiplyMatrix
*THis method multiplies both matrices (MATRIX1 and MATRIX2) without using parallelism or OpenMP
*Store the result of multiplication into the resulant MATRIX.
*/
void multiplyMatrix() {
	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			for (int k = 0; k < sizeOfMatrix; k++) {
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
}
/*
*Void DisplayMatrix
*optional method available to display any matrix
*Requires a matrix of specific size
*Display the whole matrix
*/
void displayMatrix(int matrixToDisplay[sizeOfMatrix][sizeOfMatrix]) {
	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			std::cout << matrixToDisplay[i][j] << " ";
		}
		std::cout << " \n" << endl;
	}
}
/*
*Void MultiplyMatrix
*THis method multiplies both matrices (MATRIX1 and MATRIX2) using parallelism or OpenMP
*Store the result of multiplication into the resulant MATRIX.
*/
void multiplyParallel() {
	omp_set_num_threads(4);
#pragma omp parallel for
	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			for (int k = 0; k < sizeOfMatrix; k++) {
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
}
/*
*Main of the program which is executed on RUNTIME
*/
int main(int argc, _TCHAR* argv[])
{
	//Commands for initialization of Matrices
	cout << "Generating Two Square Matrices of size: " << sizeOfMatrix;
	initialize();
	//Commands for Multiplying matrices without Parallelism and time the algoritham
	cout << "\n\nMuliplying Two matrices without Parallelism or OpenMP" << endl;
	time_t startTime = time(0);
	multiplyMatrix();
	time_t endTime = time(0);
	double timeTaken = difftime(endTime, startTime) * 1000;
	cout << "\n\tThe Multiplication took TIME in milliseconds: " << timeTaken;
	//Commands for Multiplying matrices with Parallelism and time the algoritham
	cout << "\n\nMuliplying Same Matrices with Parallelism using OpenMP" << endl;
	time_t startTimeParallel = time(0);
	multiplyParallel();
	time_t endTimeParallel = time(0);
	double timeTakenParallel = difftime(endTimeParallel, startTimeParallel) * 1000;
	cout << "\n\tThe Multiplication took TIME in milliseconds: " << timeTakenParallel;
	std::cout << "\n\n" << endl;
	system("pause");
	return 0;
}


