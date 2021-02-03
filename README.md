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
    This will create binary files in `BUILD/FF1705_L151CC/GCC_ARM-TINY/` folder
6. From the folder `BUILD/FF1705_L151CC/GCC_ARM-TINY/` copy the `mbed-os-example-lorawan-fuota.bin` file to the development board (mounted as flash storage device).

## Signing tool installation and setup of keys
1. 

## Creating a delta update
1. Before building the aplication with new updates, copy the file `mbed-os-example-lorawan-fuota_update.bin` to `./updates` folder. And rename it as `v1_update.bin`
2. Now build the application with updates. It will create binary files with necessary updates in `BUILD/FF1705_L151CC/GCC_ARM-TINY/` folder
3. Then copy the file `mbed-os-example-lorawan-fuota_update.bin` to `./updates` folder. And rename it as `v2_update.bin`
4. Create the delta file using:
    ```
    $ lorawan-fota-signing-tool sign-delta --old ./updates/v1_update.bin --new ./updates/v2_update.bin --output-format bin -o ./updates/v1_to_v2.bin
    ```

## Firmware update using Chirpstack server
1. In the Chirpstack Application server, select the device and click on `CREATE FIRMWARE UPDATE JOB` in the FIRMWARE column of the device details.
2. Upload the diff file `v1_to_v2.bin` to update job.
3. Specify all other details. For example:
    ```
    Firmware update job-name: FUOTA_TEST_1
    Select firmware file: v1_to_v2.bin
    Redundant frames: 5
    Unicast timeout: 15
    Data-rate: 5
    Frequency: 869525000
    Multicast-group type: Class-C
    Multicast-timeout: 128 seconds
    ```
4. Then create fuota deployment
5. This will create a `Multicast-group` for the mulcast session setup and update distribution

