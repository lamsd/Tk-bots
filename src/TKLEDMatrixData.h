
#ifndef _TK_LEDMATRIX_FONT_DATA_H_
#define _TK_LEDMATRIX_FONT_DATA_H_

typedef struct 
{
  uint8_t Character[1];
  uint8_t data[6];
}LED_Matrix_Font_6x8_TypeDef;

//Terminal
const LED_Matrix_Font_6x8_TypeDef Character_font_6x8[] PROGMEM =
{
    ' ',  0x00,0x00,0x00,0x00,0x00,0x00,

    '0',  0x00,0x7C,0x82,0x82,0x7C,0x00,
    '1',  0x00,0x42,0xFE,0x02,0x00,0x00,
    '2',  0x00,0x46,0x8A,0x92,0x62,0x00,
    '3',  0x00,0x44,0x92,0x92,0x6C,0x00,
    '4',  0x00,0x1C,0x64,0xFE,0x04,0x00,
    '5',  0x00,0xF2,0x92,0x92,0x8C,0x00,
    '6',  0x00,0x7C,0x92,0x92,0x4C,0x00,
    '7',  0x00,0xC0,0x8E,0x90,0xE0,0x00,
    '8',  0x00,0x6C,0x92,0x92,0x6C,0x00,
    '9',  0x00,0x64,0x92,0x92,0x7C,0x00,

    'a',  0x00,0x04,0x2A,0x2A,0x1E,0x00,
    'b',  0x00,0xFE,0x12,0x12,0x0C,0x00,
    'c',  0x00,0x0C,0x12,0x12,0x12,0x00,
    'd',  0x00,0x0C,0x12,0x12,0xFE,0x00,
    'e',  0x00,0x1C,0x2A,0x2A,0x18,0x00,
    'f',  0x00,0x10,0x3E,0x50,0x50,0x00,
    'g',  0x00,0x08,0x15,0x15,0x1E,0x00,
    'h',  0x00,0xFE,0x10,0x1E,0x00,0x00,
    'i',  0x00,0x00,0x2E,0x00,0x00,0x00,
    'j',  0x00,0x02,0x01,0x2E,0x00,0x00,
    'k',  0x00,0xFE,0x08,0x14,0x12,0x00,
    'l',  0x00,0x00,0xFE,0x02,0x00,0x00,
    'm',  0x00,0x1E,0x10,0x0E,0x10,0x0E,
    'n',  0x00,0x1E,0x10,0x10,0x0E,0x00,
    'o',  0x00,0x0C,0x12,0x12,0x0C,0x00,
    'p',  0x00,0x1F,0x12,0x12,0x0C,0x00,
    'q',  0x00,0x0C,0x12,0x12,0x1F,0x00,
    'r',  0x00,0x1E,0x08,0x10,0x10,0x00,
    's',  0x00,0x12,0x29,0x25,0x12,0x00,
    't',  0x00,0x10,0x3E,0x12,0x00,0x00,
    'u',  0x00,0x1C,0x02,0x02,0x1E,0x00,
    'v',  0x18,0x04,0x02,0x04,0x18,0x00,
    'w',  0x18,0x06,0x1C,0x06,0x18,0x00,
    'x',  0x00,0x12,0x0C,0x0C,0x12,0x00,
    'y',  0x00,0x18,0x05,0x05,0x1E,0x00,
    'z',  0x00,0x12,0x16,0x1A,0x12,0x00,

    'A',  0x00,0x7E,0x88,0x88,0x7E,0x00,
    'B',  0x00,0xFE,0x92,0x92,0x6C,0x00,
    'C',  0x00,0x7C,0x82,0x82,0x44,0x00,
    'D',  0x00,0xFE,0x82,0x82,0x7C,0x00,
    'E',  0x00,0xFE,0x92,0x92,0x82,0x00,
    'F',  0x00,0xFE,0x90,0x90,0x80,0x00,
    'G',  0x00,0x7C,0x82,0x92,0x5C,0x00,
    'H',  0x00,0xFE,0x10,0x10,0xFE,0x00,
    'I',  0x00,0x82,0xFE,0x82,0x00,0x00,
    'J',  0x00,0x0C,0x02,0x02,0xFC,0x00,
    'K',  0x00,0xFE,0x10,0x28,0xC6,0x00,
    'L',  0x00,0xFE,0x02,0x02,0x02,0x00,
    'M',  0x00,0xFE,0x40,0x30,0x40,0xFE,
    'N',  0x00,0xFE,0x40,0x30,0x08,0xFE,
    'O',  0x00,0x7C,0x82,0x82,0x82,0x7C,
    'P',  0x00,0xFE,0x90,0x90,0x60,0x00,
    'Q',  0x00,0x7C,0x82,0x8A,0x84,0x7A,
    'R',  0x00,0xFE,0x98,0x94,0x62,0x00,
    'S',  0x00,0x64,0x92,0x92,0x4C,0x00,
    'T',  0x00,0x80,0xFE,0x80,0x80,0x00,
    'U',  0x00,0xFC,0x02,0x02,0xFC,0x00,
    'V',  0x00,0xF0,0x0C,0x02,0x0C,0xF0,
    'W',  0x00,0xFE,0x04,0x38,0x04,0xFE,
    'X',  0x00,0xC6,0x38,0x38,0xC6,0x00,
    'Y',  0xC0,0x20,0x1E,0x20,0xC0,0x00,
    'Z',  0x00,0x86,0x9A,0xB2,0xC2,0x00,
    ',',  0x00,0x01,0x0e,0x0c,0x00,0x00,
    '.',  0x00,0x00,0x06,0x06,0x00,0x00,
    '%',  0x72,0x54,0x78,0x1e,0x2a,0x4e,
    '!',  0x00,0x00,0x7a,0x00,0x00,0x00,
    '?',  0x00,0x20,0x4a,0x30,0x00,0x00,
    '-',  0x00,0x10,0x10,0x10,0x10,0x00,
    '+',  0x08,0x08,0x3e,0x08,0x08,0x00,
    '/',  0x00,0x02,0x0c,0x30,0x40,0x00,
    '*',  0x22,0x14,0x08,0x14,0x22,0x00,
    ':',  0x00,0x00,0x14,0x00,0x00,0x00,
    '"',  0x00,0xC0,0x00,0xC0,0x00,0x00,
    '#',  0x28,0xFE,0x28,0xFE,0x28,0x00,
    '(',  0x00,0x00,0x7C,0x82,0x00,0x00,
    ')',  0x00,0x00,0x82,0x7C,0x00,0x00,
    ';',  0x00,0x02,0x24,0x00,0x00,0x00,
    '~',  0x00,0x40,0x80,0x40,0x80,0x00,
    ';',  0x00,0x02,0x24,0x00,0x00,0x00,
    '=',  0x00,0x28,0x28,0x28,0x28,0x00,
    '|',  0x00,0x00,0xFE,0x00,0x00,0x00,
    '>',  0x00,0x82,0x44,0x28,0x10,0x00,
    '<',  0x00,0x10,0x28,0x44,0x82,0x00,  
    '@',  0x00,0x00,0x00,0x00,0x00,0x00,  // End mark of Character_font_6x8
};






typedef struct 
{
	uint8_t data[3];
}LED_Matrix_Clock_Number_Font_3x8_TypeDef;

const LED_Matrix_Clock_Number_Font_3x8_TypeDef Clock_Number_font_3x8[] PROGMEM =
{
	0x7C,0x44,0x7C,  //0
	0x00,0x7C,0x00,  //1
	0x5C,0x54,0x74,  //2
	0x54,0x54,0x7C,  //3
	0x70,0x10,0x7C,  //4
	0x74,0x54,0x5C,  //5
	0x7C,0x54,0x5C,  //6
	0x40,0x40,0x7C,  //7
	0x7C,0x54,0x7C,  //8
	0x74,0x54,0x7C,  //9
    0x00,0x04,0x00,  //.
	0x20,0x20,0x20,  //-
	0x00,0x00,0x00,  //
};

#endif



