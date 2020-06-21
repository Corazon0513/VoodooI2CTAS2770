//
//  VoodooI2CTAS2770Device.cpp
//  VoodooI2CTAS2770
//
//  Created by Hack_Jerry on 2020/6/5.
//  Copyright © 2020 Jerry Wong. All rights reserved.
//

#include "VoodooI2CTAS2770Device.hpp"

#define super IOService
OSDefineMetaClassAndStructors(VoodooI2CTAS2770Device, VoodooI2CControllerDriver);

VoodooI2CTAS2770Device :: VoodooI2CTAS2770Device(const uint8_t deviceI2cAddr)
{
    // this->_deviceI2cAddr = deviceI2cAddr;
    // For Debug
    this -> _deviceI2cAddr = 0x82;
    this -> _tas2770_activate_default();
}

bool VoodooI2CTAS2770Device :: init(OSDictionary* properties)
{
    bool ret = super::init(properties);
    bus_device.name = "TAS2770";
    _tas2770_activate_default();
    return ret;
}

bool VoodooI2CTAS2770Device :: _tas2770_activate_default()
{
    VoodooI2CControllerBusMessage command;
    
    uint8_t comList[36][3] =
    {
        {0x62, 0x00, 0x00},
        {0x62, 0x7f, 0x00},
        {0x62, 0x01, 0x01},
        
        {0x64, 0x00, 0x00},
        {0x64, 0x7f, 0x00},
        {0x64, 0x01, 0x01},
        
        {0x66, 0x00, 0x00},
        {0x66, 0x7f, 0x00},
        {0x66, 0x01, 0x01},
        
        {0x68, 0x00, 0x00},
        {0x68, 0x7f, 0x00},
        {0x68, 0x01, 0x01},
        
        {0x62, 0x3c, 0x11},
        {0x62, 0x0e, 0x33},
        {0x62, 0x0f, 0x42},
        {0x62, 0x10, 0x40},
        {0x62, 0x03, 0x14},
        {0x62, 0x02, 0x00},
        
        {0x64, 0x3c, 0x11},
        {0x64, 0x0e, 0x33},
        {0x64, 0x0f, 0x46},
        {0x64, 0x10, 0x44},
        {0x64, 0x03, 0x14},
        {0x64, 0x02, 0x00},
        
        {0x66, 0x3c, 0x11},
        {0x66, 0x0e, 0x33},
        {0x66, 0x0f, 0x4A},
        {0x66, 0x10, 0x48},
        {0x66, 0x03, 0x14},
        {0x66, 0x02, 0x00},
        
        {0x68, 0x3c, 0x11},
        {0x68, 0x0e, 0x33},
        {0x68, 0x0f, 0x4E},
        {0x68, 0x10, 0x4C},
        {0x68, 0x03, 0x14},
        {0x68, 0x02, 0x00},
    };
    for (int i = 0; i < 36; i++) {
        command.address = this->_deviceI2cAddr;
        command.buffer = *(comList + i);
        command.length = 3;
        if(transferI2C(&command, 1) != kIOReturnSuccess)
        {
            return false;
        }
    }
    return true;
}
