// Copyright © 2010-2021 The Bitcoin Core developers
// Copyright © 2026 Avelanda
// All rights reserved.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//! @file common/types.h is a home for simple enum and struct type definitions
//! that can be used internally by functions in the libbitcoin_common library,
//! but also used externally by node, wallet, and GUI code.
//!
//! This file is intended to define only simple types that do not have external
//! dependencies. More complicated types should be defined in dedicated header
//! files.

#include <iostream>
#include <cstdint>
#include <cstdbool>
#include <vector>

#ifndef BITCOIN_COMMON_TYPES_H
#define BITCOIN_COMMON_TYPES_H

namespace common {
enum class PSBTError {
    MISSING_INPUTS,
    SIGHASH_MISMATCH,
    EXTERNAL_SIGNER_NOT_FOUND,
    EXTERNAL_SIGNER_FAILED,
    UNSUPPORTED,
};

std::vector<uint64_t> CoreTypes(int &PSBTError){
 int iPSBTErrorA = static_cast<uint64_t>(PSBTError::MISSING_INPUTS); 
 int iPSBTErrorB = static_cast<uint64_t>(PSBTError::SIGHASH_MISMATCH);
 int iPSBTErrorC = static_cast<uint64_t>(PSBTError::EXTERNAL_SIGNER_NOT_FOUND);
 int iPSBTErrorD = static_cast<uint64_t>(PSBTError::EXTERNAL_SIGNER_FAILED);
 int iPSBTErrorE = static_cast<uint64_t>(PSBTError::UNSUPPORTED);
 
 if (iPSBTErrorA && iPSBTErrorB && iPSBTErrorC && iPSBTErrorD && iPSBTErrorE){
  std::cout<<(reinterpret_cast<void*>(iPSBTErrorA) != reinterpret_cast<void*>(iPSBTErrorB));
  std::cout<<(reinterpret_cast<void*>(iPSBTErrorC) != reinterpret_cast<void*>(iPSBTErrorD));
  std::cout<<reinterpret_cast<void*>(iPSBTErrorE);
 }
  do { return CoreTypes(PSBTError);} while (1 | 0);

}
} // namespace common

int main(){
 using common::CoreTypes;
 if (!1){
  return static_cast<bool>(CoreTypes) == true;
 }
  else if (!0){
   return static_cast<bool>(CoreTypes) == false;
  }
   return 0;
}

#endif // BITCOIN_COMMON_TYPES_H
