#include "clabyrinthe.h"
#include "ccase.h"
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

CLabyrinthe::CLabyrinthe(const unsigned & y, const unsigned & x) noexcept : m_Y(y), m_X(x)
{

	
	vector <vector <CCase>> Laby;
	Laby.resize(x);
    for (unsigned i (0); i < x; ++i)
	{ 
		Laby[i].resize(y);

        for (unsigned j (0); j < y; ++ j)
        {
            CCase Case (i * x + j);
			//cout << Case.GetId() << endl;
            Laby[i][j] = Case;
        }
	}
	
	m_Labyrinthe = Laby;
}

CLabyrinthe::CLabyrinthe(const CLabyrinthe * lab) noexcept
{
    m_Y=lab->m_Y;
    m_X=lab->m_X;
    vector <vector <CCase>> Laby;
    Laby.resize(lab->GetLabyrinthe().size());
    for (unsigned i (0); i < lab->GetLabyrinthe().size(); ++i)
    {
        Laby[i].resize(lab->GetLabyrinthe()[0].size());

        for (unsigned j (0); j < lab->GetLabyrinthe()[0].size(); ++ j)
        {
            Laby[i][j] = lab->GetLabyrinthe()[i][j];
        }
    }
    m_Labyrinthe = Laby;
}

CLabyrinthe::~CLabyrinthe()
{}



/*** METHODES ***/
void CLabyrinthe::Afficher()
{
	//DISREGARD L'inversion des directions des gets ... je sai pa pk mais c'est comme ça qu'il faut faire ;(
	string vide = " ";
	string mur = "8";
	for (unsigned i(0); i < m_Labyrinthe.size(); ++i)
	{
		for (unsigned j(0); j < m_Labyrinthe[i].size(); ++j)
		{
			cout << mur;
			if (m_Labyrinthe[i][j].GetOuest())
				cout << vide;
			else
				cout << mur;
			if (j == m_Labyrinthe[i].size() - 1)
				cout << mur;
		}
		cout << endl;
		for (unsigned j(0); j < m_Labyrinthe[i].size(); ++j)
		{
			if (m_Labyrinthe[i][j].GetNord())
				cout << vide;
			else
				cout << mur;
			cout << vide;
			if (j == m_Labyrinthe[i].size() - 1)
			{
				if (m_Labyrinthe[i][j].GetSud())
					cout << vide;
				else
					cout << mur;
			}
			//else cout << 'j';
		}
		cout << endl;
	}
	for (unsigned j(0); j < m_Labyrinthe[0].size(); ++j)
	{
		cout << mur;
		if (m_Labyrinthe[m_Labyrinthe.size()-1][j].GetEst())
			cout << vide;
		else
			cout << mur;
		if (j == m_Labyrinthe[0].size() - 1)
			cout << mur;
	}
}

void CLabyrinthe::AfficherPlusChemin()
{
    //DISREGARD L'inversion des directions des gets ... je sai pa pk mais c'est comme ça qu'il faut faire ;(
    string vide = " ";
    string chemin = ".";
    string mur = "8";
    CLabyrinthe berthier = this->ReturnSolved(); // OUEST = NORD ; NORD = EST ;
    for (unsigned i(0); i < m_Labyrinthe.size(); ++i)
    {
        for (unsigned j(0); j < m_Labyrinthe[i].size(); ++j)
        {
            cout << mur;
            if(berthier.GetLabyrinthe()[i][j].GetOuest())
                cout << chemin;
            else if (m_Labyrinthe[i][j].GetOuest())
                cout << vide;
            else
                cout << mur;
            if (j == m_Labyrinthe[i].size() - 1)
                cout << mur;
        }
        cout << endl;
        for (unsigned j(0); j < m_Labyrinthe[i].size(); ++j)
        {
            if(berthier.GetLabyrinthe()[i][j].GetNord())
                cout << chemin;
            else if (m_Labyrinthe[i][j].GetNord())
                cout << vide;
            else
                cout << mur;
            if (berthier.GetLabyrinthe()[i][j].GetSud()||berthier.GetLabyrinthe()[i][j].GetEst()||berthier.GetLabyrinthe()[i][j].GetOuest()||berthier.GetLabyrinthe()[i][j].GetNord())
                cout << chemin;
            else
                cout << vide ;
            if (j == m_Labyrinthe[i].size() - 1)
            {
                if(berthier.GetLabyrinthe()[i][j].GetSud())
                    cout << chemin;
                else if (m_Labyrinthe[i][j].GetSud())
                    cout << vide;
                else
                    cout << mur;
            }
            //else cout << 'j';
        }
        cout << endl;
    }
    for (unsigned j(0); j < m_Labyrinthe[0].size(); ++j)
    {
        cout << mur;
        if(berthier.GetLabyrinthe()[m_Labyrinthe.size()-1][j].GetEst())
            cout << chemin;
        else if (m_Labyrinthe[m_Labyrinthe.size()-1][j].GetEst())
            cout << vide;
        else
            cout << mur;
        if (j == m_Labyrinthe[0].size() - 1)
            cout << mur;
    }
}

void CLabyrinthe::AfficherDebug()
{
	//A FIX SI BESOIN : les getters directions inversement qui vienne de la generation .
	for (unsigned i(0); i < m_Labyrinthe.size(); ++i)
	{
		for (unsigned j(0); j < m_Labyrinthe[i].size(); ++j)
		{
			//On test chaques segments de chaques cases, si il vaut nullptr, on crée un mur
			if (m_Labyrinthe[i][j].GetOuest() == nullptr)
			{
				cout << "O";
			}
			if (m_Labyrinthe[i][j].GetNord() == nullptr)
			{
				cout << "N";
			}
			//cout<<'['<<m_Labyrinthe[j][i].GetId()<<']'; ID
			if (m_Labyrinthe[i][j].GetSud() == nullptr)
			{
				cout << "S";
			}
			if (m_Labyrinthe[i][j].GetEst() == nullptr)
			{
				cout << "E";
			}
			cout << "|";
			//cout<<'['<<m_Labyrinthe[j][i].GetId()<<']';
		}
		cout << endl;
	}
}

void CLabyrinthe::Solve()
{
	//AfficherDebug();
	for (unsigned i = 0; i < (m_X - 1) + (m_Y - 1); ++i)
	{
		for (unsigned j = 0; j < m_Labyrinthe.size(); ++j)
		{
			for (unsigned k = 0; k < m_Labyrinthe[j].size(); ++k)
			{
				if (!m_Labyrinthe[j][k].GetEst() && !m_Labyrinthe[j][k].GetOuest() && !m_Labyrinthe[j][k].GetNord() && m_Labyrinthe[j][k].GetSud())      // Si Est Ouest Nord = Mur alors on met un mur au sud |-|
				{
					m_Labyrinthe[j][k + 1].setNord();
					m_Labyrinthe[j][k].setSud();
				}
				if (!m_Labyrinthe[j][k].GetEst() && !m_Labyrinthe[j][k].GetOuest() && !m_Labyrinthe[j][k].GetSud() && m_Labyrinthe[j][k].GetNord())  // Si Est Ouest Sud = Mur alors on met un mur au nord  |_|
				{
					m_Labyrinthe[j][k - 1].setSud();
					m_Labyrinthe[j][k].setNord();
				}
				if (!m_Labyrinthe[j][k].GetNord() && !m_Labyrinthe[j][k].GetOuest() && !m_Labyrinthe[j][k].GetSud() && m_Labyrinthe[j][k].GetEst()) // Si Nord Ouest Sud = Mur alors on met un mur a l'est
				{
					m_Labyrinthe[j + 1][k].setOuest();
					m_Labyrinthe[j][k].setEst();
				}
				if (!m_Labyrinthe[j][k].GetNord() && !m_Labyrinthe[j][k].GetSud() && !m_Labyrinthe[j][k].GetEst() && m_Labyrinthe[j][k].GetOuest())   // Si Nord Sud Est = Mur alors on met un mur a l'ouest
				{
					m_Labyrinthe[j - 1][k].setEst();
					m_Labyrinthe[j][k].setOuest();

				}
				
			}
		}
	}

	//  return Path;

}

CLabyrinthe CLabyrinthe::ReturnSolved()
{
    CLabyrinthe path(this);
    path.Solve();
    return path;
}



void CLabyrinthe::IdChemin(const unsigned & info, const unsigned short & Direction, unsigned X, unsigned Y, CLabyrinthe* laby)
{
	//Dans cette fonction récursive , on va parcourir un chemin et lui donner un id info
	//On a besoin de la Direction pour ne pas parcourir des cases en boucles 
	// X et Y sont les coordonnées de la case courante dans le labyrinthe laby
	laby->m_Labyrinthe[X][Y].setId(info);
	switch (Direction)
	{
	case 0:
		//On ne parcours pas le nord car on vient du nord
		if (laby->m_Labyrinthe[X][Y].GetSud() && laby->m_Labyrinthe[X][Y].GetSud()->GetId() != info)
			IdChemin(info, 0, X, Y + 1, laby);
		if (laby->m_Labyrinthe[X][Y].GetOuest() && laby->m_Labyrinthe[X][Y].GetOuest()->GetId() != info)
			IdChemin(info, 3, X - 1, Y, laby);
		if (laby->m_Labyrinthe[X][Y].GetEst() && laby->m_Labyrinthe[X][Y].GetEst()->GetId() != info)
			IdChemin(info, 2, X + 1, Y, laby);
		break;
	case 1:
		//On ne parcours pas le sud car on vient du sud
		if (laby->m_Labyrinthe[X][Y].GetNord() && laby->m_Labyrinthe[X][Y].GetNord()->GetId() != info)
			IdChemin(info, 1, X, Y - 1, laby);
		if (laby->m_Labyrinthe[X][Y].GetOuest() && laby->m_Labyrinthe[X][Y].GetOuest()->GetId() != info)
			IdChemin(info, 3, X - 1, Y, laby);
		if (laby->m_Labyrinthe[X][Y].GetEst() && laby->m_Labyrinthe[X][Y].GetEst()->GetId() != info)
			IdChemin(info, 2, X + 1, Y, laby);
		break;
	case 2:
		//On ne parcours pas l'ouest car on vient de l'ouest
		if (laby->m_Labyrinthe[X][Y].GetSud() && laby->m_Labyrinthe[X][Y].GetSud()->GetId() != info)
			IdChemin(info, 0, X, Y + 1, laby);
		if (laby->m_Labyrinthe[X][Y].GetNord() && laby->m_Labyrinthe[X][Y].GetNord()->GetId() != info)
			IdChemin(info, 1, X, Y - 1, laby);
		if (laby->m_Labyrinthe[X][Y].GetEst() && laby->m_Labyrinthe[X][Y].GetEst()->GetId() != info)
			IdChemin(info, 2, X + 1, Y, laby);
		break;
	case 3:
		//On ne parcours pas l'est car on vient de l'est
		if (laby->m_Labyrinthe[X][Y].GetSud() && laby->m_Labyrinthe[X][Y].GetSud()->GetId() != info)
			IdChemin(info, 0, X, Y + 1, laby);
		if (laby->m_Labyrinthe[X][Y].GetOuest() && laby->m_Labyrinthe[X][Y].GetOuest()->GetId() != info)
			IdChemin(info, 3, X - 1, Y, laby);
		if (laby->m_Labyrinthe[X][Y].GetNord() && laby->m_Labyrinthe[X][Y].GetNord()->GetId() != info)
			IdChemin(info, 1, X, Y - 1, laby);
		break;
	}
}



void CLabyrinthe::GenLaby() noexcept
{
	srand(time(NULL));
	// On va creer un chemin entre une case choisie aléatoirement et une case adjacente
	// Coordonnées de la case choisie aléatoirement
	unsigned RY;
	unsigned RX;
	// Coordonnées de la case adjacente
	unsigned RYEch;
	unsigned RXEch;

	unsigned short Direction;//0 = Nord ; 1 = Sud ; 2 = Ouest ; 3 = Est ;
					   // Compteur de condition , on créé (m*n)-1 chemin
	unsigned cpt(0);
	for (;;)
	{
		RY = rand() % m_Y;// Génération aléatoire de la coordonnée Y entre 0 et m_Y
		RX = rand() % m_X;// Génération aléatoire de la coordonnée X entre 0 et m_X
		if (RX == 0 && RY == 0)
		{
			//Case choisie dans le coin nord ouest
			//On ne peut pas prendre une case adjacente au nord ou a l'ouest
			unsigned balance(rand() % 2 + 2);
			if (balance % 2 == 0)
				Direction = 1;
			else
				Direction = 3;
		}
		else if (RY == 0 && RX == m_X - 1)
		{
			//Case choisie dans le coin nord est
			//On ne peut pas prendre une case adjacente au nord ou a l'est
			unsigned balance(rand() % 2 + 2);
			if (balance % 2 == 0)
				Direction = 1;
			else
				Direction = 2;
		}
		else if (RY == m_Y - 1 && RX == 0)
		{
			//Case choisie dans le coin sud ouest
			//On ne peut pas prendre une case adjacente au sud ou a l'ouest
			unsigned balance(rand() % 2 + 2);
			if (balance % 2 == 0)
				Direction = 0;
			else
				Direction = 3;
		}
		else if (RY == m_Y - 1 && RX == m_X - 1)
		{
			//Case choisie dans le coin sud est
			//On ne peut pas prendre une case adjacente au sud ou a l'est
			unsigned balance(rand() % 2 + 2);
			if (balance % 2 == 0)
				Direction = 0;
			else
				Direction = 2;
		}
		else if (RY == 0)
		{
			//Case choisie dans le coté nord
			//On ne peut pas prendre une case adjacente au nord
			unsigned balance(rand() % 3);
			if (balance == 0)
				Direction = 1;
			else if (balance == 1)
				Direction = 2;
			else
				Direction = 3;
		}
		else if (RX == 0)
		{
			//Case choisie dans le coté ouest
			//On ne peut pas prendre une case adjacente a l'ouest
			unsigned balance(rand() % 3);
			if (balance == 0)
				Direction = 1;
			else if (balance == 1)
				Direction = 0;
			else
				Direction = 3;
		}
		else if (RY == m_Y - 1)
		{
			//Case choisie dans le coté sud
			//On ne peut pas prendre une case adjacente au sud
			unsigned balance(rand() % 3);
			if (balance == 0)
				Direction = 0;
			else if (balance == 1)
				Direction = 2;
			else
				Direction = 3;
		}
		else if (RX == m_X - 1)
		{
			//Case choisie dans le coté est
			//On ne peut pas prendre une case adjacente a l'est
			unsigned balance(rand() % 3);
			if (balance == 0)
				Direction = 1;
			else if (balance == 1)
				Direction = 2;
			else
				Direction = 0;
		}
		else
		{
			Direction = rand() % 4;
		}
		switch (Direction)//On met les coordonnées de la case adjacante suivant la direction
		{
		case 0:
			RYEch = RY - 1;
			RXEch = RX;
			break;
		case 1:
			RYEch = RY + 1;
			RXEch = RX;
			break;
		case 2:
			RYEch = RY;
			RXEch = RX - 1;
			break;
		case 3:
			RYEch = RY;
			RXEch = RX + 1;
			break;
		}
		// Si les deux cases on le même identifiant , ça veut dire qu'ils appartiennent
		// au même chemin , donc on ne créer pas de chemin
		if (m_Labyrinthe[RX][RY].GetId() < m_Labyrinthe[RXEch][RYEch].GetId())
		{
			switch (Direction)//On creer le chemin en fonction de la direction
			{
			case 0:
				m_Labyrinthe[RX][RY].setNord(m_Labyrinthe[RXEch][RYEch]);
				m_Labyrinthe[RXEch][RYEch].setSud(m_Labyrinthe[RX][RY]);
				Direction = 1;
				break;
			case 1:
				m_Labyrinthe[RX][RY].setSud(m_Labyrinthe[RXEch][RYEch]);
				m_Labyrinthe[RXEch][RYEch].setNord(m_Labyrinthe[RX][RY]);
				Direction = 0;
				break;
			case 2:
				m_Labyrinthe[RX][RY].setOuest(m_Labyrinthe[RXEch][RYEch]);
				m_Labyrinthe[RXEch][RYEch].setEst(m_Labyrinthe[RX][RY]);
				Direction = 3;
				break;
			case 3:
				m_Labyrinthe[RX][RY].setEst(m_Labyrinthe[RXEch][RYEch]);
				m_Labyrinthe[RXEch][RYEch].setOuest(m_Labyrinthe[RX][RY]);
				Direction = 2;
				break;
			}
			//on incremente le compteur 
			++cpt;
			//On parcours le chemin auquel apartient la case adjacente et on donne a ce 
			// chemin l'ID de la premiere case
			IdChemin(m_Labyrinthe[RX][RY].GetId(), Direction, RXEch, RYEch, this);
			//On sort de la boucle de création de chemin quand on a créé m*n-1
            cout << cpt << "/" << (m_X*m_Y) - 1 << "\r";
			if (cpt >= (m_X*m_Y) - 1)break;
		}
	}
	//Entree sortie
	// On réutilise RX , RY , RXEch et RYEch
	// en tant que coordonnées pour la case d'entrée et de sortie
	Direction = rand() % 4;//0 = Nord ; 1 = Sud ; 2 = Ouest ; 3 = Est ;
	switch (Direction)//0 = Nord ; 1 = Sud ; 2 = Ouest ; 3 = Est ;
	{
	case 0:
		RX = rand() % m_X;
		RY = 0;
		RXEch = rand() % m_X;
		RYEch = m_Y - 1;
		m_Labyrinthe[RX][RY].setNord(m_Enter);
		m_Labyrinthe[RXEch][RYEch].setSud(m_Exit);
		m_Enter.setSud(m_Labyrinthe[RX][RY]);
		m_Exit.setNord(m_Labyrinthe[RXEch][RYEch]);
		break;
	case 1:
		RX = rand() % m_X;
		RY = m_Y - 1;
		RXEch = rand() % m_X;
		RYEch = 0;
		m_Labyrinthe[RX][RY].setSud(m_Enter);
		m_Labyrinthe[RXEch][RYEch].setNord(m_Exit);
		m_Enter.setNord(m_Labyrinthe[RX][RY]);
		m_Exit.setSud(m_Labyrinthe[RXEch][RYEch]);
		break;
	case 2:
		RX = 0;
		RY = rand() % m_Y;
		RXEch = m_X - 1;
		RYEch = rand() % m_Y;
		m_Labyrinthe[RX][RY].setOuest(m_Enter);
		m_Labyrinthe[RXEch][RYEch].setEst(m_Exit);
		m_Enter.setEst(m_Labyrinthe[RX][RY]);
		m_Exit.setOuest(m_Labyrinthe[RXEch][RYEch]);
		break;
	case 3:
		RX = m_X - 1;
		RY = rand() % m_Y;
		RXEch = 0;
		RYEch = rand() % m_Y;
		m_Labyrinthe[RX][RY].setEst(m_Enter);
		m_Labyrinthe[RXEch][RYEch].setOuest(m_Exit);
		m_Enter.setOuest(m_Labyrinthe[RX][RY]);
		m_Exit.setEst(m_Labyrinthe[RXEch][RYEch]);
		break;
	}
	m_CoordEnter = make_pair(make_pair(RX, RY), Direction);
	m_CoordExit = make_pair(make_pair(RXEch, RYEch), Direction);
}

pair<pair<unsigned, unsigned>, unsigned short> CLabyrinthe::GetCoordEnter()
{
	return m_CoordEnter;
	
}
std::pair<std::pair<unsigned, unsigned>, unsigned short> CLabyrinthe::GetCoordExit()
{
	return m_CoordExit;
}



/*** GETTERS ***/
CCase CLabyrinthe::GetEnter()
{
	return m_Enter;
}
CCase CLabyrinthe::GetExit()
{
	return m_Exit;
}



std::vector<std::vector<CCase> >  CLabyrinthe::GetLabyrinthe() const
{
    return m_Labyrinthe;
}
