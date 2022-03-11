#include "John_Rosa_ESP32_MLI-Infinity.h"
#include  <Arduino.h>

//Fonction de configuration des entrées/sorties du µC
void initialiserOLED_BP(void){
	pinMode(BOUTON_SW1, ENTREE) ;
	pinMode(BOUTON_SW2, ENTREE);
	pinMode(BOUTON_SW3, ENTREE) ;
    pinMode(LED_ROUGE, SORTIE) ;
    pinMode(LED_VERTE, SORTIE) ;
    pinMode(LED_ORANGE, SORTIE) ;
    digitalWrite(LED_ORANGE, ETEINDRE);
    digitalWrite(LED_VERTE, ETEINDRE);
    digitalWrite(LED_ROUGE, ETEINDRE);

    ledcAttachPin(LED_ROUGE,channelRouge);
    ledcAttachPin(LED_ORANGE,channelOrange);
    ledcAttachPin(LED_VERTE,channelVert);
    Serial.begin(9600);

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

// clignotement d'une led en millisecondes
void changerIntensiteLed(uint8_t laled,uint32_t rapportCyclique){
    
}

void boutonAllumerLed(uint8_t laled,uint8_t bouton){
int etatled = digitalRead(bouton) ;
    if(etatled == HIGH)
    {
        digitalWrite(laled, HIGH);
    }

}


void changerIntesiteLed(uint8_t channel,uint32_t duty){
    if(duty == 0){
        piloterLed(channel,ETEINDRE);
    }
    if(duty == 1){
        int frequenceLed = additionRapportCyclique * 1;
        ledcWrite(channel,frequenceLed);
    }
    if(duty == 2){
        int frequenceLed = additionRapportCyclique * 2;
        ledcWrite(channel,frequenceLed);     
    }
    if(duty == 3){
        int frequenceLed = additionRapportCyclique * 3;
        ledcWrite(channel,frequenceLed);        
    }
    if(duty == 4){
        int frequenceLed = additionRapportCyclique * 4;
        ledcWrite(channel,frequenceLed);         
    }
    if(duty == 5){
        int frequenceLed = additionRapportCyclique * 5;
        ledcWrite(channel,frequenceLed);         
    }
    if(duty == 6){
        int frequenceLed = additionRapportCyclique * 6;
        ledcWrite(channel,frequenceLed);         
    }
    if(duty == 7){
        int frequenceLed = additionRapportCyclique * 7;
        ledcWrite(channel,frequenceLed);         
    }
    if(duty == 8){
        int frequenceLed = additionRapportCyclique * 8;
        ledcWrite(channel,frequenceLed);       
    }
    if(duty == 9){
        int frequenceLed = additionRapportCyclique * 9;
        ledcWrite(channel,frequenceLed);      
    }
     if(duty == 10){
        int frequenceLed = additionRapportCyclique * 10;
        ledcWrite(channel,frequenceLed);        
    }
}
