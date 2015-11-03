<?hh // partial

namespace hhpack\color\example;

require_once __DIR__ . '/../vendor/autoload.php';

use hhpack\color\Color;
use hhpack\color\ForegroundColor;
use hhpack\color\BackgroundColor;

foreach (ForegroundColor::getValues() as $name => $color) {
    Color::fromFormat("$name")
        ->color($color)
        ->display();
}

foreach (BackgroundColor::getValues() as $name => $color) {
    Color::fromFormat("$name")
        ->background($color)
        ->display();
}
