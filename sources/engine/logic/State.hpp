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

#include "engine/graphics/Window.hpp"

namespace engine { namespace logic {
    class State {
    public:
        virtual void init() = 0;
        virtual void clear() = 0;

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void input(engine::graphics::Window *win) = 0;
        virtual void update(engine::graphics::Window *win) = 0;
        virtual void render(engine::graphics::Window *win) = 0;

        void ChangeState(engine::graphics::Window *win, State *state) {
            win->ChangeState(state);
        }
    protected:
        State() { }
    };
} }
