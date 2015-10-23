/*
    MAX9814.cpp - MAX9814 sensor library
    Developed by Andrea Corrado   
*/

#include "mbed-drivers/mbed.h"
#include "MAX9814/MAX9814.h"

MAX9814::MAX9814(PinName pin): _pin(pin) { //, _led1(LED1), _led2(LED2), _led3(LED3) {
    
}



float MAX9814::sound_level() {

    _t.start();
    float peakToPeak=0, signalMax=0, signalMin=1024;

    while (_t.read_ms()<50) {
        _sample=_pin.read();

        if (_sample<1024) {
            if (_sample>signalMax)
                signalMax=_sample;

            else if (_sample<signalMin)
                signalMin=_sample;
        }
    }
    _t.stop();
    _t.reset();
    peakToPeak=signalMax-signalMin;
    _value= (peakToPeak*3.3);
    _value = floor(_value * 100) / 100;

    return _value;
}
