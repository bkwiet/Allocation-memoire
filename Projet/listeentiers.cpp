/******************************************************************************
	Fichier:	listeentiers.cpp

	Classes:	CNoeudEntier et CListeEntiers

	Auteur:		CRECEL Xavier

	Utilit�:	Impl�mentation des m�thodes des classes 
				CNoeudEntier et CListeEntiers.
******************************************************************************/

#include "listeentiers.h"

/******************************************************************************

	Classe: CNoeudEntier.

******************************************************************************/

/******************************************************************************
	Ce constructeur permet d'initialiser les valeurs des donn�es-membres.
******************************************************************************/
CNoeudEntier::CNoeudEntier(int iUnEntier)
	:m_iElement (iUnEntier),m_pLeSuivant (0)
{
}

/******************************************************************************
	Ce constructeur permet d'initialiser les donn�es-membres de l'objet avec 
	les valeurs des attributs d'un objet type CNoeudEntier re�u en param�tre.
******************************************************************************/
CNoeudEntier::CNoeudEntier(const CNoeudEntier & unNoeudEntier)
	:m_iElement (unNoeudEntier.m_iElement) , 
	 m_pLeSuivant (unNoeudEntier.m_pLeSuivant)
{
}

/******************************************************************************

	Classe: CListeEntiers.

******************************************************************************/

/******************************************************************************
	Ce constructeur permet d'initialiser les valeurs des donn�es-membres.
******************************************************************************/
CListeEntiers::CListeEntiers()
	: m_pLePremier (0)
{
}

/******************************************************************************
	Ce constructeur permet d'initialiser les donn�es-membres de l'objet avec 
	les valeurs des attributs d'un objet type CListeEntiers re�u en param�tre
	par l'entremise de l'op�rateur =.
******************************************************************************/
CListeEntiers::CListeEntiers(const CListeEntiers & uneListeEntiers)
	: m_pLePremier (0)
{
	*this = uneListeEntiers;
}

/******************************************************************************
	Ce destructeur permet de liberer la memoire attribuer a la liste par
	le biais de la methode "Vider"
******************************************************************************/
CListeEntiers::~CListeEntiers()
{
	Vider();
}

/******************************************************************************
	La m�thode "operateur" == (...) permet d'initialiser les valeurs de 
	l'objet courant avec les les valeurs des attributs d'un objet type 
	CListeEntiers re�u en param�tre.
******************************************************************************/
const CListeEntiers & CListeEntiers::operator = 
			(const CListeEntiers & uneListeEntiers )
{
	Vider();

	m_pLePremier = uneListeEntiers.m_pLePremier; 

	return *this;
}

/******************************************************************************
	La m�thode "operateur" [] (...) permet de parcourir la liste et renvoie
	l'element contenu a l'indice pass� en param�tre.
******************************************************************************/
int & CListeEntiers::operator [] (unsigned int uiIndice)
{
	unsigned int iNbElements = NbElements();

		if(uiIndice >= iNbElements)
		{
			throw "Indice en dehors de la plage.";
		}

		unsigned int iIterateur;
		CNoeudEntier * unNoeudEntierCourant = m_pLePremier;

		for(iIterateur = 0 ; iIterateur < uiIndice ; iIterateur++)
		{
			unNoeudEntierCourant = unNoeudEntierCourant->m_pLeSuivant;
		}
		
		return unNoeudEntierCourant->m_iElement;
}

/******************************************************************************
	La m�thode "Ajouter" permet d'ajouter un �l�ment re�u en param�tre
	a la liste.
******************************************************************************/
void CListeEntiers::Ajouter(int iUnEntier)
{
	if(m_pLePremier != 0)
	{
		CNoeudEntier * unNoeudEntierCourant = m_pLePremier;

		while(unNoeudEntierCourant ->m_pLeSuivant != 0)
		{
			unNoeudEntierCourant = unNoeudEntierCourant ->m_pLeSuivant;
		}
		
		CNoeudEntier * unNoeudEntierNouveau = new CNoeudEntier(iUnEntier);

		unNoeudEntierCourant ->m_pLeSuivant = unNoeudEntierNouveau;

		unNoeudEntierCourant = m_pLePremier;

	}
	else
	{
		m_pLePremier = new CNoeudEntier(iUnEntier);
	}
}

/******************************************************************************
	La m�thode "Retirer" permet de retirer un �l�ment de la liste 
	a l'indice re�u en param�tre.
******************************************************************************/
bool CListeEntiers::Retirer(unsigned int uiIndice) /*  EN CHANTIER */
{

	if(uiIndice == 0)
	{
		if(m_pLePremier != 0)
		{
			CNoeudEntier * unNoeudEntier = m_pLePremier;
			m_pLePremier = m_pLePremier->m_pLeSuivant;
			delete unNoeudEntier;

			return true;
		}
		return false;
	}
	else
	{
		unsigned int iIterateur;
		CNoeudEntier * unNoeudEntierCourant = m_pLePremier;

		for(iIterateur = 0 ; iIterateur < uiIndice ; iIterateur++)
		{
			unNoeudEntierCourant = unNoeudEntierCourant->m_pLeSuivant;
		}

		if(unNoeudEntierCourant != 0 && unNoeudEntierCourant->m_pLeSuivant !=0)
		{
			CNoeudEntier *unNoeudEntierTemp = 
				unNoeudEntierCourant->m_pLeSuivant;

			unNoeudEntierCourant = unNoeudEntierCourant->m_pLeSuivant ->m_pLeSuivant;

			delete unNoeudEntierTemp;
			unNoeudEntierCourant = m_pLePremier;

			return true ;
		}
		return false;
	}

}
		
/******************************************************************************
	La m�thode "NbElements" permet de retourner le nombre d'�l�ments contenu
	dans la liste.
******************************************************************************/	
const unsigned int CListeEntiers::NbElements()
{
	unsigned int uiNbElements =0;

	if(m_pLePremier != 0 )
	{
		uiNbElements = 1;
		CNoeudEntier * unNoeudEntierCourant = m_pLePremier;
	
		while(unNoeudEntierCourant ->m_pLeSuivant != 0)
		{
			uiNbElements++;
			unNoeudEntierCourant = unNoeudEntierCourant ->m_pLeSuivant;			
		}

		unNoeudEntierCourant = m_pLePremier;
	}

	return uiNbElements;
}

/******************************************************************************
	La m�thode "EstVide" permet de v�ifier si la liste est vide
	retourne vrai si elle est vide , autrement retourne faux.
******************************************************************************/
const bool CListeEntiers::EstVide()
{
	if(m_pLePremier != 0)
	{
		return false;
	}

	return true;
}

/******************************************************************************
	La m�thode "Vider" permet de vider la liste en detruisant chaque �l�ments
	de celle-ci.
******************************************************************************/
void CListeEntiers::Vider()
{
	CNoeudEntier *unNoeudEntier = m_pLePremier;

	while(unNoeudEntier != 0)
	{
		CNoeudEntier *unNoeudEntierTemp = unNoeudEntier;

		unNoeudEntier = unNoeudEntier->m_pLeSuivant;

		delete unNoeudEntierTemp;
	}

	m_pLePremier = 0;
}