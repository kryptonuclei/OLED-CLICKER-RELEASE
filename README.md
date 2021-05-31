
# OLED-Clicker

This creation is designed to both be a fidget item while also being able to serve a purpose. It is an electronic counter and a fidget clicker utilizing mechanical keyboard switches. The OLED used is 1.3in across, larger than the typical horizontal OLEDs. The processor is an ATMEGA32U4, from an arduino leonardo framework. The code was developed in visual studio using arduino libraries. It is powered by an 18650 that is charged via a USB C connector. The 5V rail is connected to a TP4056 to handle the charging. The 32U4 is also connected to the USB C for programming.

There are some things that would be cool to integrate but have not been completed such as https://github.com/AlexIII/t-rex-duino and a selection of menus rather than the current mode toggles.

# Pictures

![IMG_4665](https://user-images.githubusercontent.com/83693142/119259817-60d67500-bc13-11eb-968d-9f2689180bc3.JPG)

![137523917_1570962459765296_4746547366832083114_n](https://user-images.githubusercontent.com/83693142/120181269-2a6eaa80-c250-11eb-8624-102d7ce35407.jpg)

# Model

![image](https://user-images.githubusercontent.com/83693142/117139576-c0e5b280-adef-11eb-8131-cfbc835e359f.png)


# PCB
![image](https://user-images.githubusercontent.com/83693142/117138961-081f7380-adef-11eb-83d0-88e22469623d.png)


![image](https://user-images.githubusercontent.com/83693142/117139038-1cfc0700-adef-11eb-91f2-fe83ca2f539f.png)




# Components

Link to OLED: https://www.aliexpress.com/item/1648493376.html?spm=a2g0s.9042311.0.0.50434c4dDTX8kw

| Part  | Value                                   | Device                                  | Description                                                                                                                    |
| ----- | --------------------------------------- | --------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| BT1   |                                         | BATTERY-18650-Holder                           | Battery - Single Cell                                                                                                          |
| C1    | 1u                                      | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| C2    | 100n                                    | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| C3    | 22p                                     | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| C4    | 22p                                     | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| C5    | 2.2u                                    | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| C6    | 0.1u                                    | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| C7    | 4.7u                                    | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| C8    | 0.1u                                    | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| C9    | 4.7u                                    | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| C10   | 10u                                     | C-EUC0805                               | CAPACITOR, European symbol                                                                                                     |
| C11   | 0.1u                                    | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| C12   | 0.1u                                    | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| C13   | 4.7p                                    | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| C14   | 0.1u                                    | C-EUC0603                               | CAPACITOR, European symbol                                                                                                     |
| D1    |                                         | LED0603                                 | LED (Generic)                                                                                                                  |
| D2    |                                         | LED0603                                 | LED (Generic)                                                                                                                  |
| D4    |                                         | LED0603                                 | LED (Generic)                                                                                                                  |
| D5    |                                         | LED0603                                 | LED (Generic)                                                                                                                  |
| D6    |                                         | DIODE\_SOD-123FL                        | Diode                                                                                                                          |
| IC1   | DW01A                                   | DW01A                                   | Battery Protection                                                                                                                               |
| IC2   | TP4056                                  | TP4056                                  | Battery Charger                                                                                                                               |
| J1    | DX07S016JA1R1500                        | DX07S016JA1R1500                        | USB-C (USB TYPE-C) USB 2.0 Receptacle Connector 24 (16+8 Dummy) Position Surface Mount, Right Angle; Through Hole  |
| L1    |                                         | L-EUL3225M                              | INDUCTOR, European symbol                                                                                                      |
| OLED1 | ADAFRUIT\_DISPLAY\_OLED\_128X64\_SH1107 | ADAFRUIT\_DISPLAY\_OLED\_128X64\_SH1107 | Horizontal ribbon 1.3in OLED                                                                                                   |
| Q1    | FS8205A                                 | FS8205A                                 | MOSFET                                                                                                                         |
| R1    | 22                                      | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R2    | 22                                      | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R3    | 10k                                     | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R4    | 330                                     | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R5    | 330                                     | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R6    | 560k                                    | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R7    | 4.7k                                    | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R8    | 1k                                      | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R9    | 1k                                      | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R10   | 1k                                      | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R11   | 1k                                      | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R12   | 100                                     | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R13   | 4.7k                                    | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R14   | 4.7k                                    | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R15   | 1.43m                                   | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| R16   | 205k                                    | R-EU\_R0603                             | RESISTOR, European symbol                                                                                                      |
| U$1   | ATMEGA32U4QFN2                          | ATMEGA32U4QFN2                          | Atmel 44-pin 8-bit Microcontroller with 32KBytes of ISP Flash and USB Controller -----                                         |
| U$2   | CHERRY-MX                               | CHERRY-MX                               | Cherry MX series keyswitch                                                                                                     |
| U1    | TPS61040DBVR                            | TPS61040DBVR                            | Boost IC                                                                                                            |
| Y1    | 16MHz                                   | CRYSTAL-16MHZSMD-5X3.2                  | 16MHz Crystal                                                                                                                  |
