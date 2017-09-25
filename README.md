# Pandemik
School project, simulates the spread of a deadly disease without cure. Uses airports / naval ports for more realism

## To make sure it works
* make sure you have the necessary libraries installed :
  * `sudo apt-get install freeglut3-dev`
  * `sudo apt-get install libx11-dev:i386`
  * `sudo apt-get install ibx11-dev`

### Once you installed all of this you can just type `make` in terminal once in the project root folder
#### if something goes wrong, you can always try `make clean`, then go back to previous step.

### To run the simulator, type `./conway`

## To change the map for the second one provided :

* open the `conway.c` file, you're looking for the `void gestionEvenement(EvenementGfx evenement)` function (line 37)
* change the bmp file for **CartedeFrance.bmp** for example or any map you created (see next section).

## To change the map for one you made :
* open the `conway.c` file, you're looking for the `void gestionEvenement(EvenementGfx evenement)` function (line 37)
* change the bmp file name for the one you want to try
> #### the file has to be a BMP file
* make sure your map uses the right colors :
  * land is in black (**#000000**)
  * water is in blue (**#35D6FF**)
  * airports / naval ports are in yellow (**#FFD821**)
