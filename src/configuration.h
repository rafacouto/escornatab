
#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H

// send button
#define PIN_BUTTON 2

// 9 pins by row (3 tabs)
#define PIN_TAB_1_1 5
#define PIN_TAB_1_2 6
#define PIN_TAB_1_3 7
#define PIN_TAB_2_1 8
#define PIN_TAB_2_2 9
#define PIN_TAB_2_3 10
#define PIN_TAB_3_1 11
#define PIN_TAB_3_2 12
#define PIN_TAB_3_3 13

// connected rows (3 tabs by row)
#define ROW_ACTIVATION_MILLIS 100
#define ROW_COUNT 2
#define PIN_ROW_1 A0
#define PIN_ROW_2 A1

// generic codes
#define CODE_0 "000"
#define CODE_1 "001"
#define CODE_2 "010"
#define CODE_3 "011"
#define CODE_4 "100"
#define CODE_5 "101"
#define CODE_6 "110"
#define CODE_7 "111"
#define TAB_SEPARATOR "-"
#define ROW_SEPARATOR ""
#define PRG_SEPARATOR "\n"

/*
// escornabot codes
#define CODE_0 "g"
#define CODE_1 "n"
#define CODE_2 "s"
#define CODE_3 "e"
#define CODE_4 "w"
#define CODE_5 "E"
#define CODE_6 "W"
#define CODE_7 "G"
#define TAB_SEPARATOR "\n"
#define ROW_SEPARATOR ""
#define PRG_SEPARATOR ""
*/

#endif // _CONFIGURATION_H

