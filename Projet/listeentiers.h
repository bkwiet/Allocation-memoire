/******************************************************************************
	Fichier:	listeentiers.h

	Classes:	CNoeudEntier et CListeEntiers

	Auteur:		CRECEL Xavier

	Utilité:	Déclaration des classes CNoeudEntier et CListeEntiers
******************************************************************************/

#ifndef __LISTEENTIERS_H
#define __LISTEENTIERS_H

class CNoeudEntier
{

	friend class CListeEntiers;

	public :

		// Constructeurs
		CNoeudEntier(int iUnEntier = 0);
		CNoeudEntier(const CNoeudEntier & unNoeudEntier);

		// Methodes

	private:

		// Données-membres
		int m_iElement;
		CNoeudEntier * m_pLeSuivant;

};

class CListeEntiers
{

	public :

		// Constructeurs
		CListeEntiers();
		CListeEntiers(const CListeEntiers & uneListeEntiers);

		// Destructeur
		~CListeEntiers();

		// Methodes
		const CListeEntiers & operator = 
			(const CListeEntiers & uneListeEntiers );
		int & operator [] (unsigned int uiIndice);
		void Ajouter(int iUnEntier);
		bool Retirer(unsigned int uiIndice);	
		const unsigned int NbElements();
		const bool EstVide();
		void Vider();

	private:

		// Données-membres
		CNoeudEntier * m_pLePremier;
};
#endif