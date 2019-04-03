//
// TCPServerConnection.cpp
//
// $Id: //poco/1.4/Net/src/TCPServerConnection.cpp#1 $
//
// Library: Net
// Package: TCPServer
// Module:  TCPServerConnection
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Exception.h"
#include "Poco/ErrorHandler.h"


using Poco::Exception;
using Poco::ErrorHandler;


namespace Poco {
namespace Net {


TCPServerConnection::TCPServerConnection(const StreamSocket& socket):
	_socket(socket)
{
}


TCPServerConnection::~TCPServerConnection()
{
}


void TCPServerConnection::start()
{
	try
	{
		run();
	}
	catch (Exception& exc)
	{
	// TODO - add precompiled directive POCO_ALLOW_UNKNOWN_CERT so we can eventually commit this change in master
	// #if defined(POCO_ALLOW_UNKNOWN_CERT)
		std::string s(exc.what());
		if (s.compare("error:14094416:SSL routines:ssl3_read_bytes:sslv3 alert certificate unknown"))
		{
			return;
		}
	// #endif

		ErrorHandler::handle(exc);
	}
	catch (std::exception& exc)
	{
		ErrorHandler::handle(exc);
	}
	catch (...)
	{
		ErrorHandler::handle();
	}
}


} } // namespace Poco::Net
