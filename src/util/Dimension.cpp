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

#include <zzbgames/util/Dimension.hpp>

namespace zzbgames {

namespace util {

Dimension::Dimension(unsigned long width, unsigned long height)
    : m_height(height),
      m_width(width)
{
}

Dimension::Dimension(const sf::Vector2u& size)
    : m_height(size.y),
      m_width(size.x)
{
}

Dimension::~Dimension()
{
}

unsigned long Dimension::height() const
{
    return m_height;
}

Dimension& Dimension::height(unsigned long height)
{
    m_height = height;

    return *this;
}

unsigned long Dimension::width() const
{
    return m_width;
}

Dimension& Dimension::width(unsigned long width)
{
    m_width = width;

    return *this;
}

}

}
