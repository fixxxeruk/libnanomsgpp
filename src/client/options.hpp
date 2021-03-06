/*
 * Copyright (C) 2014 Christopher Gilbert <christopher.john.gilbert@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef CLIENT_OPTIONS_HPP
#define CLIENT_OPTIONS_HPP

#include <nanomsgpp/nanomsgpp.hpp>

#include <iostream>
#include <string>
#include <vector>

namespace client {

	enum class echo_format {
		none, raw, ascii, quoted, msgpack
	};

	struct options {
		// miscellaneous options
		bool                     show_usage;
		bool                     show_help;
		bool                     show_version;

		// global options
		bool                     verbose;

		// socket options
		std::string              type;
		std::vector<std::string> bind;
		std::vector<std::string> connect;
		int                      send_timeout;
		int                      recv_timeout;
		std::vector<std::string> subscribe;

		// input options
		std::string              format;
		bool                     raw;
		bool                     ascii;
		bool                     quoted;

		// output options
		int                      interval;
		int                      delay;
		std::string              data;
		std::string              file;

		options()
			: show_usage(false)
			, show_help(false)
			, show_version(false)
			, verbose(false)
			, type()
			, bind(), connect()
			, send_timeout(-1), recv_timeout(-1)
			, subscribe()
			, format()
			, raw(false), ascii(false), quoted(false)
			, interval(-1), delay(-1)
			, data(), file()
		{}

		nanomsgpp::socket_type get_type() const;

		echo_format get_format() const;

		std::string get_data() const;
	};

}

client::options process_command_line(int argc, char const* argv[]);
std::ostream& show_usage(std::ostream& stream);
std::ostream& show_help(std::ostream& stream);

#endif // CLIENT_OPTIONS_HPP
