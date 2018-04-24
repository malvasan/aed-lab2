#include <iostream>

using namespace std;
template <class T>
struct nodo
{
    T valor;
    nodo<T>* next;
    nodo(T val)
    {
        valor=val;
        next=0;
    }
};
template <class U>
class lista
{
    nodo<U>* head;
    lista();
    bool buscar(U x,nodo<U>**& p);
    bool insertar(U x);
    bool borrar(U x);
    void imprimir();
    ~lista();
};
template <class U>
bool lista<U>::buscar(U x,nodo<U>**& p)
{
    for(p=&head;*p && (*p)->valor<x;p=(*p)->next);
    return *p && (*p)->valor==x;
}
template <class U>
bool lista<U>::insertar(U x)
{
    nodo<U>** p;
    if(buscar(x,p))return 0;
    nodo<U>* pr= new nodo<U>(x);
    pr->next=*p;
    *p=pr;
}
template <class U>
bool lista<U>::borrar(U x)
{
    nodo<U>** p;
    if(!buscar(x,p)) return 0;
    nodo<U>* pr=*p;
    *p=(*p)->next;
    delete pr;
}
template <class U>
bool lista<U>::imprimir()
{
    for(lista<U>* o=head;o;o++){
        cout<<*o<<endl;
    }
}
template <class U>
lista<U>::~lista();
{
    lista<U>* ptr2=&head;
    for(lista<U>** ptr1=&(ptr2->next);ptr2;ptr1=&(ptr2->next))
        delete prt2;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

