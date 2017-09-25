#include "GfxLib.h"
#include "ESLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "moteur.h"
#include "conway.h"
/**
 * \file affichage.h
 * \brief Prototypes de Fonctions graphiques.
 * \author Jérémie Anache
 * \version Pandemik.release.2.3
 * \date 13 Juin 2014
 *
 * Prototypes des fonctions du affichage.h
 *
 */

void ecrisPixel(tableau,int,int);
void choixPixel(tableau, ImageGris ,int ,int );
void DessinBoutons(bool);
void ecrisCouleurTableauMap(tableau,Nombres);
int EtatPixel(ImageGris,int ,int);
void ecrisTableauPixel(tableau);
void contourMapOff(ImageGris,tableau,Nombres,bool);
void ecrisNombrePixel(Nombres,bool temps);
void DessinTemps(void);
