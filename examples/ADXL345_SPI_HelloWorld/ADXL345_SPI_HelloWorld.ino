#include "ADXL345.h"

ADXL345 accelerometer(SPI_MOSI, SPI_MISO, SPI_SCK, SPI_SS);

int main() {
    int readings[3] = {0, 0, 0};

    printf("Starting ADXL345 test...\n");
    printf("Device ID is: 0x%02x\n", accelerometer.getDevId());

    // Go into standby mode to configure the device.
    accelerometer.setPowerControl(0x00);

    // Full resolution, +/-16g, 4mg/LSB.
    accelerometer.setDataFormatControl(0x0B);

    // 3.2kHz data rate.
    accelerometer.setDataRate(ADXL345_3200HZ);

    //Measurement mode.
    accelerometer.setPowerControl(0x08);

    while (1) {
        wait(0.1);

        accelerometer.getOutput(readings);

        // 13-bit, sign extended values.
        printf("%d, %d, %d\n", readings[0], readings[1], readings[2]);
    }
}
