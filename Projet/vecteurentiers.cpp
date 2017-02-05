/******************************************************************************
	Fichier:	vecteurentiers.cpp

	Classe:		CVecteurEntiers

	Auteur:		CRECEL Xavier

	Utilité:	Implémentation des méthodes de la classe CVecteurEntiers.
******************************************************************************/

#include "vecteurentiers.h"

/******************************************************************************
	Ce constructeur permet d'initialiser les valeurs des données-membres à 0.
******************************************************************************/
CVecteurEntiers::CVecteurEntiers()
	: m_piLesElements (0), m_uiNbElements (0)
{
}

/******************************************************************************
	Ce constructeur permet d'initialiser les données-membres de l'objet avec 
	les valeurs des attributs d'un objet type CVecteurEntiers reçu en paramétre
	par l'entremise de l'opérateur =.
******************************************************************************/
CVecteurEntiers::CVecteurEntiers(const CVecteurEntiers & unVecteurEntiers )
	: m_piLesElements (0)
{
	*this = unVecteurEntiers;
}

/******************************************************************************
	Ce destructeur permet de liberer la memoire attribuer au vecteur et de 
	detruire celui-ci.
******************************************************************************/
CVecteurEntiers::~CVecteurEntiers()
{
	if( m_piLesElements != 0)
	{
		delete [] m_piLesElements;
		m_piLesElements = 0;
		m_uiNbElements = 0;
	}
}

/******************************************************************************
	La méthode "operateur" == (...) permet d'initialiser les valeurs de 
	l'objet courant avec les les valeurs des attributs d'un objet type 
	CVecteurEntiers reçu en paramétre.
******************************************************************************/
const CVecteurEntiers & CVecteurEntiers::operator = 
	(const CVecteurEntiers & unVecteurEntiers)
{
	unsigned int uiIterateur;

	if (m_piLesElements != 0)
	{
		delete [] m_piLesElements;
	}

	m_uiNbElements = unVecteurEntiers.m_uiNbElements;

	if (m_uiNbElements > 0) 
	{
		m_piLesElements = new int [m_uiNbElements];
		for (uiIterateur = 0; uiIterateur < m_uiNbElements; uiIterateur++)
		{
			m_piLesElements [uiIterateur] = unVecteurEntiers.m_piLesElements
				[uiIterateur];
		}
	}
	return * this;
}

/******************************************************************************
	La méthode "operateur" [] (...) permet de parcourir le vecteur et renvoie
	l'element contenu a l'indice passé en paramétre.
******************************************************************************/
int & CVecteurEntiers::operator [] (unsigned int uiIndice)
{
	if (uiIndice >= m_uiNbElements)
	{
		throw "Indice en dehors de la plage.";
	}
	return m_piLesElements [uiIndice];	
}

/******************************************************************************
	La méthode "Ajouter" permet d'ajouter un élément reçu en paramétre
	au vecteur.
******************************************************************************/
void CVecteurEntiers::Ajouter( int iUnEntier )
{
	int * piLesElements;
	unsigned int uiIterateur;

	piLesElements = new int[m_uiNbElements + 1];

	for (uiIterateur = 0; uiIterateur < m_uiNbElements; uiIterateur++)
	{
		piLesElements [uiIterateur] = m_piLesElements [uiIterateur];
	}

	piLesElements [uiIterateur] = iUnEntier;
	
	if (m_piLesElements != 0)
	{
		delete [] m_piLesElements;
	}

	m_piLesElements = piLesElements;
	m_uiNbElements++;
}

/******************************************************************************
	La méthode "Retirer" permet de retirer un élément du vecteur 
	a l'indice reçu en paramétre.
******************************************************************************/
bool CVecteurEntiers::Retirer(unsigned int uiIndice)
{
	if (uiIndice < m_uiNbElements)
	{
		int * piLesElements;

		if (m_uiNbElements > 1)
		{
			unsigned int uiIterateur;

			piLesElements = new int [m_uiNbElements - 1];

			for (uiIterateur = 0; uiIterateur < m_uiNbElements; uiIterateur++)
			{
				if (uiIterateur < uiIndice)
				{
					piLesElements [uiIterateur] = m_piLesElements[uiIterateur];
				}

				else if (uiIterateur > uiIndice)
				{
					piLesElements [uiIterateur - 1] = m_piLesElements[uiIterateur];
				}
			}

		}

		else
		{
			piLesElements = 0;
		}

		delete [] m_piLesElements;
		m_piLesElements = piLesElements;
		m_uiNbElements--;

		return true;
	}

	return false;
}

/******************************************************************************
	La méthode "NbElements" permet de retourner le nombre d'éléments contenu
	dans le vecteur.
******************************************************************************/
const unsigned int CVecteurEntiers::NbElements()
{
	return m_uiNbElements;
}