So there's next to no resources online for this particular build. That is, in the sense of, "oh you need to use rufus and then the F10 key"
As you may be aware, there's still limited support for (compared to Raspberry) managing custom builds on Orange/Potato/Odroid SBCs 
when we look at all of the awesome cyberdecks that folks are churning out with their Pi400s and zero's. 

I stumbled across a video describing QubesOS while watching some tutorials on RISC-OS and trying to get it online 
(I had RISC loaded to the Zero w and wanted to code on it from a fishfinder screen with a Rii Mini X1 BLE Keypad).
I first had to kick myself for not jumping on LFS faster because the cubes/panels thing for VMs in a hypervisor was something a friend and 
myself discussed in 2023... I guess we were about 9 years too late to the game anyway (tear). That said: I'm stoked that someone when through 
the trouble of designing and developing an entire operating system based on the idea of containerization and security. If only I could load
it to this new dev board and make a custom laptop with it. THE ANCIENT LENOVO!!! 
(...So it's another thumb-in-cheek at those guys for using *hook.exe in their boot scripts, which caused a 0day and two critical CVE's.)

Well this just got a lot more complex. 

So the idea here is to load QubesOS to a microSD, figure out which order and presence of bootloader to alter to force the Opi H3 chip
to use it, and then attach the board inside of the Lenovo Ideapad 100S from 2016... after I cannibalize it. This comes much later 
in the build and will definitely require some 3D printing. 

For startes:
The OrangePi 3 LTS user manual - https://uelectronics.com/wp-content/uploads/2022/04/OrangePi-3-LTS-H6-User-manual-v1.0.pdf
The Qubes .iso - https://www.qubes-os.org/
Possibly a copy of Armbian - https://www.armbian.com/orangepi3-lts/
I think maybe a copy of Ubuntu - https://ubuntu.com/download/desktop

So these Allwinner chipsets don't have a BIOS that you can F-key to or a bootloader menu to really customize things, and this is totally
ok. As an exercise in hardware and firmware, I'm almost glad this is the case. It's a great learning experience and there's always 
something lower in the stack to be learned. My first idea is to load Armbian because it's lightweight and I've seen it recommended 
on the few forums who cater to OrangePi. Second, I'll have to departition the microSD, and look at the placement of it's boot scripts to
make them presentable to the H3 chip. This superuser forum gives a better explaination: https://superuser.com/questions/1393266/changing-boot-sequence-for-an-orange-pi

But wait, I saw something funky on youtube, where a guy was loading Qubes to a Dell and he used two seperate USBs (really a microSD and a 
SSD for speed). I think he was onto something.... 

One. Eternity. Later.

So it turns out you can use two removeable drives to hand-hold the hardware into booting your OS, but I think he did that because
he knew it would work and it was easier in his case. Here, we're looking to shore up one microSD and flash the U-boot binary to it. 
Also, he states in his video, he was using a SSD for speed which makes sense, because adding a usb drive might slow this down considerably.

Kind of random, but I have to clear write protection from the microSD to reload QubesOS.
  (from PowerShell)
  >diskpart
  >select disk 1
  >attributes disk clear readonly
Then we use Rufus to rewrite the SD card with Qubes iso and ensure we've checked the "dd" option when prompted.

(From WSL-Kali)
Using U-boot:
  Let's see if we can't clone the repository and set the boot instruction to run from 8K (hex 0x2000)
  >git clone https://gitlab.denx.de/u-boot/u-boot
  >lsblk (checking the location where we'll flash u-boot)
    looks like in my case sdb is the correct drive (same size as what's printed on the card)
  >cd u-boot/
  >cat README (it's a long one.. like 30 pages or so, extremely extensive and essentially a clinic in firmware)
  >ls (for funzies, I'd like to know what we pulled and what's available)

Let's search for our configuration file in the /configs directory
  >cd configs/
it's orangepi_3_defconfig - of note, there's about a thousand boards in here supported by u-boot. This is pretty cool!
  >cd ..
  >make orangepi_3_defconfig
Here Comes The Confusing Part
  In order to configure a boot file that's assigned to this software package, on this microSD, that initiates at the correct
  moment, we have to configure the settings in an extant .config file that has interoperability with our loaded OS and the hardware
  of the Single Board Computer. this configuration menu is entered by sending
  >make menuconfig
  This opens up one of those BIOS/DOS grey and blue tabs, that only takes key-input... there's a thousand options.
  Fear not, most of them make sense and the acronyms are easy. 
--Boot Options
--Boot Media (this brings up a seven item list of boot options
--I activated boot from: 'SD/EMMC', 'SD/EMMC and enable QSPI', as well as 'Support booting from SPI Flash' by entering "Y" on their selection
--After searching around in the menus I found Use a custom location for the initial stack pointer address, and entered it's hex loc: 2x2000
--I followed the in menu promts to save to .config
Then
>make
Aaaaand it threw a bunch of warnings (not fatal errors).
So, like any good samaritan would do, I went out searching for the partition from WSL to the BUSIDs and proceeded to use dd

WSL
>lsblk
selecting sdb
>sudo dd if=u-boot-sunxi-with-spl.bin of=/dev/sdb bs=1024 seek=8
and this is basically telling our terminal to load the .bin file into the removeable media, then calibrating the load size and location

Then we can add a line to the .config file to ensure our boot path will be executed
CROSS_COMPILE=arm-linux=gnuabi-

>sudo dd if=u-boot-sunxi-with-spl.bin of=/dev/sdb bs=1024 seek=8
more could not find errors >> looks like I'll have to go looking for this thing
> find . -name "u-boot*"
>not in those

I'll edit the Makefile
  >nano Makefile
   ARCH ?= arm
   CROSS_COMPILE ?= arm-linux-gnueabi-
   CPU ?= cortex-a55
Hopefully editing the kernel will allow us to use the correct architecture between the build and the boot process...

>make clean
  throws a cross_compile dependancy error. Well, let's go get some cross-compilation software
  >sudo apt-get install gcc-arm-linux-gnueabi

So this level of troubleshooting is nothing short of rebuilding parts of the kernel, let's try to move down the wire.
  First we're going to try some trick out of the holster like using another flash package to burn the OS onto the SD card
  For this we'll use Etcher instead of Rufus. I'm also not going to unzip the download. Also, so it's more likely to boot
  from the correct location, we'll use a more commonplace OS like Ubuntu. Once we develop a process for successful boot,
  I'll take small steps back into the realm of QubesOS. Who knows, it might be a reason to get an upgraded SBC.

Success!
  Ubuntu Jammy and Bionic start up just fine when pulled from the official OrangePi downloads page for 3LTS. I used Balena Etcher
  instead of Rufus, though I'm sure Rufus would work just fine. The bionic desktop looks a little bleak and app availability is quite 
  starving considering this is likely an ultralight distro. Jammy looks about the same, just a little more robust. Let's work on
  dual booting this system with Jammy and Qubes on the microSD.

Dual boot Jammy/Qubes
  [Win+x]
  Select "Disk Management"
  Now in the bottom panel I can see both partitions, the first being my operating system and the second being the 64GB SD card.
  lets shrink that Jammy partition down to a minimal (or close to it) size to leave our QubesOS the bulk of the memory.
  RC > selecting "shrink volume"
  ...we're going to go ahead and use Paragon Partitioning Manager to deal with this since Windows likes to write protect everything.
  ***Most partitioning management tools come with hidden fees but paragon is free and works on write protected devices
  I resized the partition with Jammy on it to 9.5GB (sounds like a cool number). And added an additional partition of around 49GB.
  Then I copied the QubesOS image from my downloads into the SD cards new NTFS partition in the file manager.
  ***Even after updating the active status of the new partition with Paragon, the OrangePi wouldn't boot using Qubes.

Clean Aproach with WSL
  So the first time this was tried, I attempted to load up U-boot, slap the defconfig file on top of Qubes on the SD, and boot it.
  This didn't work, in large part, because I didn't understand how to use u-boot correctly. I think the best way to go about this is to
  flash the orangepi_defconfig as a standalone, boot the orangepi, then change it's grub file to select the Qubes partition.
  I'd run into some problems with u-boot not compiling the defconfig file correctly due to architecture issues. 
  sudo apt-get install gcc-aarch64-linux-gnu
  This should take care of that by loading up ARM8 tools.
  


  
  
  
  


