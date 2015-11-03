<?hh // partial

namespace hhpack\color\spec;

use hhpack\color\Color;
use hhpack\color\ForegroundColor;
use hhpack\color\BackgroundColor;

describe(Color::class, function() {
  describe('__toString', function() {
    context('when foreground color specified', function () {
      it('returns string content', function () {
        $message = Color::fromText('foo')
          ->color(ForegroundColor::Red);

        expect((string) $message)->toBe("\e[0;31;49mfoo\e[0m");
      });
    });
    context('when background color specified', function () {
      it('returns string content', function () {
        $message = Color::fromText('foo')
          ->color(ForegroundColor::Red)
          ->background(BackgroundColor::White);

        expect((string) $message)->toBe("\e[0;31;107mfoo\e[0m");
      });
    });
  });
});
