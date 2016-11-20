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

#ifndef ZZB_CORE_TEXT_HPP
#define ZZB_CORE_TEXT_HPP

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include <zzbgames/text/Font.hpp>

namespace zzbgames {

namespace text {

/**
 * @brief The Text class represents a drawable text based on a tile Font.
 */
class Text : public sf::Drawable, public sf::Transformable {
public:
    /**
     * @brief Creates a new Text object.
     *
     * @param font The font used to draw the text.
     * @param text The text to draw.
     */
    Text(const Font& font, const std::string& text);

    ~Text();

    /**
     * @brief Draws this Text object to the render target.
     *
     * @param target The target to draw to.
     * @param states The current rendering states.
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    /// @brief The font used to draw the text.
    const Font& m_font;

    /// @brief The vertex array to draw the text.
    sf::VertexArray m_vertices;
};

}

}

#endif //ZZB_CORE_TEXT_HPP
