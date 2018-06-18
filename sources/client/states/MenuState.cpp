/*
 * This file is part of PongGL.
 * Copyright (C) 2018 Rodrigo Casamayor.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "MenuState.hpp"

namespace client { namespace states {

    MenuState MenuState::_MenuState;

    void MenuState::init()
    {
        std::cout << "MenuState: Init successful!" << std::endl;

        glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
    }

    void MenuState::clear()
    {
        std::cout << "MenuState: Clear successful!" << std::endl;
    }

    void MenuState::pause()
    {
        std::cout << "MenuState: Paused!" << std::endl;
    }

    void MenuState::resume()
    {
        std::cout << "MenuState: Resumed!" << std::endl;
    }

    void MenuState::input(engine::graphics::Window *win)
    {

    }

    void MenuState::update(engine::graphics::Window *win)
    {

    }

    void MenuState::render(engine::graphics::Window *win)
    {

    }

} }