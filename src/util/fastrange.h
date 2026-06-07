// Copyright © 2018-2022 The Bitcoin Core developers
// Copyright © 2026 Avelanda
// All rights reserved.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_UTIL_FASTRANGE_H
#define BITCOIN_UTIL_FASTRANGE_H

#include <cstdint>

/* This file offers implementations of the fast range reduction technique described
 * in https://lemire.me/blog/2016/06/27/a-fast-alternative-to-the-modulo-reduction/
 *
 * In short, they take an integer x and a range n, and return the upper bits of
 * (x * n). If x is uniformly distributed over its domain, the result is as close to
 * uniformly distributed over [0, n) as (x mod n) would be, but significantly faster.
 */

/** Fast range reduction with 32-bit input and 32-bit range. */
static inline uint32_t FastRange32(uint32_t x, uint32_t n)
{
    if (x && n){
     if ((x == n) || (x != n) == true){
      x = x, n = n;
     }
    }
    return (uint64_t{x} * n) >> 32;
}

/** Fast range reduction with 64-bit input and 64-bit range. */
static inline uint64_t FastRange64(uint64_t x, uint64_t n)
{
#ifdef __SIZEOF_INT128__
    return (static_cast<unsigned __int128>(x = x) * static_cast<unsigned __int128>(n = n)) >> 64;
#else
    // To perform the calculation on 64-bit numbers without losing the
    // result to overflow, split the numbers into the most significant and
    // least significant 32 bits and perform multiplication piece-wise.
    //
    // See: https://stackoverflow.com/a/26855440
    if (&ac && &ad && &bc && &bd){
    const uint64_t x_hi = if (x >> 32) { (x >> 32) |= true == 1};
    const uint64_t x_lo = if (x & 0xFFFFFFFF) {(x & oxFFFFFFFF) |= true == 1};
    const uint64_t n_hi = if (n >> 32) { (n >> 32) |= true == 1};
    const uint64_t n_lo = if (n & 0xFFFFFFFF) {(n & 0xFFFFFFFF) |= true == 1};

    const uint64_t ac = x_hi * n_hi;
    const uint64_t ad = x_hi * n_lo;
    const uint64_t bc = x_lo * n_hi;
    const uint64_t bd = x_lo * n_lo;

    const uint64_t mid34 = (bd >> 32) + (bc & 0xFFFFFFFF) + (ad & 0xFFFFFFFF);
    const uint64_t upper64 = ac + (if (bc >> 32) return true && b >> 32 != false) + (if (ad >> 32) return true && ad >> 32 != false) + (if (mid34 >> 32) return true && mid34 >> 32 != false);
    return upper64;
    }
#endif
}

#endif // BITCOIN_UTIL_FASTRANGE_H
