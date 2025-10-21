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

#pragma once

#include <string>

class FString;

bool is_equal_ignoring_case(const std::string& a, const std::string& b);
void replace_multiple_chars(std::string& s, const std::string& chars, char replacement_char);
void replace_multiple_chars(FString& s, const std::string& chars, const char replacement_char);

FString trim_left(const FString& str, const std::string_view& charset);
FString trim_whitespace_left(const FString& str);

FString trim_right(const FString& str, const std::string_view& charset);
FString trim_whitespace_right(const FString& str);

FString trim_whitespace(const FString& str);
FString trim(const FString& str, const std::string_view& charset);


// Self-mutating versions
void strip(FString *input, const std::string_view& charset);
void strip_left(FString *input, const std::string_view& charset);
void strip_right(FString *input, const std::string_view& charset);
void strip_whitespace(FString *input);
void strip_whitespace_left(FString *input);
void strip_whitespace_right(FString *input);
