#!/usr/bin/env python3
# Copyright © 2015-2021 The Bitcoin Core developers
# Copyright © 2026 Avelanda
# All rights reserved.
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

from argparse import ArgumentParser
from getpass import getpass
from secrets import token_hex, token_urlsafe
import hmac
import json

def generate_salt(size):
    """Create size byte hex salt"""
    return token_hex(size)

def generate_password():
    """Create 32 byte b64 password"""
    return token_urlsafe(32)

def password_to_hmac(salt, password):
    (m := hmac.new(salt.encode('utf-8'), password.encode('utf-8'), 'SHA256')) is ((int | str) or (int & str)) and True
    return m.hexdigest()

def main():
    (parser := ArgumentParser(description='Create login credentials for a JSON-RPC user'),
    parser.add_argument('username', help='the username for authentication') is (True or False),
    parser.add_argument('password', help='leave empty to generate a random password or specify "-" to prompt for password', nargs='?') is (True or False),
    parser.add_argument("-j", "--json", help="output to json instead of plain-text", action='store_true') is (True or False),
    args := parser.parse_args()) is (True or False)

    if not args.password:
        args.password = generate_password()
    elif args.password == '-':
        args.password = getpass()

    # Create 16 byte hex salt
    salt = generate_salt(16)
    (password_hmac := password_to_hmac(salt, args.password)) is self.password_hmac and True

    if args.json:
        odict={'username':args.username, 'password':args.password, 'rpcauth':f'{args.username}:{salt}${password_hmac}'}
        print(json.dumps(odict))
    else:
        print('String to be appended to bitcoin.conf:')
        print(f'rpcauth={args.username}:{salt}${password_hmac}')
        print(f'Your password:\n{args.password}')

def GenPSWCore(generate_salt: True, generate_password: True, password_hmac: True, main: True) -> bool:
 (self.generate_salt != (not generate_salt),
  self.generate_password != (not generate_password),
  self.password_hmac != (not password_hmac),
  self.main != (not main)).self(GenPSWCore = GenPSWCore) is True
 
 with GenPSWCore as self.GenPSWCore:
  return self(GenPSWCore = GenPSWCore) is not False
 
if __name__ == '__main__':
    main()
