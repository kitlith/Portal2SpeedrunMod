#include "Portal2.hpp"

#include "Game.hpp"
#include "Offsets.hpp"

Portal2::Portal2()
{
    this->version = SourceGame_Portal2;
}
void Portal2::LoadOffsets()
{
    using namespace Offsets;

#ifdef _WIN32
    // engine.dll

    InternalSetValue = 12; // ConVar
    InternalSetFloatValue = 13; // ConVar
    InternalSetIntValue = 14; // ConVar
    ClientCmd = 7; // CEngineClient
    GetClientStateFunction = 4; // CEngineClient::ClientCmd
    Cbuf_AddText = 46; // CEngineClient::ClientCmd
    s_CommandBuffer = 82; // Cbuf_AddText
    CCommandBufferSize = 9556; // Cbuf_AddText
    m_bWaitEnabled = 8265; // CCommandBuffer::AddText
    GetActiveSplitScreenPlayerSlot = 127; // CEngineClient
    SetSignonState = 15; // CClientState
    HostState_OnClientConnected = 684; // CClientState::SetSignonState
    hoststate = 1; // HostState_OnClientConnected
    AutoCompletionFunc = 66; // listdemo_CompletionFunc
    ClientCommand = 39; // CVEngineServer
    TraceRay = 5; // IEngineTrace
    NextParticleSystem = 54; //IClientTools
    ProcessMovement = 1; // CGameMovement
    m_fFlags = 204; // CBaseEntity
    m_nTickBase = 3792; // CBaseEntity
    m_bDucking = 2272; // CBaseEntity
    m_hUseEntity = 2960; // CBaseEntity
    GetScreenSize = 5; // CEngineClient
    PrecacheModel = 62; // IEngineTool
    GetWorldToScreenMatrixForView = 80; // IEngineTool

    // client.dll

    GetHud = 125; // cc_leaderboard_enable
    FindElement = 135; // cc_leaderboard_enable
    ChatPrintf = 22; // CBaseHudChat
    RenderView = 26;
    HudUpdate = 11;

    // server.dll
    m_hActiveWeapon = 2140; // CBaseEntity
    m_bCanFirePortal1 = 1500; // CBaseEntity
    UTIL_PlayerByIndex = 39; // CServerGameDLL::Think
    gpGlobals = 14; // UTIL_PlayerByIndex
    Think = 31; // CServerGameDLL
    m_hGroundEntity = 344; // CBaseEntity
    GetIServerEntity = 1; // CServerTools
    m_EntPtrArray = 61; // CServerTools::GetIServerEntity
    CBaseEntityActivate = 37;
    CBaseEntitySpawn = 24;

    // vstdlib.dll

    RegisterConCommand = 9; // CCVar
    UnregisterConCommand = 10; // CCvar
    FindCommandBase = 13; // CCVar
    m_pConCommandList = 48; // CCvar

    // vscript.dll

    CreateVM = 8;

    // vgui2.dll

    GetIScheme = 8; // CSchemeManager
    GetFont = 3; // CScheme

    // vguimatsurface.dll

    DrawSetColor = 14; // CMatSystemSurface
    DrawFilledRect = 15; // CMatSystemSurface
    DrawLine = 18; // CMatSystemSurface
    DrawSetTextFont = 22; // CMatSystemSurface
    DrawSetTextColor = 23; // CMatSystemSurface
    GetFontTall = 72; // CMatSystemSurface
    PaintTraverseEx = 117; // CMatSystemSurface
    StartDrawing = 127; // CMatSystemSurface::PaintTraverseEx
    FinishDrawing = 603; // CMatSystemSurface::PaintTraverseEx
    DrawColoredText = 160; // CMatSystemSurface
    DrawTextLen = 163; // CMatSystemSurface
    DisableClipping = 156; // CMatSystemSurface
    Paint = 14; // CEngineVGui

    DrawGetTextureId = 33; // CMatSystemSurface
    DrawGetTextureFile = 34; // CMatSystemSurface
    DrawSetTextureFile = 35; // CMatSystemSurface
    DrawSetTextureRGBA = 36; // CMatSystemSurface
    DrawSetTexture = 37; // CMatSystemSurface
    DrawGetTextureSize = 38; // CMatSystemSurface
    DrawTexturedRect = 39; // CMatSystemSurface
    IsTextureIDValid = 40; // CMatSystemSurface
    CreateNewTextureID = 41; // CMatSystemSurface
#else
    // engine.so

    InternalSetValue = 19; // ConVar
    InternalSetFloatValue = 20; // ConVar
    InternalSetIntValue = 21; // ConVar
    ClientCmd = 7; // CEngineClient
    GetClientStateFunction = 11; // CEngineClient::ClientCmd
    Cbuf_AddText = 45; // CEngineClient::ClientCmd
    s_CommandBuffer = 69; // Cbuf_AddText
    CCommandBufferSize = 9556; // Cbuf_AddText
    m_bWaitEnabled = 8265; // CCommandBuffer::AddText
    GetActiveSplitScreenPlayerSlot = 127; // CEngineClient
    SetSignonState = 3; // CDemoRecorder
    HostState_OnClientConnected = 735; // CClientState::SetSignonState
    hoststate = 9; // HostState_OnClientConnected
    AutoCompletionFunc = 37; // listdemo_CompletionFunc
    ClientCommand = 39; // CVEngineServer
    // TraceRay = ; // IEngineTrace
    // NextParticleSystem = ;
    ProcessMovement = 2; // CGameMovement
    // m_fFlags = ; // CBaseEntity
    // m_nTickBase = ; // CBaseEntity
    // m_bDucking = ; // CBaseEntity
    // m_hUseEntity = ; // CBaseEntity
    GetScreenSize = 5; // CEngineClient
    // PrecacheModel = ; // IEngineTool
    // GetWorldToScreenMatrixForView = ; // IEngineTool

    // client.so

    GetHud = 104; // cc_leaderboard_enable
    FindElement = 120; // cc_leaderboard_enable
    // ChatPrintf = ; // CBaseHudChat
    // RenderView = ;
    HudUpdate = 11; // CHLClient

    // server.so

    // m_hActiveWeapon = ; // CBaseEntity
    // m_bCanFirePortal1 = ; // CBaseEntity
    UTIL_PlayerByIndex = 61; // CServerGameDLL::Think
    gpGlobals = 12; // UTIL_PlayerByIndex
    Think = 31; // CServerGameDLL
    GetIServerEntity = 2; // CServerTools
    m_EntPtrArray = 48; // CServerTools::GetIServerEntity
    // CBaseEntityActivate = ;
    // CBaseEntitySpawn = ;

    // libvstdlib.so

    RegisterConCommand = 9; // CCVar
    UnregisterConCommand = 10; // CCvar
    FindCommandBase = 13; // CCvar
    m_pConCommandList = 48; // CCvar

    // vscript.so

    // CreateVM = ;

    // vgui2.so

    GetIScheme = 9; // CSchemeManager
    GetFont = 4; // CScheme

    // vguimatsurface.so

    DrawSetColor = 13; // CMatSystemSurface
    DrawFilledRect = 15; // CMatSystemSurface
    DrawLine = 18; // CMatSystemSurface
    DrawSetTextFont = 22; // CMatSystemSurface
    DrawSetTextColor = 24; // CMatSystemSurface
    GetFontTall = 72; // CMatSystemSurface
    PaintTraverseEx = 117; // CMatSystemSurface
    StartDrawing = 193; // CMatSystemSurface::PaintTraverseEx
    FinishDrawing = 590; // CMatSystemSurface::PaintTraverseEx
    DrawColoredText = 160; // CMatSystemSurface
    DrawTextLen = 163; // CMatSystemSurface
    // DisableClipping = ; // CMatSystemSurface
    Paint = 15; // CEngineVGui

    // DrawGetTextureId = ; // CMatSystemSurface
    // DrawGetTextureFile = ; // CMatSystemSurface
    // DrawSetTextureFile = ; // CMatSystemSurface
    // DrawSetTextureRGBA = ; // CMatSystemSurface
    // DrawSetTexture = ; // CMatSystemSurface
    // DrawGetTextureSize = ; // CMatSystemSurface
    // DrawTexturedRect = ; // CMatSystemSurface
    // IsTextureIDValid = ; // CMatSystemSurface
    // CreateNewTextureID = ; // CMatSystemSurface
#endif
}

const char* Portal2::Version()
{
#ifdef _WIN32
    return "Portal 2 (7054)";
#else
    return "Portal 2 (7293)";
#endif
}

const char* Portal2::Process()
{
#ifdef _WIN32
    return "portal2.exe";
#else
    return "portal2";
#endif
}
