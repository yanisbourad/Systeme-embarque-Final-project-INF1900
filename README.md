# Systeme-embarque-Final-project-INF1900
notre projet contient 2 repertoire:
# 1/ app : qui contient le programme du  robot, avec tout les etats de la trajectoire.
# 2/ lib : notre librairie qui contient tout les classes qu'on a definie.

Dans le dossier lib, on a principalement 15 classes:
# Timer0
permet d'initialiser un timer0 ainsi que ces parametres afin de l'utiliser pour emettre du son.
# Timer1
initialise timer1 qu'on utilise dans l'application principale, pour servir comme compteur.
# Timer2 
initialise un timer2, qu'on va utiliser pour générer les signaux PWM pour alimenter nos roues.
# PushButton 
sert a régler les registres pour permettre les interruptions externe, pour les 2 boutons qu'on a sur le robot
(le bouton interrupt et le bouton blanc).
# Note
c'est la classe qui utilise le timer0, afin d'implementer le son.
# Navigation 
contient les méthodes que nous utilisons pour ajuster les signaux pwm qui controles 
les roues, en utilisant des coefficients dépendant de la trajectoire, soit pour faire avancer le robot, soit pour 
s'ajuster à l'intérieur d'une trajectoire rectiligne, soit pour se tourner pendant les maneuvres.
# Motor 
contient une methode, qui sert a generer un signal PWM pour chacun des 2 roues.
# LSS05
contient la methode moveRobot, qui fait avancer le robot en ligne droite, selon le capteur 
suiveur de ligne, ainsi que les methodes qui le fait tourner gauche ou droite a 90 degrés.
# Classe Can
c'est la classe qui sert a initialiser le convertisseur analogique numerique.
# GP2D12
représente la classe que nous utilisons pour lire les valeurs émises par le capteur de distance.
# Del 
allume la del sur la carte mer en 2 couleurs, rouge ou vert.
# Conversion
sert a convertir des unités, et nous fournit une methode pour donner la position du robot,
selon la valeur captée, du capteur distance.
# lcm & conversion
permettre l'affichage sur le LCD.
