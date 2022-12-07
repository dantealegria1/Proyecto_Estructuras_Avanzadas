//PROBLEMA DE GRAFO DE ASIGNACION SIMPLE
/*
  Problema a solucionar: En una empresa que produce puertas de maderas, el jefe necesita evaluar de sus cinco
  empleados en cual dia de la semana es cuando estos producen menos puertas de madera. En donde aparezca un uno, 
  es el indicativo de que en dicho dia se generan menos puertas. 
*/


#include<bits/stdc++.h>
using namespace std;

int m[5][5] = {	{15,10,9,11,7},
				{9,15,10,11,12},
				{9,2,10,11,12},
				{9,15,10,1,12},
				{10,12,8,23,9}};
				
int a[5][5] = {	{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0},
				{0,0,0,0,0}};
struct cost{
	int x,y,c;
};
cost aux[3];
int main(){
	int minim;
	for(int i=0;i<5;i++){
		minim=999;
		for(int j=0;j<5;j++){
			if(m[i][j]<minim){
				minim=m[i][j];
				aux[i].x=j;
				aux[i].y=i;
				aux[i].c=m[i][j];
			}
		}
	}
	
	for(int i=0;i<5;i++){
		a[aux[i].y][aux[i].x]=aux[i].c;
	}
	for(int k=0;k<5;k++){
		switch(k){
		
			case 4: for(int i=0;i<5;i++){
						for(int j=0;j<5;j++){
							if(k>=i){
								if(a[i][j]>=1) cout<<1<<"\t";
								else cout<<a[i][j]<<"\t";
							}else cout<<0<<"\t";
						}
						cout<<"\n";
					} break;
		}
		cout<<"\n";
	}

}