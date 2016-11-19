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

#ifndef ZZB_CORE_TILESET_HPP
#define ZZB_CORE_TILESET_HPP

#include <string>

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <zzbgames/util/Dimension.hpp>
#include <zzbgames/util/Insets.hpp>

namespace zzbgames {

namespace tiles {

/**
 * @brief The Tileset class represents an image split in a tile grid.
 */
class Tileset {
public:
    /**
     * @brief Creates a new Tileset object from a file with empty margin and spacing
     *
     * @param filename The name of the tileset image file.
     * @param tileSize The size of each tile in pixels.
     *
     * @throw std::ios_base::failure if the loading of the image fails.
     */
    Tileset(const std::string& filename, const util::Dimension& tileSize);

    /**
     * @brief Creates a new Tileset object from a file.
     *
     * @param filename The name of the tileset image file.
     * @param tileSize The size of each tile in pixels.
     * @param margin The inner margin of this tileset.
     * @param spacing The spacing between each tile in pixels.
     *
     * @throw std::ios_base::failure if the loading of the image fails.
     */
    Tileset(const std::string& filename, const util::Dimension& tileSize, const util::Insets& margin,
            const util::Insets& spacing);

    ~Tileset();

    /**
     * @brief Returns the internal SFML::Texture of this Tileset.
     *
     * @return The internal SFML::Texture of this Tileset.
     */
    const sf::Texture& texture() const;

    /**
     * @brief Returns a tile from its index in this Tileset as a SFML::IntRect.
     *
     * @param index The index of the tile.
     *
     * @return the area of the tile in this Tileset.
     *
     * @throws an std::out_of_range exception if index is greater than the number of tiles.
     */
    sf::IntRect tileAsRect(unsigned long index) const;

    /**
     * @brief Returns the number of tiles of this tileset.
     *
     * @return the number of tiles of this tileset.
     */
    unsigned long tileCount() const;

    /**
     * @brief Returns the size of each tile of this Tileset.
     *
     * @return the size of each tile of this Tileset.
     */
    const util::Dimension& tileSize() const;

private:
    /**
     * @brief Computes and initializes the grid size.
     */
    void computeGridSize();

private:
    /// @brief The size of this Tileset in squares.
    util::Dimension m_gridSize;

    /// @brief The image used by this tileset.
    sf::Image m_image;

    /// @brief The inner margin of this tileset.
    util::Insets m_margin;

    /// @brief The spacing between each tile in pixels.
    util::Insets m_spacing;

    /// @brief The texture used by this tileset.
    sf::Texture m_texture;

    /// @brief The size of each tile in pixels.
    util::Dimension m_tileSize;
};

}

}

#endif //ZZB_CORE_TILESET_HPP
