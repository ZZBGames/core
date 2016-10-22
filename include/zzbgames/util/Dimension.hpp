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

#ifndef ZZB_CORE_DIMENSION_HPP
#define ZZB_CORE_DIMENSION_HPP

#include <SFML/System/Vector2.hpp>

namespace zzbgames {

namespace util {

/**
 * @brief The Dimension class encapsulates the width and the height of a component.
 */
class Dimension {
public:
    /**
     * @brief Creates a new Dimension object with the specified width and height.
     *
     * @param width The specified width.
     * @param height The specified height.
     */
    Dimension(unsigned long width, unsigned long height);

    /**
     * @brief Creates a new Dimension object with the specified size.
     *
     * @param size The specified size.
     */
    Dimension(const sf::Vector2u& size);

    ~Dimension();

    /**
     * @brief Returns the height.
     *
     * @return the height.
     */
    unsigned long height() const;

    /**
     * @brief Sets the height and returns this Dimension.
     *
     * @param height The new height value.
     *
     * @return Returns this Dimension.
     */
    Dimension& height(unsigned long height);

    /**
     * @brief Returns the width.
     *
     * @return the width.
     */
    unsigned long width() const;

    /**
     * @brief Sets the width and returns this Dimension.
     *
     * @param width The new width value.
     *
     * @return Returns this Dimension.
     */
    Dimension& width(unsigned long width);

private:
    /// @brief The height dimension.
    unsigned long m_height;

    /// @brief The width dimension.
    unsigned long m_width;
};

}

}

#endif //ZZB_CORE_DIMENSION_HPP
