/* 
 * File:   switch.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
 */

#include <xc.h>
#include "switch.h"


void initSwitch1(){
    //TODO: Initialize switch 1
    SW1 = INPUT;
    CNPUDbits.CNPUD6 = 1;
}
