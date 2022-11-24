//guardar grafo en una lista 
//big 0: O(n^2)
#include <iostream>
#include <math.h>
using namespace std; 


int main()
{
	//variables a usar
	int num,cant,**lista; //puntador doble para alamacenar lo del primero 
	
	//pedimos el largo del grafo al usuario 
	cout<<"Ingrese la cantidad de nodos: "<<endl; 
	cin>>num;
	
	lista=new int *[num]; //lo que hacemos aqui, es adignarle al doble puntero el valor 
	//que nos de el usuario como el tamaño máximo del grafo. 
	
	//pide valores al usuario para ver las uniones entre cada parte del grafo 
	for(int i=0;i<num;i++)
	{
		cout<<"cuantos valores tiene el nodo "<<i+1<<" :"; 
		cin>>cant;//se le piden los valores exactos de cada grafo 
		lista[i]=new int [cant]; //creamos una nueva variable que por medio del puntero, contendra 
		//el largo de las concexiones del grafo 
		for(int j=0;j<cant;j++)//es hasta el valor de cant paraque pida solo los necesarios 
		{
			cout<<"con que valor tiene conexión el nodo: "<<i+1<<" : ";
			cin>>lista[i][j]; //como i ya lo declaramos antes, al lado del numero que 
			//se guarda en i, se guardara el valor que el usuario puso como conexión. 
		}
	}
	
	//imprimimos 
	for(int i=0;i<num;i++)
	{
		int j=0;
		cout<<"su nodo "<<i+1<<" esta conectado con: ";
		while(lista[i][j]<=num) //evalue a menor iguql que num para que no generara otros valores 
		{
			cout<<lista[i][j]<<", ";
			j++;
		}
		cout<<endl;
	}
}

