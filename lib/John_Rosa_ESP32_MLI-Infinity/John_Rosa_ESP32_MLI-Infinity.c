#include "John_Rosa_ESP32_MLI-Infinity.h"
#include  <Arduino.h>

//Fonction de configuration des entrées/sorties du µC
void initialiserOLED_BP(void){
	pinMode(BOUTON_SW1, ENTREE) ;
	pinMode(BOUTON_SW2, ENTREE);
    pinMode(LED_ROUGE, SORTIE) ;
    pinMode(LED_VERTE, SORTIE) ;
    pinMode(LED_ORANGE, SORTIE) ;
    digitalWrite(LED_ORANGE, ALLUME);
    digitalWrite(LED_VERTE, ALLUME);
    digitalWrite(LED_ROUGE, ALLUME);
}


//Fonction de pilotage de LEDs
void piloterLed(uint8_t brocheLed, bool etat){
    digitalWrite(brocheLed, etat);
}

// clignotement d'une led en millisecondes
void clignoterLed(uint8_t laled,uint32_t periode){
piloterLed(laled,ALLUME);
delay(periode/2);
piloterLed(laled,ETEINDRE);
delay(periode/2);
}


void boutonAllumerLed(uint8_t laled,uint8_t bouton){
int etatled = digitalRead(bouton) ;
    if(etatled == HIGH)
    {
        digitalWrite(laled, HIGH);
    }

}


