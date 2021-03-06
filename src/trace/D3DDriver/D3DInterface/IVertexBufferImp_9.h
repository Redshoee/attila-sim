#ifndef IVERTEXBUFFERIMP_9_H_INCLUDED
#define IVERTEXBUFFERIMP_9_H_INCLUDED

class IDeviceImp9;

class IVertexBufferImp9 : public IDirect3DVertexBuffer9 {
public:
   /// Singleton method, maintained to allow unimplemented methods to return valid interface addresses.
    static IVertexBufferImp9 &getInstance();

    IVertexBufferImp9(StateDataNode* s_parent, IDeviceImp9* i_parent, UINT Length , DWORD Usage , DWORD FVF , D3DPOOL Pool);
private:
    /// Singleton constructor method
    IVertexBufferImp9();

    IDeviceImp9* i_parent;
    StateDataNode* state;

    ULONG refs;

public:

    HRESULT D3D_CALL QueryInterface (  REFIID riid , void** ppvObj );
    ULONG D3D_CALL AddRef ( );
    ULONG D3D_CALL Release ( );
    HRESULT D3D_CALL GetDevice (  IDirect3DDevice9** ppDevice );
    HRESULT D3D_CALL SetPrivateData (  REFGUID refguid , CONST void* pData , DWORD SizeOfData , DWORD Flags );
    HRESULT D3D_CALL GetPrivateData (  REFGUID refguid , void* pData , DWORD* pSizeOfData );
    HRESULT D3D_CALL FreePrivateData (  REFGUID refguid );
    DWORD D3D_CALL SetPriority (  DWORD PriorityNew );
    DWORD D3D_CALL GetPriority ( );
    void D3D_CALL PreLoad ( );
    D3DRESOURCETYPE D3D_CALL GetType ( );
    HRESULT D3D_CALL Lock (  UINT OffsetToLock , UINT SizeToLock , void** ppbData , DWORD Flags );
    HRESULT D3D_CALL Unlock ( );
    HRESULT D3D_CALL GetDesc (  D3DVERTEXBUFFER_DESC * pDesc );

};

#endif

