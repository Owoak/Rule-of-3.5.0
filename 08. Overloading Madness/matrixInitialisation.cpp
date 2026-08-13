#include "Matrix.h"

Matrix& Matrix::operator=(const std::vector<std::vector<int>>& data) {
	this->_data = data;
	return *this;
}
Matrix& Matrix::operator+=(const Matrix& other) {
	std::vector<std::vector<int>> new_data = this->_data;
	for (int row = 0; row != new_data.size(); row++) {
		for (int collumn = 0; collumn != new_data.size(); collumn++) {
			//checks if the smaller vector is valid
			bool check = (other._data.size() > row) and (other._data.size() > collumn);
			if (check) {
				new_data[row][collumn] += other._data[row][collumn];
			}
		}
	}
	this->_data = new_data;
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& other) {
	for (int row = 0; row != this->_data.size(); row++) {
		for (int collumn = 0; collumn != this->_data.size(); collumn++) {
			bool check = (other._data.size() > row) and (other._data.size() > collumn);
			if (check) {
				this->_data[row][collumn] -= other._data[row][collumn];
			}
		}
	}
	return *this;
}
Matrix& Matrix::operator*=(const Matrix& other) {
	for (int row = 0; row != this->_data.size(); row++) {
		for (int collumn = 0; collumn != this->_data.size(); collumn++) {
			bool check = (other._data.size() > row) and (other._data.size() > collumn);
			if (check) {
				this->_data[row][collumn] *= other._data[row][collumn];
			}
		}
	}
	return *this;
}
Matrix& Matrix::operator/=(const Matrix& other) {
	for (int row = 0; row != this->_data.size(); row++) {
		for (int collumn = 0; collumn != this->_data.size(); collumn++) {
			bool check = (other._data.size() > row) and (other._data.size() > collumn);
			if (check) {
				if (other._data[row][collumn] == 0) {
					this->_data[row][collumn] = 0;
				}
				else {
					this->_data[row][collumn] /= other._data[row][collumn];
				}
			}
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
	for (int row = 0; row != matrix._data.size(); row++) {
		for (int collumn = 0; collumn != matrix._data.size(); collumn++) {
			os << matrix._data[row][collumn] << ' ';
		}
		os << std::endl;
	}
	return os;
}