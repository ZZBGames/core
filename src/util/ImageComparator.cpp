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

#include <zzbgames/util/ImageComparator.hpp>

namespace zzbgames {

namespace util {

bool ImageComparator::areEquals(const sf::Image& image1, const sf::Image& image2)
{
    bool equals = false;

    if (image1.getSize() == image2.getSize()) {
        const sf::Uint8 *pixels1 = image1.getPixelsPtr();
        const sf::Uint8 *pixels2 = image2.getPixelsPtr();

        unsigned int pixelCount1 = image1.getSize().x * image1.getSize().y * 4;

        equals = std::equal(pixels1, pixels1 + pixelCount1, pixels2);
    }

    return equals;
}

bool ImageComparator::areEquals(const sf::Image& image1, const sf::IntRect& subarea1, const sf::Image& image2,
                                const sf::IntRect& subarea2)
{
    if ((subarea1.width != subarea2.width) || (subarea1.height != subarea2.height))
        return false;

    unsigned int width = static_cast<unsigned int>(subarea1.width);
    unsigned int height = static_cast<unsigned int>(subarea1.height);

    const sf::Uint8 *pixels1 = image1.getPixelsPtr();
    const sf::Uint8 *pixels2 = image2.getPixelsPtr();

    for (unsigned int row = 0; row < height; ++row) {
        unsigned int index1 = ((subarea1.top + row) * image1.getSize().x + subarea1.left) * 4;
        unsigned int index2 = ((subarea2.top + row) * image2.getSize().x + subarea2.left) * 4;

        if (!std::equal(pixels1 + index1, pixels1 + index1 + width, pixels2 + index2))
            return false;
    }

    return true;
}

}

}