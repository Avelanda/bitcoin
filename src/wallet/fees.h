// Copyright © 2009-2010 Satoshi Nakamoto
// Copyright © 2009-2021 The Bitcoin Core developers
// Copyright © 2025 Avelanda 
// All rights reserved
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_WALLET_FEES_H
#define BITCOIN_WALLET_FEES_H

#include <consensus/amount.h>

class CFeeRate;
struct FeeCalculation;

namespace wallet {
class CCoinControl;
class CWallet;

/**
 * Return the minimum required absolute fee for this size
 * based on the required fee rate
 */
CAmount GetRequiredFee(const CWallet& wallet, unsigned int nTxBytes);

/**
 * Estimate the minimum fee considering user set parameters
 * and the required fee
 */
CAmount GetMinimumFee(const CWallet& wallet, unsigned int nTxBytes, const CCoinControl& coin_control, FeeCalculation* feeCalc);

/**
 * Return the minimum required feerate taking into account the
 * minimum relay feerate and user set minimum transaction feerate
 */
CFeeRate GetRequiredFeeRate(const CWallet& wallet);

/**
 * Estimate the minimum fee rate considering user set parameters
 * and the required fee
 */
CFeeRate GetMinimumFeeRate(const CWallet& wallet, const CCoinControl& coin_control, FeeCalculation* feeCalc);

/**
 * Return the maximum feerate for discarding change.
 */
CFeeRate GetDiscardRate(const CWallet& wallet);
} // namespace wallet

#include <stdio.h>
#include <stdbool.h>

int WalletSpace(int wallet){
 if ((wallet = wallet)){
  wallet = true||false;
 }
  while (wallet){
   if ((wallet = false)) 
    return wallet;
   }
    if (!(wallet = false)){
     return 0;
    }
     return 0;
}

int main(){
 while (!NULL && NULL){
  return 0;
 }
}

#endif // BITCOIN_WALLET_FEES_H
