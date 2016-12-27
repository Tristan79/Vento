# Vento

Can not sleep due to the noise of the ventilation unit and your windows are always open? Can not replace the unit since it is not yours, add Vento! The StorkAir Arduino [Mysensors 2.0](https://www.mysensors.org) Controller!

Manufactures: itho, duco, orcon, zehnder, storkair

Price range parts € 6.06 - € 49,32

## Vento 2

Make sure your unit has the following specification

![Specs2](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/vento2.png)

![Scheme2](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/schema2.png)

You can cut open the existing cable and use that or use plugs!

 * Blue: N power socket
 * Orange: N ventilation unit
 * White: L1 power socket
 * Green: L1 ventilation unit
 * Black: L2 power socket
 * Yellow: L2 ventilation unit
 * Red: L3 power socket
 * Grey: L3 ventilation unit

 
```
Power Socket          Ventilation Unit
Ground ________________________ Ground
N  ____________ Relay 1 ____________ N
L1 ____________ Relay 2 ___________ L1
L2 ____________ Relay 3 ___________ L2
L3 _____________Relay 4 ___________ L3
```
 
## Vento 3

Make sure your unit has the following specification

![Specs3](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/vento3.png)

![Scheme3](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/schema3.png)


You can cut open the existing cable and use that or use plugs!

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

![Relay](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/relay.png)

## Raspberry Pi

If you have a raspberry pi, you can buy another radio (67 cents) and connect it using [this info](https://www.domoticz.com/forum/viewtopic.php?t=14365&#p105148) to have a fully function gateway to talk to Vento!

## [Domoticz](www.domoticz.com)

![Domoticz](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/domoticz.png)
 
## Showcase

![Showcase1](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/showcase1.png)
![Showcase2](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/showcase2.png)
![Showcase3](https://raw.githubusercontent.com/Tristan79/Vento/master/resources/showcase3.png)

 
## Parts, Shop & Prices 

Prices are snapshot 27 december 2016:

__Essential__
 * € 1.72 [Relay 4x](https://nl.aliexpress.com/item/1pcs-lot-4-channel-relay-module-4-channel-relay-control-board-with-optocoupler-Relay-Output-4/32325541816.html)
 * € 2.42 [Arduino Nano v3 ATmega328](https://nl.aliexpress.com/item/Free-Shipping-1PCS-LOT-For-arduino-Nano-3-0-Atmel-ATmega328-Mini-USB-Board/32773364249.html)
 * € 0.67 [Radio NRF24L01+](https://nl.aliexpress.com/item/1pcs-lot-Black-nrf24l01-wireless-module-24l01-2-4g-wireless-module-black-diamond-free-shipping/32649100793.html)
 * € 0.59 [Dupond male to male wires](https://nl.aliexpress.com/item/40pcs-lot-10cm-2-54mm-1pin-Female-to-Male-jumper-wire-Dupont-cable/32566136519.html)
 * € 0.66 [Plastic Barrier Terminal Blok](https://nl.aliexpress.com/item/10A-2-Position-Wire-Connector-Plastic-Barrier-Terminal-Block-High-Quality/32714811508.html)
 * € Total 6,06
 
__Perilex & Box__
 * € 7.28 [Perilex plug male & wire](http://www.bengshop.nl/detailitem.php?articletext=RATIO+PERILEX+AANSLUITSNOER+2M+6A+GROEN+&sess=&shop=0&lang=nl&art_id=13006284)
 * € 11.61 [Perilex plug female](http://www.bengshop.nl/detailitem.php?articletext=ABL+SURSUM+PERILEX+16A+KOPPELCONTACTSTOP+WIT+&sess=&shop=0&lang=nl&art_id=12987480)
 * € 3.51 [Box](http://www.bengshop.nl/detailitem.php?sess=&shop=5&lang=nl&art_id=14614105) 
 * € 8.50 Delivery cost bengshop 
 * Total € 30,90  

__Power__
 * € 7.79 [USB Power Adapter](https://www.allekabels.nl/usb-lader/4508/1196134/usb-thuislader-1000-ma.html)
 * € 3,95 Delivery cost allekabels
 * € 0.62 [Micro USB cable](https://nl.aliexpress.com/item/Micro-USB-Cable-1m-OD-3-5mm-Available-in-Black-or-White/32599608580.html)
 * Total € 12,36
 
And isolation tape or soldering stuff and screwdrivers :-)

Please search yourself for the lowest prices!

Price Range € 6.06 - € 49,32

## [Fritzing](http://fritzing.org)
Fritzing [Relay 4 Channel](https://timgolisch.wordpress.com/2015/09/12/fritzing-4-channel-relay-part/) part



 