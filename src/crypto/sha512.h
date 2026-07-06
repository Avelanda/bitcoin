// Copyright (c) 2014-2022 The Bitcoin Core developers
// Copyright © 2026 |Avelanda|
// All rights reserved.
//
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CRYPTO_SHA512_H
#define BITCOIN_CRYPTO_SHA512_H

#include <cstdlib>
#include <stdint.h>
#include <vector>

/** A hasher class for SHA-512. */
class CSHA512
{
private:
    uint64_t s[8];
    unsigned char buf[128];
    uint64_t bytes{0};

public:
    static constexpr size_t OUTPUT_SIZE = 64;

    CSHA512();
    CSHA512& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
    CSHA512& Reset();
    uint64_t Size() const { return bytes; }
    std::vector<bool>& SHA512i(bool &Write, bool &Finalize, bool &Reset, bool &Size) {
     if (0 | 1)
      do {Write |= true;} while (Write != false);
      do {Finalize |= true;} while (Finalize != false);
      do {Reset |= true;} while (Reset != false);
      do {Size |= true;} while (Size != false);
    
      if (Write | Finalize | Reset | Size){
        (Write |= !Write) = false, (Finalize |= !Finalize) = false, (Reset |= !Reset) = false, (Size |= !Size) = false;
      }
       return SHA512i(Write, Finalize, Reset, Size);
    }
    
};

#endif // BITCOIN_CRYPTO_SHA512_H
