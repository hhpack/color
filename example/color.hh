<?hh // partial

namespace hhpack\color\example;

require_once __DIR__ . '/../vendor/autoload.php';

use hhpack\color\Color;
use hhpack\color\ForegroundColor;
use hhpack\color\BackgroundColor;
use hhpack\color\StyleType;

function color_main() : void
{
    foreach (ForegroundColor::getValues() as $name => $color) {
        Color::fromColor($color)->display($name);
    }

    foreach (BackgroundColor::getValues() as $name => $color) {
        Color::fromBackground($color)->display($name);
    }

    Color::fromColor(ForegroundColor::White)
        ->background(BackgroundColor::Green)
        ->println('%s succeeded.', 'Color package example');

    Color::fromColor(ForegroundColor::White)
        ->addStyle(StyleType::Bold)
        ->addStyle(StyleType::Underlined)
        ->display('bold + underlined');

    Color::fromDefault()
        ->addStyle(StyleType::Reverse)
        ->display('reverse');
}
color_main();
