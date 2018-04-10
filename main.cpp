#include <iostream>

using namespace std;

template<class T>
class nodo
{
public:
    T valor;
    nodo<T> *next;
    nodo(T value=0,nodo<T>* proximo=0)
    {
        valor=value;
        next=proximo;
    }
};

template<class U>
class lsta_nlzada
{
public:
    nodo<U>* head;
    lsta_nlzada()
    {
        head=0;
    }
    bool buscar(U n,nodo<U>* nd_ntrior)
    {
        if(head==0)
            return true;
        nd_ntrior=head;
        int i=0;
        if((head+i)->valor==n)
                return false;
        i++;
        while(nd_ntrior->next!=0){
            if((head+i)->valor==n)
                return false;
            else if((head+i)->valor>n)
                return true;
            nd_ntrior=head+i;
            i++;
        }
        return true;
    }
    void insertar(U numero)
    {
        nodo<U>* ptr_anterior=0;
        if(buscar(numero,ptr_anterior)==true)
        {
        nodo<U>* ptr = new nodo<U>(numero);
        if(head==0){
            head=ptr;
            head->next=0;
            return;
        }
        if(head->valor > ptr->valor){
            ptr->next=head;
            head=ptr;
            return;
        }
        if(ptr_anterior->next==0){
            ptr_anterior->next=ptr;
            ptr->next=0;
            return;
        }
        ptr->next=ptr_anterior->next;
        ptr_anterior->next=ptr;
        }
    }
    void eliminar(U numero)
    {
        nodo<U>* ptr_anterior;
        if(buscar(numero,ptr_anterior)==false)
        {
            if(ptr_anterior==head)
            {
                if(head->next==0)
                    delete head;
                ptr_anterior=head->next; //guarda el siguiente
                delete head;
                head=ptr_anterior;
            }
            if(ptr_anterior->next->next==0)
            {
                delete ptr_anterior->next;
                ptr_anterior->next=0;
                return;
            }
            nodo<U>* ptr=ptr_anterior->next;
            ptr_anterior->next=ptr->next;
            delete ptr;
        }
    }
};
int main()
{
    lsta_nlzada<int> lista;
    //cout<<lista.head<<endl;
    lista.insertar(1);
    lista.insertar(0);

    cout << lista.head->next << endl;
    return 0;
}

