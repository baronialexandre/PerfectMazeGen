#include <iostream>
#include <vector>
#include "clabyrinthe.h"
#include "ccase.h"
#include <utility>


using namespace std;

int main()
{
    //CLabyrinthe john(16, 16);
    CLabyrinthe john(79, 44); //my terminal max
    //CLabyrinthe john(3000,3000); // need more then 2000000 taille de la reserve de la pile (equivalent de 2Go de ram)
	john.GenLaby();
	//john.Solve();
	john.Afficher();
    int non;
    cin>>non;
    return 0;
}
