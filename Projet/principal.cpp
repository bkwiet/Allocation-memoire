/******************************************************************************
	Fichier:	principal.cpp

	Auteur:		CRECEL Xavier

	Utilité:	Permet d'allouer de la memoire , d'afficher les éléents
				et liberer la memoire d'un vecteur et d'une liste, par le
				biais des classes CVecteursEntiers et CListeEntiers
******************************************************************************/

#include <iostream>
#include <ctime>
#include "aleatoire.h"
#include "vecteurentiers.h"
#include "listeentiers.h"

using namespace std;

#ifdef _WIN32
const char EFFACER_ECRAN [] = "cls";
#else
const char EFFACER_ECRAN [] = "clear";
#endif

int main()
{
	char cReponse = ' ';
	char cReponseMenuAlloc = ' ';
	unsigned int uiNbElements;
	unsigned int uiIterateur;
	clock_t clkDebut;
	clock_t clkFin;
	double dDuree;
	CListeEntiers *pUneListeEntiers = new CListeEntiers();
	CVecteurEntiers *pUnVecteurEntiers = new CVecteurEntiers();

	do
	{

		system(EFFACER_ECRAN);

		// Menu Principal
		cout << "Menu principal" << '\n' << '\n'

			 << "[1] Allocation de la memoire" << '\n'
			 << "[2] Affichage des donnees" << '\n'
			 << "[3] Liberation de la memoire" << '\n'
			 << "[4] Quitter" << '\n' << '\n'

			 << "Votre choix : " << flush;

		cReponse = cin.get();
		while(cin.get() != '\n');

		//Traitement du choix utilisateur
		switch(cReponse)
		{
			// Allocation de la memoire
			case '1':
				// Vérifier si la liste et le vecteur son vide
				if(pUneListeEntiers->EstVide())
				{
					do
					{
						system(EFFACER_ECRAN);

				/**********Sous-Menu Allocation de la memoire    ********/
						cout << "Allocation de la memoire" << '\n' << '\n'

							 << "[1] Creer 20000 elements" << '\n'
							 << "[2] Creer 60000 elements" << '\n'
							 << "[3] Creer 100000 elements" << '\n'
							 << "[4] Annuler" << '\n' << '\n'

							 << "Votre choix : " << flush;

						cReponseMenuAlloc = cin.get();
						while(cin.get() != '\n');

						//Traitement du choix d'allocation
						if(cReponseMenuAlloc < '1' || 
							cReponseMenuAlloc > '4')
						{
							cout << '\n' 
								 << "Choix invalide. Appuyez sur <Entree> "
								 << "pour continuer..."
								 << flush;
							while(cin.get() != '\n');
						}
						else if(cReponseMenuAlloc != '4')
						{
							// Calcul du nombre d'éléments a ajouter
							uiNbElements = 
								((40 * (unsigned int)(cReponseMenuAlloc - '0'))
								-20)*1000;
											

							// Remplissage du vecteur
							cout <<'\n'
								 <<"Ajout des "<< uiNbElements 
								 <<" elements au vecteur... \n";

							clkDebut = clock();
							for(uiIterateur = 0 ; uiIterateur < uiNbElements;
								uiIterateur++)
							{
								pUnVecteurEntiers->Ajouter
									(GenererNbAleatoire(0,32767));
							}
							clkFin = clock();

							// Calcul et affichage du temps d'exécution 						
							// de l'opération effectué sur le vecteur
							dDuree =
								(double)(clkFin -clkDebut) / CLOCKS_PER_SEC;

							cout <<"Temps pris pour l'allocation du vecteur : "
								 << dDuree << " \n \n";

							// Remplissage de la liste
							cout <<"Ajout des "<< uiNbElements 
								 <<" elements a la liste... \n";

							clkDebut = clock();
							for(uiIterateur = 0 ; uiIterateur < uiNbElements; 
								uiIterateur++)
							{
								pUneListeEntiers->Ajouter
									(GenererNbAleatoire(0,32767));
							}
							clkFin = clock();

							// Calcul et affichage du temps d'exécution 							 
							// de l'opération effectué sur la liste
							dDuree = 
								(double)(clkFin -clkDebut) / CLOCKS_PER_SEC;

							cout <<"Temps pris pour l'allocation de la liste :" 
								 << dDuree << " \n \n";


							cReponseMenuAlloc = '4';
								cout << "Appuyez sur <Entree> pour retourner " 
									 << "au menu principal..." << flush;

								while(cin.get() != '\n');
						}						

					}
					while(cReponseMenuAlloc != '4');
				/********* FIN	Sous-Menu Allocation de la memoire    ********/
				}
				else
				{
					// Message si la memoire est deja alloué
					system(EFFACER_ECRAN);

					cout << "Allocation de la memoire" << '\n' << '\n'

						 << "Vous devez liberer la memoire avant de faire"
						 << " une nouvelle allocation. \n \n" 
						 << "Appuyez sur <Entree> pour retourner " 
						 << "au menu principal..." << flush;
						
					while(cin.get() != '\n');
				}
				/******** FIN	Menu Allocation de la memoire    *************/
				break;

			// Affichage des donnees
			case '2':
				system(EFFACER_ECRAN);
				
				cout << "Affichage des donnees" << '\n' << '\n';

				if(pUneListeEntiers->EstVide())
				{
					cout << "Le vecteur et la liste dont vides. \n \n";
				}
				else
				{
					// Affichage du vecteur
					cout <<"Appuyez sur <Entree> pour demarrer l'affichage" 
						 <<" des elements du vecteur.."<< flush;
					while(cin.get() != '\n');

					for(uiIterateur = 0 ; uiIterateur < uiNbElements; 
						uiIterateur++)
					{
						cout << (*pUnVecteurEntiers)[uiIterateur] << '\t';
					}

					cout << "\n \n"
						 << "Fin de l'affichage des elements du vecteur"
						 << "\n \n";

					// Affichage de la liste
					cout <<"Appuyez sur <Entree> pour demarrer l'affichage" 
						 <<" des elements de la liste.."<< flush;
					while(cin.get() != '\n');

					for(uiIterateur = 0 ; uiIterateur < uiNbElements; 
						uiIterateur++)
					{
						cout << (*pUneListeEntiers)[uiIterateur] << '\t';
					}

					cout << "\n \n"
						 << "Fin de l'affichage des elements du vecteur"
						 << "\n \n";
				}
				cout << "Appuyez sur <Entree> pour retourner " 
					 << "au menu principal..." << flush;

					while(cin.get() != '\n');

				break;

			// Liberation de la memoire
			case '3':
				system(EFFACER_ECRAN);
				
				cout << "Liberation de la memoire" << '\n' << '\n';
				if(pUneListeEntiers->EstVide())
				{
					cout << "Vous devez allouer la memoire" 
					     <<" avant de la liberer. \n \n";
				}
				else
				{
					// Retrait elements du vecteur
					cout <<"Retrait des "<< uiNbElements 
						 <<" elements du vecteur... \n";

					clkDebut = clock();
					for(uiIterateur = 0 ; uiIterateur < uiNbElements; 
						uiIterateur++)
					{

						pUnVecteurEntiers->Retirer(
							(uiNbElements-1)-uiIterateur);
					}
					clkFin = clock();
					dDuree = (double) (clkFin -clkDebut) / CLOCKS_PER_SEC;

					if(!pUnVecteurEntiers->Retirer(0))
					{
						cout <<"Temps pris pour la liberation du vecteur : " 
							 << dDuree << " \n \n";

						// Retrait elements de la liste
						cout <<"Retraits des "<< uiNbElements 
							 <<" elements de la liste... \n";

						clkDebut = clock();
						pUneListeEntiers->Vider();
						clkFin = clock();
						dDuree = (double) (clkFin -clkDebut) / CLOCKS_PER_SEC;

						cout <<"Temps pris pour la liberation de la liste : " 
							 << dDuree << " \n \n";
					}
				}			

				cout << "Appuyez sur <Entree> pour retourner " 
					 << "au menu principal..." << flush;

					while(cin.get() != '\n');

				break;

			// Quitter le programme
			case'4':
				system(EFFACER_ECRAN);
				
				cout << "Destruction du vecteur et de la liste" << "\n \n";

				// Destruction du vecteur
				cout <<"Liberation du vecteur... \n";

				clkDebut = clock();
	
				pUnVecteurEntiers->~CVecteurEntiers();
				delete pUnVecteurEntiers;
				clkFin = clock();
				dDuree = (double) (clkFin -clkDebut) / CLOCKS_PER_SEC;

	
				cout <<"Temps pris pour la destruction du vecteur : " 
					 << dDuree << " \n \n";

				// Destruction de la liste
				cout <<"Liberation de la liste... \n";

				clkDebut = clock();
				pUneListeEntiers->~CListeEntiers();
				delete pUneListeEntiers;
				clkFin = clock();
				dDuree = (double) (clkFin -clkDebut) / CLOCKS_PER_SEC;

				cout <<"Temps pris pour la destruction de la liste : " 
					 << dDuree << " \n \n";

				break;

			// Si aucune entrée est valide
			default :
				cout << '\n' 
					<< "Choix invalide. Appuyez sur <Entree> pour continuer..."
					<< flush;
				while(cin.get() != '\n');
		}
	}
	while(cReponse != '4');

	cout  << "Appuyez sur <Entree> pour quitter... " << flush;

	while(cin.get() != '\n');

	return 0;
}





