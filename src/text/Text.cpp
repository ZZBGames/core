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

#include <zzbgames/text/Text.hpp>

namespace zzbgames {

namespace text {

Text::Text(const Font& font, const std::string& text)
    : m_font(font),
      m_vertices(sf::Quads, static_cast<unsigned int>(text.size() * 4))
{
    const tiles::Tileset& tileset = font.tileset();
    const util::Dimension& tileSize = tileset.tileSize();

    for (unsigned int index = 0; index < text.size(); ++index) {
        unsigned long tileIndex = font.characterToTileIndex(text.at(index));

        const sf::IntRect& tileArea = tileset.tileAsRect(tileIndex);

        sf::Vertex *quad = &m_vertices[index * 4];

        quad[0].position = sf::Vector2f(index * tileSize.width(), 0);
        quad[1].position = sf::Vector2f((index + 1) * tileSize.width(), 0);
        quad[2].position = sf::Vector2f((index + 1) * tileSize.width(), tileSize.height());
        quad[3].position = sf::Vector2f(index * tileSize.width(), tileSize.height());

        quad[0].texCoords = sf::Vector2f(tileArea.left, tileArea.top);
        quad[1].texCoords = sf::Vector2f(tileArea.left + tileArea.width, tileArea.top);
        quad[2].texCoords = sf::Vector2f(tileArea.left + tileArea.width, tileArea.top + tileArea.height);
        quad[3].texCoords = sf::Vector2f(tileArea.left, tileArea.top + tileArea.height);
    }
}

Text::~Text()
{
}

void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_font.tileset().texture();

    target.draw(m_vertices, states);
}

}

}