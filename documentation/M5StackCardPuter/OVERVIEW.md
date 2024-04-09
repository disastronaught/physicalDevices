A few months back I ordered and received an M5 Stack Cardputer, which hosts an ESP32, 56 key-board, and a host of signal reception sensors.
One might say this is akin to the flipper: it is, in a sense. I prefer the Cardputer because it has an OS feel to it, but is down low enough to
interact with subGhz and also play around with WiFi. What's also much faster, is loading firmwares to the Cardputer. 

With the M5Burner desktop app, I can select a distribution, download it and burn it over the wire in seconds. I tested out NEMO first, and Bruce,
then moved on to the classic Marauder, and finally I landed on EvilCardputer. 

EvilCardputer is designed with an attack framework in mind. It's strictly WiFi centric, but the order of operations is present and the heuristics
of the fonts, screen resolution, and sharpness of characters are all there. This differs also in the reduction of keys used. Yes, you can manually
enter SSIDs during evil twin style attacks and on some pcap operations, but for the most part, it's a morse code-ey use of the 'Go' button for both
scroll and selection. 

A nice project for the Cardputer would be merging this firmware and some components of Bruce or Nemo into a single package that combines a few BLE
and sub Ghz methodology, using EvilCardputer selection schemes. If I have time over the next week or two, I may get them both in UIFlow and see what
there is to do on that front.
