#include "GfxLib.h"
#include "ESLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "moteur.h"
#include "affichage.h"
#define p 0.5
/**
 * \file moteur.c
 * \brief Multiples Fonctions motrices.
 * \author Jérémie Anache
 * \version Pandemik.release.2.3
 * \date 13 Juin 2014
 *
 * Multiples fonctions de fonctionnement du programme et de manipulation de données.
 *
 */

/**
 * \brief Fonction d'initialisation des celules infectées aleatoirement.
 *
 * \param T1, tableau des données initiales.
 * \param image, Image en niveaux de Gris.
 * \return 0 si OK.
 */
int initialisation_alea(tableau T1,ImageGris image)
{
	int i,j,etat;
	float k;
	
	for(i=0;i<=(Largeur-1);i++) 
	{
		for(j=0;j<=(Hauteur-1);j++)
		{
		etat=EtatPixel(image,i,j);
		
	if (etat==1)
	{
			if (T1[i][j]==0)
			{
			k=valeurIntervalleZeroUn();
			
			if(k>0.999) 
			{
				T1[i][j]=1; //cellule infectée
			}
			else  
			{
				T1[i][j]=0; // cellule saine
			} 
			k=0;
			}
	}	}
}
	return 0;
}

/**
 * \brief Fonction d'initialisation à zero d'un tableau de données.
 *
 * \param T3, rableau de données.
 * \return 0 si OK.
 */
int initialisationTabVierge(tableau T3)
{
	int i,j;

	for(i=0;i<=(Hauteur-1);i++) 
	{
		for(j=0;j<=(Largeur-1);j++)
		{
		
			T3[i][j]=0; //morte
		
		}
	}
	return 0;
}


/**
 * \brief Fonction de lecture du type de Terrain de la carte.
 *
 * \param image, Image en niveau de Gris.
 * \param T, tableau de données.
 */
void initTableauMap(ImageGris image,tableau T)
{
	int i,j;
	
	for (i=0;i<HauteurImageBMPLib;i++)
	{
		for (j=0;j<LargeurImageBMPLib;j++)
		{
			T[i][j]=lisPixelOK(image ,i ,j);
		}
	}
}

/**
 * \brief Fonction de lecture de la couleur d'un pixel dans une image en niveaux de Gris.
 *
 * \param image, Image en niveau de gris de la carte.
 * \param x, coordonné x.
 * \param y, coordonné y.
 * \return 0 si ok. -1 si code erreur.
 */
int lisPixelOK(ImageGris image, int x, int y)
{
        int valeurRetour ;
        // Si les coordonnees sont valides 
	if ( ( x >= 0) && (x < HauteurImageBMPLib) && (y >= 0) && (y < LargeurImageBMPLib) )
        {
	 // Lire la valeur du pixel concerne */
        valeurRetour = image[y][x];
        return (valeurRetour);
        }
		else 
	return(-1);
	
}

/**
 * \brief Fonction de lecture de la couleur d'un pixel dans un tableau.
 *
 * \param image, Image en niveau de gris de la carte.
 * \param x, coordonné x.
 * \param y, coordonné y.
 * \return 0 si ok. -1 si code erreur.
 */
int lisPixelTableau(tableau image, int x, int y)
{
        int valeurRetour ;
        // Si les coordonnees sont valides 
	if ( ( x >= 0) && (x < HauteurImageBMPLib) && (y >= 0) && (y < LargeurImageBMPLib) )
        {
	 // Lire la valeur du pixel concerne */
        valeurRetour = image[y][x];
        return (valeurRetour);
        }
		else 
	return(-1);
	
}

/**
 * \brief Fonction de calcul des infections et des morts au cours du temps pour un pixel.
 *
 * \param T1, tablau de données.
 * \param i, coordonné i.
 * \param j, coordonné j.
 * \param T2, tableau de données au temps t+1.
 */
void calculModeleStochastique (tableau T1, int i, int j, tableau T2){
	int ni, ns, bi, bs, mi, ms, Z;
	float probaContamine=0.0;
	ni=0;
	ns=0;
	bi=23;
	bs=4;
	mi=12;
	ms=3;
	
	// comptage de voisins infectés  et susceptibles d'être infectés autour d'une case vide

	if (T1[i][j] == 0){
		if (i>0)
		{
			if (T1[i-1][j] == 1)
				ns = (ns+1);
			else if (T1[i-1][j] == 2)
				ni = (ni+1);
		} //haut
		
		if (j<Largeur){
			if (T1[i][j+1] == 1) ns = (ns+1);
			else if (T1[i][j+1] == 2) ni = (ni+1);
		} //droite

		if (i<Hauteur) {
			if (T1[i+1][j] == 1) ns = (ns+1);
			else if (T1[i+1][j] == 2) ni = (ni+1);
		} //bas

		if (j>0){
			if (T1[i][j-1] == 1) ns = (ns+1);
			else if (T1[i][j-1] == 2) ni = (ni+1); 
		}//gauche
	}


/* calcul des probas de naissance et placement la naissance se fait sur une 
 * case voisine directe si elle est deja prise, on tourne dans le sens horaire */


	 if (T1[i][j] == 1)
	{
		if (((valeurIntervalleZeroUn()*100)<=bs) || ((valeurIntervalleZeroUn()*100)<=bi))
		{
			if ((T1[i-1][j] == 0)&&(i>0)) T2[i-1][j]=1;	//si le haut est vide, on place le foyer vivant

			else if ((T1[i][j+1] == 0)&&(j<Largeur)) T2[i][j+1]=1; //sinon on le met a droite s'il est vide

			else if ((T1[i+1][j] == 0)&&(i<Hauteur)) T2[i+1][j]=1; //sinon en bas s'il est vide

			else if ((T1[i][j-1] == 0)&&(j>0)) T2[i][j-1]=1; //sinon a gauche s'il est vide
		
		//si tous sont occupés, on ne fait rien
		}

/* on calcule ensuite les probas de contamination */
	if (T1[i][j]==1){
		
		
		
		Z = pow((1-p),ni);
		probaContamine=(((1-ms)*(1-Z))*100);
		
	}
	if ((valeurIntervalleZeroUn()*100)<=probaContamine) T2[i][j]=10;


/* on calcule ensuite les morts de foyers */
	if ((T1[i][j] == 1)  &&  ((valeurIntervalleZeroUn()*100)<=ms))  T2[i][j]=10;
//s'il est infecté , on tire un numéro au hasard et si proba OK, il meurt sinon on ne fait rien
	else if ((T1[i][j] == 2)  &&  ((valeurIntervalleZeroUn()*100)<=mi))  T2[i][j]=10;
//s'il est infecté , on tire un numéro au hasard et si proba OK, il meurt sinon on ne fait rien
	}
	
	

	
}


/**
 * \brief Fonction de calcul des infections et des morts au cours du temps pour un tableau.
 *
 * \param T1, tablau de données.
 * \param T2, tableau de données au temps t+1.
 * \param image, Image en niveau de Gris.
 * \param NB, talbeau d'entiers.
 * \param Probaaero, probabilité d'infections des aeroports de la carte. (non implémenté dans cette version)
 */
void calculModeleStochastiqueEntier (tableau T1, tableau T2,ImageGris image,Nombres NB,float Probaero){
	
	int i, j, V,NBtemps;
//	float ProbaVille; //non implémenté dans cette version.
	NBtemps=NB[2];
	for (i=0 ; i<Hauteur ; i++)
	{
		for(j=0 ; j<Largeur ; j++)
		{
			V=EtatPixel(image,i,j);
			if ((V==1)||(V==2))
			{

//code non fonctionnel des aeroports
				
		/*		V=EtatPixel(image,i,j);
			if ((T1[i][j]==1)&&(V==2))		//permet de répendre le virus parmis les aeroports
			{
				ProbaVille=valeurIntervalleZeroUn();	
				if (ProbaVille<=Probaero)
					T2[i][j]=1;
			}	
			*/		
			calculModeleStochastique (T1, i, j, T2);		
			}	
		}
	}	
			
	for(i=0;i<Hauteur;i++) 
	{
		for(j=0;j<Largeur;j++)
		{
					T1[i][j]=T2[i][j];	// rajout fonction etatpixel
		}
	}		
		
	NB[2]=NBtemps+1;
	
}



