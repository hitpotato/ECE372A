/* 
 * File:   switch.c
 * Author: Long Chen
 *
 * Created on August 27, 2015, 3:12 PM
 */

#include <xc.h>
#include "switch.h"


void initSwitch1(){
    //TODO: Initialize switch 1
 
    TRISDbits.TRISD7 = INPUT; 
    CNPUDbits.CNPUD7 = 1;       // Enable Internal Pull-up resistor
}
