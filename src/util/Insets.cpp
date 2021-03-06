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

#include <zzbgames/util/Insets.hpp>

namespace zzbgames {

namespace util {

Insets::Insets()
    : Insets(0, 0, 0, 0)
{
}

Insets::Insets(unsigned long top, unsigned long left, unsigned long bottom, unsigned long right)
    : m_bottom(bottom),
      m_left(left),
      m_right(right),
      m_top(top)
{
}

Insets::~Insets()
{
}

unsigned long Insets::bottom() const
{
    return m_bottom;
}

unsigned long Insets::left() const
{
    return m_left;
}

unsigned long Insets::right() const
{
    return m_right;
}

unsigned long Insets::top() const
{
    return m_top;
}

}

}
