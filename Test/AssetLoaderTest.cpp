#include "AssetLoader.hpp"
#include "MemoryManager.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace My;

namespace My {
    IMemoryManager* g_pMemoryManager = new MemoryManager();
    AssetLoader*   g_pAssetLoader = new AssetLoader();
}

int main(int , char** )
{
    g_pMemoryManager->Initialize();
    g_pAssetLoader->Initialize();

#ifdef __ORBIS__
    g_pAssetLoader->AddSearchPath("/app0");
#endif
    string shader_pgm = g_pAssetLoader->SyncOpenAndReadTextFileToString("Shaders/HLSL/basic.vert.hlsl");

    cout << shader_pgm;

    g_pAssetLoader->Finalize();
    g_pMemoryManager->Finalize();

    delete g_pAssetLoader;
    delete g_pMemoryManager;

    return 0;
}

