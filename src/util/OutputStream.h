/*
 * Xournal++
 *
 * Output streams for writing
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <boost/filesystem/path.hpp>
using boost::filesystem::path;

#include "StringUtils.h"
#include "XournalType.h"
#include <zlib.h>

class OutputStream
{
public:
	OutputStream();
	virtual ~OutputStream();

public:
	virtual void write(const char* data);
	virtual void write(const char* data, int len) = 0;
	virtual void write(const string& str);

	virtual void close() = 0;
};

//TODO boost::iostreams
class GzOutputStream : public OutputStream
{
public:
	GzOutputStream(path filename);
	virtual ~GzOutputStream();

public:
	virtual void write(const char* data, int len);

	virtual void close();


	string& getLastError();

private:
	XOJ_TYPE_ATTRIB;

	gzFile fp;

	string error;

	string target;
	path filename;
};
