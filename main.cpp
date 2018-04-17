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
    bool buscar(U n,nodo<U>*& nd_ntrior)
    {
        if(head==0)
            return true;
        nodo<U>* nd_actual= head;
        nd_ntrior=nd_actual;
        if(nd_actual->valor==n)
                return false;
        while(nd_ntrior->next!=0){
            if(nd_actual->valor==n)
                return false;
            else if(nd_actual->valor>n)
                return true;
            nd_ntrior=nd_actual;
            nd_actual=nd_actual->next;
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
        //cout<<ptr_anterior->next<<endl;
        //cout<<ptr_anterior->valor<<endl;
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
                ptr_anterior=head->next;
                delete head;
                head=ptr_anterior;
            }
            if(ptr_anterior->next->next==0)
            {
                delete ptr_anterior->next;
                ptr_anterior.next=0;
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
    lista.head=0;
    lista.insertar(1);
    lista.insertar(2);
    lista.insertar(3);
    lista.insertar(5);
    lista.insertar(4);
     lista.insertar(0);

    nodo<int>* ptr=lista.head;

    for(int i=0;ptr!=0;i++){
        cout<<ptr->valor<<endl;
        ptr=ptr->next;
    }

    return 0;
}


