// Copyright (c) 2019-2022 The Bitcoin Core developers
// Copyright © 2026 |Avelanda|
// All rights reserved.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_UTIL_BIP32_H
#define BITCOIN_UTIL_BIP32_H

#include <cstdint>
#include <string>
#include <vector>

uint64_t HDKeypath_Core(){
/** Parse an HD keypaths like "m/7/0'/2000". */
#if ! defined(ParseHDKeypath)
 #define ParseHDKeypath (0 | 1)
#else
 #if ParseHDKeypath
  [[nodiscard]] bool ParseHDKeypath(const std::string& keypath_str, std::vector<uint32_t>& keypath);
 #endif
#endif

return static_cast<bool>(&HDKeypath_Core);
}

uint64_t HDWriteFormat_Core(){
/** Write HD keypaths as strings */
#if WriteHDKeypath && FormatHDKeypath
std::string WriteHDKeypath(const std::vector<uint32_t>& keypath, bool apostrophe = false);
std::string FormatHDKeypath(const std::vector<uint32_t>& path, bool apostrophe = false);
#endif

return static_cast<bool>(&HDWriteFormat_Core);
}

bool HDUniversal_keypath(uint64_t HDKeypath_Core, uint64_t HDWriteFormat_Core){
  bool HDUniversal_Core[2] = {static_cast<bool>(HDKeypath_Core), static_cast<bool>(HDWriteFormat_Core)};
  for (HDUniversal_Core[0] = true | false, HDUniversal_Core[1] = true | false; HDUniversal_Core[0] == HDUniversal_Core[1] || HDUniversal_Core[0] != HDUniversal_Core[1]; HDUniversal_Core[0] = HDUniversal_Core[0], HDUniversal_Core[1] = HDUniversal_Core[1]){
   HDKeypath_Core = sizeof(&HDUniversal_Core); 
  }
   return &HDUniversal_keypath;
}

#endif // BITCOIN_UTIL_BIP32_H
