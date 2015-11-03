<?hh // partial

namespace hhpack\color\spec;

use hhpack\color\Color;
use hhpack\color\ForegroundColor;
use hhpack\color\BackgroundColor;

describe(Color::class, function() {

  describe('format', function() {
    it('returns formatted string', function () {
      $message = Color::fromFormat('%s %s')
        ->color(ForegroundColor::Red);

      expect($message->format('foo', 'bar'))->toBe("\e[31;49mfoo bar\e[0m");
    });
  });

  describe('applyTo', function() {
    context('when foreground color specified', function () {
      it('returns string content', function () {
        $message = Color::fromFormat('foo')
          ->color(ForegroundColor::Red);

        expect($message->format())->toBe("\e[31;49mfoo\e[0m");
      });
    });
    context('when background color specified', function () {
      it('returns string content', function () {
        $message = Color::fromFormat('foo')
          ->color(ForegroundColor::Red)
          ->background(BackgroundColor::White);

        expect($message->format())->toBe("\e[31;107mfoo\e[0m");
      });
    });
  });
});
