/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    T1CON = 0x30; // turn timer off and set prescaller to 1:256
    TMR1 = 0;
    PR1 = 0xFFFF;
    T1CONSET = 0x8000; // start timer
    
}

initTimer2(){
    //TODO: Initialize Timer 2.
}

delayMs(int delay){
    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
}