#include <ArduinoJson.h>
#include <Wire.h>
#ifndef I2C_SDA
#define I2C_SDA SDA
#endif
#ifndef I2C_SCL
#define I2C_SCL SCL
#endif

// Specifics
#include <INA.h>
INA input;
char ts[25];
uint8_t  sat;
nmea_float_t lat, lon, alt, sog, cog, hdop;
bool fx;
char s[] = "%s: Lat: %.6f, Lon: %.6f, HDOP: %.2f, sat: %u, alt: %.2f, %s\n";

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.printf("\nINA Example Test\n");

    Wire.setPins(I2C_SDA, I2C_SCL);
    Wire.begin();

    if (input.begin()) {
        Serial.println("INA initialized successfully.");
    } else {
        Serial.println("Failed to initialize INA!");
        delay(10000);
        exit(0);
    }
        // delay(10000);
}

void loop() {
    if (input.getData(&ts[0], lat, lon, alt, sog, cog, sat, fx,hdop)) {
        Serial.printf(s, ts, lat, lon,hdop,sat,alt,fx ? "Got fix" : "No fix");
    } else {
        Serial.println("Failed to get INA data.");
    }

    delay(1000);
}