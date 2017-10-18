/**************************************************************************/
/*!
    @file     HAPLightBulb.cpp
    @author   hathach

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2017, Adafruit Industries (adafruit.com)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/

#include <bluefruit.h>
#include "HAPUuid.h"
#include "HAPLightBulb.h"

HAPLightBulb::HAPLightBulb(void)
  : HAPService(HAP_UUID_SVC_LIGHT_BULB), _on(HAP_UUID_CHR_ON, BLE_GATT_CPF_FORMAT_BOOLEAN)
{

}

err_t HAPLightBulb::begin(void)
{
  VERIFY_STATUS( HAPService::begin() ); // Invoke base class begin()

  // ON char
  _on.setHapProperties(HAP_CHR_PROPS_SECURE_READ | HAP_CHR_PROPS_SECURE_WRITE | HAP_CHR_PROPS_NOTIFY );
  _on.setPermission(SECMODE_OPEN, SECMODE_OPEN);
  _on.setFixedLen(1);
  VERIFY_STATUS( _on.begin() );
  _on.write( (uint8_t) 0x00 );

  return ERROR_NONE;
}
