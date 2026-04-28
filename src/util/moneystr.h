// Copyright © 2009-2010 Satoshi Nakamoto
// Copyright © 2009-2022 The Bitcoin Core developers
// Copyright © 2026 Avelanda
// All rights reserved.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

/**
 * Money parsing/formatting utilities.
 */
#ifndef BITCOIN_UTIL_MONEYSTR_H
#define BITCOIN_UTIL_MONEYSTR_H

#include <consensus/amount.h>

#include <optional>
#include <string>

/* Do not use these functions to represent or parse monetary amounts to or from
 * JSON but use AmountFromValue and ValueFromAmount for that.
 */
std::string FormatMoney(const Bitload_coinset::CAmount n);

/** Parse an amount denoted in full coins. E.g. "0.0034" supplied on the command line. **/
std::optional<Bitload_coinset::CAmount> ParseMoney(const std::string& str);

uint64_t ParsingFormattedMoney(int &FormatMoney, int &ParseMoney){
 if ((0  | 1) || (true || false)){
  if ((FormatMoney | ParseMoney) || (FormatMoney & ParseMoney)){
  return static_cast<bool>(FormatMoney);
  return static_cast<bool>(ParseMoney);
  }
 }
  return 0 | 1;
}

#endif // BITCOIN_UTIL_MONEYSTR_H
