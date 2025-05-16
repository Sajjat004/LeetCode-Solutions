int MOD = 1e9 + 7;

class MatrixExpo {
public:
  vector<vector<int>> matrix;
  int rows, cols;

  MatrixExpo(int rows, int cols) : rows(rows), cols(cols) { matrix.resize(rows, vector<int>(cols)); }
  MatrixExpo(const vector<vector<int>>& mat) : rows(mat.size()), cols(mat[0].size()), matrix(mat) {}
  MatrixExpo(const MatrixExpo& other) : rows(other.rows), cols(other.cols), matrix(other.matrix) {}

  MatrixExpo operator+(const MatrixExpo& other) const {
    assert(rows == other.rows && cols == other.cols);

    MatrixExpo result(rows, cols);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        result.matrix[i][j] = (matrix[i][j] + other.matrix[i][j]) % MOD;
      }
    }

    return result;
  }

  MatrixExpo operator-(const MatrixExpo& other) const {
    assert(rows == other.rows && cols == other.cols);

    MatrixExpo result(rows, cols);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        result.matrix[i][j] = (matrix[i][j] - other.matrix[i][j] + MOD) % MOD;
      }
    }

    return result;
  }

  MatrixExpo operator*(const MatrixExpo& other) const {
    assert(cols == other.rows);

    MatrixExpo result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < other.cols; ++j) {
        for (int k = 0; k < cols; ++k) {
          result.matrix[i][j] = (result.matrix[i][j] + (1LL * matrix[i][k] * other.matrix[k][j]) % MOD) % MOD;
        }
      }
    }

    return result;
  }

  MatrixExpo& operator+=(const MatrixExpo& other) { return *this = *this + other; }
  MatrixExpo& operator-=(const MatrixExpo& other) { return *this = *this - other; }
  MatrixExpo& operator*=(const MatrixExpo& other) { return *this = *this * other; }
  bool operator==(const MatrixExpo& other) const { return matrix == other.matrix; }
  bool operator!=(const MatrixExpo& other) const { return matrix != other.matrix; }

  static MatrixExpo identity(int size) {
    MatrixExpo result(size, size);
    for (int i = 0; i < size; ++i) {
      result.matrix[i][i] = 1;
    }

    return result;
  }

  MatrixExpo power(long long exp) const {
    assert(rows == cols);

    MatrixExpo result = identity(rows);
    MatrixExpo base = *this;

    while (exp) {
      if (exp & 1) {
        result = result * base;
      }
      base = base * base;
      exp >>= 1;
    }

    return result;
  }
};

class Solution {
public:
  int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    vector<int> initialFreq(26, 0);
    for (char c : s) {
      initialFreq[c - 'a']++;
    }

    MatrixExpo transformationMatrix(26, 26);
    for (int i = 0; i < 26; ++i) {
      for (int j = 1; j <= nums[i]; ++j) {
        transformationMatrix.matrix[(i + j) % 26][i] = 1;
      }
    }

    MatrixExpo powerMatrix = transformationMatrix.power(t);

    MatrixExpo result(26, 1);
    for (int i = 0; i < 26; ++i) {
      result.matrix[i][0] = initialFreq[i];
    }

    result = powerMatrix * result;

    int totalLength = 0;
    for (int i = 0; i < 26; ++i) {
      totalLength = (totalLength + result.matrix[i][0]) % MOD;
    }

    return totalLength;
  }
};

// Problem Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description/