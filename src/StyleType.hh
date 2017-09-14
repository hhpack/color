<?hh //strict

/**
 * This file is part of HHPack\Color.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Color;

enum StyleType : int {
  DefaultStyle = 0;
  Bold = 1;
  Dim = 2;
  Italic = 3;
  Underlined = 4;
  Blink = 5;
  Reverse = 7;
  Hidden = 8;
}
