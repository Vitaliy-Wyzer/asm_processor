#include<iostream>
#include<iomanip>

using namespace std;
typedef long long int INT64;
typedef unsigned int uint;

extern "C" INT64 zad1_asm(int, int, int);
extern "C" int zad2_asm(int, int, int, int, int);
extern "C" INT64 zad3_asm(int *, uint);
extern "C" void zad4_asm(INT64*, INT64*, uint);
extern "C" void zad5_asm(int**, uint, uint);

int * fillptr(unsigned int n = 10) {
	int * ptr = new int[n];
	for (unsigned int i = 0; i < n; ++i) {
		ptr[i] = i+1;
	}
	ptr[0] = 2;
	ptr[2] = 2;
	cout << "[ ";
	for (unsigned int i = 0; i < n; ++i) {
		cout << ptr[i] << ", ";
	}
	cout << "]" << endl;
	return ptr;
}

void printPtr(INT64* ptr, uint n) {
	cout << "[ ";
	for (uint i = 0; i < n; ++i) {
		cout << ptr[i] << ", ";
	}
	cout << "]" << endl;
}

INT64* fillptr64(unsigned int n = 10) {
	INT64* ptr = new INT64[n];
	for (unsigned int i = 0; i < n; ++i) {
		ptr[i] = i + 1;
	}
	cout << "[ ";
	for (unsigned int i = 0; i < n; ++i) {
		cout << ptr[i] << ", ";
	}
	cout << "]" << endl;
	return ptr;
}

int zad2_cpp(int a, int b, int c, int i, int x) {
	switch (i) {
	case 10:
		return a*x+b+c+i;
	case 11:
		return (b-200*i)/(2*a*x+1);
	case 12:
		return (a*x*x-4*c);
	default:
		return 0;
	}
}

INT64 zad3_cpp(int *v, int n=10) {
	INT64 count = 0;
	for (unsigned int i = 0; i < n; ++i) {
		if (v[i] % 2 != 0) {
			count++;
		}
	}
	return count;
}

void zad4_cpp(INT64* a, INT64* b, uint n) {
	for (uint i = 0; i < n; ++i) {
		a[i] += 7*b[i];
	}
}

int** fillmatrix(uint n, uint m) {
	int** A = new int*[n];
	for (uint i = 0; i < n; ++i) {
		A[i] = new int[m];
		for (uint j = 0; j < m; ++j) {
			A[i][j] = (m*i)+(j+1);
		}
	}
	return A;
}

void printmatrix(int**A, uint n, uint m) {
	cout << "[ " << endl;
	for (uint i = 0; i < n; ++i) {
		cout << "[ ";
		for (uint j = 0; j < m; ++j) {
			cout << setw(5) << A[i][j] << ", ";
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;
}

void zad5_cpp(int** A, uint n, uint m) {
	uint less = (n<m) ? n: m;
	for (uint i = 0; i < less; ++i) {
		A[i][i] /= 2;
	}
}

void freeMatrix(int** A, uint n) {
	for (uint i = 0; i < n; ++i) {
		delete [] A[i];
	}
	delete [] A;
}

int main() {

	//zad1
	/*
	Dane są trzy liczby typu int. Wyznacz najmniejszą z nich. Wynik zwróc jako liczbę __int64.
	*/
	/*cout << zad1_asm(1, 2, 3) << endl;
	cout << zad1_asm(3, 2, 1) << endl;
	cout << zad1_asm(2, 1, 3) << endl;
	cout << zad1_asm(1, 3, 2) << endl;
	cout << zad1_asm(3, 1, 2) << endl;
	cout << zad1_asm(2, 3, 1) << endl;*/

	//zad2
	/*
	Zrealizuj instrukcję wyboru wyrażoną jako:

		{ax+b+c+i			i=10
	y = {(b-200i)/2ax+1		i=11
		{ax^2+1				i=12
		{0					in other cases

	*/
	/*int a = 5, b = 3, c = 2, i = 12, x = 5;

	cout << zad2_asm(a,b,c,i,x) << endl;
	cout << zad2_cpp(a,b,c,i,x) << endl;*/
	//zad3
	/*
	Policz ile liczb nieparzystych znajduje się w wektorze v (int). 
	Wynik zwróć jako liczbę __int64.
	*/
	/*unsigned int n = 10;
	int *vector = fillptr();

	cout << zad3_cpp(vector, n) << endl;
	cout << zad3_asm(vector, n) << endl;
	
	delete [] vector;*/

	//zad 4
	/*
	Wyznacz wartość funkcji dla wektorów a i b (__int64). Wynik zwróć w wektorze a:
	*/
	/*uint n = 10;
	INT64 *a_asm = fillptr64();
	INT64 *b = fillptr64();
	INT64* a_cpp = fillptr64();

	zad4_cpp(a_cpp, b, n);
	zad4_asm(a_asm, b, n);

	printPtr(a_cpp, n);
	printPtr(a_asm, n);

	delete [] a_asm;
	delete [] a_cpp;*/

	//zad 5
	/*
	Podziel przez 2 wszystkie elementy macierzy (int) znajdujące się na głównej przekątnej.
	*/
	/*uint n=5,m=7;
	int**A = fillmatrix(n, m);
	int** B = fillmatrix(n, m);
	zad5_cpp(A,n,m);
	printmatrix(A, n, m);
	zad5_asm(B,n,m);
	printmatrix(B,n,m);

	freeMatrix(A, n);
	freeMatrix(B, n);*/
	
	return 0;
}