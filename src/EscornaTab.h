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

#ifndef _ESCORNA_TAB_H
#define _ESCORNA_TAB_H

#include <Arduino.h>
#include <stdint.h>

#include "configuration.h"


class EscornaTab
{
    public:

        struct Config
        {
            uint8_t buttonPin;
            uint8_t tabPins[9];
            uint8_t rowPins[ROW_COUNT];
        };

        // instance and configuration
        EscornaTab(const Config& cfg, Stream& serial);

        // initialize Escornatab
        int init();

        // loop update
        void update();

        // read tabs by row
        void readTabs(uint8_t row, uint8_t* tabs);

    private:

        const Config& _cfg;
        Stream& _stream;

        bool _scanButton();
        bool _sendRow(uint8_t* tabs);
        void _sendCode(uint8_t code);
};

#endif // _ESCORNA_TAB_H

