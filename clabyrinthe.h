#pragma once
#include "ccase.h"
#include <vector>
#include <utility>

class CLabyrinthe
{
    private:
        std::vector <std::vector <CCase>>  m_Labyrinthe;
        unsigned m_X;
        unsigned m_Y;
		CCase m_Enter;
		CCase m_Exit;
		std::pair<std::pair<unsigned, unsigned>, unsigned short> m_CoordEnter;
		std::pair<std::pair<unsigned, unsigned>, unsigned short> m_CoordExit;
    public:
        CLabyrinthe(const unsigned & y, const unsigned & x) noexcept;
		~CLabyrinthe();
		
		
		/*** METHODES ***/
		void Afficher();
		void AfficherDebug();
		void Solve();

		void IdChemin(const unsigned & info, const unsigned short & Direction, unsigned X, unsigned Y, CLabyrinthe* laby);
		void GenLaby() noexcept;
		std::pair<std::pair<unsigned, unsigned>, unsigned short> GetCoordEnter();
		std::pair<std::pair<unsigned, unsigned>,unsigned short> GetCoordExit();

		

		/*** GETTERS ***/
		CCase GetEnter(void);
		CCase GetExit(void);

        std::vector<std::vector<CCase>> GetLabyrinthe() const;

};
