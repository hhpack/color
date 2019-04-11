color
================================================

[![Latest Stable Version](https://poser.pugx.org/hhpack/color/v/stable)](https://packagist.org/packages/hhpack/color)
[![CircleCI](https://circleci.com/gh/hhpack/color/tree/master.svg?style=svg)](https://circleci.com/gh/hhpack/color/tree/master)[![Dependency Status](https://www.versioneye.com/user/projects/563848a0e935640017000001/badge.svg?style=flat)](https://www.versioneye.com/user/projects/563848a0e935640017000001)
[![License](https://poser.pugx.org/hhpack/color/license)](https://packagist.org/packages/hhpack/color)

![ScreenShot](https://raw.githubusercontent.com/hhpack/color/master/screen-shot.png)

Basic usage
------------------------------------------------

The user can output to stdout by specifying the color.

```hack
Color::fromColor(ForegroundColor::White)
    ->background(BackgroundColor::Green)
    ->println('%s succeeded.', 'Color package example');
```

or 

```hack
$color = Color::fromColor(ForegroundColor::White)
    ->background(BackgroundColor::Green);
$color('%s succeeded.', 'Color package example');
```

Applying styles
------------------------------------------------

The user can use the **applyTo** method in order to apply a style to text.

```hack
$text = Color::fromColor(ForegroundColor::White)
    ->background(BackgroundColor::Green)
    ->applyTo('target text');

echo $text;
```

Custom style for text
------------------------------------------------

The user can pull the bold and underline.

```hack
Color::fromColor(ForegroundColor::White)
    ->addStyle(StyleType::Bold)
    ->addStyle(StyleType::Underlined)
    ->println('%s + %s', 'bold', 'underlined');
```

Run the test
------------------------------------------------

You can run the test with the following command.

	composer install
	composer test
