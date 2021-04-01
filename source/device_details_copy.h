/*
* 
* This is file is used to store device details 
* used to connect it to LoRa application and asvin platform
* 
* It also contains the Firmware version of the application
* User should provide correct version before building the application.
*   FW_VER_STR has to be updated everytime the user create new firmware
* 
*/

#ifndef DEVICE_DETAILS_H
#define DECICE_DETAILS_H

#include <stdint.h>

//LoRa connection specifics
// Note: if the device has built-in dev eui (see dev_eui_helper.h), the dev eui will be overwritten in main()
static uint8_t DEV_EUI[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
static uint8_t APP_EUI[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
static uint8_t APP_KEY[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
static uint8_t GEN_APP_KEY[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

//asvin credentials
const std::string DEVICE_NAME = "";
const std::string DEVICE_MAC = "";
const std::string DEVICE_KEY = "";
const std::string CUSTOMER_KEY = "";
const std::string FW_VER_STR = "1.00"; // The string shall have only 4 characters
#endif