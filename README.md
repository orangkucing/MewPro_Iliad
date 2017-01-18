# MewPro_Iliad
A Sync Generator/Controller for Hero 4 Black/Silver and MewPro.

### Supported video modes

We thought we've already supported all the video modes that Black and/or Silver could do. But that was false. (Hero 4 adjusts fps when the "low light" option is set. And we deceived by this function... How foolish we are!)

>Note: Currently we are very hard to work supporting more video modes. So please check this document again if your favorite video mode is not supported, yet.

The following video modes are known to work with Iliad + MewPro and Hero 4 Black.

| Resolution | fps | FOV |
| ---------- | -------- | --- |
| 4K         | (30), 25, 24 | W   |
| 4K S       | 24 | W |
| 2.7K       | 60, 50, 48, 30, 25, 24 | W, M|
| 2.7K S     | 30, 25 | W |
| 2.7K 4:3   | 30, 25 | W |
| 1440p      | 60, 50, 48, 30, 25, 24 | W, M |
| 1080p S    | 60, 50, 48, 30, 25, 24 | W |
| 1080p      | 60, 50, 48, 30, 25, 24 | N |
| 1080p      | 120, 60, 50, 48, 30, 25, 24 | W, M |
| 960p       | 100, 50 | W |
| 720p S     | 100, 60, 50    | W |
| 720p       | 240, 60, 50, 30, 25   | N |
| 720p       | 120, 60, 50, 30, 25 | W, M |
| WVGA       | 240    | W |

4K30 does not work well under daylight.

(Currently we don't have Hero 4 Silver in our lab. As soon as we borrow the camera from someone, we'll publish the table for Silver, too.)

# How To Update Iliad Software

MewPro Iliad uses Seeed Studio's Seeeduino Mega (Arduino Mega 2560 enhanced clone). We implemented these sync functionality to Arduino environment simply because it's very popular and very well-documented especially in entry-level tutorials.  So before asking something to us please google your question by yourself.

The following is a brief guide on how to update Iliad.

- Step 1. Download Arduino IDE from <https://www.arduino.cc/en/main/software>. For installation instructions please refer [the Getting Started page](https://www.arduino.cc/en/Guide/HomePage) in this same site.
- Step 2. Download Iliad source code from our GitHub repo <https://github.com/orangkucing/MewPro_Iliad>, and unzip it to some folder/directory.
- Step 3. Download the following Arduino libraries:
 * **IRremote library** at <https://github.com/z3t0/Arduino-IRremote>. (_Note: The IRremote library conflicts with RobotIRremote library in the standard Arduino IDE. So please delete_ "your IDE installation folder"_/Contents/Java/libraries/RobotIRremote_)
 * **RTClib** at <https://learn.adafruit.com/adafruit-ds3231-precision-rtc-breakout/wiring-and-test>.
- Step 4. Install the above downloaded libraries (To install Arduino Library please refer [this page](https://www.arduino.cc/en/Guide/Libraries)).
- Step 5. Compile Iliad source code and upload it to Seeeduino Mega. (In Arduino IDE, set [Tools]->[Board] to "Arduino/Genuino Mega or Mega 2560", [Tools]->[Processor] to "Atmega2560 (Mega 2560)", [Tools]->[Port] to your serial port that Seeeduino Mega is connected.)
- Step 6. Enjoy!

