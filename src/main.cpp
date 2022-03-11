////////////////////////////////////////////////////////////////
/*
Programme John_Rosa_ESP32_MLI-Ifinity
crée par Rosa John le 13/01/22 
Version 1.0

Ce programme consisteras à faire varier une intensité lumineuse,
sur une des trois led de notre carte. Et de aussi pouvoir éteiddre,
la led selctionné

Cahier des carges:
  - l’appui sur SW1 sélectionne DEL
  - l’appui sur SW2 augmente l’intensité lumineuse de la DEL sélectionnée
  - l’appui sur SW3 éteint la DEL sélectionnée
  - Configuration du module MLI : fréquence de 2kHz, résolution de 12 bits,rapport cyclique variable.

  Fonction à créer
    -Allumez LED en fonction du nombre d’appuis (rapportCyclique)

*/
////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include "John_Rosa_ESP32_MLI-Infinity.h"

int  nombreAppuisSW1 = 0;
int  nombreAppuisSW2 = 0;
int  nombreAppuisSW3 = 0;

uint32_t decompteMilis = 0;

int rapportCyclique = 0;
////////////////////////////////////////////////////////////////
void IRAM_ATTR InteruptionSW1(){
  if (millis() - DECOMPTE >= decompteMilis) {
    nombreAppuisSW1++;
    Serial.println("InteruptSW1");
  }
}

void IRAM_ATTR InteruptionSW2(){
  if (millis() - DECOMPTE >= decompteMilis) {
    nombreAppuisSW2++;
    Serial.println("InteruptSW2");
  }
}

void IRAM_ATTR InteruptionSW3(){
  if (millis() - DECOMPTE >= decompteMilis) {
    nombreAppuisSW3++;
    Serial.println("InteruptSW3");
  }
}
////////////////////////////////////////////////////////////////
void setup() {
initialiserOLED_BP();
attachInterrupt(BOUTON_SW1, InteruptionSW1, FRONT_MONTANT) ;
attachInterrupt(BOUTON_SW2, InteruptionSW2, FRONT_MONTANT) ;
attachInterrupt(BOUTON_SW3, InteruptionSW3, FRONT_MONTANT) ;
Serial.println("FinSetup");
}

void loop() {


  switch (nombreAppuisSW1)
  {

    case 1: //LedRouge
      Serial.println("case 1");
      delay(100);
      if(nombreAppuisSW3 == 0)
      {
        Serial.println("nbAppuisSW3 = 0");
        delay(100);
        if(nombreAppuisSW2 == 0){
          Serial.println("nbAppuisSW2 = 0");
          delay(100);
          piloterLed(LED_ROUGE,ETEINDRE);
        }else{
          changerIntesiteLed(LED_ROUGE,nombreAppuisSW2);
          Serial.println("change l'intensité");
          delay(100);
        } 
      }else {
        nombreAppuisSW2 = 0;
        nombreAppuisSW3 = 0;
      }
  
    break;


  case 2: //LedOrange
  Serial.println("case 2");
  break;


  case 3: //ledVerte
  Serial.println("case 3");
  nombreAppuisSW1 = 1;
  break;
  }


}

