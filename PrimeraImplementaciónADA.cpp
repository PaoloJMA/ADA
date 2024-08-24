// Modular, Clases, Diseño de patrones,Templates, Calculadora :

// Diseño de patrones:
/*
#include <iostream>
#include <list>
#include <vector>
using namespace std;
template <typename Container> void Write(Container &ds, ostream &os)
{
typename Container::iterator iter = ds.begin();
for( ; iter != ds.end() ; iter++ )
os << *iter << "\n";
}
int main(int argc, char* argv[])
{
  list<float> mylist;
  vector<float> myvector;
  for( int i = 0 ; i < 10 ; i++ )
    {
    mylist .push_back( i );
    myvector.push_back(i+50);
    }
  Write(mylist, cout);
  Write(myvector, cout);
  return 0;
}
SALIDA :
0
1
2
3
4
5
6
7
8
9
50
51
52
53
54
55
56
57
58
59
*/

// Modular:
/*
#include <iostream>
using namespace std;
int *gpVect = NULL;
int gVect[100]; // Buffer to save the elements
int gnCount;
int gnMax = 0;
struct Vector {
  int *m_pVect, m_nCount, m_nMax, m_nDelta;
};
void Resize(Vector *pThis) {
  pThis->m_pVect =
      (int *)realloc(gpVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
  pThis->m_nMax += pThis->m_nDelta;
}
void Insert(Vector *pThis, int elem) {
  if (pThis->m_nCount == pThis->m_nMax)
    Resize(pThis);
  pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main() {
  Vector myVector;

  myVector.m_pVect =
      (int *)malloc(sizeof(int) * 10);
  myVector.m_nCount = 0;
  myVector.m_nMax = 10;
  myVector.m_nDelta = 10;

  Insert(&myVector, 5);
  Insert(&myVector, 10);
  Insert(&myVector, 15);
  Insert(&myVector, 20);

  cout << "Elementos del vector:" << endl;
  for (int i = 0; i < myVector.m_nCount; ++i) {
    cout << myVector.m_pVect[i] << " ";
  }
  cout << endl;
  free(myVector.m_pVect);

  return 0;
}
SALIDA:
5 10 15 20

*/

// Clases:
/*
#include <iostream>
#include <cstdlib> // Para realloc y free

using namespace std;

class CVector
{
private:
    int *m_pVect;
    int m_nCount, m_nMax, m_nDelta;
    void Resize(); 
public:
    CVector(int delta = 10) : m_pVect(nullptr), m_nCount(0), m_nMax(delta), m_nDelta(delta) 
    {
        m_pVect = (int*)malloc(sizeof(int) * m_nMax);
    }
    ~CVector() {
        free(m_pVect);
    }
    void Insert(int elem);
    void Display() const;
};

void CVector::Resize()
{
    m_nMax += m_nDelta;
    m_pVect = (int*)realloc(m_pVect, sizeof(int) * m_nMax);
}

void CVector::Insert(int elem)
{
    if (m_nCount == m_nMax)
    {
        Resize();
    }
    m_pVect[m_nCount++] = elem; 
}

void CVector::Display() const
{
    cout << "Elementos del vector:" << endl;
    for (int i = 0; i < m_nCount; ++i)
    {
        cout << m_pVect[i] << " ";
    }
    cout << endl;
}

int main()
{
    CVector vec;
    vec.Insert(5);
    vec.Insert(10);
    vec.Insert(15);
    vec.Insert(20);
    vec.Display();

    return 0;
}

SALIDA:
Elementos del vector:
5 10 15 20
*/
// Templates:
/*
#include <iostream>
using namespace std;

template <typename Type>
class CVector
{
private:
    Type* m_pVect;
    int m_nCount, m_nMax, m_nDelta;

    void Init(int delta);
    void Resize();

public:
    CVector(int delta = 10);
    ~CVector();
    void Insert(Type elem);
    void Display() const;
};

template <typename Type>
void CVector<Type>::Init(int delta)
{
    m_nDelta = delta;
    m_nCount = 0;
    m_nMax = delta;
    m_pVect = (Type*)malloc(sizeof(Type) * m_nMax);
}

template <typename Type>
CVector<Type>::CVector(int delta)
{
    Init(delta);
}

template <typename Type>
CVector<Type>::~CVector()
{
    free(m_pVect);
}

template <typename Type>
void CVector<Type>::Resize()
{
    m_nMax += m_nDelta;
    m_pVect = (Type*)realloc(m_pVect, sizeof(Type) * m_nMax);
}

template <typename Type>
void CVector<Type>::Insert(Type elem)
{
    if (m_nCount == m_nMax) {
        Resize();
    }
    m_pVect[m_nCount++] = elem;
}

template <typename Type>
void CVector<Type>::Display() const
{
    cout << "Elementos del vector:" << endl;
    for (int i = 0; i < m_nCount; ++i) {
        cout << m_pVect[i] << " ";
    }
    cout << endl;
}

int main()
{
    CVector<int> vec;
    vec.Insert(5);
    vec.Insert(10);
    vec.Insert(15);
    vec.Insert(20);
    vec.Display();
    return 0;
}
SAIDA:
Elementos del vector:
5 10 15 20
*/

//Calculadora:
/*
#include <iostream>
#include <cstdlib> 

using namespace std;
float Addition(float x, float y) {
    return x + y;
}

float Subtraction(float x, float y) {
    return x - y;
}

float Multiplication(float x, float y) {
    return x * y;
}

float Division(float x, float y) {
    if (y != 0) {
        return x / y;
    }
    cout << "Error: Division by zero" << endl;
    return 0;
}

template <typename Type>
class CVector
{
private:
    Type* m_pVect;
    int m_nCount, m_nMax, m_nDelta;

    void Init(int delta);
    void Resize();

public:
    CVector(int delta = 10);
    ~CVector();
    void Insert(Type elem);
    void Display() const;
};

template <typename Type>
void CVector<Type>::Init(int delta)
{
    m_nDelta = delta;
    m_nCount = 0;
    m_nMax = delta;
    m_pVect = (Type*)malloc(sizeof(Type) * m_nMax);
}

template <typename Type>
CVector<Type>::CVector(int delta)
{
    Init(delta);
}

template <typename Type>
CVector<Type>::~CVector()
{
    free(m_pVect);
}

template <typename Type>
void CVector<Type>::Resize()
{
    m_nMax += m_nDelta;
    m_pVect = (Type*)realloc(m_pVect, sizeof(Type) * m_nMax);
}

template <typename Type>
void CVector<Type>::Insert(Type elem)
{
    if (m_nCount == m_nMax) {
        Resize();
    }
    m_pVect[m_nCount++] = elem;
}

template <typename Type>
void CVector<Type>::Display() const
{
    cout << "Resultados almacenados en el vector:" << endl;
    for (int i = 0; i < m_nCount; ++i) {
        cout << m_pVect[i] << " ";
    }
    cout << endl;
}

int main()
{
    typedef float (*lpfnOperation)(float, float);
    lpfnOperation vpf[4] = {&Addition, &Subtraction, &Multiplication, &Division};
    float a, b;
    int opt;
    cout << "Ingrese dos números: ";
    cin >> a >> b;
    cout << "Ingrese la operación (0: Adición, 1: Resta, 2: Multiplicación, 3: División): ";
    cin >> opt;

    if (opt < 0 || opt >= 4) {
        cout << "Opción inválida" << endl;
        return 1;
    }
    CVector<float> results;
    float c = (*vpf[opt])(a, b);
    results.Insert(c);
    results.Display();

    return 0;
}
*/