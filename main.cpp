#include <iostream>
#include <iomanip>

using namespace std;

typedef long long int INT64;
typedef unsigned int uint;

extern "C" void zad1_asm(int, int, int, int*);
extern "C" void zad2_asm(int, int, int*);
extern "C" int zad3_asm(int, int);
extern "C" INT64 zad4_asm(INT64, INT64, INT64, INT64, INT64, INT64);
extern "C" void zad5_asm(int**, uint, uint);

int** fillMartix(uint n, uint m) {
    int** A = new int* [n];
    for (uint i = 0; i < n; ++i) {
        A[i] = new int[m];
        for (uint j = 0; j < m; ++j) {
            A[i][j] = (m * i) + (j + 1);
        }
    }
    return A;
}

void printMatrix(int** A, uint n, uint m) {
    for (uint i = 0; i < n; ++i) {
        cout << "[ ";
        for (uint j = 0; j < m; ++j) {
            cout << setw(5) << A[i][j] << ", ";
        }
        cout << "]" << endl;
    }
    cout << endl;
}

void zad1_cpp(int a, int b, int c, int* d) {
    *d = b*b-4*a*c;
}

void zad2_cpp(int a, int b, int* i) {
    *i = (b+1)/a;
}

INT64 zad4_cpp(INT64 a1, INT64 b1, INT64 a2, INT64 b2, INT64 a3, INT64 b3) {
    return a1*b1+a2*b2+a3*b3;
}

void zad5_cpp(int** A, uint n, uint m) {
    for (uint i = 0; i < n; ++i) {
        for (uint j = 0;j < m;++j) {
            A[i][j] = (i<j) ? 0: A[i][j];
        }
    }
}

int main()
{
    //zad1
    /*
    Dane są liczby całkowite: a,b,c, i d
    Wyznaczyć w d = b^2 - 4ac
    */
    /*int a,b,c,*d_cpp, *d_asm;
    a = 10; b = 15; c = 5;
    d_cpp = new int;
    d_asm = new int;
    
    zad1_asm(a,b,c,d_asm);
    zad1_cpp(a,b,c,d_cpp);

    cout << *d_asm << endl;
    cout << *d_cpp << endl;
    
    delete d_cpp;
    delete d_asm;*/
    //zad2
    /*
    Dane są liczby całkowite a, b, i i.
    Obliczyć, zgodnie z zasadami zaokrąglania, iloraz i = b/a
    */
    /*int a = 2, b=7, *i_cpp = new int, *i_asm = new int;

    zad2_cpp(a,b,i_cpp);
    zad2_asm(a, b, i_asm);

    cout << *i_cpp << endl;
    cout << *i_asm << endl;

    delete i_cpp;
    delete i_asm;*/
    //zad3
    /*
    Dane są dwie liczby całkowite a i b. Zrealizować bez instrukcji skoku:
    if (a>=b) { y=a-b } else { y=b-a }
    */
    /*int a =7, b =5;
    int y_asm, y_cpp = (a>=b) ? a-b: b-a;
    y_asm = zad3_asm(a,b);

    cout << y_asm << endl;
    cout << y_cpp << endl;*/
    //zad4
    /*
    Napisać pełen kod funkcji wywoływanej: y=is64(a1,b1,a2,b2,a3,b3),
    obliczającej y=a1*b1+a2*b2+a3*b3. Wynik i parametry typu INT64.
    */
    /*int a1=1,b1=2,a2=3,b2=4,a3=5,b3=6;
    
    cout << zad4_cpp(a1,b1,a2,b2,a3,b3) << endl;
    cout << zad4_asm(a1, b1, a2, b2, a3, b3) << endl;*/
    //zad5
    /*
    Dana kwadratowa macierz nxn, typu int32.
    Wyzerować wszystkie elementy powyżej głownej przekątnej (gdzie i<j).
    */
    /*uint n=5,m=5;
    int ** A = fillMartix(n,m);
    printMatrix(A, n, m);
    int ** B = fillMartix(n, m);
    
    zad5_cpp(A, n, m);
    printMatrix(A, n ,m);
    zad5_asm(B,n,m);
    printMatrix(B,n,m);*/

    return 0;
}
