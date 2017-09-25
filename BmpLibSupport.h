/*
 *  BMPLibSupport.h
 *  isentlib
 *
 *  Created by gou on 17/02/06.
 *
 */

/* Partie publique basique
   Cette partie est relative a toutes les informations utiles pour
   lire et ecrire un fichier BMP de taille predefinie */

#include <stdbool.h>

 //Largeur et hauteur par defaut d'une image correspondant a nos criteres modif PONZO
#define LargeurImageBMPLib 700
#define HauteurImageBMPLib 700
/*
#define LargeurImageBMPLib 600
#define HauteurImageBMPLib 600
*/
/* La fonction suivante essaie d'interpreter le fichier donne en parametre
	et en cas de succes ecrit le contenu de l'image en niveaux de gris
	dans l'image passee elle aussi en parametre et renvoie vrai. Renvoie faux sinon */
bool lisFichier_DansImageNG(char *nomFichier, int imageDestination[HauteurImageBMPLib][LargeurImageBMPLib]);

/* La fonction suivante ecrit le contenu de l'image en niveaux de gris
	passee en parametre dans le fichier donne en parametre lui aussi. Elle renvoie
	vrai en cas de succes, faux sinon */
bool ecrisImageNG_DansFichier(int imageSource[HauteurImageBMPLib][LargeurImageBMPLib], char *nomFichier);

/* afficheImageNG : affiche une image en niveaux de gris dans le coin inferieur gauche */
void afficheImageNG(int imageSource[HauteurImageBMPLib][LargeurImageBMPLib]);
