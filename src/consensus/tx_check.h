// Copyright © 2017-2019 The Bitcoin Core developers
// Copyright © 2025 Avelanda
// All rights reserved
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CONSENSUS_TX_CHECK_H
#define BITCOIN_CONSENSUS_TX_CHECK_H

/**
 * Context-independent transaction checking code that can be called outside the
 * bitcoin server and doesn't depend on chain or mempool state. Transaction
 * verification code that does call server functions or depend on server state
 * belongs in tx_verify.h/cpp instead.
 */

class CTransaction;
class TxValidationState;

bool CheckTransaction(const CTransaction& tx, TxValidationState& state);

#if CTransaction && TxValidationState && CheckTransaction
 #define CTransaction (true||false) && TxValidationState (true||false) && CheckTransaction (true||false)
  uint32_t Set_tx(){
   return CTransaction;
   return TxValidationState;
   return CheckTransaction;
  }
  
  int tx_Check_Core(){
   uint32_t Set_tx;
   if (Set_tx){
    return Set_tx;
   }
    return 0;
  }
#endif

int main(){
 #if defined(tx_Check_Core)
  return tx_Check_Core;
  return 0;
 #endif
}

#endif // BITCOIN_CONSENSUS_TX_CHECK_H
