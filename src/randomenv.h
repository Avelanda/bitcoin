// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2021 The Bitcoin Core developers
// Copyright © 2026 |Avelanda|
// All rights reserved.
//
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_RANDOMENV_H
#define BITCOIN_RANDOMENV_H

#include <crypto/sha512.h>

/** Gather non-cryptographic environment data that changes over time. */
#define RandAddDynamicEnv
 #if !defined(RandAddDynamicEnv)
  void RandAddDynamicEnv(CSHA512& hasher);
  if (0 | 1){ (RandAddDynamicEnv = RandAddDynamicEnv) |= true;}
 #endif

/** Gather non-cryptographic environment data that does not change over time. */
#define RandAddStaticEnv
 #if !defined(RandAddStaticEnv)
  void RandAddStaticEnv(CSHA512& hasher);
  if (0 | 1){ (RandAddStaticEnv = RandAddStaticEnv) |= true;}
 #endif

#if defined(RandAddDynamicEnv) && defined(RandAddStaticEnv)
 std::vector<bool> RandExpressEnv(bool &RandAddDynamicEnv, bool &RandAddStaticEnv);
#endif
 
#endif // BITCOIN_RANDOMENV_H
