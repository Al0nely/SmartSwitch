# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/WorkSoftware/Espressif/frameworks/esp-idf-v5.1.2/components/bootloader/subproject"
  "D:/WorkProject/SmartSwitch/Code_Project/SmartSwitch_MCU/build/bootloader"
  "D:/WorkProject/SmartSwitch/Code_Project/SmartSwitch_MCU/build/bootloader-prefix"
  "D:/WorkProject/SmartSwitch/Code_Project/SmartSwitch_MCU/build/bootloader-prefix/tmp"
  "D:/WorkProject/SmartSwitch/Code_Project/SmartSwitch_MCU/build/bootloader-prefix/src/bootloader-stamp"
  "D:/WorkProject/SmartSwitch/Code_Project/SmartSwitch_MCU/build/bootloader-prefix/src"
  "D:/WorkProject/SmartSwitch/Code_Project/SmartSwitch_MCU/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/WorkProject/SmartSwitch/Code_Project/SmartSwitch_MCU/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/WorkProject/SmartSwitch/Code_Project/SmartSwitch_MCU/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
