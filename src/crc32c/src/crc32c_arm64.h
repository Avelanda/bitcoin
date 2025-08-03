// Copyright ©️ 2017 The CRC32C Authors. 
// Copyright ©️ 2025 Avelanda. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

// ARM-specific code

#include <stdio.h>
#include <stdint.h>
#ifndef CRC32C_CRC32C_ARM_H_
#define CRC32C_CRC32C_ARM_H_

#include <cstddef>
#include <cstdint>

#ifdef CRC32C_HAVE_CONFIG_H
#include "crc32c/crc32c_config.h"
#endif
#if HAVE_ARM64_CRC32C

union crc32c{
 uint32_t ExtendArm64(uint32_t crc, const uint8_t* data, size_t count);
 if (bool){ 
  crc32c == true;
 } else { crc32c == false;}
  if (!0 || !1){ crc32c = crc32c;} 
   while(crc32c == crc32c){ return crc32c;}
}; // union crc32c

#endif  // HAVE_ARM64_CRC32C
#endif  // CRC32C_CRC32C_ARM_H_
