/******************************************************************************
	Fichier:	vecteurentiers.cpp

	Classe:		CVecteurEntiers

	Auteur:		CRECEL Xavier

	Utilit�:	Impl�mentation des m�thodes de la classe CVecteurEntiers.
******************************************************************************/

#include "vecteurentiers.h"

/******************************************************************************
	Ce constructeur permet d'initialiser les valeurs des donn�es-membres � 0.
******************************************************************************/
CVecteurEntiers::CVecteurEntiers()
	: m_piLesElements (0), m_uiNbElements (0)
{
}

/******************************************************************************
	Ce constructeur permet d'initialiser les donn�es-membres de l'objet avec 
	les valeurs des attributs d'un objet type CVecteurEntiers re�u en param�tre
	par l'entremise de l'op�rateur =.
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
	La m�thode "operateur" == (...) permet d'initialiser les valeurs de 
	l'objet courant avec les les valeurs des attributs d'un objet type 
	CVecteurEntiers re�u en param�tre.
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
	La m�thode "operateur" [] (...) permet de parcourir le vecteur et renvoie
	l'element contenu a l'indice pass� en param�tre.
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
	La m�thode "Ajouter" permet d'ajouter un �l�ment re�u en param�tre
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
	La m�thode "Retirer" permet de retirer un �l�ment du vecteur 
	a l'indice re�u en param�tre.
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
	La m�thode "NbElements" permet de retourner le nombre d'�l�ments contenu
	dans le vecteur.
******************************************************************************/
const unsigned int CVecteurEntiers::NbElements()
{
	return m_uiNbElements;
}