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
        private string $format,
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

    public function formatText(string $format) : this
    {
        $this->format = $format;
        return $this;
    }

    public function println(...) : void
    {
        $text = call_user_func_array([ $this, 'format' ], func_get_args());
        fwrite(STDOUT, $text . PHP_EOL);
    }

    public function display() : void
    {
        fwrite(STDOUT, $this->format());
    }

    public static function fromFormat(string $format) : this
    {
        return new Color($format);
    }

    public function format(...) : string
    {
        $parts = Set { $this->format };
        $parts->addAll( func_get_args() );

        $text = call_user_func_array('sprintf', $parts->toArray());

        return $this->applyTo($text);
    }

    public function applyTo(string $text) : string
    {
        $parts = Set {};
        $parts->add("\e[%s;%s;%sm%s\e[0m");

        if ($this->styles->isEmpty()) {
            $this->addStyle(StyleType::DefaultStyle);
        }

        $styles = $this->styles->toValuesArray();
        $styleText = implode(';', $styles);
        $parts->add($styleText);

        $parts->add((string) $this->color);
        $parts->add((string) $this->backgroundColor);
        $parts->add($text);

        return call_user_func_array('sprintf', $parts->toArray());
    }

}
