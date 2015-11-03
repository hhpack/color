color
================================================

[![Latest Stable Version](https://poser.pugx.org/hhpack/color/v/stable)](https://packagist.org/packages/hhpack/color)
[![Build Status](https://travis-ci.org/hhpack/color.svg)](https://travis-ci.org/hhpack/color)
[![Dependency Status](https://www.versioneye.com/user/projects/563848a0e935640017000001/badge.svg?style=flat)](https://www.versioneye.com/user/projects/563848a0e935640017000001)
[![License](https://poser.pugx.org/hhpack/color/license)](https://packagist.org/packages/hhpack/color)

![ScreenShot](https://raw.githubusercontent.com/hhpack/color/master/screen-shot.png)

Basic usage
------------------------------------------------

```hack
Color::fromFormat('%s succeeded.')
    ->color(ForegroundColor::White)
    ->background(BackgroundColor::Green)
    ->println('Color package example');
```

Run the test
------------------------------------------------

You can run the test with the following command.

	composer install
	composer test
