<img src="assets/NA.svg" width=200 align="right">

# INA - Input Navigation A
This is a GNSS (GPS) Sensor providing navigational data.
| Specifications | |
| --: | :--: |
| Communication | I²C |
| I²C Address | 0x10 |
| ChipSet | Quectel L76-L-M33|
| Datasheet | [see datasheets folder](datasheets) |
| Suggested Arduino Library | [GitHub](https://github.com/adafruit/Adafruit_GPS) |
| Standard Altitude Limit | 10000 m |
| Balloon Altitude Limit | 80000 m |
| GNSS Systems: | GPS, GLONASS (or BeiDou), Galileo and SBAS |
| Firmware: | L76LNR02A02SC (2019/06/28) |
| Protocols: | NMEA 0183, PMTK, PQ |
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

### External Antenna:
The board has a solder switch allowing to cut the signal to the onboard antenna, and solder a connection to the U.Fl/Ipex antenna connector. The board has null <TODO> components, (0 Ω resistor and unpopulated capacitors, all 0805 sized) for own <TODO>.

### Battery:
The circuit has components for a non-rechargeble coincell battery of type <TODO>, which can optionally soldered on, in order to reduce cold boot acquisition time.

### RX/TX Solder pads
As default the Serial (UART) connection to the GPS is not connected. The user is expected to use I²C, similar to other sensors. However the RX/TX solder pads can be soldered close to establish a Serial connection to a core. If this is done, this INA xChip has to be removed from a circuit everytime a core is programmed, since the core is programmed over the serial connection.

  
  
# License: 
<img src="assets/CC-BY-NC-SA.svg" width=200 align="right">
Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License

[View License Deed](https://creativecommons.org/licenses/by-nc-sa/4.0/) | [View Legal Code](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode)
