/* 
PERMUTACION
nPr=n!/(n-r)!

COMBINACION
nCr=n!/(n-r)!r!

Nombre: Maria Yoselin Garcia Medina
Fecha: 11 08 22
*/

#include <iostream>
#include<stdio.h>
using namespace std;
int main(){
	//inicializamos variables 
	int n;
	int i;
	int j;
	cout<<" Dame el valor de n: ";	//la cantidad de valores que ingresaremos para permutar
	cin>>n;
	int vector[n];
	for(i=0;i<n;i++)	//pedirá los valores que le indicamos anteriormente
	{
	 cout<<"Dame el valor de "<<i+1<<endl;
	 cin>>vector[i];
	}
	system("cls");
	cout<<"----PERMUTUACIONES----"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(vector[i]!=vector[j])	//si los valores son diferentes 
			{
				cout << vector[i] << "," << vector[j] << endl;
			}
		}	
	}
	

	return 0;
}
