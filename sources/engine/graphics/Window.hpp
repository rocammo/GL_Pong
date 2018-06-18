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

#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

namespace engine {
	namespace logic {
		class State;
	}

	namespace graphics {
		class Window {
		private:
			const char *_title;
			int _width, _height;

			GLFWwindow *_window;

		public:
			Window(const char *title, int width, int height);
			~Window();
            void update();
			void clear() const;
			bool closed() const;
		private:
			bool init();

        public:
		    void ChangeState(engine::logic::State *state);
		    void PushState(engine::logic::State *state);
		    void PopState(engine::logic::State *state);
		private:
            std::vector<engine::logic::State *> states;
		};
} }