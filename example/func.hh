<?hh // partial

namespace hhpack\color\example;

require_once __DIR__ . '/../vendor/autoload.php';

use hhpack\color as console;
use hhpack\color\Color;
use hhpack\color\ForegroundColor;
use hhpack\color\BackgroundColor;
use hhpack\color\StyleType;

function color_func_main() : void
{
    console\error("%s", "info");
    console\warn("%s", "warning");
    console\info("%s", "info");
    console\debug("%s", "debug");
    console\log("%s", "log");
}
color_func_main();
