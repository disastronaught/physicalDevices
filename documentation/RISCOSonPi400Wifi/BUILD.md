So I decided to build a cyberdeck using a Pi 400 keyboard, with a fishfinder screen, Li battery pack, and a 1/8" sheet of acrylic...

The usage: I wanted a little bit of internet, and would otherwise use the machine to dev in ARM assembly and BASIC.
The twist: I'm using RISC OS which is super niche and obscure and really outdated. 
BASICally, a low level development standalone box, literally bolted to some plexiglass and ramshackled together in around an hour.

The components: Pi 400, 512Gb mSD, 38000mAh Li battery, microHDMI to HDMI short cable, USB to USB-C short, USB to 9/12VDC adapter with VDC display.

I sliced some 3/4" by 3/4" by 6" walnut strips on the table saw and chamfered them with a mini hand plane to mount using 3/4" self tappers.
These went on the bottom of the acrylic sheet so it wouldn't be all wobbly when I mounted everything else. 
The monitor is about 7" and has an articulating mount which I bolted through the acrylic using more self tappers.

I flashed the micro SD using the Pi imager with RISC OS and booted to the pinboard (this is what Acorn called the desktop in 1987)

Internet:
From here I noticed that internet connectivity is more akin to intranet or share-access-only, which is sort of annoying when you want to use the
download functionality to retrieve new packages. On RISC we're using PacMan (package manager) much like on Arch Linux, and without a wifi connection,
we're sort of dead in the water. Since there's currently no wifi support for RISC on Pi, we're gonna have to resort to more workarounds.
There's an ethernet port on the Pi, and you could potentially plug in a cable to the network switch, but that's not very 'standalone' and 
someone in the past 35 years has to have solved this for us...

Introducing the ethernet-to-usb-bridge. Vonets VAP11N300 was $25USD on Amazon and covers us with 2.4GHz wifi which is enough for us in this case.
There's also the Vonets VAP11AC which is dual band and a possible extension for future use when I delve into hardening the security on this thing.











