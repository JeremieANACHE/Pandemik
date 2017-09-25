#include "GfxLib.h"
#include "ESLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "BmpLibSupport.h"

#define HauteurFenetre 700
#define LargeurFenetre 700

/**
 * \file conway.h
 * \brief 
 * \author Jérémie Anache
 * \version Pandemik.release.2.3
 * \date 13 Juin 2014
 *
 */

typedef int ImageGris[HauteurImageBMPLib][LargeurImageBMPLib];
void gestionEvenement(EvenementGfx);

