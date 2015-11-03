<?hh // partial

namespace hhpack\color\spec;

use hhpack\color\Color;
use hhpack\color\ForegroundColor;
use hhpack\color\BackgroundColor;

describe(Color::class, function() {

  describe('format', function() {
    it('returns formatted string', function () {
      $message = Color::fromColor(ForegroundColor::Red);
      expect($message->format('%s %s', 'foo', 'bar'))->toBe("\e[0;31;49mfoo bar\e[0m");
    });
  });

  describe('applyTo', function() {
    context('when foreground color specified', function () {
      it('returns string content', function () {
        $message = Color::fromColor(ForegroundColor::Red);
        expect($message->applyTo('foo'))->toBe("\e[0;31;49mfoo\e[0m");
      });
    });
    context('when background color specified', function () {
      it('returns string content', function () {
        $message = Color::fromColor(ForegroundColor::Red)
          ->background(BackgroundColor::White);

        expect($message->applyTo('foo'))->toBe("\e[0;31;107mfoo\e[0m");
      });
    });
  });
});
