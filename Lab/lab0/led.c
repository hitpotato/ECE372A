/* 
 * File:   led.c
 * Author: Long Chen
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "led.h"

void initLEDs(){
    
    //TODO: Initialize LEDs
    TRISDbits.TRISD0 = OUTPUT;
    TRISDbits.TRISD1 = OUTPUT;
    TRISDbits.TRISD2 = OUTPUT;
    LATDbits.LATD0 = 0;
    LATDbits.LATD1 = 0;
    LATDbits.LATD2 = 0;
}

void turnOnLED(int led){
    
    if(led == 1){
        LATDbits.LATD0 = 1;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 0;
    }
    else if(led == 2){
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 1;
        LATDbits.LATD2 = 0;        
    }
    else if(led == 3){
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 1;
    }//TODO: You may choose to write this function
    // as a matter of convenience
    
}