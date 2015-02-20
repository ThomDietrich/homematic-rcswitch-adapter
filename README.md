# HomeMatic Funk-Schaltsteckdosen Adapter

Eine Arduino Schaltung und Programmierung um über ein HomeMatic 8-Kanal-Empfangsmodul Funk-Schaltsteckdosen aller Art zu schalten.

![Schaltung: HM Modul, RF Modul, Arduino, Antennen](2015-02-20_15.51.15.jpg "fertiger Aufbau")

Das Projekt basiert auf:
* Funk-Schaltsteckdosen
  * bspw. 3er-Set mit Fernbedienung für 10€ in jedem Baumarkt
  * aus diversen Gründen sind Module vom "Typ A" zu empfehlen [10-fach DIP-Schalter](http://rc-switch.googlecode.com/svn/wiki_images/typeA.png)
* HomeMatic 8-Kanal-Empfangsmodul
  * http://www.elv.de/homematic-8-kanal-empfangsmodul.html
  * ~20€
* Arduino Nano
  * http://arduino.cc/en/Main/ArduinoBoardNano
  * bspw. http://www.ebay.de/itm/301292188973
  * USB-Controller-Treiber für günstigen China-Clone: http://www.5v.ru/ch340g.htm
  * ~4€
* 433 MHz Transmitter
  * bspw. http://www.ebay.de/itm/221652085232
  * rc-switch Bibliothek: http://code.google.com/p/rc-switch
  * ~3€ 