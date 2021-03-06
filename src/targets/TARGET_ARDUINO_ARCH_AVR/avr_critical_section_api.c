/* mbino - basic mbed APIs for the Arduino platform
 * Copyright (c) 2017, 2018 Thomas Kemmer
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
#ifdef ARDUINO_ARCH_AVR

#include <Arduino.h>

#include "hal/critical_section_api.h"

static volatile bool critical_interrupts_enabled;
static volatile bool state_saved = false;

// TODO: proper implementation on AVR?
bool core_util_is_isr_active(void)
{
    return false;
}

bool core_util_are_interrupts_enabled(void)
{
    return (SREG & (1 << SREG_I)) != 0;
}

void hal_critical_section_enter(void)
{
    bool interrupts_enabled = core_util_are_interrupts_enabled();
    cli();
    if (!state_saved) {
        critical_interrupts_enabled = interrupts_enabled;
        state_saved = true;
    }
}

void hal_critical_section_exit(void)
{
    state_saved = false;
    if (critical_interrupts_enabled) {
        sei();
    }
}

bool hal_in_critical_section(void)
{
    return state_saved;
}

#endif
