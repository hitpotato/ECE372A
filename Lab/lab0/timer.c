/* 
 * File:   timer.c
 * Author: Long Chen
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>
#include "timer.h"

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    TMR1 = 0;// clear TMR1
    PR1 = 2441;// Initialize PR1
    T1CONbits.TCKPS = 3; // Initialize pre-scalar
    T1CONbits.TCS = 0; // Setting the oscillator
    IFS0bits.T1IF = 0;// Put the flag down
    IPC1bits.T1IP = 3;// Configure the Interrupt Priority
    IEC0bits.T1IE = 1;// Enable the interrupt
    T1CONbits.ON = 1;// Turn the timer on
}

void initTimer2(){
    //TODO: Initialize Timer 2.
    TMR2 = 0;// clear TMR2
    T2CONbits.TCKPS = 0; // Initialize pre-scalar
    T2CONbits.TCS = 0; // Setting the oscillator
    IFS0bits.T2IF = 0;// Put the flag down
}

void delayMs(int delay){
//    TODO: Using timer 2, create a delay
//     that is delay amount of ms.
    TMR2 = 0;// clear TMR2
    PR2 = delay * 624;// Initialize PR2
    IFS0bits.T2IF = 0;// Put the flag down
    T2CONbits.ON = 1;// Turn the timer on
    while(IFS0bits.T2IF == 0);// Wait
    T2CONbits.ON = 0;
    
}