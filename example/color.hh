<?hh // partial

namespace hhpack\color\example;

require_once __DIR__ . '/../vendor/autoload.php';

use hhpack\color\Color;
use hhpack\color\ForegroundColor;
use hhpack\color\BackgroundColor;
use hhpack\color\StyleAttribute;

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

Color::fromFormat('%s succeeded.')
    ->color(ForegroundColor::White)
    ->background(BackgroundColor::Green)
    ->println('Color package example');

Color::fromFormat('bold + underlined')
    ->color(ForegroundColor::White)
    ->addStyle(StyleAttribute::Bold)
    ->addStyle(StyleAttribute::Underlined)
    ->display();
