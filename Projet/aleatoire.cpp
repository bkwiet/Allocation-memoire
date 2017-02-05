/******************************************************************************
	Fichier:	aleatoire.cpp

	Auteur:		Jos� Consola

	Utilit�:	Impl�mentation de la biblioth�que contenant la fonction de
				g�n�ration de nombres pseudo-al�atoires.
******************************************************************************/
#include "aleatoire.h"
#include <time.h>
#include <stdlib.h>


/******************************************************************************
	La fonction GenererNbAleatoire (...) permet d'obtenir un nombre al�atoire
	dont la valeur est comprise inclusivement entre les bornes pass�es en
	param�tres. Lance une exception si l'une ou l'autre des bornes est
	n�gative ou si la borne inf�rieure a une valeur plus grande que la borne
	sup�rieure.
******************************************************************************/
int GenererNbAleatoire (short sMin, short sMax)
{
	// Variable statique qui permet de v�rifier si le g�n�rateur des nombres
	// al�atoires a �t� initialis�.
	// N.B.:	Une variable d�clar�e statique � l'int�rieur d'une fonction
	//			reste en m�moire (et conserve sa valeur) m�me lorsque la
	//			fonction a termin� son ex�cution.
	static bool bInitialise = false;

	// Initialisation unique du g�n�rateur de nombres al�atoires.
	if (! bInitialise)
	{
		srand ((unsigned) time (NULL));
		bInitialise = true;
	}
	if (sMin < 0 || sMax < 0 || sMin > sMax)
	{
		throw "Limites invalides.";
	}
	// La fonction rand () retourne un nombre pseudo-al�atoire compris
	// entre 0 et 32767 (inclusivement). La constante RAND_MAX poss�de la
	// valeur 32767.
	// N.B.:	Le r�sultat retourn� par rand () et la valeur de RAND_MAX
	//			d�pendent de leur impl�mentation.
	return sMin + (int) ((double) rand () * (sMax - sMin + 1)
		/ ((unsigned) RAND_MAX + 1));
}