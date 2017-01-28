#pragma once

class CCase
{
    private:
        CCase* m_Nord;
        CCase* m_Sud;
        CCase* m_Est;
        CCase* m_Ouest;

		unsigned IdGen;
    public:

        CCase(const unsigned & Id) noexcept;
		CCase() noexcept;
       ~CCase(void) noexcept;

        //Getteurs

        CCase* GetOuest() const noexcept;
        CCase* GetEst()   const noexcept;
        CCase* GetSud()   const noexcept;
        CCase* GetNord()  const noexcept;

		void setWall(); 

		unsigned GetId()  const noexcept;


        //Setteurs

        void setNord(const CCase &  Nord) noexcept;
        void setSud(const CCase &   Sud)  noexcept;
        void setEst(const CCase &  Est)  noexcept;
        void setOuest(const CCase  & Ouest)noexcept;
		void setId(const unsigned & Id)noexcept;

		void setNord() noexcept;
		void setSud()  noexcept;
		void setEst()  noexcept;
		void setOuest()noexcept;


		

};
