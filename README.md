# Introduction
This is a basic FreeRTOS application on Raspberry Pi Pico.
Two tasks are running:
- A slow task: a message is printed to stdout every 1 second.
- A fast task: the onboard led of the Raspberry Pi Pico board blinks at 5 Hz.

Hardware:
- Raspberry Pi Pico board
- Micro-USB cable

# Prerequisite
- Install CMake and the Pico SDK toolchain. Please follow the instructions of "Chapter 2. The SDK" from this document: [Getting started with Raspberry Pi Pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)
- Install a tool allowing to get serial data coming from the Raspberry Pi Pico board. For instance:
    - On Ubuntu: minicom (used in this demo)<br>
    `sudo apt update`<br>
    `sudo apt install minicom`

    - On both Ubuntu and Windows: [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html)

# Setup
Execute *setup.sh* to: setup the project, pull the FreeRTOS kernel and make a first build.
`./setup.sh`

# Build
If changes are made to the code, go to *build* folder and type <br>
`make`<br>
or<br>
`make -j4`<br>
for faster build.

# Deploy
- Unplug the Micro-USB cable
- Press the *BOOTSEL* button on the Raspberry Pi Pico board
- Plug the Micro-USB cable
- Release the *BOOTSEL* button on the Raspberry Pi Pico board
- Copy *rp2040_freertos_demo.uf2* (in *build* folder) to the Raspberry Pi Pico board (actually behaving as a mass storage). <br>
On Ubuntu: `cp rp2040_freertos_demo.uf2 /media/*username*/RPI-RP2/`

# The demo
- The fast task should be easily verified: the led on the Raspberry Pi Pico board should be blinking at 5 Hz.
- To see messages from the slow task, run<br>
`sudo minicom -b 115200 -D /dev/ttyACM0`<br>
To exit minicom: CTRL-A then X then ENTER