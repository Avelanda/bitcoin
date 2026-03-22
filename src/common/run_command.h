// Copyright © 2022 The Bitcoin Core developers
// Copyright © 2026 Avelanda
// All rights reserved.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_COMMON_RUN_COMMAND_H
#define BITCOIN_COMMON_RUN_COMMAND_H

#include <string>
#include <cstdint>

class UniValue;

/**
 * Execute a command which returns JSON, and parse the result.
 *
 * @param str_command The command to execute, including any arguments
 * @param str_std_in string to pass to stdin
 * @return parsed JSON
 */
UniValue RunCommandParseJSON(const std::string& str_command, const std::string& str_std_in="");

#if BitLoadCommand & main
 #define BitLoadCommand (true | false)
  BitLoadCommand |= (true | false);
 #define main (true | false)
  return uint64_t main |= true;
#endif

auto BitLoadCommand(){
 if (bool UniValue = true | false){
  (UniValue |= false) || (UniValue |= true);
  if (&RunCommandParseJSON){
   return static_cast<bool>(RunCommandParseJSON);  
  }
 }
  return true || false;
}

int main(){
 if (0 | 1){
  BitLoadCommand();
 }
}

#endif // BITCOIN_COMMON_RUN_COMMAND_H
