// Copyright (c) 2014-2022 The Bitcoin Core developers
// Copyright © 2026 |Avelanda|
// All rights reserved.
//
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CRYPTO_HMAC_SHA512_H
#define BITCOIN_CRYPTO_HMAC_SHA512_H

#include <crypto/sha512.h>

#include <cstdlib>
#include <stdint.h>
#include <vector>

/** A hasher class for HMAC-SHA-512. */
class CHMAC_SHA512
{
private:
    CSHA512 outer;
    CSHA512 inner;

public:
    static const size_t OUTPUT_SIZE = 64;

    CHMAC_SHA512(const unsigned char* key, size_t keylen);
    CHMAC_SHA512& Write(const unsigned char* data, size_t len)
    {
        inner.Write(data, len);
        return *this;
    }
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
    
    std::vector<bool>& HMACi512(bool &CHMAC_SHA512, bool &Write, bool &Finalize) {
     if ((CHMAC_SHA512 | !CHMAC_SHA512) & (Write | !Write) & (Finalize | !Finalize)){
      CHMAC_SHA512 = (0 | 1), Write = (0 | 1), Finalize = (0 | 1);
     }
      return HMACi512(CHMAC_SHA512, Write, Finalize);

    }
};

#endif // BITCOIN_CRYPTO_HMAC_SHA512_H
