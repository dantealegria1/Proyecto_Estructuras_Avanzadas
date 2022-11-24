//guardar grafo en una matriz 
//big 0: O(n^2)
#include <iostream>
#include <math.h>
using namespace std; 

int main ()
{
	//generacion de variables 
	int num,n1,n2,n,opc=1; 
	
	cout<<"ingrese el tamaño de su matriz: ";cin>>num; 
	cout<<endl;
	//creacion de matriz ;
	int Mat[num][num] ;
   //se empieza a rellenar la matriz con ceros por el momento, del tamaño que pidio el usuario 
   for (int i=0;i<num;i++)
   {
   	 for(int j=0;j<num;j++)
   	 {
   	 	Mat[i][j]=0;
	 }
   }
	//se genera un while que le permitira al usuario seguir generando uniones en el grafo
	while(opc==1)
	{
		cout<<"UNION DE ARISTAS: "<<endl; 
		cout<<"ingresa tu primer nodo: ";cin>>n1;
		cout<<"ingresa a que otro nodo se unira: ";cin>>n2;
		//con la matriz,le quita una posicion al número dado para poder llegar a su posicion exacta 
		//de esta manera, modificar el cero, en la posicion que se escogio unir el nodo 
		Mat[n1-1][n2-1]=1;
		Mat[n2-1][n1-1]=1;
		cout<<"desea unir más nodos? SI=1 NO=2 ";cin>>opc;
	}
	
	//comenzamos a imprimir la matriz 
	cout<<"----------------------------------------------------"<<endl<<endl;
	cout<<"impresion de grafo de acuerdo a los puntos de union: "<<endl;
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			cout<<Mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//comenzamos a mostrar las uniones de matriz generadas por el usuario
	 cout<<endl;
	cout<<"----------------------------------------------------"<<endl<<endl;
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			if(	Mat[i][j]==1)
			{
				cout<<"union de nodo: "<<i+1<<" con nodo: "<<j+1<<endl; 
			}
		}
	}
}








