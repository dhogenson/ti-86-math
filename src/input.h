#ifndef INPUT_H
#define INPUT_H

/*
 * lcd_getkey - Get raw key scancode from TI-86 keyboard
 *
 * Blocks until a key is pressed.
 *
 * @return Raw TI-86 scancode (0-255, no ASCII translation)
 */
unsigned char lcd_getkey(void);

/**
 * The following defines are hex and are the return values of the lcd_getkey function
 *
 * Note: The getchar function will work return different values then the lcd_getkey function would
 * because the lcd_getkey function returns raw hex values and getchar does not
 */

#define DOWN_ARROW 0x04
#define UP_ARROW 0x03
#define RIGHT_ARROW 0x01
#define LEFT_ARROW 0x02
#define ENTER_KEY 0x06
#define DELETE_KEY 0x09

#define MINI_MINUS_KEY 0x1A
#define MINUS_KEY 0x0D

#define KEY_0 0x1C
#define KEY_1 0x1D
#define KEY_2 0x1E
#define KEY_3 0x1F
#define KEY_4 0x20
#define KEY_5 0x21
#define KEY_6 0x22
#define KEY_7 0x23
#define KEY_8 0x24
#define KEY_9 0x25

// The reset are input functions

int get_number(char *prompt);

#endif
