#include "GfxLib.h"
#include "ESLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "BmpLibSupport.h"
#include "conway.h"

#define Hauteur 700
#define Largeur 700

/**
 * \file moteur.h
 * \brief Prototypes de Fonctions motrices.
 * \author Jérémie Anache
 * \version Pandemik.release.2.3
 * \date 13 Juin 2014
 *
 * Prototypes des fonctions du moteur.h
 *
 */

typedef int tableau [Largeur][Hauteur];
typedef int Nombres [100];
int initialisation_alea(tableau,ImageGris);
int initialisationTabVierge(tableau);
int lisPixelOK(ImageGris, int, int);
void initTableauMap(ImageGris,tableau);
int lisPixelTableau(tableau, int, int);
void calculModeleStochastiqueEntier (tableau, tableau,ImageGris,Nombres,float);
void calculModeleStochastique (tableau, int, int, tableau);
void ContaminationAeroport(ImageGris,tableau);
