<?hh //strict

namespace HHPack\Color\test;

use HHPack\Color\Color;
use HHPack\Color\StyleType;
use HHPack\Color\ForegroundColor;
use HHPack\Color\BackgroundColor;
use HackPack\HackUnit\Contract\Assert;

final class ColorTest
{

    <<Test>>
    public function addStyleAndRemoveStyle(Assert $assert) : void
    {
        $message = Color::fromDefault();
        $message->addStyle(StyleType::Underlined);
        $message->removeStyle(StyleType::Underlined);

        $assert->string($message->applyTo('bar'))->is("\e[0;39;49mbar\e[0m");
    }

    <<Test>>
    public function format(Assert $assert) : void
    {
        $message = Color::fromColor(ForegroundColor::Red);
        $assert->string($message->format('%s %s', 'foo', 'bar'))->is("\e[0;31;49mfoo bar\e[0m");
    }

    <<Test>>
    public function foregroundColor(Assert $assert) : void
    {
        $message = Color::fromColor(ForegroundColor::Red);
        $assert->string($message->applyTo('foo'))->is("\e[0;31;49mfoo\e[0m");
    }

    <<Test>>
    public function backgroundColor(Assert $assert) : void
    {
        $message = Color::fromColor(ForegroundColor::Red)
            ->background(BackgroundColor::White);

        $assert->string($message->applyTo('foo'))->is("\e[0;31;107mfoo\e[0m");
    }

}
