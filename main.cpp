#include <iostream>
#include <vector>
#include "clabyrinthe.h"
#include "ccase.h"
#include <utility>
#include <fstream>

using namespace std;

void Display(CLabyrinthe bob)
{
    bob.Afficher();
}
void DisplaySolved(CLabyrinthe bob)
{
    bob.AfficherPlusChemin();
}
void SaveAsText(CLabyrinthe bob)
{
    ofstream fw;
    cout << "filename ? (.txt added automatically)"<<endl;
    string fn;
    cin >> fn;
    fw.open(fn+".txt");
    std::streambuf *oldbuf = std::cout.rdbuf(); //save
    std::cout.rdbuf(fw.rdbuf());
    bob.Afficher();
    std::cout.rdbuf(oldbuf);
    cout << "file saved !" << endl;
}
void SaveAsTextSolved(CLabyrinthe bob)
{
    ofstream fw;
    cout << "filename ? (.txt added automatically)"<<endl;
    string fn;
    cin >> fn;
    fw.open(fn+".txt");
    std::streambuf *oldbuf = std::cout.rdbuf(); //save
    std::cout.rdbuf(fw.rdbuf());
    bob.AfficherPlusChemin();
    std::cout.rdbuf(oldbuf);
    cout << "file saved !" << endl;
}

int main()
{

    int newmaze(1);
    while (newmaze==1)
    {

        newmaze = 0;
        cout << "vvelcome to the best maze gen you ever executed on your machine" << endl
             << "Please input the number of rows for the maze : " << endl;
        int rows;
        cin >> rows;
        cout << "And now the number of columns for the maze : "<< endl;
        int columns;
        cin >> columns;
        cout << "Very good , generating a " << rows << " * " << columns <<" maze !"<<endl;
        CLabyrinthe bob(columns,rows);
        bob.GenLaby();
        cout << endl << "The maze was randomly generated yay" << endl ;
        string watdoyoudo;
        while(watdoyoudo!="quit"){
            getline(cin,watdoyoudo);
            if (watdoyoudo == "display")
                Display(bob);
            else if (watdoyoudo == "displaysolved")
                DisplaySolved(bob);
            else if (watdoyoudo == "saveastext")
                SaveAsText(bob);
            else if (watdoyoudo == "saveastextsolved")
                SaveAsTextSolved(bob);
            else if (watdoyoudo == "newmaze")
                newmaze=1;
            cout << endl << "what do you want to do with it ? (display|displaysolved|saveastext|saveastextsolved|newmaze|quit)"<< endl;
            }
    }
    return 0;
}
/*  ofstream fw;
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
    //cin>>non;*/
