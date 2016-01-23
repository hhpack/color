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

function error(string $format, ...) : void
{
    $color = Color::fromColor(ForegroundColor::Red);
    call_user_func_array($color, func_get_args());
}

function info(string $format, ...) : void
{
    $color = Color::fromColor(ForegroundColor::Cyan);
    call_user_func_array($color, func_get_args());
}

function warn(string $format, ...) : void
{
    $color = Color::fromColor(ForegroundColor::Yellow);
    call_user_func_array($color, func_get_args());
}

function debug(string $format, ...) : void
{
    $color = Color::fromColor(ForegroundColor::DarkGray);
    call_user_func_array($color, func_get_args());
}

function log(string $format, ...) : void
{
    $color = Color::fromColor(ForegroundColor::DefaultColor);
    call_user_func_array($color, func_get_args());
}
