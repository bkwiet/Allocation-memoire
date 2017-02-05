/******************************************************************************
	Fichier:	listeentiers.cpp

	Classes:	CNoeudEntier et CListeEntiers

	Auteur:		CRECEL Xavier

	Utilité:	Implémentation des méthodes des classes 
				CNoeudEntier et CListeEntiers.
******************************************************************************/

#include "listeentiers.h"

/******************************************************************************

	Classe: CNoeudEntier.

******************************************************************************/

/******************************************************************************
	Ce constructeur permet d'initialiser les valeurs des données-membres.
******************************************************************************/
CNoeudEntier::CNoeudEntier(int iUnEntier)
	:m_iElement (iUnEntier),m_pLeSuivant (0)
{
}

/******************************************************************************
	Ce constructeur permet d'initialiser les données-membres de l'objet avec 
	les valeurs des attributs d'un objet type CNoeudEntier reçu en paramétre.
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
	Ce constructeur permet d'initialiser les valeurs des données-membres.
******************************************************************************/
CListeEntiers::CListeEntiers()
	: m_pLePremier (0)
{
}

/******************************************************************************
	Ce constructeur permet d'initialiser les données-membres de l'objet avec 
	les valeurs des attributs d'un objet type CListeEntiers reçu en paramétre
	par l'entremise de l'opérateur =.
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
	La méthode "operateur" == (...) permet d'initialiser les valeurs de 
	l'objet courant avec les les valeurs des attributs d'un objet type 
	CListeEntiers reçu en paramétre.
******************************************************************************/
const CListeEntiers & CListeEntiers::operator = 
			(const CListeEntiers & uneListeEntiers )
{
	Vider();

	m_pLePremier = uneListeEntiers.m_pLePremier; 

	return *this;
}

/******************************************************************************
	La méthode "operateur" [] (...) permet de parcourir la liste et renvoie
	l'element contenu a l'indice passé en paramétre.
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
	La méthode "Ajouter" permet d'ajouter un élément reçu en paramétre
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
	La méthode "Retirer" permet de retirer un élément de la liste 
	a l'indice reçu en paramétre.
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
	La méthode "NbElements" permet de retourner le nombre d'éléments contenu
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
	La méthode "EstVide" permet de véifier si la liste est vide
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
	La méthode "Vider" permet de vider la liste en detruisant chaque éléments
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