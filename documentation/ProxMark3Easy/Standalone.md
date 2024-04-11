So If you've ever used a PM3, you know how silly it is to carry a laptop around with you connected to the device, or tether it
to a phone, with a string of cables and the Walrus app... so why not treat it like a Pico or Arduino and load a single script
to it, for capturing and maybe recording a single range of signal. RfidResearchGroup has a whole batch of them on their Github:
https://github.com/RfidResearchGroup/proxmark3/blob/master/armsrc/Standalone/hf_14asniff.c
^That one immediately caught my eye because it saves to memory

If you need a longer list of more widely functional scripts here's a page dedicated to just that:
https://github.com/RfidResearchGroup/proxmark3/wiki/Standalone-mode


For my project. I used my Pi 400 with Unbuntu machine that I built and pushed the script to the device from the terminal by using the following:

git clone https://github.com/Proxmark/proxmark3.git
cd proxmark3
curl -O https://raw.githubusercontent.com/RfidResearchGroup/proxmark3/master/armsrc/hf_14asniff.c
make hf_14asniff
./proxmark3 /dev/ttyACM0
script run hf_14asniff
