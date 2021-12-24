/*
 * Classe permettant l'acces au convertisseur analogique/numerique
 * du microcontroleur ATMega16 de Atmel.
 *
 * Ecole Polytechnique de Montreal
 * Departement de genie informatique
 * Cours inf1995
 *
 * Matthew Khouzam et Jerome Collin
 * 2005-2006
 *
 * Code qui n'est sous aucune license.
 *
 */

#ifndef CAN_H
#define CAN_H

#include <avr/io.h> 


/*
 * Classe can:
 *   Le constructeur initialise le convertisseur.
 *   Une lecture enclanche une conversion et le resultat
 *   est retourne sur 16 bits.
 *
 */

class Can{
   public:
      Can();
      ~Can();
      // retourne la valeur numerique correspondant a la valeur
      // analogique sur le port A.  pos doit etre entre 0 et 7
      // inclusivement.  Seulement les 10 bits de poids faible
      // sont significatifs.
      uint16_t read(uint8_t pos);
      // shifts parameter by 2 positions to get a value on 8 bits
      uint8_t get8Bits(uint16_t valueFromAdc);
      // sets PORTA as entry port
      void initializePortA();

   private:
      const static uint8_t shiftingPositions = 2;
      const static uint8_t IN = 0x00;
};

#endif /* CAN_H */
