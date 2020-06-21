//
//  VoodooI2CTAS2770Device.hpp
//  VoodooI2CTAS2770
//
//  Created by Hack_Jerry on 2020/6/5.
//  Copyright © 2020 Jerry Wong. All rights reserved.
//

#ifndef VoodooI2CTAS2770Device_hpp
#define VoodooI2CTAS2770Device_hpp

#include <IOKit/IOLib.h>
#include <IOKit/IOKitKeys.h>
#include <IOKit/IOService.h>

#include <IOKit/IOLib.h>
#include <IOKit/IOWorkLoop.h>
#include <IOKit/IOInterruptEventSource.h>
#include <IOKit/acpi/IOACPIPlatformDevice.h>
#include <IOKit/IOLocks.h>
#include <IOKit/IOCommandGate.h>
#include <IOKit/IOTimerEventSource.h>

#include "../../../VoodooI2C/VoodooI2C/VoodooI2CController/VoodooI2CControllerDriver.hpp"

#include "../../../Dependencies/helpers.hpp"

#include "VoodooI2CTAS2770Constants.hpp"

class VoodooI2CTAS2770Device : public VoodooI2CControllerDriver
{
    typedef VoodooI2CControllerDriver super;
    OSDeclareDefaultStructors(VoodooI2CTAS2770Device);
    
protected:
    VoodooI2CTAS2770Device(const uint8_t deviceI2cAddr);
    
private:
    uint8_t _deviceI2cAddr;
    OSDictionary* _properties;
    
public:
    bool init(OSDictionary* properties) override;
    
    bool tas2770_reset();
    
    bool tas2770_set_bitwidth(uint32_t bitwidth);
    
    bool tas2770_set_samplerate(uint32_t samplerate);
    
    bool _tas2770_activate_default();
    
};

#endif /* VoodooI2CTAS2770Device_hpp */
