<?hh //strict

/**
 * This file is part of hhpack\color.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\color;

final class Color
{

    private Set<StyleType> $styles;

    public function __construct(
        private ForegroundColor $color = ForegroundColor::DefaultColor,
        private BackgroundColor $backgroundColor = BackgroundColor::DefaultColor
    )
    {
        $this->styles = Set {};
    }

    public function color(ForegroundColor $color) : this
    {
        $this->color = $color;
        return $this;
    }

    public function background(BackgroundColor $color) : this
    {
        $this->backgroundColor = $color;
        return $this;
    }

    public function addStyle(StyleType $style) : this
    {
        $this->styles->add($style);
        return $this;
    }

    public function removeStyle(StyleType $style) : this
    {
        $this->styles->remove($style);
        return $this;
    }

    public function println(string $format, ...) : void
    {
        $text = call_user_func_array([ $this, 'format' ], func_get_args());
        fwrite(STDOUT, $text . PHP_EOL);
    }

    public function display(string $format, ...) : void
    {
        $text = call_user_func_array([ $this, 'format' ], func_get_args());
        fwrite(STDOUT, $text);
    }

    public static function fromColor(ForegroundColor $color) : this
    {
        return new Color($color);
    }

    public static function fromBackground(BackgroundColor $color) : this
    {
        return new Color(ForegroundColor::DefaultColor, $color);
    }

    public static function fromDefault() : this
    {
        return new Color();
    }

    public function format(string $format, ...) : string
    {
        $parts = Set { $format };
        $parts->addAll( func_get_args() );

        $text = call_user_func_array('sprintf', $parts->toArray());

        return $this->applyTo($text);
    }

    public function applyTo(string $text) : string
    {
        $styles = Set {};

        if ($this->styles->isEmpty()) {
            $this->addStyle(StyleType::DefaultStyle);
        }

        $styles->addAll($this->styles);

        $styles->add((string) $this->color);
        $styles->add((string) $this->backgroundColor);

        $styleText = implode(';', $styles->toValuesArray());

        return sprintf("\e[%sm%s\e[0m", $styleText, $text);
    }

}
