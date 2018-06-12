#include <iostream>
#include <vector>
using namespace std;

template<class U>
struct ascendente
{
	bool cmp(U a ,U b)
	{
		if(a<b)
			return 1;
		return 0;
	}
};
template<class U>
struct descendente
{
	bool cmp(U a ,U b)
	{
		if(a>b)
			return 1;
		return 0;
	}
};

template <class U>
struct CNode
{
	U n_valor;
	CNode<U>* nodos[2];
	CNode(U val)
	{
		n_valor=val;
		nodos[0]=0;
		nodos[1]=0;
	}
};
template<class U,class V>
class CArbol
{
public:
	CArbol();
	bool buscar(U x,CNode<U>**& ptr,vector<CNode<U>**>& recorrido);
	bool insertar(U x);
	bool borrar(U x);
	CNode<U>** Rep(CNode<U>** ptr);
	void imprimir(CNode<U>* p, int cont);
	V comparador;
	CNode<U>* raiz;
	vector<CNode<U>**> recorrido;
	void balancear(vector<CNode<U>** > arr);
private:
	int buscar_peso(CNode<U>* pointer);
};
template<class U,class V>
CArbol<U,V>::CArbol()
{
	raiz=0;
}
template<class U,class V>
bool CArbol<U,V>::buscar(U x,CNode<U>**& ptr,vector<CNode<U>**>& recorrido)
{
	for(ptr=&raiz;*ptr && (*ptr)->n_valor!=x;ptr=&((*ptr)->nodos[comparador.cmp((*ptr)->n_valor,x)])){
		cout<<(*ptr)<<"  ";
		recorrido.push_back(ptr);}
	return !!(*ptr);
}

template<class U,class V>
bool CArbol<U,V>::insertar(U x)
{
	CNode<U>** p;
	recorrido.clear();
	if(buscar(x,p,recorrido)) return 0;
	//CNode<U>*ptr =new CNode<U>(x);
	//*p=ptr;
	*p=new CNode<U>(x);
	balancear(recorrido);
	return 1;
}
template<class U,class V>
CNode<U>** CArbol<U,V>::Rep(CNode<U>** ptr)
{
	for(ptr=&((*ptr)->nodos[0]);(*ptr)->nodos[1];ptr=&((*ptr)->nodos[1]));
	return ptr;
}

template<class U,class V>
bool CArbol<U,V>::borrar(U x)
{
	CNode<U>** p;
	recorrido.clear();
	if(!buscar(x,p,recorrido)) return 0;
	if((*p)->nodos[0] && (*p)->nodos[1])
	{
		CNode<U>** q=Rep(p);
		(*p)->n_valor=(*q)->n_valor;
		p=q;
	}
	CNode<U>* t=*p;
	*p=(*p)->nodos[!(*p)->nodos[0]];
	delete t;
	//recorrido.pop_back();
	balancear(recorrido);
	return 1;
}
template<class U,class V>
void CArbol<U,V>::imprimir(CNode<U>* p,int cont)
{
    /*
	if(!p) return ;
	imprimir(p->nodos[0]);
	cout<<p->nodos[0]<<"  "<<p<<"  "<<p->nodos[1]<<"   "<<p->n_valor<<endl;
	imprimir(p->nodos[1]);
	*/
	if(!p) return;
	imprimir(p->nodos[1],cont+1);
	for(int i=0;i<cont;i++){
        cout<<"   ";
	}
	cout<<p->n_valor<<endl;
	imprimir(p->nodos[0],cont+1);
}
template<class U,class V>
void CArbol<U,V>::balancear(vector<CNode<U>** > arr)
{
	int i=arr.size();
	int p1,p2,peso,peso_sub_arbol;
	p1=0;p2=0;peso=0;peso_sub_arbol=0;
	cout<<"i>> "<<i<<endl;
	i--;
	for (;i>=0;i--){
		p1=0;p2=0;peso=0;peso_sub_arbol=0;
		p1=buscar_peso((*arr[i])->nodos[0]);
		p2=buscar_peso((*arr[i])->nodos[1]);
		peso=p2-p1;

		cout<<"nodo>> "<<(*arr[i])->n_valor<<endl;
        //cout<<"nodo>> "<<peso<<endl;

		if(peso>=2){
			//cout<<"aqui"<<endl;
			cout<<"sub_arbol>>"<<(*arr[i])->nodos[1]->n_valor <<endl;
			peso_sub_arbol=buscar_peso((*arr[i])->nodos[1]->nodos[1])-buscar_peso((*arr[i])->nodos[1]->nodos[0]);
			cout<<"peso_sub_arbol>>"<<peso_sub_arbol <<endl;
			if(peso_sub_arbol==1){
				CNode<U>* ptr=*arr[i];
				*arr[i]=(*arr[i])->nodos[1] ;
				ptr->nodos[1]=(*arr[i])->nodos[0];
				(*arr[i])->nodos[0]=ptr;
				return;
			}
			if(peso_sub_arbol==-1){
                cout<<"aqui"<<endl;
				CNode<U>* ptr=*arr[i];
				CNode<U>* ptr2=(*arr[i])->nodos[1];
				*arr[i]=(*arr[i])->nodos[1]->nodos[0];
				ptr->nodos[1]=(*arr[i])->nodos[0];
				ptr2->nodos[0]=(*arr[i])->nodos[1];
				(*arr[i])->nodos[0]=ptr;
				(*arr[i])->nodos[1]=ptr2;
				return;
			}
		}
		else if(peso<=-2){
		   peso_sub_arbol=buscar_peso((*arr[i])->nodos[0]->nodos[1])-buscar_peso((*arr[i])->nodos[0]->nodos[0]);
           cout<<"peso_sub_arbol>>"<<peso_sub_arbol <<endl;
		if(peso_sub_arbol==-1){
			CNode<U>* ptr=*arr[i];
			*arr[i]=(*arr[i])->nodos[0];
			ptr->nodos[0]=(*arr[i])->nodos[1];
			(*arr[i])->nodos[1]=ptr;
			return;
		}
		if(peso_sub_arbol==1){
            cout<<"aqui"<<endl;
			CNode<U>* ptr=*arr[i];
			CNode<U>* ptr2=(*arr[i])->nodos[0];
			*arr[i]=(*arr[i])->nodos[0]->nodos[1];
			ptr->nodos[0]=(*arr[i])->nodos[1];
			ptr2->nodos[1]=(*arr[i])->nodos[0];
			(*arr[i])->nodos[1]=ptr;
			(*arr[i])->nodos[0]=ptr2;
			return;
		}
		}
	}
}
template<class U,class V>
int CArbol<U,V>::buscar_peso(CNode<U>* pointer)
{
	int x=0;
	CNode<U>* ptr=pointer;
	for(;ptr;ptr=ptr->nodos[!ptr->nodos[0]])
	{
		x++;
		if(ptr->nodos[0] && ptr->nodos[1]){
			int y=buscar_peso(ptr->nodos[0]);
			int z=buscar_peso(ptr->nodos[1]);
			if(y>z)
				x=x+y;
			else
				x=x+z;
			break;
		}
	}
	//x=x-1;
	return x;
}
int main()
{
	CArbol<int,ascendente<int> > arbol;
	//arbol.insertar(55);
	//arbol.insertar(33);
	//arbol.insertar(88);
	//arbol.insertar(12);
	// arbol.insertar(47);
	arbol.insertar(77);
	//arbol.insertar(98);
	arbol.insertar(81);
	arbol.insertar(79);
	//arbol.insertar(78);
	//arbol.insertar(9);
	// arbol.insertar(35);
	//arbol.insertar(40);
	//arbol.borrar(81);
	arbol.imprimir(arbol.raiz, 0);
	return 0;
}
