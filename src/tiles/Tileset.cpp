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

#include <ios>

#include <zzbgames/tiles/Tileset.hpp>

namespace zzbgames {

namespace tiles {

Tileset::Tileset(const std::string& filename, const util::Dimension& tileSize, const util::Insets& margin,
                 const util::Insets& spacing)
    : m_gridSize(0, 0),
      m_image(),
      m_margin(margin),
      m_spacing(spacing),
      m_texture(),
      m_tileSize(tileSize)
{
    if (!m_image.loadFromFile(filename))
        throw std::ios_base::failure("Failed to load texture from " + filename);

    if (!m_texture.loadFromImage(m_image))
        throw std::ios_base::failure("Failed to load texture from " + filename);

    computeGridSize();
}

Tileset::~Tileset()
{
}

void Tileset::computeGridSize()
{
    unsigned long tileWidth = m_spacing.left() + m_tileSize.width() + m_spacing.right();
    unsigned long tileHeight = m_spacing.top() + m_tileSize.height() + m_spacing.bottom();

    util::Dimension textureSize(m_texture.getSize());

    m_gridSize.width((textureSize.width() - m_margin.left() - m_margin.right()) / tileWidth);
    m_gridSize.height((textureSize.height() - m_margin.top() - m_margin.bottom()) / tileHeight);
}

unsigned long Tileset::tileCount() const
{
    return m_gridSize.height() * m_gridSize.width();
}

}

}
