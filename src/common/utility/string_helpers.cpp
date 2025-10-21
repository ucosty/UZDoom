//-----------------------------------------------------------------------------
//
// Copyright 2025 Matthew Costa
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/
//
//-----------------------------------------------------------------------------

#include "string_helpers.h"
#include "zstring.h"

#include <algorithm>

bool is_equal_ignoring_case(const std::string &a, const std::string &b) {
    if (a.size() != b.size()) {
        return false;
    }

    return std::equal(a.begin(), a.end(), b.begin(), [](const char char_a, const char char_b) {
        return std::tolower(static_cast<unsigned char>(char_a)) == std::tolower(static_cast<unsigned char>(char_b));
    });
}

void replace_multiple_chars(std::string& s, const std::string& chars, const char replacement_char) {
    std::ranges::replace_if(s,
        [&chars](const char c) {
            return chars.find(c) != std::string::npos;
        },
        replacement_char
    );
}

void replace_multiple_chars(FString& s, const std::string& chars, const char replacement_char) {
    std::ranges::replace_if(s,
        [&chars](const char c) {
            return chars.find(c) != std::string::npos;
        },
        replacement_char
    );
}
