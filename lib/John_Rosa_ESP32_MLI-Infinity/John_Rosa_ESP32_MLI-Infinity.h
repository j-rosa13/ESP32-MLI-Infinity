//inclu arduino
#include <Arduino.h>


//One fais tout ç1a si elle n'est pas deja definie
#ifndef Rosa_John_LED_BP

//on definit ALLUME SUR HIGH
#define ALLUME      HIGH
#define ETEINDRE    LOW

#define FRONT_MONTANT RISING

#define ENTREE INPUT
#define SORTIE OUTPUT

//On déclare les bouton sur leurs pins
#define BOUTON_SW1  27
#define BOUTON_SW2  33
#define BOUTON_SW3  32
#define LED_ROUGE   16
#define LED_VERTE   5
#define LED_ORANGE  17
#define DECOMPTE 250
#define additionRapportCyclique 409.6

#define channelRouge 0
#define channelOrange 0
#define channelVert 0
/////////////////////////////////////////////////////////////

void initialiserOLED_BP(void);

// on déclare la fonction lire entree, 
//avec un entier entreeUC

void piloterLed(uint8_t brocheLed, bool etat);  // piloter les leds de la carte
void clignoterLed(uint8_t laled,uint32_t periode);

void boutonAllumerLed(uint8_t laled,uint8_t bouton);
void changerIntesiteLed(uint8_t channel,uint32_t duty);

//fini
#endif 


