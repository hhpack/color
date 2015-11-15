# -*- coding: utf-8 -*-

from subprocess import call
from sys import exit

PROGRAM = 'hh_client'

def restart():
  return call([ PROGRAM, 'restart' ])

def check():
  return call([ PROGRAM, 'check' ])

if __name__ == '__main__':
  for command in [ restart, check ]:
    exit_code = command()
    if exit_code != 0:
      break
  exit(exit_code)
