//
// Position.cpp
//
// Library: SQL
// Package: SQLCore
// Module:  Position
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/SQL/Position.h"


namespace Poco {
namespace SQL {


Position::Position(Poco::UInt32 positionValue): _value(positionValue)
{
}


Position::~Position()
{
}


} } // namespace Poco::SQL
