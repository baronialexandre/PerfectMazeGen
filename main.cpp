#include <iostream>
#include <vector>
#include "clabyrinthe.h"
#include "ccase.h"
#include <utility>


using namespace std;

int main()
{
    CLabyrinthe john(6, 6);//COOOOL
    //CLabyrinthe john(79, 44); //my terminal max
    //CLabyrinthe john(3000,3000); // need more then 2000000 taille de la reserve de la pile (equivalent de 2Go de ram)
    john.GenLaby();
	//john.Solve();
	john.Afficher();
    cout<<endl;
    CLabyrinthe berthier = john.ReturnSolved();
    berthier.Afficher();
    int non;
    cin>>non;
    return 0;
}
