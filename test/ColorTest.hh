<?hh //strict

namespace HHPack\Color\Test;

//use namespace HHPack\Color\Test;

use type HHPack\Color\{Color, StyleType, ForegroundColor, BackgroundColor};
use type Facebook\HackTest\HackTest;
use function Facebook\FBExpect\expect;


final class ColorTest extends HackTest {
  public function testAddStyleAndRemoveStyle(): void {
    $message = Color::fromDefault();
    $message->addStyle(StyleType::Underlined);
    $message->removeStyle(StyleType::Underlined);

    expect($message->applyTo('bar'))->toBeSame("\e[0;39;49mbar\e[0m");
  }

  public function testFormat(): void {
    $message = Color::fromColor(ForegroundColor::Red);

    expect($message->format('%s %s', 'foo', 'bar'))->toBeSame("\e[0;31;49mfoo bar\e[0m");
  }

  public function testForegroundColor(): void {
    $message = Color::fromColor(ForegroundColor::Red);

    expect($message->applyTo('foo'))->toBeSame("\e[0;31;49mfoo\e[0m");
  }

  public function testBackgroundColor(): void {
    $message =
      Color::fromColor(ForegroundColor::Red)
        ->background(BackgroundColor::White);

    expect($message->applyTo('foo'))->toBeSame("\e[0;31;107mfoo\e[0m");
  }

}
