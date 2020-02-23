/*******************************************************************************
 * Copyright (c) 2014 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial API and implementation and/or initial documentation
 *******************************************************************************/

#ifndef MOS_CONTRIB_COUNTDOWN_H_
#define MOS_CONTRIV_COUNTDOWN_H_

#include "mgos.h"

namespace countdown 
{

class Countdown {
public:
    Countdown() {  
		intervalEndMS = 0L;
    }
    
    Countdown(uint32_t ms) {
        CountdownMS(ms);   
    }
    
    bool Expired() {
        return (intervalEndMS > 0L) && (millis() >= intervalEndMS);
    }
    
    void CountdownMS(uint32_t ms) {
        intervalEndMS = millis() + ms;
    }
    
    void CountdownS(int seconds) {
        CountdownMS((uint32_t)seconds * 1000L);
    }
    
    int LeftMS() {
        return intervalEndMS - millis();
    }

    bool Enabled() {       
        return (intervalEndMS > 0L) ? true : false;
    }

    static uint32_t millis(void) {
        return mgos_uptime_micros() / 1000;
    }

private:
    uint32_t intervalEndMS; 
};

Countdown* NewCountdown(uint32_t ms = 0);

}

#endif