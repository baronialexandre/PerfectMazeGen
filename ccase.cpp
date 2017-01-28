#include "ccase.h"
#include <iostream>

using namespace std;
CCase::CCase(const unsigned & Id) noexcept  : IdGen(Id)
{
	m_Nord = nullptr;
	m_Sud = nullptr;
	m_Est = nullptr;
	m_Ouest = nullptr;

   
}

CCase::CCase () noexcept {}
CCase::~CCase(void) noexcept
{

	//std::cout << "Detruit " << std::endl;
}

/*** GETTERS ***/
CCase *CCase::GetOuest() const noexcept
{
    return m_Ouest;
}
CCase *CCase::GetEst() const noexcept
{
    return m_Est;
}
CCase *CCase::GetSud() const noexcept
{
    return m_Sud;
}
CCase *CCase::GetNord() const noexcept
{
    return m_Nord;
}
unsigned CCase::GetId() const noexcept
{
	return IdGen;
}


/**** SETTERS ***/
void CCase::setNord(const CCase & Nord) noexcept
{
	m_Nord = new CCase(Nord);

}
void CCase::setSud(const CCase & Sud) noexcept
{
	m_Sud = new CCase(Sud);

}
void CCase::setEst(const CCase & Est) noexcept
{
	m_Est = new CCase(Est);
}
void CCase::setOuest(const CCase & Ouest) noexcept
{
	m_Ouest = new CCase(Ouest);

}



void CCase::setNord() noexcept
{
	m_Nord = nullptr;

}
void CCase::setSud() noexcept
{
	m_Sud = nullptr;

}
void CCase::setEst() noexcept
{
	m_Est = nullptr;
}
void CCase::setOuest() noexcept
{
	m_Ouest = nullptr;

}

void CCase::setId(const unsigned & Id) noexcept
{
	IdGen = Id;

}



