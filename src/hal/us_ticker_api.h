/* mbino - basic mbed APIs for the Arduino platform
 * Copyright (c) 2017 Thomas Kemmer
 *
 * mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License.  You
 * may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.  See the License for the specific language governing
 * permissions and limitations under the License.
 */
#ifndef MBINO_US_TICKER_API_H
#define MBINO_US_TICKER_API_H

#include "ticker_api.h"

extern "C" {
    unsigned long micros();
}

namespace mbino {

    const ticker_data_t* get_us_ticker_data();

    void us_ticker_init();

    inline uint32_t us_ticker_read() {
        // make this inline so simply using us_ticker_read() does not
        // pull in whole ticker API...
        return micros();
    }

    void us_ticker_set_interrupt(timestamp_t timestamp);

}

#endif
