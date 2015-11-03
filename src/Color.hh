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

    public function __construct(
        private string $text,
        private ForegroundColor $color = ForegroundColor::White,
        private BackgroundColor $backgroundColor = BackgroundColor::Default
    )
    {
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

    public function text(string $text) : this
    {
        $this->text = $text;
        return $this;
    }

    public function display() : void
    {
        fwrite(STDOUT, (string) $this);
    }

    public static function fromText(string $text) : this
    {
        return new Color($text);
    }

    public function __toString() : string
    {
        return "\e[" . (string) $this->color . "m" . $this->text . "\e[0m";
    }

}
