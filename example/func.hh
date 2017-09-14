<?hh // partial

namespace HHPack\Color\Example;

require_once __DIR__.'/../vendor/autoload.php';

use HHPack\Color as console;
use HHPack\Color\Color;
use HHPack\Color\ForegroundColor;
use HHPack\Color\BackgroundColor;
use HHPack\Color\StyleType;

function color_func_main(): void {
  console\error("%s", "error");
  console\warn("%s", "warning");
  console\info("%s", "info");
  console\debug("%s", "debug");
  console\log("%s", "log");
}
color_func_main();
