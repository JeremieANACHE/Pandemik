#include "GfxLib.h"
#include "ESLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "conway.h"
#include "affichage.h"
#include <string.h>
/**
 * \file conway.c
 * \brief Programme Principal.
 * \author Jérémie Anache
 * \version Pandemik.release.2.3
 * \date 13 Juin 2014
 *
 * Pandemik est un programme de simulation d'épidemie.
 * Codé à l'occasion du projet d'algorithmique de Semestre 2.
 * A l'ISEN de Toulon, en CIR, Première Année.
 *
 */

int main(int argc, char **argv)
{

	initialiseGfx(argc, argv); 

	prepareFenetreGraphique("Jeu de la vie ", LargeurFenetre, HauteurFenetre);

	lanceBoucleEvenements();

	ecrisChaine("Fin du main "); 
	return 0;
}


void gestionEvenement(EvenementGfx evenement)
{
	
	char nomImage[] = "carte-du-monde.bmp";
	static 	ImageGris image;
	static tableau T1,T2,T3;
	static Nombres NB;
	static int x,y,C,T,i,j; 
	static float Probaero;
	static bool P,I,Ville,temps;
	static bool resu ;
	
	// En fonction de l'evenement envoye par le systeme...
	switch(evenement)
	{
			
			// Le message "Initialisation" est envoye une seule fois, au debut du programme
			// Il faut y placer tout ce qui permet d'initialiser le programme
		case Initialisation:
		effaceEcran();	
			resu = lisFichier_DansImageNG(nomImage, image);
			if ( resu == true ) printf(" lisFichier %s  OK", nomImage );
								else printf(" lisFichier %s  pas OK", nomImage );
						
			resu = ecrisImageNG_DansFichier(image, "copie.bmp");
			if ( resu == true ) printf(" ecrisImageNG_DansFichier  %s  OK", nomImage );
								else printf(" lisFichier %s  pas OK", nomImage );			
			initialisationTabVierge(T3);
			P=false;
			temps=false;
			Ville=true;
			I=true;
			printf("\n --> I <-- Afficher/Cacher l'aide \n");
			initTableauMap(image,T3);
			ecrisPixel(T3,x,y);
			C=1;
			j=0;
			
			
			if(strcmp(nomImage, "carte-du-monde.bmp") == 0)
				{
					Probaero=0.5;
				}
			else
				{
					Probaero=0.1;
				}
			
		
			
			break;
		
			// Le systeme demande au programme de dessiner la fenetre
			//
		case Affichage:
		
			if (!P)
			{	
				
			
			
			ecrisPixel(T3,x,y);
			contourMapOff(image,T1,NB,Ville);
			ecrisCouleurTableauMap(T3,NB);	
			
				
			
				
				if (C==1)
				{
					contourMapOff(image,T1,NB,Ville);
					ecrisPixel(T3,x,y);
					
				}
				if (C==2)
				{
				calculModeleStochastiqueEntier(T3,T2,image,NB,Probaero);
				ecrisCouleurTableauMap(T3,NB);	
				contourMapOff(image,T1,NB,Ville);
				
				}
				
					
				if (I)	
				{
				
					DessinBoutons(P);
				}
				if (temps)
				{
				 DessinTemps();
				}
					
				ecrisNombrePixel(NB,temps);
				rafraichisFenetre();
				
			}
			break;
			case Clavier: // Une touche du clavier a ete pressee
			switch (caractereClavier())
			{
				case 'Q': // Pour sortir quelque peu proprement du programme
				case 'q':
					exit(0);
					break;
				case 's':
				case 'S': 
				
								
					break ;	
				case 'r':
				case 'R': 
				
				printf("\n Lancement de la Propagation \n");
				
					C=2;
					
					break;
				case 'T':
				case 't': 
				
					temps=!temps;
					
					if ((j=1)&&(!temps))
					{
						NB[3]=0;
					for (i=0;i<T;i++)
					{
						calculModeleStochastiqueEntier(T3,T2,image,NB,Probaero);
					}	
							
						ecrisPixel(T3,x,y);
						j=0;
						C=1;
						T=0;
					}
					
					break;
					
				case 'i':
				case 'I': 
					I=!I;
				
					
					break;
					
				case 'c':
				case 'C': 
				printf(" \n Remise a zéro \n");
				NB[2]=0;
				initialisationTabVierge(T2);
				initTableauMap(image,T3);
				ecrisCouleurTableauMap(T3,NB);	
				ecrisPixel(T3,x,y);
				
				
				C=1;
									
					break ;	
				case 'p':
				case 'P': 
				P=!P;
				
				if(P)
				{
					printf("\n Programme en pause\n");	
					DessinBoutons(P);
				}
				if(!P)
				{
					printf("\n Programme en Marche\n");
					rafraichisFenetre();
				}	
				break;
				case 'n':
				case 'N': 
					printf("\n Génération aléatoire \n");
					initialisation_alea(T3,image);
					
					ecrisPixel(T3,x,y);
					
					
					C=1;
					
					
				break;
				
				case 'V':
				case 'v': 
				printf(" \n cacher/afficher Villes \n");
				Ville=!Ville;
					
					break ;	
			}
		case BoutonSouris: // Un bouton de la souris a ete appuye
			if ((etatBoutonSouris() == GaucheAppuye)&& (!P))
			{
				if (temps)
				{
					
				ecrisChaine("\n Tableau défini en : \n");
				ecrisEntier(abscisseSouris());	
					
                T=abscisseSouris() ;
                NB[3]=T;
                j=1;
                
                
				}
				
				else
				{
				ecrisChaine("\npixel généré sur tableau personnel en : \n");
               	ecrisEntier(abscisseSouris());		
                x=abscisseSouris() ;    
        		ecrisChaine(", "); 
        		ecrisEntier(ordonneeSouris());                     
		        y=ordonneeSouris();
		        
				
  				choixPixel(T3,image,x,y);
  				ecrisPixel(T3,x,y);							
				}				
			}
			
			else if (etatBoutonSouris() == DroiteAppuye)
			{
							
			}
			break;

		// Les messages suivants ne sont pas traites ici, mais existent
		case Inactivite:
        	case ClavierSpecial:
		case Souris:
		case Redimensionnement:
	 		 break;
	}
}
