#include <iostream>
#include <stdexcept>
#include <string>
#include <ctime>
#include <cstdlib>

template <typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;

    void allocateMemory() {
        data = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }
    void freeMemory() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        allocateMemory();
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    ~Matrix() {
        freeMemory();
    }

    void fillFromKeyboard() {
        std::cout << "enter elements (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Element [" << i << "][" << j << "]: ";
                std::cin >> data[i][j];
            }
        }
    }
    void fillRandomStrings(int length = 5) {
        static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::string randomString;
                for (int k = 0; k < length; ++k) {
                    randomString += charset[rand() % (sizeof(charset) - 1)];
                }
                data[i][j] = randomString;
            }
        }
    }
ы
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    T maxElement() const {
        T maxVal = data[0][0];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] > maxVal) {
                    maxVal = data[i][j];
                }
            }
        }
        return maxVal;
    }

    T minElement() const {
        T minVal = data[0][0];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] < minVal) {
                    minVal = data[i][j];
                }
            }
        }
        return minVal;
    }
};
