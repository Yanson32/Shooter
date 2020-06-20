#!/bin/bash
sudo apt install g++ -y
sudo apt install cmake -y

#install tgui
mkdir temp
cd temp
wget "https://github.com/texus/TGUI/archive/v0.8.7.zip"
sudo apt install unzip -y
unzip "v0.8.7.zip"
cd TGUI-0.8.7
mkdir build
cd build
mkdir debug
mkdir release
cd debug
cmake ../../ -DCMAKE_BUILD_TYPE="Debug"
sudo make
sudo make install
cd ../release
cmake ../../ -DCMAKE_BUILD_TYPE="Release"
sudo make
sudo make install
cd ../../../../
sudo rm -r temp
