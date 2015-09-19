/* 
 * File:   main.c
 * Author: Long Chen
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"


#define OUTPUT 0
#define INPUT 1

//TODO: Define states of the state machine

typedef enum state {
    led1, led2, led3, wait, wait2
} stateType;

//TODO: Use volatile variables that change within interrupts
volatile stateType state = led3;
volatile int count = 0;

int main() {
    //TODO: Write each initialization function
    initSwitch1();
    initLEDs();
    initTimer1();
    initTimer2();
    //This function is necessary to use interrupts. 
    enableInterrupts();
    int ps, ns; // previous state, next state
    while (1) {
        //TODO: Implement a state machine to create the desired functionality
        switch (state) {
            // wait for press
            case wait:
                if (SW1 == PRESSED) {
                    delayMs(10); 
                    TMR1 = 0;
                    count = 0;
                    T1CONbits.ON = 1;// turn on timer1 to 
                    state = wait2;
                }
                break;
            // check if its less or more than 2 seconds
            case wait2:
                if ((count >= 2) && (SW1 == RELEASED)) {
                    delayMs(10);
                    T1CONbits.ON = 0; // turn off timer1
                    if (ps == 1) {
                        state = led1;
                    } else if (ps == 2) {
                        state = led2;
                    } else if (ps == 3) {
                        state = led3;
                    }
                } else if ((count < 2) && (SW1 == RELEASED)) {
                    delayMs(10);
                    T1CONbits.ON = 0; // turn off timer1
                    if (ns == 1) {
                        state = led1;
                    } else if (ns == 2) {
                        state = led2;
                    } else if (ns == 3) {
                        state = led3;
                    }
                }
                break;
            // turn on the corresponding led
            case led1:
                turnOnLED(1);
                ps = 3;
                ns = 2;
                state = wait;
                break;
            case led2:
                turnOnLED(2);
                ps = 1;
                ns = 3;
                state = wait;
                break;
            case led3:
                turnOnLED(3);
                ps = 2;
                ns = 1;
                state = wait;
                break;
        }
    }
    return 0;
}
//use timer2 to count how many seconds it passed.
void __ISR(_TIMER_1_VECTOR, IPL3SRS) _T1Interrupt() {
    IFS0bits.T1IF = 0;
    if (state == wait2) {
        count = count + 1;
    }
}