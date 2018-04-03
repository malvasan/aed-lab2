#include <iostream>

using namespace std;

template<class T>
class nodo
{
public:
    T valor;
    nodo<T> *next;
    nodo(T value,nodo<T>* proximo)
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
    lzta_nlzada()
    {
        head=0;
    }
    bool buscar(U n,nodo<U>* nd_ntrior)
    {
        if(head==0)
            return true;
        nd_ntrior=head;
        int i=0;
        while(nd_ntrior->next!=0){
            if((head+i)->valor==n)
                return false;
            else if((head+i)->valor>n)
                return true;
            nd_ntrior=(head+i);
            i++;
        }
        return true;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
