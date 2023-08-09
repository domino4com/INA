<img src="assets/INA.svg" width=200 align="right">

[![PlatformIO](https://github.com/domino4com/INA/actions/workflows/platformio.yml/badge.svg)](https://github.com/domino4com/INA/actions/workflows/platformio.yml)
[![Arduino](https://github.com/domino4com/INA/actions/workflows/arduino.yml/badge.svg)](https://github.com/domino4com/INA/actions/workflows/arduino.yml)

# INA - Input Navigation A
This is a GNSS (GPS) Sensor providing navigational data.
| Specifications | |
| --: | :--: |
| Communication | I²C |
| I²C Address | 0x10 |
| ChipSet | Quectel L76-L-M33|
| Datasheet | [see datasheets folder](datasheets) |
| Suggested Arduino Library | [GitHub](https://github.com/adafruit/Adafruit_GPS) |
| Suggested MicroPython Library | [GitHub](https://github.com/inmcm/micropyGPS) |
| Standard Altitude Limit | 10000 m |
| Balloon Altitude Limit | 80000 m |
| GNSS Systems: | GPS, GLONASS, Galileo and QZSS |
| Differential: | DGPS, SBAS (WAAS/EGNOS/MSAS/GAGAN) |
| Firmware: | L76LNR02A02SC (2019/06/28) |
| Protocols: | NMEA 0183 (v4.10), PMTK, PQ |
| On Board Antenna: | 1575 Mhz, 4.3dBi gain |
| Cold boot fix acqusition | <2 min typ |
| **Max Dynamic Performance** ||
| Altitude: | Max. 18000 m |
| Velocity: | Max. 515 m/s |
| Acceleration: | Max. <span>&#177;</span>4g |

## Supported I²C Modes
- [X] 100 kbit/s Standard Mode (SM) 
- [X] 400 kbit/s	Fast Mode	FM
- [ ] 1 Mbit/s	Fast Mode Plus	FM+
- [ ] 3.4Mbit/s	High Speed Mode	HS
- [ ] 5 Mbit/s	Ultra Fast Mode	UFM

## Software Notes:

### High Altitude Balloon (HAB) mode:
Using this command: ```$PMTK886```, the unit can be entering into High Altitude Balloon (HAB) mode, which will allow flights to 80 km (50 miles/260k feet). Otherwise the altitude limit is 10 km (6 miles/30k feet). See the protocol datasheet in the datasheets folder.

## Hardware Notes:

### Green LED:
The Green LED is directly connected to the PPS signal. It (typically) steady when on, but no fix, and blinking when a fix has been aquired. The PPS signal can be changed using the ```$PQ1PPS``` command. See the SDK manual in the datasheets folder.

### External Antenna:
The board has a solder switch allowing to cut the signal to the onboard antenna, and solder a connection to the U.Fl/Ipex antenna connector. The board has footprints for matching antenna impedance components, (0 Ω resistor and unpopulated capacitors, all 0805 sized). *This part is experimental and no attempt of finding an antenna and specifying a impedeance matching sets of componnets has been done. However, an active antenna has been connected and without any matching circuits a cold boot acquision fix was obtained in < 20 min typical.*

### Battery:
The circuit has a footprint for a non-rechargeble coincell battery holder of type *CR1220*, which can optionally be soldered on, in order to reduce cold boot acquisition time.

### RX/TX Solder pads
As default the Serial (UART) connection to the GPS is not connected. The user is expected to use I²C, similar to other sensors. However the RX/TX solder pads can be soldered close to establish a Serial connection to a core. If this is done, this INA xChip has to be removed from a circuit everytime a core is programmed, since the core is programmed over the serial connection.

  
  
# License: 
<img src="assets/CC-BY-NC-SA.svg" width=200 align="right">
Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License

[View License Deed](https://creativecommons.org/licenses/by-nc-sa/4.0/) | [View Legal Code](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode)
