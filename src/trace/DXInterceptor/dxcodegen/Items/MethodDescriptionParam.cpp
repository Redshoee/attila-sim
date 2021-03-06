////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Items/SmartPointer.h"
#include "Items/MethodDescriptionParam.h"

using namespace std;
using namespace dxcodegen::Items;

////////////////////////////////////////////////////////////////////////////////

MethodDescriptionParam::MethodDescriptionParam()
{
}

////////////////////////////////////////////////////////////////////////////////

MethodDescriptionParam::~MethodDescriptionParam()
{
}

////////////////////////////////////////////////////////////////////////////////

void MethodDescriptionParam::SetType(const string& type)
{
  m_type = type;
}

////////////////////////////////////////////////////////////////////////////////

string& MethodDescriptionParam::GetType()
{
  return m_type;
}

////////////////////////////////////////////////////////////////////////////////

void MethodDescriptionParam::SetName(const string& name)
{
  m_name = name;
}

////////////////////////////////////////////////////////////////////////////////

string& MethodDescriptionParam::GetName()
{
  return m_name;
}

////////////////////////////////////////////////////////////////////////////////
