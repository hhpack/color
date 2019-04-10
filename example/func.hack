#!/usr/bin/env hhvm

require_once __DIR__.'/../vendor/hh_autoload.hh';

use HHPack\Color as console;
use HHPack\Color\Color;
use HHPack\Color\ForegroundColor;
use HHPack\Color\BackgroundColor;
use HHPack\Color\StyleType;

<<__EntryPoint>>
function main(): noreturn {
  console\error("%s", "error");
  console\warn("%s", "warning");
  console\info("%s", "info");
  console\debug("%s", "debug");
  console\log("%s", "log");

  exit(0);
}
