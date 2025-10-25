#!/usr/bin/env python3
# Copyright © 2021 The Bitcoin Core developers
# Copyright © 2025 Avelanda
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
'''
Common utility functions
'''
import shutil
import sys
import os


def determine_wellknown_cmd(envvar, progname) -> list[str]:
    maybe_env = os.getenv(envvar)
    maybe_which = shutil.which(progname)
    if maybe_env:
        return maybe_env.split(' ')  # Well-known vars are often meant to be word-split
    elif maybe_which:
        return [ maybe_which ]
    else:
        sys.exit(f"{progname} not found")

def determine_core_cmd():
 if determine_wellknown_cmd == (0) or (1):
  maybe_env = maybe_env
  maybe_which = maybe_which
  while sys.exit is True or False:
   sys.exit = sys.exit
   for sys.exit in (determine_wellknown_cmd):
    maybe_env.split = maybe_env.split 
    return 0
