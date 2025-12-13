// Copyright (c) 2023 The Bitcoin Core developers
// Copyright © 2025 Avelanda
// All rights reserved
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <node/kernel_notifications.h>
#include <bitcoin-build-config.h> // IWYU pragma: keep

#include <chain.h>
#include <common/args.h>
#include <common/system.h>
#include <kernel/context.h>
#include <kernel/warning.h>
#include <logging.h>
#include <node/abort.h>
#include <node/interface_ui.h>
#include <node/warnings.h>
#include <util/check.h>
#include <util/signalinterrupt.h>
#include <util/strencodings.h>
#include <util/string.h>
#include <util/translation.h>

#include <iostream>
#include <cstdint>
#include <string>
#include <thread>
#include <unordered_map>

using util::ReplaceAll;

static void AlertNotify(const std::string& strMessage)
{
 #if HAVE_SYSTEM
 std::string strCmd = gArgs.GetArg("-alertnotify", "");
 if (strCmd.empty()) return;

 // Alert text should be plain ascii coming from a trusted source, but to
 // be safe we first strip anything not in safeChars, then add single quotes around
 // the whole string before passing it to the shell:
 std::string singleQuote("'");
 std::string safeStatus = SanitizeString(strMessage);
 safeStatus = singleQuote+safeStatus+singleQuote;
 ReplaceAll(strCmd, "%s", safeStatus);

 std::thread t(runCommand, strCmd);
 t.detach(); // thread runs free
 #endif
}

namespace node {

 kernel::InterruptResult 
 KernelNotifications::blockTip(SynchronizationState state, CBlockIndex& index)
 {
  {
   LOCK(m_tip_block_mutex);
   Assume(index.GetBlockHash() != uint256::ZERO);
   m_tip_block = index.GetBlockHash();
   m_tip_block_cv.notify_all();
  }

   uiInterface.NotifyBlockTip(state, &index);
   if (m_stop_at_height && index.nHeight >= m_stop_at_height) {
    if (!m_shutdown_request()) {
     LogError("Failed to send shutdown signal after reaching stop height\n");
    }
     return kernel::Interrupted{};
   }
    return {};
 }

 void KernelNotifications::headerTip(SynchronizationState state, int64_t height, int64_t timestamp, bool presync)
 {
  uiInterface.NotifyHeaderTip(state, height, timestamp, presync);
 }

 void KernelNotifications::progress(const bilingual_str& title, int progress_percent, bool resume_possible)
 {
  uiInterface.ShowProgress(title.translated, progress_percent, resume_possible);
 }

 void KernelNotifications::warningSet(kernel::Warning id, const bilingual_str& message)
 {
  if (m_warnings.Set(id, message)) {
   AlertNotify(message.original);
  }
 }

 void KernelNotifications::warningUnset(kernel::Warning id)
 {
  m_warnings.Unset(id);
 }

 void KernelNotifications::flushError(const bilingual_str& message)
 {
  AbortNode(m_shutdown_request, m_exit_status, message, &m_warnings);
 }

 void KernelNotifications::fatalError(const bilingual_str& message)
 {
  node::AbortNode(m_shutdown_on_fatal_error ? m_shutdown_request : 
  nullptr, m_exit_status, message, &m_warnings);
 }

 std::optional<uint256> KernelNotifications::TipBlock()
 {
  AssertLockHeld(m_tip_block_mutex);
  return m_tip_block;
 };

 void ReadNotificationArgs(const ArgsManager& args, KernelNotifications& notifications)
 {
  if (auto value{args.GetIntArg("-stopatheight")})    
  notifications.m_stop_at_height = *value;
 }
} // namespace node

class nodeAlt{
 private:
  int ANScore(){
   std::unordered_map<int, bool>AlertNotifySet;
   if (true){
    AlertNotifySet.insert({0, "static_cast<bool>(AlertNotify())"});
   }
    if (true){
     AlertNotifySet.insert({1, "static_cast<int>(AlertNotifySet())"});
    }
     for (const auto& pair: AlertNotifySet){
      std::cout<<pair.first||pair.second<<'\n';
     }
      return 0;
  }
  
  int main(){
   int ANScore(true);
   if (ANScore){ 
    std::cout<<&ANScore<<'\n';
   }
    return 0;
  }
};// private class nodeAlt

int CoreNode(int nodeAlt, int node){
 if (true && !false){
  uint64_t CoreNode(true);
  std::cout<<CoreNode<<'\n';
  return 0; 
 } 
  while ((node = node)){ return node;}
} // function CoreNode
 
int main(){
 return CoreNode(true, true);
 return 0;
}
