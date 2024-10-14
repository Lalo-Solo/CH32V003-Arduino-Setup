# CH32V003-Arduino-Setup
Instructions to setup Arduino to code for CH32V003 microcontroller

# Context
Since the release of libraries to code for Microchips from **WCH** (https://www.wch-ic.com/) on Arduino IDE, populatity of the MCU has increased, however that doesn't mean that all the power of the microchip is fully available seamless as any ardunio board.

# Prerequisites
For this example to work you need:
1. A recent version of Arduino IDE installed (2.2.0 or newer).
2. Arduino core support for CH32 EVT Boards (version 1.0.4 or newer)
3. A development board for the CH32V003 MCU (a protoboard version could work as well)
4. WCH-LinkE Programmer to load code into the MCU.
5. It is also recommended to have some wires (DuPount are the recommended ones).

This repository will no explain how to install Ardunio IDE nor the libary for CH32 EVT baords, since instructions are publicly available.

# Hardware Setup
Connections are very simple, the key is to have available all prerequisites listed above.

The **Development Board** is the most recommended way to learn and develop code for this MCU.

## Attaching the LinkE Programmer
First, connect the LinkE to the chip depending on your own available hardware.

Follow this diagram with some DuPont wires.

![Connection to the Development Board](assets/Connections%20-%20DevBoard.jpg)


## Attaching the chip
Of course it is not possible to attach anything directly to the chip, however, it's good to know how would be done it that was possible.

![Connection to the Development Board](assets/Connections%20-%2020%20pin.jpg)

After connections are done, the final connection is the LinkE to the computer, that should be the last step to prevent from making any short-circuit on the USB port.

# Configure Ardunio IDE
In Arduino, there should be an indication to the IDE about the board being used.
That is made from menu "Tools" and following throug menus as seen in the image.

If menus are not available as seen in the image, this means that the `core support` for CH32 EVT Boards is missing, and must be installed first.
![Arduino Configuration](assets/Arduino%20Board%20Config.jpg)

(text)
![Arduino Serial Configuration](assets/Arduino%20Serial%20Configuration.jpg)

# Testing the compiling and loading

# The Code
Code is aligned with the Fast Flash mode to write into Flash, there is another mode, which is the standard, however that one is not covered here.
It includes optional lines to `DEBUG` with output to the Serial Monitor of IDE.

By the time of this release, it includes only the writing of an `integer` (16 bits), and and array of up to 16 integers.

It uses a page of 64 bytes located at the end of the flash memory segment, which is shared with the code.

The functions perform a test to confirm that data written matches with the intended data to be stored.

## Steps
Include the library from the `core support` to take advantage of definitions and functions already available.
* **Step 1**: Unlock access to Flash memory
* **Step 2**: Erase block of flash memory (64 bytes, all with zeros) startig at ADDR1 base location
* **Step 3**: Reset internal buffer that will recive data to be written
* **Step 4**: Load page (16 x 4 bytes) to be written into internal buffer
* **Step 5**: Write the whole page into Flash memory, starting at ADDR1 location
* **Step 6**: Lock access to Flash memory
* **Step 7**: Verify that bytes that were written into Flash memory matches the original input data
  
# Download Links
