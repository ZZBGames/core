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

#ifndef ZZB_CORE_FONT_HPP
#define ZZB_CORE_FONT_HPP

#include <zzbgames/tiles/Tileset.hpp>

namespace zzbgames {

namespace text {

/**
 * @brief The Font class is the base class for fonts based on a tiles::Tileset.
 */
class Font {
public:
    /**
     * @brief Creates a new Font object from a Tileset.
     *
     * @param tileset The tileset used by this font.
     */
    Font(const tiles::Tileset& tileset);

    ~Font();

    /**
     * @brief Returns the tile to use to draw the character.
     *
     * @param character The character to draw.
     *
     * @return the index of the tile corresponding to the character.
     */
    virtual unsigned long characterToTileIndex(char character) const = 0;

    /**
     * @brief Returns the Tileset this Font is based on.
     *
     * @return the Tileset this Font is based on.
     */
    const tiles::Tileset& tileset() const;

private:
    /// @brief A reference to the Tileset object used by this Font.
    const tiles::Tileset& m_tileset;
};

}

}

#endif //ZZB_CORE_FONT_HPP
