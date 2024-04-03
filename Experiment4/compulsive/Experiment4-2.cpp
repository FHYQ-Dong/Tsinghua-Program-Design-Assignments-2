#include <iostream>
#include <cstring>

template <typename T>
class Matrix {
    private:
        size_t rows, cols;
        T* data;

    template<typename U>
    friend std::istream& operator >> (std::istream& os, const Matrix<U>& m);
    template<typename U>
    friend std::ostream& operator << (std::ostream& os, const Matrix<U>& m);

    public:
        Matrix(size_t rows=1, size_t cols=1) : rows(rows), cols(cols) {
            data = new T[rows*cols];
            memset(data, 0, rows*cols*sizeof(T));
        }
        Matrix(const Matrix<T>& m) : rows(m.rows), cols(m.cols) {
            data = new T[rows*cols];
            memcpy(data, m.data, rows*cols*sizeof(T));
        }
        Matrix(T* d, size_t rows, size_t cols) : rows(rows), cols(cols) {
            data = new T[rows*cols];
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    data[i*cols+j] = d[i*cols+j];
                }
            }
        }
        ~Matrix() {
            delete[] data;
        }
        Matrix<T> operator + (const Matrix<T>& m) const {
            if (rows != m.rows || cols != m.cols) throw("Invalid matrix addition");
            Matrix<T> result(rows, cols);
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    result.data[i*cols+j] = data[i*cols+j] + m.data[i*cols+j];
                }
            }
            return result;
        }
        Matrix<T> operator - (const Matrix<T>& m) const {
            if (rows != m.rows || cols != m.cols) throw("Invalid matrix subtraction");
            Matrix<T> result(rows, cols);
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    result.data[i*cols+j] = data[i*cols+j] - m.data[i*cols+j];
                }
            }
            return result;
        }
        Matrix<T> operator * (const T& s) const {
            Matrix<T> result(rows, cols);
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    result.data[i*cols+j] = data[i*cols+j] * s;
                }
            }
            return result;
        }
        Matrix<T> operator / (const T& s) const {
            Matrix<T> result(rows, cols);
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    result.data[i*cols+j] = data[i*cols+j] / s;
                }
            }
            return result;
        }
        Matrix<T> operator * (const Matrix<T>& m) const {
            if (cols != m.rows) throw("Invalid matrix multiplication");
            Matrix<T> result(rows, m.cols);
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < m.cols; j++) {
                    for (size_t k = 0; k < cols; k++) {
                        result.data[i*m.cols+j] += data[i*cols+k] * m.data[k*m.cols+j];
                    }
                }
            }
            return result;
        }
        Matrix<T> operator += (const Matrix<T>& m) {
            if (rows != m.rows || cols != m.cols) throw("Invalid matrix addition");
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    data[i*cols+j] += m.data[i*cols+j];
                }
            }
            return *this;
        }
        Matrix<T> operator -= (const Matrix<T>& m) {
            if (rows != m.rows || cols != m.cols) throw("Invalid matrix subtraction");
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    data[i*cols+j] -= m.data[i*cols+j];
                }
            }
            return *this;
        }
        Matrix<T> operator *= (const T& s) {
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    data[i*cols+j] *= s;
                }
            }
            return *this;
        }
        Matrix<T> operator /= (const T& s) {
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    data[i*cols+j] /= s;
                }
            }
            return *this;
        }
        Matrix<T> operator *= (const Matrix<T>& m) {
            if (cols != m.rows) throw("Invalid matrix multiplication");
            Matrix<T> result(rows, m.cols);
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < m.cols; j++) {
                    for (size_t k = 0; k < cols; k++) {
                        result.data[i*m.cols+j] += data[i*cols+k] * m.data[k*m.cols+j];
                    }
                }
            }
            return result;
        }
        T* operator [] (size_t i) {
            return &data[i*cols];
        }
        Matrix<T> trans() const {
            Matrix<T> result(cols, rows);
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    result.data[j*rows+i] = data[i*cols+j];
                }
            }
            return result;
        }
        Matrix<T> cofactor(size_t r, size_t c) const {
            if (rows == 1 || cols == 1) throw("Invalid matrix cofactor");
            Matrix<T> result(rows-1, cols-1);
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    if (i == r || j == c) continue;
                    result.data[(i<r?i:i-1)*result.cols+(j<c?j:j-1)] = data[i*cols+j];
                }
            }
            return result;
        }
        Matrix<T> det() const {
            if (rows != cols) throw("Invalid matrix determinant");
            if (rows == 1) return data[0];
            if (rows == 2) return data[0]*data[3] - data[1]*data[2];
            T result = 0;
            for (size_t i = 0; i < rows; i++) {
                result += data[i*cols] * cofactor(i, 0);
            }
            return result;
        }
        Matrix<T> inv() const {
            if (rows != cols) throw("Invalid matrix inverse");
            T d = det();
            if (d == 0) throw("Invalid matrix inverse");
            Matrix<T> result(rows, cols);
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    result.data[i*cols+j] = cofactor(i, j) / d;
                }
            }
            return result;
        }
};

template<typename U>
std::istream& operator >> (std::istream& os, const Matrix<U>& m) {
    for (size_t i = 0; i < m.rows; i++) {
        for (size_t j = 0; j < m.cols; j++) 
            os >> m.data[i*m.cols+j];
    }
    return os;
}
template<typename U>
std::ostream& operator << (std::ostream& os, const Matrix<U>& m) {
    for (size_t i = 0; i < m.rows; i++) {
        for (size_t j = 0; j < m.cols; j++) 
            os << m.data[i*m.cols+j] << ' ';
        os << std::endl;
    }
    return os;
}


int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Matrix<int> m1((int*)(a), 3, 3), m2(3, 3);
    std::cin >> m2;
    std::cout << "m1 + m2 =\n" << (m1 + m2) << std::endl;
    std::cout << "m1 - m2 =\n" << (m1 - m2) << std::endl;
    return 0;
}