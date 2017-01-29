#include <iostream>
#include <vector>
#include "clabyrinthe.h"
#include "ccase.h"
#include <utility>
#include <fstream>

using namespace std;

int main()
{
    ofstream fw;
    fw.open("text.txt");
    std::streambuf *oldbuf = std::cout.rdbuf(); //save
    std::cout.rdbuf(fw.rdbuf());

    //CLabyrinthe john(12, 12);//COOOOL
    CLabyrinthe john(79, 42); //my terminal max
    //CLabyrinthe john(100,100);
    //CLabyrinthe john(3000,3000); // need more then 2000000 taille de la reserve de la pile (equivalent de 2Go de ram)
    john.GenLaby();
    //john.Solve();
    //john.Afficher();

    john.AfficherPlusChemin();

    //reset back to standard input
    std::cout.rdbuf(oldbuf);
    cout<<endl;
    int non;
    //cin>>non;
    return 0;
}
