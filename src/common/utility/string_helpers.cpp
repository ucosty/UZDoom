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

constexpr std::string_view WHITESPACE_CHARSET = " \t\n\r\f\v";

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

struct CharacterLookup {
    bool table[256]{};

    explicit CharacterLookup(const std::string_view& s) {
        for (const unsigned char c: s) {
            table[c] = true;
        }
    }

    bool contains(const char c) const {
        return table[static_cast<unsigned char>(c)];
    }
};

size_t find_first_not_matching(const FString& str, const std::string_view& charset) {
    const auto length = str.Len();
    const auto lookup = CharacterLookup(charset);
    for (size_t i = 0; i < length; ++i) {
        if (const auto ch = str[i]; !lookup.contains(ch)) {
            return i;
        }
    }
    return std::string::npos;
}

size_t find_last_not_matching(const FString& str, const std::string_view& charset) {
    const auto length = str.Len();
    const auto lookup = CharacterLookup(charset);
    for (size_t i = length - 1; i > 0; --i) {
        if (const auto ch = str[i]; !lookup.contains(ch)) {
            return length - i - 1;
        }
    }
    return std::string::npos;
}

FString trim_left(const FString& str, const std::string_view& charset) {
    const auto substring_start = find_first_not_matching(str, charset);
    if (substring_start == std::string::npos) {
        return {};
    }
    return str.substr(substring_start, str.Len() - substring_start);
}

FString trim_whitespace_left(const FString& str) {
    return trim_left(str, WHITESPACE_CHARSET);
}

FString trim_right(const FString& str, const std::string_view& charset) {
    const auto substring_end = find_last_not_matching(str, charset);
    if (substring_end == std::string::npos) {
        return {};
    }
    return str.substr(0, str.Len() - substring_end);
}

FString trim_whitespace_right(const FString& str) {
    return trim_right(str, WHITESPACE_CHARSET);
}

FString trim_whitespace(const FString& str) {
    return trim(str, WHITESPACE_CHARSET);
}

FString trim(const FString& str, const std::string_view& charset) {
    const auto substring_start = find_first_not_matching(str, charset);
    const auto substring_end = find_last_not_matching(str, charset);
    if (substring_start == std::string::npos) {
        return {};
    }
    return str.substr(substring_start, str.Len() - substring_end - substring_start);
}

void strip(FString *input, const std::string_view& charset) {
    *input = trim(*input, charset);
}

void strip_left(FString *input, const std::string_view& charset) {
    *input = trim_left(*input, charset);
}

void strip_right(FString *input, const std::string_view& charset) {
    *input = trim_right(*input, charset);
}

void strip_whitespace(FString *input) {
    *input = trim(*input, WHITESPACE_CHARSET);
}

void strip_whitespace_left(FString *input) {
    *input = trim_left(*input, WHITESPACE_CHARSET);
}

void strip_whitespace_right(FString *input) {
    *input = trim_right(*input, WHITESPACE_CHARSET);
}
