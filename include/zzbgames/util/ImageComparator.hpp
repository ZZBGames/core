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

#ifndef ZZB_CORE_IMAGECOMPARATOR_HPP
#define ZZB_CORE_IMAGECOMPARATOR_HPP

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace zzbgames {

namespace util {

/**
 * @brief Utility class for image comparison.
 */
class ImageComparator {
public:
    /**
     * @brief Returns true if the two images are equals.
     *
     * @param image1 The first image to compare.
     * @param image2 The second image to compare.
     *
     * @return True if the two images are equals, false otherwise.
     */
    static bool areEquals(const sf::Image& image1, const sf::Image& image2);

    /**
     * @brief Returns true if the two subareas of the two images are equals.
     *
     * @param image1 The first image to compare.
     * @param subarea1 The subarea of the first image to compare.
     * @param image2 The second image to compare.
     * @param subarea2 The subarea of the second image to compare.
     *
     * @return Returns true if the two subareas of the two images are equals, false otherwise.
     */
    static bool areEquals(const sf::Image& image1, const sf::IntRect& subarea1, const sf::Image& image2,
                          const sf::IntRect& subarea2);
};

}

}


#endif //ZZB_CORE_IMAGECOMPARATOR_HPP
