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

To configure the Vonets VAP11N300, I needed to do so on the Vonets official website; Since my main machine doesn't have a physical network adapter,
I decided to do this as a continuation on the Pi.

The workaround here is to load a second micro SD card with Ubunto 22.something and fire it up in the Pi 400. This was quick and I did some configuration before going to the RISC OS for finalizing the connection. 
Plugging both ethernet and power-over-USB into the Pi, I logged into http://vonets.cfg with "admin:admin" and proceeded to witness all of my 
neighbors' router's MACs in plain text... plus their decibel signal strength, gooood ole chinese radio devices eh?

I have a strong desire to physically dismantly this device and connect it to my microchip PLC programming board somehow and see just how this 
thing tics. After the nerve racking step of hand jamming my 2.4G password into an http Chinese website (awesome) I rebooted the VAP and waited 
for the progress window to give me the green light... this takes a while. Going to bed, will continue...

As one can imagine, there needs to be some driver-like package loaded to this for it to be compatible with RISC OS. 
If we were using say, a brostrend 2.4G wifi adapter and wanted to configure it on a Windows machine, for use on a Linux machine,
easy peasy lemon squeazy, plug in here, load there, now we're sniffing networks... with RISC it's a little different. 
Luckily there's a package for this at heyrick.ddns.net/files/vonets_pre001.zip









