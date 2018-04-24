#include <iostream>

using namespace std;
template <class T>
struct CNodo
{
    T valor;
    CNodo<T>* next;
    CNodo<T>* ant;
    CNodo(T val)
    {
        valor=val;
        next=0;
        ant=0;
    }
};
template <class U,class V>
class Clcir
{
    CNodo<U>* head;
    Clcir()
    {
        head=0;
    }
    bool buscar(U x,CNodo<U>**& ptr,CNodo<U>**& ptr2);
    void agregar(U x);
    void eliminar(U x);
    void imprimir(U x);
    ~Clcir();
};
template <class U,class V>
bool Clcir<U,V>::buscar(U x,CNodo<U>**& ptr,CNodo<U>**& ptr2)
{

    for(ptr=&head && ptr2=&((*ptr)->ant);ptr!=head && (*ptr)->valor!=x && (*ptr)->valor<x;ptr=&((*ptr)->next)) && ptr2=&((*ptr)->ant);
    return;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
