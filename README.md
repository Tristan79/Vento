# Vento

Wanna control you ventilation unit from your computer, tablet or phone? Can't sleep? Cuz the noise of the ventilation unit is too loud! Can't replace the unit because it is not yours, add Vento! The itho, duco, orcon, zehnder, storkair, berschenhoek: Arduino [MySensors 2.0](https://www.mysensors.org) perilex ventilation controller!

Manufactures air ventilation unit: itho, duco, orcon, zehnder, storkair, berschenhoek or ...

Price range parts: essential € 5 ~ full blown € 50

You need a MySensors gateway and a Smart Home Controller supporting MySensors like [Domoticz](www.domoticz.com)
Luckily if you have a raspberry Pi a gateway costs just 67 cents extra! [See this](https://www.domoticz.com/forum/viewtopic.php?t=14365&#p105148)

Contact <tristan@monkeycat.nl>!

## Other Nice Smarthome stuff!!

 * [iBrew](https://github.com/Tristan79/iBrew) iKettle, iKettle 2.0 and Smarter Coffee Interface.
 * [iSamsungTV](https://github.com/Tristan79/iSamsungTV) the command line interface to Samsung TV series C, D, E, F and Blue Ray Disc Players with Smart Hub feature.
 * [Medisana Scale](https://github.com/keptenkurk/BS440) Domoticz bridge (easily adaptible) to Medisana BS440, BS430,... weight scales.
 * [Xiaomi Mi Plant Sensor](https://github.com/open-homeautomation/miflora) with Domoticz [bridge](http://domoticz.com/forum/viewtopic.php?f=56&t=13306&hilit=mi+flora&start=20#p105255) (easily adaptible) 

## Vento!

![Domoticz](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/images/domoticz.png)

![Scheme3](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/images/schema.png)

Choose between Vento L1 and Vento L3 depending on your model.

## Vento L1

__Make sure your unit has the following specification__

![Specs2](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/images/ventoL1.png)

You can cut open the existing cable and use that! Or use extra perilex plugs!

 * Blue: N power socket
 * Brown: L1 power socket
 * Orange: N ventilation unit
 * Yellow: L3 ventilation unit
 * Green: L2 ventilation unit
 * L2 & L3 power socket terminated
 * L1 & Ground directly connected

```
Power Socket          Ventilation Unit
Ground ________________________ Ground
N  ____________ Relay 1 ____________ N
L1 ________________________________ L1
L2 (T)      |___Relay 2 ___________ L2
L3 (T)      |__ Relay 3 ___________ L3
```

## Vento L3
__Make sure your unit has the following specification__

![Specs3](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/images/ventoL3.png)

You can cut open the existing cable and use that! Or use extra perilex plugs!

 * Blue: N power socket
 * Brown: L3 power socket
 * Orange: N ventilation unit
 * Yellow: L1 ventilation unit
 * Green: L2 ventilation unit
 * L1 & L2 power socket terminated
 * L3 & Ground directly connected

```
Power Socket          Ventilation Unit
Ground ________________________ Ground
N  ____________ Relay 1 ____________ N
L3 ________________________________ L3
L2 (T)      |___Relay 2 ___________ L2
L1 (T)      |__ Relay 3 ___________ L1
```

## Relay

![Relay](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/images/relay.png)

## [Domoticz](www.domoticz.com)

 
## Showcase

Prototype!?

![Showcase1](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/images/showcase/1.jpg)

The unit...

![Showcase2](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/images/showcase/2.jpg)

All connected!

![Showcase3](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/images/showcase/3.jpg)

Assembled!

![Showcase4](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/images/showcase/4.jpg)

Photo's in the dark such that you really see the lights of Level 1, Level 2 and Level 3

![Level1](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/images/level/1.jpg)![Level2](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/images/level/2.jpg)![Level3](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/images/level/3.jpg)

 
## Parts, Shop & Prices 

Prices are snapshot 27 december 2016:

__Essential__
 * € 1.72 [Relay 4x](https://nl.aliexpress.com/item/1pcs-lot-4-channel-relay-module-4-channel-relay-control-board-with-optocoupler-Relay-Output-4/32325541816.html)
 * € 2.42 [Arduino Nano v3 ATmega328](https://nl.aliexpress.com/item/Free-Shipping-1PCS-LOT-For-arduino-Nano-3-0-Atmel-ATmega328-Mini-USB-Board/32773364249.html)
 * € 0.67 [Radio NRF24L01+](https://nl.aliexpress.com/item/1pcs-lot-Black-nrf24l01-wireless-module-24l01-2-4g-wireless-module-black-diamond-free-shipping/32649100793.html)
 * € 0.59 [Dupond male to male wires](https://nl.aliexpress.com/item/40pcs-lot-10cm-2-54mm-1pin-Female-to-Male-jumper-wire-Dupont-cable/32566136519.html)
 * € 0.66 [Plastic Barrier Terminal Blok](https://nl.aliexpress.com/item/10A-2-Position-Wire-Connector-Plastic-Barrier-Terminal-Block-High-Quality/32714811508.html)
 * € 0.37 [4.7µ - 47µF Capacitor](https://nl.aliexpress.com/item/Free-shipping-100pcs-47UF-50V-Electrolytic-Capacitor-50V-47UF-Aluminum-Electrolytic-Capacitor-6X12mm/32316099910.html)
 * € Total 6,43
 
__Perilex & Box__
 * € 7.28 [Perilex plug male & wire](http://www.bengshop.nl/detailitem.php?articletext=RATIO+PERILEX+AANSLUITSNOER+2M+6A+GROEN+&sess=&shop=0&lang=nl&art_id=13006284)
 * € 11.61 [Perilex plug female](http://www.bengshop.nl/detailitem.php?articletext=ABL+SURSUM+PERILEX+16A+KOPPELCONTACTSTOP+WIT+&sess=&shop=0&lang=nl&art_id=12987480)
 * € 3.51 [Box](http://www.bengshop.nl/detailitem.php?sess=&shop=5&lang=nl&art_id=14614105) 
 * € 8.50 Delivery cost bengshop 
 * Total € 30,90  

__Power__
 * € 7.79 [USB Power Adapter](https://www.allekabels.nl/usb-lader/4508/1196134/usb-thuislader-1000-ma.html)
 * € 3,95 Delivery cost allekabels
 * € 1.26 [Mini USB cable](https://nl.aliexpress.com/item/White-1m-MiNi-USB-to-USB-2-0-Cable-Data-Sync-Charge-Cable-for-MP3-MP4/32622398168.html)
 * Total € 12,36
 
And isolation tape or soldering stuff and screwdrivers :-)

Please search yourself for the lowest prices!

Price Range € 6.43 - € 50,33

## [Fritzing](http://fritzing.org)
Fritzing [Relay 4 Channel](https://timgolisch.wordpress.com/2015/09/12/fritzing-4-channel-relay-part/) part

## License

Copyright (c) 2017, Tristan Crispijn
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. You may not use source, binary forms or derivative work, with or without modification, for commercial purposes. 

4. Written consent of the Vento creator Tristan Crispijn with original authentic signature on paper.


THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. YOU AGREE TO NOT USE THIS SOFTWARE IN ANY WAY.               


 