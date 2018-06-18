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

#pragma once

#include "engine/logic/State.hpp"

namespace client { namespace states {
    class MenuState : public engine::logic::State {
    public:
        void init();
        void clear();

        void pause();
        void resume();

        void input(engine::graphics::Window *win);
        void update(engine::graphics::Window *win);
        void render(engine::graphics::Window *win);

        static MenuState* getInstance() {
            return &_MenuState;
        }
    protected:
        MenuState() { }
    private:
        static MenuState _MenuState;
    };
} }
