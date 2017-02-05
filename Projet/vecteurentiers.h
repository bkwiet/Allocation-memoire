/******************************************************************************
	Fichier:	vecteurentiers.h

	Classe:		CVecteurEntiers

	Auteur:		CRECEL Xavier

	Utilit�:	D�claration de la classe CVecteurEntiers 
******************************************************************************/

#ifndef __VECTEURENTIERS_H
#define __VECTEURENTIERS_H

class CVecteurEntiers
{

	public :

		// Constructeurs
		CVecteurEntiers();
		CVecteurEntiers(const CVecteurEntiers & unVecteurEntiers );
		
		// Destructeur
		~CVecteurEntiers();

		// Methodes
		const CVecteurEntiers & operator = (const CVecteurEntiers & unVecteurEntiers);
		int & operator [] (unsigned int uiIndice);
		void Ajouter( int iUnEntier );
		bool Retirer(unsigned int uiIndice);		
		const unsigned int NbElements();

	private:

		// Donn�es-membres
		int * m_piLesElements;
		unsigned int m_uiNbElements;
};

#endif