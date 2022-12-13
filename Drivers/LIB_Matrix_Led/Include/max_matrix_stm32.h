#include "main.h"
#include "stdbool.h"


// change the max7219 PORT and Pins below
#define maxport GPIOA
#define data_Pin MATRIXDATA_Pin
#define cs_Pin MATRIXCS_Pin
#define clock_Pin MATRIXCLK_Pin


// Set the number of dot-matrix-displays being used
#define num 4


#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))


// Define for the shift left or right operation
#define left 'L'
#define right 'R'


/*
  Set a value to the single LED
	col = which column to set
	row = which row to set
	value = value
*/
void setled(uint8_t col, uint8_t row, uint8_t value);


/*
  Set value to the entire ROW
	row = which row to set
	value = value
*/
void setrow(uint8_t row, uint8_t value);


/*
  write a character to the dot matrix
	c = character to write
	max = the number of dot matrix display to write on ----> input values >=1
*/
void write_char (char c,  uint8_t max);

/*
  Scroll a character
	c = character to Scroll
	speed = time delay in ms between btween 2 shifts
	direction = direction of Scroll (enter left or right)
*/
void scroll_char (char c,uint32_t speed, char direction);


// used for shifting the string
void shift_char (char c, uint32_t speed, char direction);


/*
  Scroll the string
	*string = pointer to the string
	speed = time delay in ms between btween 2 shifts
	direction = direction of Scroll (enter left or right)
*/
void scroll_string (uint8_t *string, uint32_t speed, char direction);


/*
  Initialise MAX7219
	brightness = brightness of the LEDs.. input between 1 to 15
*/
void max_init (uint8_t brightness);


void shiftleft(void);  // shift the display LEFT

void shiftright(void); // shift the display RIGHT

void write_byte (uint8_t byte);  // write a byte to the max7219

void write_max_cmd (uint8_t address, uint8_t cmd); // write command to the max7219

void max_clear(void); // clear the buffer
