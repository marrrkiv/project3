#include <iostream>

using namespace std;

class Matrix {
private:

	int M[20][20];
	int n;
	int trace;

public:

	Matrix(int size);
	Matrix() { }
	friend void operator+(Matrix& m1, Matrix& m2) {

		int mat[20][20];

		for (int i = 0; i < m1.n; i++) {
			for (int j = 0; j < m1.n; j++) {
				mat[i][j] = m1.M[i][j] + m2.M[i][j];
			}
		}

		for (int i = 0; i < m1.n; i++) {
			for (int j = 0; j < m1.n; j++) {
				cout << mat[i][j] << ' ';
			}
			cout << endl;
		}
	}

	friend bool operator>(const Matrix& m1, const Matrix& m2) {
		return m1.trace > m2.trace;
	}
	friend ostream& operator<< (ostream &out, const Matrix &matrix) {
		
		for (int i = 0; i < matrix.n; i++) {
			for (int j = 0; j < matrix.n; j++) {
				out << matrix.M[i][j] << ' ' ;
			}
			cout << endl;
		}
		cout << endl;
		return out;
	}
	void Input(int k);
	void Print(Matrix mas[], int n);
	int Trace();
	void insertion_sort(Matrix mas[], int n);
	~Matrix();
};


Matrix::Matrix(int size) {
	n = size;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			M[i][j] = 0;
	cout << "\n";

}

Matrix::~Matrix() {}

void Matrix::Input(int k) {
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			cout << "[" << i << "][" << j << "]=";
			cin >> M[i][j];
			cout << "\n";
		}

	trace = Trace();
}

void Matrix::Print(Matrix mas[], int n) {
	
	for (int i = 0; i < n; i++) {
		cout  << mas[i] << " ";
		cout << "\n";
	}
	cout << "\n";
}

int Matrix::Trace() {
	int k = 0;
	for (int i = 0; i < n; i++) {
		k += M[i][i];
	}
	return k;
}
void Matrix::insertion_sort(Matrix mas[], int n)
{
	{
		int j = 0;
		Matrix key;
		for (int i = 1; i < n; i++)
		{
			key = mas[i];
			j = i - 1;
			while (j >= 0 && mas[j] > key)
			{
				mas[j + 1] = mas[j];
				j--;
			}
			mas[j + 1] = key;
		}
	}
}
int main() {
	Matrix arr[10];
	int n, k;
	cout << " COUNT OF MATRIX : ";
	cin >> n;
	cout << " COUNT OF ELEMENTS IN MATRIX : ";
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		arr[i] = Matrix(k);
		cout << " ELEMENTS IN " << i + 1 << " MATRIX : " << endl;
		arr[i].Input(k);
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			cout << "\nsum of " << i + 1 << " and " << j + 1 << " = " << endl;
			arr[i] + arr[j];
			cout << endl;
			if (arr[i] > arr[j])
				cout << i + 1 << " bigger than " << j + 1 << endl;
			else
				cout << i + 1 << " smaller than " << j + 1 << endl;
		}

	arr->insertion_sort(arr, n);
	cout << "sorted matrixs :" << endl;
	arr->Print(arr, n);
	return 0;
}