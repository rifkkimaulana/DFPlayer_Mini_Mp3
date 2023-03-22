
#include "Arduino.h"
#include "SoftwareSerial.h"

uint8_t send_buf[10] = {
	0x7E, 0xFF, 06, 00, 00, 00, 00, 00, 00, 0xEF};
uint8_t recv_buf[10];

//* void(*send_func)() = NULL;
//* HardwareSerial *hserial = NULL;
//* SoftwareSerial *sserial = NULL;
//* boolean is_reply = false;

// 7E FF 06 0F 00 01 01 xx xx EF
// 0	->	7E is start code
// 1	->	FF is version
// 2	->	06 is length
// 3	->	0F is command
// 4	->	00 is no receive
// 5~6	->	01 01 is argument
// 7~8	->	checksum = 0 - ( FF+06+0F+00+01+01 )
// 9	->	EF is end code

void mp3_set_reply (boolean state); 

void mp3_fill_cmd (uint8_t cmd, uint16_t arg);
void mp3_fill_cmd (uint8_t cmd);

void mp3_set_serial (HardwareSerial &theSerial); 

void mp3_set_serial (SoftwareSerial &theSerial); 

// Set the serial port used for logging
void mp3_set_debug_serial (HardwareSerial &theSerial);

uint16_t mp3_get_checksum (uint8_t *thebuf); 

void mp3_fill_checksum (); 

void mp3_play_physical (uint16_t num); 
void mp3_play_physical (); 

void mp3_next (); 

void mp3_prev (); 

//0x06 set volume 0-30
void mp3_set_volume (uint16_t volume); 

//0x07 set EQ0/1/2/3/4/5    Normal/Pop/Rock/Jazz/Classic/Bass
void mp3_set_EQ (uint16_t eq); 

//0x09 set device 1/2/3/4/5 U/SD/AUX/SLEEP/FLASH
void mp3_set_device (uint16_t device); 

void mp3_sleep (); 

void mp3_reset (); 

void mp3_pause (); 

void mp3_stop (); 

void mp3_play (); 

//specify a mp3 file in mp3 folder in your tf card, "mp3_play (1);" mean play "mp3/0001.mp3"
void mp3_play (uint16_t num); 

void mp3_get_state (); 
// Wait for mp3_get_state reply
int mp3_wait_state ();

void mp3_get_volume (); 
// Wait for mp3_get_volume reply
int mp3_wait_volume ();

void mp3_get_u_sum (); 
// Wait for mp3_get_u_sum reply
int mp3_wait_u_sum ();

void mp3_get_tf_sum (); 
// Wait for mp3_get_tf_sum reply
int mp3_wait_tf_sum ();

void mp3_get_flash_sum (); 
// Wait for mp3_get_flash_sum reply
int mp3_wait_flash_sum ();

void mp3_get_tf_current (); 
// Wait for mp3_get_tf_current reply
int mp3_wait_tf_current();

void mp3_get_u_current (); 
// Wait for mp3_get_u_current reply
int mp3_wait_u_current ();

void mp3_get_flash_current (); 
// Wait for mp3_get_flash_current reply
int mp3_wait_flash_current ();

//set single loop 
void mp3_single_loop (boolean state); 

void mp3_single_play (uint16_t num); 

void mp3_DAC (boolean state); 

void mp3_random_play (); 

// Query total file numbers of a folder
void mp3_get_folder_sum (uint16_t folder);
// Wait for mp3_get_folder_sum reply
int mp3_wait_folder_sum ();

// Play mp3 file in selected folder
void mp3_play_file_in_folder (uint8_t folder, uint32_t num);