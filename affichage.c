#include "GfxLib.h"
#include "ESLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "affichage.h"
/**
 * \file affichage.c
 * \brief Multiples Fonctions graphiques.
 * \author Anache Jérémie
 * \version Pandemik.release.2.3
 * \date 13 Juin 2014
 *
 * Multiples fonctions de dessin ou de colorisation d'une carte et de la simulation sur fenetre graphique.
 *
 */




/**
 * \brief Fonction de Dessin d'un pixel 1x1.
 *
 * \param T, Tableau contenant les données de la simulation.
 * \param x, coordonné x.
 * \param y, coordonné y.
 */
void ecrisPixel(tableau T,int x, int y)
{
			rectangle(x,y,x+1,y+1);
			
}

/**
 * \brief Fonction de lecture du type de Terrain de la carte.
 *
 * \param image, Image en niveau de gris de la carte.
 * \param x, coordonné x.
 * \param y, coordonné y.
 * \return une valeur codée du type de terrain (-1 si eau, 0 si terre, 2 si Ville)
 */
int EtatPixel(ImageGris image, int x,int y)
{
	
	int Valeur;
	Valeur=lisPixelTableau(image,x,y);
	
	if (Valeur==186) //si gris
		return(-1); //eau
	if (Valeur==0) //si noir
		return(1); //terre
	else
		return(2); //sinon ville
	
}

/**
 * \brief Fonction graphique de changement de couleur au cours de l'initialisation au clic.
 *
 * \param T, Tableau de donnnées de la simulation.
 * \param image, Image en niveau de gris de la carte.
 * \param x, coordonné x.
 * \param y, coordonné y.
 */
void choixPixel(tableau T,ImageGris image ,int x,int y)
{
	int etat;
	
	etat=EtatPixel(image,x,y);
	lisPixelTableau(T,x,y)	;
	
	if (etat==1) //si terre
	{
		if (T[x][y]==0) //si sain
			T[x][y]=1; //devient infecté
		else
			T[x][y]=0;	//sinon reste sain
	}
		
		if(etat==2) //si ville
		{
			if (T[x][y]==203) //si sain	
				T[x][y]=1; //devient infecté
			else
				T[x][y]=203; //reste sain
		}
}

/**
 * \brief Fonction graphique de dessin du menu d'aide.
 *
 * \param P, booleen qui nous informe si le programme est en pause ou non.
 */
void DessinBoutons(bool P)
{
	epaisseurDeTrait(2);
	const int xTexte = 10;
	couleurCourante(100,100,100);
	rectangle(0,Hauteur,Largeur,(Hauteur-125));
	couleurCourante(255,255,255);
	rectangle(2,Hauteur-2,Largeur-2,((Hauteur-125)+2));
	couleurCourante(0,0,0);
	afficheChaine("Clic gauche pour initialiser les cellules", 14, xTexte, (Hauteur-15));
	afficheChaine("Tapez ' N ' pour une simulation aléatoire", 14, xTexte, (Hauteur-35));
	afficheChaine("Tapez ' P ' pour Pause/Play", 14, xTexte, (Hauteur-55));
	afficheChaine("Tapez ' R ' pour simuler votre Virus", 14, xTexte, (Hauteur-75));
	afficheChaine("Tapez ' I ' pour Afficher/Cacher l'aide", 14, xTexte, (Hauteur-95));
	afficheChaine("Tapez ' V ' pour afficher/cacher les villes", 14, 350, (Hauteur-95));
	afficheChaine("Tapez ' C ' pour Remise a zero", 14, xTexte, (Hauteur-115));
	afficheChaine("Tapez ' T ' pour sumuler au temps choisi", 14, 350, (Hauteur-115));
	epaisseurDeTrait(3);
	couleurCourante(204,0,0);
	afficheChaine("Pandemik", 35, (xTexte+400), (Hauteur-45));
	//afficheChaine("   faire si l'aide est visible !", 23, (xTexte+340), (Hauteur-78));
	
	if (P) //si programme passe en pause
	{	
		couleurCourante(255,0,0);
		epaisseurDeTrait(3);
		afficheChaine("PAUSE", 35, ((LargeurFenetre/2)-50), (HauteurFenetre/2));
		couleurCourante(255,255,255);
	}
	
	
}

/**
 * \brief Fonction graphique de dessin du menu d'avance rapide de la simulation.
 * 
 */
void DessinTemps()
{

		couleurCourante(255,255,255);
		rectangle(0,((Hauteur/2)+100),Largeur,((Hauteur/2)-200));
		couleurCourante(255,255,255);
		couleurCourante(0,0,0);
		epaisseurDeTrait(3);
		afficheChaine("cliquez sur la valeur T souhaitee", 35, ((LargeurFenetre/2)-300), (HauteurFenetre/2));
		epaisseurDeTrait(2);
		afficheChaine("rappuyer sur ' T ' pour lancer la simulation au temps choisis ", 15, ((LargeurFenetre/2)-250), (HauteurFenetre/2)-35);
		afficheChaine("0", 15, 5, (HauteurFenetre/3)+5);
		afficheChaine("50", 15, 55, (HauteurFenetre/3)+5);
		afficheChaine("100", 15, 105, (HauteurFenetre/3)+5);
		afficheChaine("150", 15, 155, (HauteurFenetre/3)+5);
		afficheChaine("200", 15, 205, (HauteurFenetre/3)+5);
		afficheChaine("250", 15, 255, (HauteurFenetre/3)+5);
		afficheChaine("300", 15, 305, (HauteurFenetre/3)+5);
		afficheChaine("350", 15, 355, (HauteurFenetre/3)+5);
		afficheChaine("400", 15, 405, (HauteurFenetre/3)+5);
		afficheChaine("450", 15, 455, (HauteurFenetre/3)+5);
		afficheChaine("500", 15, 505, (HauteurFenetre/3)+5);
		afficheChaine("550", 15, 555, (HauteurFenetre/3)+5);
		afficheChaine("600", 15, 605, (HauteurFenetre/3)+5);
		afficheChaine("650", 15, 655, (HauteurFenetre/3)+5);
		
		couleurCourante(200,50,200);
		ligne(0, HauteurFenetre/3,LargeurFenetre,  HauteurFenetre/3);
		epaisseurDeTrait(3);
		ligne(0, (HauteurFenetre/3)+10,0,  (HauteurFenetre/3)-10);
		ligne(50, (HauteurFenetre/3)+10,50,  (HauteurFenetre/3)-10);
		ligne(100, (HauteurFenetre/3)+10,100,  (HauteurFenetre/3)-10);
		ligne(150, (HauteurFenetre/3)+10,150,  (HauteurFenetre/3)-10);
		ligne(200, (HauteurFenetre/3)+10,200,  (HauteurFenetre/3)-10);
		ligne(250, (HauteurFenetre/3)+10,250,  (HauteurFenetre/3)-10);
		ligne(300, (HauteurFenetre/3)+10,300,  (HauteurFenetre/3)-10);
		ligne(350, (HauteurFenetre/3)+10,350,  (HauteurFenetre/3)-10);
		ligne(400, (HauteurFenetre/3)+10,400,  (HauteurFenetre/3)-10);
		ligne(450, (HauteurFenetre/3)+10,450,  (HauteurFenetre/3)-10);
		ligne(500, (HauteurFenetre/3)+10,500,  (HauteurFenetre/3)-10);
		ligne(550, (HauteurFenetre/3)+10,550,  (HauteurFenetre/3)-10);
		ligne(600, (HauteurFenetre/3)+10,600,  (HauteurFenetre/3)-10);
		ligne(650, (HauteurFenetre/3)+10,650,  (HauteurFenetre/3)-10);
		
			
}

/**
 * \brief Fonction graphique d'ecriture du nombre de cellule infectée(s) et morte(s).
 *
 * \param NB, Tableau d'entiers.
 * \param temps, bolleen d'affichage du temps choisi par l'utilisateur dans le menu.
 */
void ecrisNombrePixel(Nombres NB,bool temps)
{
	int NBmort, NBvirus,NBtemps,Tchoisis;
	
	NBmort=NB[1]; //nombre de morts
	NBvirus=NB[0]; //nombre d'infectés
	NBtemps=NB[2]; // temps au cours de la simulation
	Tchoisis=NB[3]; //temps selection par l'utilisateur
	char tada[200]; //tableau de multiples chaine de caractères pour l'affichage.
	sprintf(tada,"Infectes : %d", NBvirus);
	couleurCourante(255,255,255);
	afficheChaine(tada, 20, 5,5);
	
	sprintf(tada,"Mortes : %d", NBmort);
		couleurCourante(255,255,255);
	afficheChaine(tada, 20, 5,30);
	
	sprintf(tada,"Temps(jours) : %d", NBtemps);
		couleurCourante(255,255,255);
	afficheChaine(tada, 20, 5,55);
	
	if (temps) //si l'utilisateur a selectionné un temps dans l'avance rapide.
	{
	sprintf(tada,"Temps choisis : %d", Tchoisis);
	couleurCourante(0,0,0);
	afficheChaine(tada, 20, Largeur/2-100,Hauteur/3-50);
	}
}

/**
 * \brief Fonction graphique d'affichage des couleurs au cours de la simulation automatique.
 *
 * \param T, Tableau de donnnées de la simulation.
 * \param NB, Tableau d'entiers.
 */
void ecrisCouleurTableauMap(tableau T,Nombres NB)
{
	int i,j,NBvirus,NBmort,NBsaines;

	NBvirus=0;
	NBmort=0;
	NBsaines=0;
	for (i=0 ; i<LargeurImageBMPLib ; i++)
	{
		for (j=0 ; j<HauteurImageBMPLib ; j++)
		{
		
				if (T[i][j]==203) //si Ville en niveau de gris
					{
						couleurCourante(255,255,0); 
						ecrisPixel(T,i,j); //dessine en jaune
					}
				if (T[i][j]==0) // si terre en niveau de gris
					{
						NBsaines=NBsaines+1; 
						couleurCourante(153,204,102);
						ecrisPixel(T,i,j); //dessine en vert
					}
				if(T[i][j]==186) //si eau
					{
						couleurCourante(0,0,255);
						ecrisPixel(T,i,j); //dessine en bleu
					}
				if (T[i][j]==1) //si pixel infecté
					{
						NBvirus=NBvirus+1;
						
						couleurCourante(255,0,0);
						ecrisPixel(T,i,j); //dessine en rouge
						
					}
					if (T[i][j]==10) //si pixel mort
					{
						NBmort=NBmort+1;
						
						couleurCourante(0,0,0);
						ecrisPixel(T,i,j); //dessine en noir
					}
			
		}
	}
	NB[5]=NBsaines;  //sauvegarde dans NB.
	NB[0]=NBvirus;  //sauvegarde dans NB.
	NB[1]=NBmort;  //sauvegarde dans NB.
	

}

/**
 * \brief Fonction graphique de dessin d'un tableau entier (utile à l'initialisation).
 *
 * \param T, Tableau de donnnées de la simulation.
 */
void ecrisTableauPixel(tableau T)
{
	int i,j;
	
	for (i=0 ; i<LargeurImageBMPLib ; i++)
	{
		for (j=0 ; j<HauteurImageBMPLib ; j++)
		{
			ecrisPixel(T,i,j);
			
		}
	}
}

/**
 * \brief Fonction graphique de dessin d'un calque ou contour autour de la carte.
 *
 * \param image, Image en niveau de gris de la carte.
 * \param T, Tableau de donnnées de la simulation.
 * \param NB, Tableau d'entiers.
 * \param V, boleen d'etat Ville ou eau.
 */ 
void contourMapOff(ImageGris image,tableau T,Nombres NB,bool Ville)
{
	int i,j,V,NBeau;
	NBeau=0;
	
	for (i=0 ; i<LargeurImageBMPLib ; i++)
	{
		for (j=0 ; j<HauteurImageBMPLib ; j++)
			{
				V=EtatPixel(image,i,j);
				if(V==-1) //si eau
				{
				NBeau=NBeau+1;	
				couleurCourante(0,0,255);
				ecrisPixel(T,i,j); //dessine en bleu
				}
				if ((Ville)&&(V==2)) //si ville 
									//permet de laisser les points jaunes de ville au dessus de la simulation
				{
				couleurCourante(255,255,0);
				ecrisPixel(T,i,j); //dessine en jaune
				}
				
	
			}
	}
	NB[4]=NBeau; //sauvegarde dans NB.
}	

