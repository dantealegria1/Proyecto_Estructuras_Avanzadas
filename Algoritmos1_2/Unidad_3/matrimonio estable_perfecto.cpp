//programa matrimonio estable como parte de la creacion de un algortimo de grafo bipartito perfecto 
#include <iostream>
#define SINGLE 0
using namespace std;


int main()
{
    int wList[4][4] = {{0, 0, 0, 0},
                       {1, 2, 1, 3},
                       {2, 1, 2, 3},
                       {3, 1, 2, 3}};
    int mList[4][4] = {{0, 0, 0, 0},
                       {1, 1, 2, 3},
                       {2, 2, 1, 3},
                       {3, 1, 2, 3}};
    int manCurrentMatch[4] = {0, 0, 0, 0};   
    int womanCurrentMatch[4] = {0, 0, 0, 0}; 
    int manNextProposal[4] = {1, 1, 1, 1};  
	string listM[4] = {"","Jorge", "Luis", "Mario"};
	string listW[4] = {"", "Ana", "Bea", "Clara"};

    bool hombreDisponible = true;
    int m = 1;
    while (hombreDisponible)
    {
        hombreDisponible = false;
        int w = mList[m][manNextProposal[m]++];
        if (womanCurrentMatch[w] == SINGLE)
        {
            womanCurrentMatch[w] = m;
            manCurrentMatch[m] = w;
        }
        else
        {
            bool esUnaMejorPropuesta = false;
            for (int i = 1; i <= 3; i++)
            {
                if (wList[w][i] == womanCurrentMatch[w])
                {
                    esUnaMejorPropuesta = false;
                    break;
                }
                if (wList[w][i] == m)
                {
                    esUnaMejorPropuesta = true;
                    break;
                }
            }
            if (esUnaMejorPropuesta)
            {
                manCurrentMatch[womanCurrentMatch[w]] = SINGLE;
                womanCurrentMatch[w] = m;
                manCurrentMatch[m] = w;
            }
        }
        for (int j = 1; j <= 3; j++)
        {
            if (manCurrentMatch[j] == SINGLE)
            {
                m = j;
                hombreDisponible = true;
                break;
            }
        }
    }

	cout << "Matriz de Preferencias de los Hombres: " << endl;
    for (int g = 1; g <= 3; g++)
    {
    	cout << g << " " << listM[g] << "\t";
        for (int d = 1; d < 4; d++)
        {
            cout << mList[g][d] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    
	cout << "Matriz de Preferencias de las Mujeres: " << endl;
    for (int h = 1; h <= 3; h++)
    {
    	cout << h << " " << listW[h] << "\t";
        for (int u = 1; u < 4; u++)
        {
            cout << wList[h][u] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    
	cout << "\tMatrimonios Estables" << endl;
    for (int k = 1; k <= 3; k++)
    {
        cout << listM[k] << " junto a " << listW[manCurrentMatch[k]] << endl;
    }    
    return 0;
}
