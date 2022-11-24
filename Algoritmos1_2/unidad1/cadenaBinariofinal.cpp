/*
BIG 0: 0(n)
*/
#include <iostream>
#include <stdio.h>
using namespace std;

//creacion de porotipos
void tabla(int num);

int main()
{
	int num;
	cout<<"ingresa tu valor: ";cin>>num;
	cout<<endl;
	cout<<"TABLA DE BINARIO"<<endl;
  	for(int i=num;i>=0;i--)
  	{
  		//mandamos a llamar a la funcion
  		tabla(i);
  		cout<<"----> "<<i<<endl;
	}
}

void tabla(int num)
{
	//variables 
	int x=0;
	//arreglo
	int vector[100];
	
	//creacion de while para dividir la operacion 
	while(num!=0)
	{
		vector[x]=num%2;
		num=num/2;
		x++;
	}
	cout<<endl;
	
	//creacion del for para imprimir 
	for(int i=x-1;i>=0;i--)
	{
		cout<<vector[i];
	}
}

