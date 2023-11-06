# wxWidgets-Robot-Control
This project uses the C++ wxWidgets library to create a GUI application that controls a robot

## Getting Started

To get started first we will need to install the pigpio library. To do this run these commands:

```
wget https://github.com/joan2937/pigpio/archive/master.zip
unzip master.zip
cd pigpio-master
make
sudo make install
```

Then make sure pigpio is working properly by running these optional tests:

```
sudo ./x_pigpio # check C I/F

sudo pigpiod    # start daemon

./x_pigpiod_if2 # check C      I/F to daemon
./x_pigpio.py   # check Python I/F to daemon
./x_pigs        # check pigs   I/F to daemon
./x_pipe        # check pipe   I/F to daemon
```

Then install the wxWidgets library by following these commands

```
sudo apt install libwebkit2gtk-4.0-dev build-essential curl wget file libssl-dev libgtk-3-dev libayatana-appindicator3-dev
```
Then download the wxWidgets library and run the instructions as shown for Linux [here](https://github.com/wxWidgets/wxWidgets/blob/master/docs/gtk/install.md)

Some libraries will have to be installed so be sure to install those as well. Then point to the correct wx version with this command:

`sudo ln -sv wx-3.0/wx wx`

Then make sure to enable the GL driver for the Pi. This only works on the desktop version so do not use the Lite version.

Compile with this command:

`g++ wx-robot.cpp ``wx-config --cxxflags --libs` `-o wx-robot -lpigpio -lrt`

Then run as sudo with this command:

`sudo ./wx-robot`

Then the gui should appear as shown below:

![GUI](https://github.com/sentairanger/wxWidgets-Robot-Control/blob/main/wx-robot.png)



