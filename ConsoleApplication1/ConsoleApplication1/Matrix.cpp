#include "Matrix.h"

void Matrix::AllocateMemory() {
	matrix = new double* [ySize];
	for(int i = 0; i < ySize; i++) {
		matrix[i] = new double[xSize];
		for (int j = 0; j < xSize; j++) {
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(int y, int x) {
	if (y < 1 || x < 1) {
		throw std::invalid_argument("Matrix size must be greater than 0");
	}
	xSize = x;
	ySize = y;
	AllocateMemory();
}

Matrix::Matrix(int size) : Matrix(size, size) {}

Matrix::Matrix() : Matrix(1, 1) {}

Matrix::Matrix(int y, int x, double** matrix) : Matrix(y, x) {
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			try {
				this->matrix[i][j] = matrix[i][j];
			}
			catch (std::out_of_range& e) {
				throw std::out_of_range("Matrix index out of range");
			}
		}
	}
}

Matrix::Matrix(const Matrix& other) {
	xSize = other.xSize;
	ySize = other.ySize;
	AllocateMemory();
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < ySize; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int Matrix::GetX() {
	return xSize;
}

int Matrix::GetY() {
	return ySize;
}

double Matrix::Get(int y, int x) {
	if(y < 0 || y >= ySize || x < 0 || x >= xSize) {
		throw std::out_of_range("Matrix index out of range");
	}
	return matrix[y][x];
}

Matrix Matrix::operator+(const Matrix& other) {
	if(xSize != other.xSize || ySize != other.ySize) {
		throw std::invalid_argument("Matrix sizes do not match for addition");
	}
	Matrix result(ySize, xSize);
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
		}
	}
	return result;
}

Matrix Matrix::operator-(const Matrix& other) {
	try {
		Matrix result = (-1) * other;
		return *this + result;
	}
	catch (std::invalid_argument& e) {
		throw std::invalid_argument("Matrix sizes do not match for subtraction");
	}
}

Matrix Matrix::operator*(const Matrix& other) {
	if (xSize != other.ySize) {
		throw std::invalid_argument("Matrix sizes do not match for multiplication");
	}
	Matrix result(ySize, other.xSize);
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < other.xSize; j++) {
			for (int k = 0; k < xSize; k++) {
				result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
			}
		}
	}
	return result;
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this == &other) {
		return *this;
	}
	this->~Matrix();
	xSize = other.xSize;
	ySize = other.ySize;
	AllocateMemory();
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
	try {
		*this = *this * other;
		return *this;
	}
	catch(std::invalid_argument& e) {
		throw std::invalid_argument("Matrix sizes do not match for multiplication");
	}
}

Matrix& Matrix::operator+=(const Matrix& other) {
	try {
		*this = *this + other;
		return *this;
	}
	catch (std::invalid_argument& e) {
		throw std::invalid_argument("Matrix sizes do not match for addition");
	}
}

Matrix& Matrix::operator-=(const Matrix& other) {
	try {
		*this = *this - other;
		return *this;
	}
	catch (std::invalid_argument& e) {
		throw std::invalid_argument("Matrix sizes do not match for subtraction");
	}
}

Matrix Matrix::operator*(double scalar) {
	Matrix result = *this;
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			result.matrix[i][j] *= scalar;
		}
	}
	return result;
}

Matrix operator*(double scalar, const Matrix& matrix) {
	Matrix result = matrix;
	for (int i = 0; i < result.ySize; i++) {
		for (int j = 0; j < result.xSize; j++) {
			result.matrix[i][j] *= scalar;
		}
	}
	return result;
}

Matrix& Matrix::operator*=(double scalar) {
	*this = *this * scalar;
	return *this;
}

bool Matrix::operator==(const Matrix& other) {
	if(xSize != other.xSize || ySize != other.ySize) {
		return false;
	}
	for(int i = 0; i < ySize; i++) {
		for(int j = 0; j < xSize; j++) {
			if(matrix[i][j] != other.matrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix& other) {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, Matrix& matrix) {
	int max_width = 0;
	for (int i = 0; i < matrix.ySize; i++) {
		for (int j = 0; j < matrix.xSize; j++) {
			double value = matrix.Get(i, j);
			int width = value < 0 ? std::log10(-value) + 2 : std::log10(value) + 1;
			max_width = std::max(max_width, width);
		}
	}
	for (int i = 0; i < matrix.ySize; i++) {
		os << "\n";
		for (int j = 0; j < matrix.xSize; j++) {
			os << "[" << std::setw(max_width) << matrix.matrix[i][j] << "]";
		}
	}
	return os;
}

Matrix Matrix::Transposition() {
	Matrix result(xSize, ySize);
	for (int i = 0; i < xSize; i++) {
		for (int j = 0; j < ySize; j++) {
			result.matrix[i][j] = matrix[j][i];
		}
	}
	return result;
}

double Matrix::Trace() {
	if (xSize != ySize) {
		throw std::invalid_argument("Matrix is not square");
	}
	double result = 0;
	for (int i = 0; i < ySize; i++) {
		result += matrix[i][i];
	}
	return result;
}
