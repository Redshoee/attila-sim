////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IDirect3DDevice9InterceptorStub.h"
#include "IDirect3DVertexDeclaration9InterceptorStub.h"

////////////////////////////////////////////////////////////////////////////////

IDirect3DVertexDeclaration9InterceptorStub::IDirect3DVertexDeclaration9InterceptorStub(DXPainter* painter, IDirect3DVertexDeclaration9* original, IDirect3DDevice9InterceptorStub* creator) : 
DXInterceptorStub(painter),
m_original(original),
m_creator(creator)
{
}

////////////////////////////////////////////////////////////////////////////////

IDirect3DVertexDeclaration9InterceptorStub::~IDirect3DVertexDeclaration9InterceptorStub()
{
  FREE_D3D_RESOURCE();
}

////////////////////////////////////////////////////////////////////////////////

HRESULT IDirect3DVertexDeclaration9InterceptorStub::DoSpecific(DXMethodCallPtr call)
{
  switch (call->GetToken())
  {
  case DXMethodCallHelper::TOK_IDirect3DVertexDeclaration9_QueryInterface:
    {
      IID param1;
      CHECK_CALL(call->Pop_IID(&param1));

      DXIgnoredParameter ignoredParam;
      CHECK_CALL(call->Pop_DXIgnoredParameter(&ignoredParam));
      
      VOID* param2;

      HRESULT hr = m_original->QueryInterface(param1, &param2);
      CHECK_CALL_RETURN_VALUE_HRESULT(hr);
    }
    break;

  case DXMethodCallHelper::TOK_IDirect3DVertexDeclaration9_AddRef:
    {
      ULONG result = m_original->AddRef();
      CHECK_CALL_RETURN_VALUE_ADDREF_RELEASE(ULONG, result);
    }
    break;

  case DXMethodCallHelper::TOK_IDirect3DVertexDeclaration9_Release:
    {
      ULONG result = m_original->Release();
      if (!result)
      {
        m_painter->RemoveStub(this);
        m_original = NULL;
      }
      CHECK_CALL_RETURN_VALUE_ADDREF_RELEASE(ULONG, result);
    }
    break;

  case DXMethodCallHelper::TOK_IDirect3DVertexDeclaration9_GetDevice:
    {
      DXResourceObjectID param1ResID;
      CHECK_CALL(call->Pop_DXResourceObjectID(&param1ResID));
      IDirect3DDevice9* param1;

      HRESULT hr = m_original->GetDevice(&param1);
      CHECK_CALL_RETURN_VALUE_HRESULT(hr);
    }
    break;

  case DXMethodCallHelper::TOK_IDirect3DVertexDeclaration9_GetDeclaration:
    {
      D3DVERTEXELEMENT9* arrElement;
      {
        DXIgnoredParameter ignoredParam;
        CHECK_CALL(call->Pop_DXIgnoredParameter(&ignoredParam));
      }

      UINT pNumElements;
      CHECK_CALL(call->Pop_UINT(&pNumElements));

      arrElement = new D3DVERTEXELEMENT9[pNumElements];
      
      HRESULT result = m_original->GetDeclaration(arrElement, &pNumElements);
      
      delete[] arrElement;
      
      CHECK_CALL_RETURN_VALUE_HRESULT(result);
    }
    break;
  }

  return E_NOTIMPL;
}

////////////////////////////////////////////////////////////////////////////////
