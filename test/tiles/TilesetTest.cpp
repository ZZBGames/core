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

#include <zzbgames/tiles/Tileset.hpp>

namespace zzbgames {

namespace tiles {

TEST(TilesetTest, Constructor)
{
    util::Dimension tileSize(8, 8);
    util::Insets margin(1, 1, 0, 0);
    util::Insets spacing(0, 0, 1, 1);

    ASSERT_THROW(Tileset("undefined", tileSize, margin, spacing), std::ios::failure);

    Tileset tileset("res/tiles/tileset.png", tileSize, margin, spacing);
    ASSERT_EQ(4, tileset.tileCount());
    ASSERT_EQ(8, tileset.tileSize().height());
    ASSERT_EQ(8, tileset.tileSize().width());
}

TEST(TilesetTest, Tile)
{
    util::Dimension tileSize(8, 8);
    util::Insets margin(1, 1, 0, 0);
    util::Insets spacing(0, 0, 1, 1);
    Tileset tileset("res/tiles/tileset.png", tileSize, margin, spacing);

    for (unsigned long i = 0; i < tileset.tileCount(); ++i)
        ASSERT_NO_THROW(tileset.tileAsRect(i));
    ASSERT_THROW(tileset.tileAsRect(4), std::out_of_range);

    const sf::IntRect& tileArea1 = tileset.tileAsRect(0);
    ASSERT_EQ(1, tileArea1.left);
    ASSERT_EQ(1, tileArea1.top);
    ASSERT_EQ(8, tileArea1.width);
    ASSERT_EQ(8, tileArea1.height);

    ASSERT_EQ(10, tileset.tileAsRect(1).left);
    ASSERT_EQ(1, tileset.tileAsRect(1).top);

    ASSERT_EQ(1, tileset.tileAsRect(2).left);
    ASSERT_EQ(10, tileset.tileAsRect(2).top);

    ASSERT_EQ(10, tileset.tileAsRect(3).left);
    ASSERT_EQ(10, tileset.tileAsRect(3).top);
}

}

}