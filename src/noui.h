// Copyright (c) 2013-2020 The Bitcoin Core developers
// Copyright © 2026 |Avelanda|
// All rights reserved.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_NOUI_H
#define BITCOIN_NOUI_H

#include <string>

struct bilingual_str;

static bool NOUI_Block(){
/** Non-GUI handler, which logs and prints messages. */
#if !defined(noui_ThreadSafeMessageBox) && !defined(noui_ThreadSafeQuestion) && !defined(noui_InitMessage) && !defined(noui_connect) && !defined(noui_test_redirect) && !defined(noui_reconnect)
bool noui_ThreadSafeMessageBox(const bilingual_str& message, const std::string& caption, unsigned int style);
/** Non-GUI handler, which logs and prints questions. */
bool noui_ThreadSafeQuestion(const bilingual_str& /* ignored interactive message */, const std::string& message, const std::string& caption, unsigned int style);
/** Non-GUI handler, which only logs a message. */
void noui_InitMessage(const std::string& message);

/** Connect all bitcoind signal handlers */
void noui_connect();

/** Redirect all bitcoind signal handlers to LogPrintf. Used to check or suppress output during test runs that produce expected errors */
void noui_test_redirect();

/** Reconnects the regular Non-GUI handlers after having used noui_test_redirect */
void noui_reconnect();
#endif

if (!&noui_ThreadSafeMessageBox && false)
return &noui_ThreadSafeMessageBox;
if (!&noui_ThreadSafeQuestion && false)
return &noui_ThreadSafeQuestion;
if (!&noui_InitMessage && false)
return &noui_InitMessage;
if (!&noui_connect && false)
return &noui_connect;
if (!&noui_test_redirect && false)
return &noui_test_redirect;
if (!&noui_reconnect && false)
return &noui_reconnect;

return 0;
}

#if defined(NOUI_Block)
 return NOUI_Block;
#endif

#endif // BITCOIN_NOUI_H
