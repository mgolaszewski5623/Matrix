#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

class Matrix
{
	int xSize;
	int ySize;
	double** matrix;

	void AllocateMemory();

public:
	Matrix();
	Matrix(int size);
	Matrix(int y, int x);
	Matrix(int y, int x, double** matrix);
	Matrix(const Matrix& other);

	~Matrix();

	int GetX();
	int GetY();
	double Get(int y, int x);

	Matrix operator+(const Matrix& other);
	Matrix operator-(const Matrix& other);
	Matrix operator*(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix operator*(double scalar);
	friend Matrix operator*(double scalar, const Matrix& matrix);
	Matrix& operator*=(double scalar);
	bool operator==(const Matrix& other);
	bool operator!=(const Matrix& other);
	friend std::ostream& operator<<(std::ostream& os, Matrix& matrix);

	Matrix Transposition();
	double Trace();
};

