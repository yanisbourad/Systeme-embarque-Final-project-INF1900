# Systeme-embarque-Final-project-INF1900
Pour voir le parcours du projet: https://cours.polymtl.ca/inf1900/tp/projet/epreuves/
# Materiel
- 1 suiveur de ligne Cytron LSS05
- 1 afficheur LCD Lumex LCM-S01602DTR/M
- 1 capteur de distance GP2Y0A21YK0F (ou GP2D12)

# 1/ app  
Ce dossier contient le programme du robot, avec tout les etats de la trajectoire.
Pour pouvoir compiler le programme, vous devez bien évidemment "make clean/make" la librairie (lib).
Par la suite, vous devez entrer à nouveau les deux commandes dans l'app.
# 1.1/ FunctionRobot
Cette classe contient plusieurs méthodes pour définir le comportement du robot afin qu'il puisse réaliser le parcours.
Cette classe permet de rendre le code plus lisible et évite la répétition de code.
# 1.2/ Robot
Ce fichier contient tous les cas possibles pour réaliser le circuit. Il fait appel aux méthodes de "functionRobot" afin que le code soit plus simple à comprendre
# 2/ lib 
notre librairie qui contient tout les classes qu'on a definie.
Dans le dossier lib, on a principalement 14 classes:
# 2.1/ Timer0
permet d'initialiser un timer0 ainsi que ces parametres afin de l'utiliser pour emettre du son.
# 2.2/ Timer1
initialise timer1 qu'on utilise dans l'application principale, pour servir comme compteur.
# 2.3/ Timer2 
initialise un timer2, qu'on va utiliser pour générer les signaux PWM pour alimenter nos roues.
# 2.4/ PushButton 
sert a régler les registres pour permettre les interruptions externe, pour les 2 boutons qu'on a sur le robot
(le bouton interrupt et le bouton blanc).
# 2.5/ Note
c'est la classe qui utilise le timer0, afin d'émettre du son.
# 2.6/ Navigation 
contient les méthodes que nous utilisons pour ajuster les signaux pwm qui controlent
les roues, en utilisant des coefficients dépendant de la trajectoire, soit pour faire avancer le robot, soit pour 
s'ajuster à l'intérieur d'une trajectoire rectiligne, soit pour se tourner pendant les maneuvres.
# 2.7/ Motor 
contient une methode, qui sert a generer un signal PWM pour chacun des 2 roues.
# 2.8/ LSS05
contient la methode moveRobot, qui fait avancer le robot en ligne droite, selon le capteur 
suiveur de ligne, ainsi que les methodes qui le fait tourner gauche ou droite a 90 degrés.
# 2.9/ Can
c'est la classe qui sert a initialiser le convertisseur analogique numerique.
# 2.10/ GP2D12
représente la classe que nous utilisons pour lire les valeurs émises par le capteur de distance.
# 2.11/ Del 
allume la del sur la carte mere en 2 couleurs, rouge ou vert.
# 2.12/ Conversion
sert a convertir des unités, et nous fournit une methode pour donner la position du robot,
selon la valeur captée, du capteur distance.
# 2.13/ Lcm
permettre l'affichage sur le LCD.
