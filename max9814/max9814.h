/*
    MAX9814.h - MAX9814 sensor library
    Developed by Andrea Corrado   
*/

/*
    Example 'main.cpp'

#include "mbed.h"
#include "MAX9814.h"
Serial pc (USBTX, USBRX);


MAX9814 mic(p20);

int main()
{
    while (1) {
        mic.volume_indicator();
        pc.printf("\n\r Level is %f", mic.sound_level());
    }
}

*/

#ifndef MBED_MIC_H
#define MBED_MIC_H

#include "mbed-drivers/mbed.h"

class MAX9814 {
    
public:

    MAX9814(PinName pin); //Analogue in
    float sound_level();

protected:
    AnalogIn _pin;
    float _value;
    float _sample;
    Timer _t,_t1;
};

#endif
