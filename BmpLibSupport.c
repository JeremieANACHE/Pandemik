/*
 *  BMPLibSupport.c
 *  isentlib
 *
 *  Created by gou on 17/02/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdlib.h>
#include "BmpLibSupport.h"
#include "BmpLib.h"
#include "GfxLib.h"

/* La fonction suivante essaie d'interpreter le fichier donne en parametre
	et en cas de succes ecrit le contenu de l'image en niveaux de gris
	dans l'image passee elle aussi en parametre et renvoie vrai. Renvoie faux sinon */
bool lisFichier_DansImageNG(char *nomFichier, int imageDestination[HauteurImageBMPLib][LargeurImageBMPLib])
{
	DonneesImageRGB *image;
	bool valeurRetour = false;;
	
	if
		((image = lisBMPRGB(nomFichier)) != NULL)
	{
		/* image != NULL */
		
		if
			((image->largeurImage == LargeurImageBMPLib) && (image->hauteurImage == HauteurImageBMPLib))
		{
			int x;
			int y;
			unsigned char *pRGB = image->donneesRGB;
			for
				(y = 0; y < HauteurImageBMPLib; ++y)
			{
				for
					(x = 0; x < LargeurImageBMPLib; ++x)
				{
					/* Chaque point est converti de couleur en niveau de gris */
					imageDestination[y][x] = (int)(.11f*pRGB[0]+.69f*pRGB[1]+.20f*pRGB[2]);
					pRGB += 3;
				}
			}
			valeurRetour = true;
		}
		
		libereDonneesImageRGB(&image);
	}

	return valeurRetour;
}

/* La fonction suivante ecrit le contenu de l'image en niveaux de gris
	passee en parametre dans le fichier donne en parametre lui aussi. Elle renvoie
	vrai en cas de succes, faux sinon */
bool ecrisImageNG_DansFichier(int imageSource[HauteurImageBMPLib][LargeurImageBMPLib], char *nomFichier)
{
	DonneesImageRGB image;
	bool valeurRetour = false;
	
	if
		((image.donneesRGB = (unsigned char *)malloc(LargeurImageBMPLib*HauteurImageBMPLib*3)) != NULL)
	{
		/* image->donneesRGB != NULL */
		
		int x;
		int y;
		unsigned char *pRGB = image.donneesRGB;
		
		/* On copie chaque pixel de l'image dans les cases RVB du bitmap */
		for
			(y = 0; y < HauteurImageBMPLib; ++y)
		{
			for
				(x = 0; x < LargeurImageBMPLib; ++x)
			{
				pRGB[0] = pRGB[1] = pRGB[2] = (unsigned char)imageSource[y][x];
				pRGB += 3;
			}
		}

		image.largeurImage = LargeurImageBMPLib;
		image.hauteurImage = HauteurImageBMPLib;
		
		/* Si l'ecriture se passe bien, on en prend note */
		if
			(ecrisBMPRGB_Dans(&image, nomFichier))
		{
			valeurRetour = true;
		}
		
		/* Liberation obligatoire du buffer de donnees RGB */
		free(image.donneesRGB);
	}

	return valeurRetour;
}


/* afficheImageNG : affiche une image en niveaux de gris dans le coin inferieur gauche */
void afficheImageNG(int imageSource[HauteurImageBMPLib][LargeurImageBMPLib])
{
	int x;
	int y;
	unsigned char *donneesBitmap;
	
	if
		((donneesBitmap = (unsigned char *)malloc(3*HauteurImageBMPLib*LargeurImageBMPLib)) != NULL)
	{
		for
			(y = 0; y < HauteurImageBMPLib; ++y) // Pour chaque ligne de l'image
		{
			for
				(x = 0; x < LargeurImageBMPLib; ++x) // Pour chaque colonne de l'image
			{
				donneesBitmap[y*LargeurImageBMPLib*3+3*x] = imageSource[y][x];
				donneesBitmap[y*LargeurImageBMPLib*3+3*x+1] = imageSource[y][x];
				donneesBitmap[y*LargeurImageBMPLib*3+3*x+2] = imageSource[y][x];
			}
		}
		
		ecrisImage(0, 0, LargeurImageBMPLib, HauteurImageBMPLib, donneesBitmap);
		
		free(donneesBitmap);
	}
}
