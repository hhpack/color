namespace HHPack\Color\example;

require_once __DIR__.'/../vendor/hh_autoload.hh';

use HHPack\Color\Color;
use HHPack\Color\ForegroundColor;
use HHPack\Color\BackgroundColor;
use HHPack\Color\StyleType;

<<__EntryPoint>>
function main(): noreturn {
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

  Color::fromDefault()->addStyle(StyleType::Reverse)->display('reverse');

  exit(0);
}
