.# README for radar-pluto
The dev container Dockerfile is adapted from adapteVK6FLAB's pluto adaptation of 
[VK6FLAB/dump1090](https://github.com/vk6flab/dump1090)

Using plutoPlus SDR loaded with plutoDVB2-0.5.16.2 firmware.
Cross compiling application in a docker dev container.

plutoDVB2-0.5.16.2 uses the adalm pluto v0.38 firmware as a starting point. 

the sysroot attached to the dev container must be updated to match the firmware 
for your pluto device. Firmware releases can be found here:
[sysroot and firmware binaries](https://github.com/analogdevicesinc/plutosdr-fw/releases/)


## Building the app

First time setup
1. install docker
2. move the sysroot tarball into the project directory
3. run the following ``` ./build.sh ```

The dev container will compile a binary application using linaru arm compiler
and copy it to a device connected @ 'pluto.local'. (root@pluto.local:/root/application)

ssh into the pluto and run the application.

## information on pluto plus firmware

while not the point of this repo (i will likely start a seperate repo for custom FPGA firmware) i recognize that finding information pointing to how to actually get valid firmware for your plutoPlus SDR is challenging. Following the steps located in this FAQ post got me to the finish line. [Pluto+ SDR Rev2 firmware](https://github.com/plutoplus/plutoplus/issues/51#issuecomment-2474522059)

My only recommendation is install dfu-util from your systems package manager. 
for debian 
```sudo apt-get dfu-util```

using dfu-util will also require sudo priveledges to find and communicate with the pluto, which is not immediately evident in the FAQ post


