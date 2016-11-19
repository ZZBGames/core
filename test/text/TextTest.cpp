// Copyright (c) 2016 ZZBGames
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <gtest/gtest.h>

#include <SFML/Graphics/RenderWindow.hpp>

#include <zzbgames/text/Text.hpp>
#include <zzbgames/util/ImageComparator.hpp>

#include "FontImpl.hpp"

namespace zzbgames {

namespace text {

TEST(TextTest, Draw)
{
    tiles::Tileset tileset("res/text/font.png", util::Dimension(8, 8));
    FontImpl font(tileset);
    ASSERT_EQ(0, font.characterToTileIndex('a'));
    ASSERT_EQ(1, font.characterToTileIndex('b'));
    ASSERT_EQ(2, font.characterToTileIndex('c'));
    ASSERT_EQ(3, font.characterToTileIndex('d'));
    ASSERT_THROW(font.characterToTileIndex('e'), std::out_of_range);

    Text text(font, "abcd");

    sf::RenderWindow window(sf::VideoMode(32, 8), "TextTest - Draw");
    window.clear();
    window.draw(text);
    const sf::Image& screenshot = window.capture();

    sf::Image image;
    image.loadFromFile("res/text/font.png");

    ASSERT_EQ(true, util::ImageComparator::areEquals(screenshot, image));
}

}

}