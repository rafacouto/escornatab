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

#include "EscornaTab.h"


EscornaTab::EscornaTab(const Config& cfg, Stream& serial) :
    _cfg(cfg),
    _stream(serial)
{
}


int EscornaTab::init()
{
    int p;

    // button pin
    pinMode(_cfg.buttonPin, INPUT_PULLUP);

    // tab input pins
    for (p = 0; p < 9; p++) pinMode(_cfg.tabPins[p], INPUT);

    // row output pins
    for (p = 0; p < ROW_COUNT; p++)
    {
        uint8_t pin = _cfg.rowPins[p];
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    return 0;
}


void EscornaTab::update()
{
    // check when button was pressed
    if (_scanButton())
    {
        for (int r = 0; r < ROW_COUNT; r++)
        {
            // read each row
            uint8_t tabs[9];
            readTabs(r, tabs);

            // send the codes but check empty tab
            if (!_sendRow(tabs)) break;

            // end of row
            _stream.print(ROW_SEPARATOR);
        }

        // end of program
        _stream.print(PRG_SEPARATOR);
    }

    delay(20);
}


void EscornaTab::readTabs(uint8_t row, uint8_t* tabs)
{
    // activate row
    digitalWrite(_cfg.rowPins[row], HIGH);

    // time to energize row
    delay(ROW_ACTIVATION_MILLIS);

    // read input pins
    for (int t = 0; t < 9; t++)
        tabs[t] = (digitalRead(_cfg.tabPins[t]) == HIGH ? 1 : 0);

    // deactivate row
    digitalWrite(_cfg.rowPins[row], LOW);
}


bool EscornaTab::_scanButton()
{
    static uint8_t last_value = LOW;
    uint8_t button = digitalRead(_cfg.buttonPin);

    if (last_value ^ button)
    {
        // button has changed
        last_value = button;

        // button is active low
        if (button == LOW) return true;
    }

    return false;
}


bool EscornaTab::_sendRow(uint8_t* tabs)
{
    uint8_t code;

    // tab 1
    code = tabs[0] | tabs[1] << 1 | tabs[2] << 2;
    _sendCode(code);
    if (!code) return false;

    // tab 2
    code = tabs[3] | tabs[4] << 1 | tabs[5] << 2;
    _sendCode(code);
    if (!code) return false;

    // tab 3
    code = tabs[6] | tabs[7] << 1 | tabs[8] << 2;
    _sendCode(code);
    if (!code) return false;

    return true;
}


void EscornaTab::_sendCode(uint8_t code)
{
    static const char* code_strings[] =
        { CODE_0, CODE_1, CODE_2, CODE_3, CODE_4, CODE_5, CODE_6, CODE_7 };

    if (code < 8)
    {
        _stream.print(code_strings[code]);
        _stream.print(TAB_SEPARATOR);
    }
}


