# lorawan-fuota-mbed-os-example
The example of FUOTA over LoRaWAN

This example is forked from the repo https://github.com/ARMmbed/mbed-os-example-lorawan-fuota

Target device: [L-TEK FF1705](https://os.mbed.com/platforms/L-TEK-FF1705/)

## Steps to build the application
1. Install [Mbed Studio-1.2.1](https://os.mbed.com/studio/)
2. Import this repository via:
    ```
    $ mbed import https://github.com/asvin-io/lorawan-fuota-mbed-os-example.git
    ```
3. In main.cpp specify the `APP_EUI`, `APP_KEY`, and `GEN_APP_KEY`. Here the `DEV_EUI` will be fetched from the internal memory. Please specify this Device EUI in your LoRa Server.
4. In mbed_app.json specify the frequency plan
5. Build the application using:
    ```
    $ mbed compile -m FF1705_L151CC -t GCC_ARM --profile=./profiles/tiny.json
    ```
    This will create a binary file in `BUILD/FF1705_L151CC/GCC_ARM-TINY/` folder
6. From the folder `BUILD/FF1705_L151CC/GCC_ARM-TINY/` copy the `mbed-os-example-lorawan-fuota.bin` file to the development board (mounted as flash storage device).

## Signing tool installation and setup of keys
1. 

## Creating a delta update


## Firmware update using Chirpstack server

