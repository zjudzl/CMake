/*=========================================================================

  Program:   CMake - Cross-Platform Makefile Generator
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "cmMessageCommand.h"

// cmLibraryCommand
bool cmMessageCommand::InitialPass(std::vector<std::string> const& argsIn)
{
  if(argsIn.size() < 1 )
    {
    this->SetError("called with incorrect number of arguments");
    return false;
    }
  std::vector<std::string> args;
  cmSystemTools::ExpandListArguments(argsIn, args);
  std::string message;
  std::vector<std::string>::const_iterator i = args.begin();

  bool send_error = false;
  if (*i == "SEND_ERROR")
    {
    send_error = true;
    ++i;
    }

  for(;i != args.end(); ++i)
    {
    message += *i;
    }

  if (send_error)
    {
    cmSystemTools::Error(message.c_str());
    }
  else
    {
    cmSystemTools::Message(message.c_str());
    }

  return true;
}

