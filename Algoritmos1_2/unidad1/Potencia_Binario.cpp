//dante alejandro alegria romero
//big O es O(n)
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    //Declaracion de variables
	int i,j,limite,cantidad,opc;
    string A[100];
    //pedimos los datos
    cout<<"Ingrese el numero de elementos del conjunto"<<endl;
    cin>>limite;
    //pedimos el valor de cada elemento
    for(i=0;i<limite;i++){
       cout<<"Ingrese el elemento: "<<i+1<<"/"<<limite<<" ";
       cin>>A[i];
    }   
    system("CLS");
    //convertimos los elementos a conjunto potencia
    for(i=0;i<pow(2,limite);i++){
    	cout<<"{";
        for(j=0;j<limite;j++){
            if(i & (1<<j))
            cout<<A[j]<<"/";
        }
        cout<<"}";
        cout<<"--->";
        // en vez convertir cada uno, decimos que si ese numero aparece
        //aoarece en un 1 y si no aparece en un 0
        for(j=0;j<limite;j++)
        {
        	if(i & (1<<j))
        	{
        		cout<<"1";
			}else
			{
				cout<<"0";
			}
		}
		cout<<"\n";
    }
}
