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

#include <zzbgames/util/ImageComparator.hpp>

namespace zzbgames {

namespace util {

TEST(ImageComparatorTest, areEquals)
{
    sf::Image image1;
    image1.loadFromFile("res/tiles/tileset.png");
    ASSERT_EQ(true, ImageComparator::areEquals(image1, image1));

    sf::Image image2;
    image2.create(8, 8, sf::Color(255, 0, 0));
    ASSERT_EQ(false, ImageComparator::areEquals(image1, image2));
    ASSERT_EQ(true, ImageComparator::areEquals(image1, sf::IntRect(1, 1, 8, 8), image2, sf::IntRect(0, 0, 8, 8)));
    ASSERT_EQ(false, ImageComparator::areEquals(image1, sf::IntRect(0, 0, 8, 8), image2, sf::IntRect(0, 0, 8, 8)));
    ASSERT_EQ(false, ImageComparator::areEquals(image1, sf::IntRect(0, 0, 1, 1), image2, sf::IntRect(0, 0, 8, 8)));
}

}

}
