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

#ifndef ZZB_CORE_INSETS_HPP
#define ZZB_CORE_INSETS_HPP

namespace zzbgames {

namespace util {

/**
 * @brief The Insets class represents the borders of an object (margin, spacing...).
 */
class Insets {
public:
    /**
     * @brief Creates a new Insets object with the specified top, left, bottom and right insets.
     *
     * @param top The inset from the top.
     * @param left The inset from the left.
     * @param bottom The inset from the bottom.
     * @param right The inset from the right.
     */
    Insets(unsigned long top, unsigned long left, unsigned long bottom, unsigned long right);

    ~Insets();

    /**
     * @brief Returns the inset from the bottom.
     *
     * @return the inset from the bottom.
     */
    unsigned long bottom() const;

    /**
     * @brief Returns the inset from the left.
     *
     * @return the inset from the left.
     */
    unsigned long left() const;

    /**
     * @brief Returns the inset from the right.
     *
     * @return the inset from the right.
     */
    unsigned long right() const;

    /**
     * @brief Returns the inset from the top.
     *
     * @return the inset from the top.
     */
    unsigned long top() const;

private:
    /// @brief The inset from the bottom.
    unsigned long m_bottom;

    /// @brief The inset from the left.
    unsigned long m_left;

    /// @brief The inset from the right.
    unsigned long m_right;

    /// @brief The inset from the top.
    unsigned long m_top;
};

}

}

#endif //ZZB_CORE_INSETS_H
