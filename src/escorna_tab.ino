/*
    Copyright (C) 2020  Rafa Couto <caligari@treboada.net>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <Arduino.h>

#include "configuration.h"
#include "EscornaTab.h"


static const EscornaTab::Config cfg = 
{
    buttonPin: PIN_BUTTON,
    tabPins: 
    { 
        PIN_TAB_1_1, PIN_TAB_1_2, PIN_TAB_1_3,
        PIN_TAB_2_1, PIN_TAB_2_2, PIN_TAB_2_3,
        PIN_TAB_3_1, PIN_TAB_3_2, PIN_TAB_3_3,
    },
    rowPins: { PIN_ROW_1, PIN_ROW_2 }
};


EscornaTab escorna_tab(cfg, Serial);


void setup()
{
    escorna_tab.init();
}


void loop()
{
    escorna_tab.update();
}


