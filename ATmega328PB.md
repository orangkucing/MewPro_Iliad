Updating Bastet firmware might be a challenge because the current toolchain distributed with Arduino IDE doesn't support its microcontroller.

# Arduino IDE for ATmega328PB

MewPro Bastet uses ATmega328PB as its microcontroller.  ATmega328P**B** is QUITE DIFFERENT than ubiquitous ATmega328P (without trailing **B**) that is used in Arduino Uno, Arduino Pro Mini etc.

In order to compile source code and to upload binary to the chip it is required to install the following files to your Arduino IDE 1.6.x or 1.8.x:

* Atmel atmega328pb Xplained mini core package

* Missing tool chain files for ATmega328PB

These are explained below.

#### Install Atmel atmega328pb Xplained mini core package

(In the following we assume you have already installed Arduino IDE to your PC. If not then please [download the Arduino IDE](https://www.arduino.cc/en/Main/Software) and install it before proceeding.)

Open your Arduino IDE application on your PC. Then select [Tools]->Board->[Boards Manager].  Then a dialog box for selecting boards is shown.  You will find "Atmel AVR Xplained-minis by Atmel University France" in the list.

Click the line and select [Install] button. This installs the definitions necessary to compile source codes for ATmega328PB using Arduino IDE.

Regrettably, following two modifications are yet necessary for installed core files but these steps are not done automatically.

1. Find `boards.txt` file and edit it:

   The file is located at  
   `~/Library/Arduino15/packages/atmel-avr-xminis/hardware/avr/0.6.0/boards.txt` under Mac or  
   `~/AppData/Local/Arduino15/packages/atmel-avr-xminis/hardware/avr/0.6.0/boards.txt` under Windows.    
   
   *Note: `~` is your home and `0.6.0` the version of core.*  
   
   Then the line  
   `atmega328pb_xplained_mini.build.mcu=atmega328p`  
   required to be modified to  
   `atmega328pb_xplained_mini.build.mcu=atmega328pb`

2. Find `avrdude.conf` file and edit it:

   The file is located at 
   `Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf` under Mac or  
   `/Program Files(x86)/Arduino/hardware/tools/avr/etc/avrdude.conf` under Windows.  

   Since the file lacks the definition for ATmega328PB, find these six lines  
   `part parent "m328"`  
   `id                  = "m328p";`  
   `desc                = "ATmega328P";`  
   `signature           = 0x1e 0x95 0x0F;`  
    
   `ocdrev              = 1;`   
   `;`  
   and add the following lines after them:
   [avrdude-add.conf](https://gist.github.com/orangkucing/06954a0f5f10b2db0a5a36c90dbcf492)

#### Install the missing tool chain files

The current avr-gcc toolchain automatically installed with Arduino IDE does not support ATmega328PB.  So we must update/overwrite the chain manually.

The original updating instruction is [here](https://github.com/watterott/ATmega328PB-Testing), but you should follow this step only:
>###Installation on Arduino IDE 1.8+
>
>1. The current avr-gcc toolchain (4.9.2-atmel3.5.3-arduino2) has not all files for the Atmega328PB. So you have to update the files in `/arduino/hardware` with the [files from this repository under hardware](https://github.com/watterott/ATmega328PB-Testing/raw/master/hardware.zip).
>
>The directory is located under Windows in `/Program Files(x86)/Arduino/hardware` and under Mac in `/Applications/Arduino/Contents/Java/hardware`

---
REMARK:  
Take care to unzip the downloaded file at the proper location!  
More precisely, under Windows do:   
1. Right click the downloaded `hardware.zip` file  
2. Select "Extract all"  
3. Fill the "Files will be extracted to the folder" textbox as `/Program Files(x86)/Arduino/hardware`  
4. Dialog box "The destination has 5 files with the same names" is shown: Tick "Replace the files in the destination"  

Under Mac do:  
1. Move `hardware.zip` to `/Applications/Arduino/Contents/Java/hardware`  
2. Open "Terminal" application and type the following Unix commands   
3. `cd /Applications/Arduino/Contents/Java/hardware`  
4. `unzip -o hardware.zip`  

---

# Compile and Upload

MewPro Bastet and MewPro Iliad share [the same source code](https://github.com/orangkucing/MewPro_Iliad).

The code needs Time and TimeAlarms libraries that are downloadable from 
[the PJRC site](http://www.pjrc.com/teensy/td_libs_Time.html).
After installing the libraries uncomment the line 44 in `Iliad.h` as

`#  include <TimeLib.h>`

And also if you haven't installed IRremote library or RTClib (these are required for MewPro Iliad) then comment out respective lines 29 or 38 as

`//#  include <IRremote.h>`  
`//#  include "RTClib.h"`

Then, to compile the code and to upload the firmware to Bastet, just select [Tools]->[Board: Atmel atmega328pb Xplained mini] and set [Tools]->[Port] to your FTDI port.

*Note 1: The source code is defaulted to use Bastet with GoPro Hero 4 Black. If you like to use Bastet with GoPro Hero 4 Silver then modify the 7th and 8th lines in `Iliad.h` as `#undef HERO_4_BLACK` and `#define HERO_4_SILVER`, respectively.* 

Connecting Sparkfun FTDI breakout 3.3V to Bastet is the same as doing so to MewPro 2 board. Thus, please refer [the blog post for MewPro 2](https://mewpro.cc/2017/02/25/list-of-gopro-hero-4-i2c-commands/) at "Connection" section.

*Note 2: If you soldered Bastet at the back of master MewPro 2 as in this picture
![](https://mewpro.cc/wp-content/uploads/ontop1.jpg)
then you can update both firmwares as they remain soldered. To do this just set an "Arduino Mini Temporary FTDI Header" from either the right side (i.e., from the part side) for Bastet or the left side (i.e., from the connector side) for MewPro 2 when needed.*

