
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_t{
    int numero;
    struct nodo_t *siguiente;
}nodo;

nodo*root1=NULL;

nodo*root2=NULL;


void agregar_root1(nodo*Lista,int n){
    nodo * tmp;
    nodo * nuevo_nodo;
    tmp=Lista;
    nuevo_nodo=malloc(sizeof(nodo));
    nuevo_nodo->numero=n;
    if(tmp==NULL){
        root1=nuevo_nodo;
    }
    else{
        while(tmp->siguiente!=NULL){
            tmp=tmp->siguiente;
        }
        tmp->siguiente=nuevo_nodo;
  	}
}


void agregar_root2(nodo*Lista,int n){
    nodo * tmp;
    nodo * nuevo_nodo;
    tmp=Lista;
    nuevo_nodo=malloc(sizeof(nodo));
    nuevo_nodo->numero=n;
    if(tmp==NULL){
        root2=nuevo_nodo;
    }
    else{
        while(tmp->siguiente!=NULL){
            tmp=tmp->siguiente;
        }
        tmp->siguiente=nuevo_nodo;
  	}
}



void imprimir(nodo*lista){
	nodo*tmp;
	tmp=lista;
	
	while(tmp!=NULL){
		printf("Digito: %d\n",tmp->numero);
		tmp=tmp->siguiente;
	}
}


void espageti(nodo*lista1,nodo*lista2){
	nodo*tmp1=lista1;			//6
	nodo*tmp2=lista2;			//9	
	nodo*tmp3=lista1->siguiente;		//1
	nodo*tmp4=lista2->siguiente->siguiente;	//11

	tmp1->siguiente=tmp4;			//6->11
	tmp2->siguiente->siguiente=tmp3;	//10->1
	tmp1=tmp4->siguiente;			//tmp1=12
	tmp2=tmp3->siguiente;			//tmp2=2
	tmp3=tmp3->siguiente->siguiente;	//tmp3=3
	tmp4=tmp4->siguiente->siguiente;	//tmp4=13

	tmp1->siguiente=tmp3;			//12->3			
	tmp2->siguiente=tmp4;			//2->13
	tmp1=tmp3->siguiente;			//tmp1=4
	tmp2=tmp2->siguiente->siguiente;	//tmp2=14
	tmp3=tmp3->siguiente->siguiente;	//tmp3=8
	tmp2->siguiente=tmp3;			//14->8
	tmp1->siguiente=lista2;			//4->9
	
	
}



main(){
	agregar_root1(root1,6);
	agregar_root1(root1,1);
	agregar_root1(root1,2);
	agregar_root1(root1,3);
	agregar_root1(root1,4);
	agregar_root1(root1,8);
	
	agregar_root2(root2,9);
	agregar_root2(root2,10);
	agregar_root2(root2,11);
	agregar_root2(root2,12);
	agregar_root2(root2,13);
	agregar_root2(root2,14);
	espageti(root1,root2);
    	imprimir(root1);
	imprimir(root2);
}
