/* 
 * File:   main.c
 * Author: longchen
 *
 * Created on August 29, 2015, 6:47 PM
 */

#include <xc.h>
#include <sys/attribs.h>

#define OUTPUT 0;
#define INPUT 1;


/*
 * 
 */
int main() {
    
    
    TRISDbits.TRISD0 = OUTPUT;
    LATDbits.LATD0 = 1;
    TRISDbits.TRISD6 = INPUT;
    CNPUDbits.CNPUD6 = 1;
    

    while(1)
    {
        if(PORTDbits.RD6 == 0){
            LATDbits.LATD0 = 1;
        }
        else{
            LATDbits.LATD0 = 0;
        }
    }
    return 0;
}

