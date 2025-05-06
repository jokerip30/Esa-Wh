#pragma once
#include <d3dx9.h>
#include <dinput.h>
extern int ANTI_TEAMVIEW;
extern int TV_SHUTDOWN;
extern int MenuFolder[100];
extern int KillerKey;
extern char* Opt_OnOff[];
extern char* Opt_Folder[];
extern char* Opt_AimHeight[];
extern char* Opt_AimKey[];
extern char* Opt_Aim[];
extern char* Opt_Enemy[];
extern char* Opt_Enemy1[];
extern char* Opt_Enemy2[];
extern char* Opt_Enemy3[];
extern char* Opt_Enemy4[];
extern char* Opt_Enemy5[];
extern char Victim[60];
extern char* optVictim[];
extern char* Opt_Target[];
extern char* Opt_Tale[];
extern char* Opt_SavePosion[];
extern char* Opt_AimFov[];
extern char* Opt_SavePosion2[];
extern char* Moptonoff[];
extern char* Opt_Ammotype[];
extern char* Opt_Line[];
extern char* Opt_ESPBox[];
extern char* Opt_ColorCheat[];
extern char* Opt_SetWin[];
extern char* Opt_SetLose[];
extern char* Opt_Setkill[];
extern char* Opt_SetDeadth[];
extern char* Opt_SetAssists[];
extern char* Opt_SetMission[];
extern char* Opt_SetHeadshot[];
extern char* Opt_SetTeamkill[];
extern char* Opt_GameCount[];
extern char* Opt_GameType[];
extern char* Opt_Sp[];
unsigned long GetColorFromMenu(int menuIndex);
extern int antiTeamView;
extern int tvShutdown;
extern int MenuItem[100];
extern LPD3DXFONT pFont;
bool menuVisible = true;
int menuX = 50, menuY = 50;
int selectedItem = 0;
int totalItems = 0;
// Drag variables
bool draggingMenu = false;
int dragOffsetX = 0, dragOffsetY = 0;
LPDIRECT3DDEVICE9 Device = nullptr; // หรือกำหนดจาก EndScene/DrawIndexedPrimitive
extern LPDIRECT3DDEVICE9 Device;
float fFps = 0.0f;
float fLastTickCount = 0.0f;
float fCurrentTickCount;
char cFrameRate[50] = { 0 };

void FillRect(int x, int y, int w, int h, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice) {
    D3DRECT rect = { x, y, x + w, y + h };
    pDevice->Clear(1, &rect, D3DCLEAR_TARGET, color, 0, 0);

}
void FillGradientRect(int x, int y, int w, int h, D3DCOLOR color1, D3DCOLOR color2, LPDIRECT3DDEVICE9 pDevice) {
    for (int i = 0; i < h; i++) {
        float alpha = (float)i / h; // Calculate gradient alpha
        int r = static_cast<int>((color1 >> 16 & 0xFF) * (1 - alpha) + (color2 >> 16 & 0xFF) * alpha);
        int g = static_cast<int>((color1 >> 8 & 0xFF) * (1 - alpha) + (color2 >> 8 & 0xFF) * alpha);
        int b = static_cast<int>((color1 & 0xFF) * (1 - alpha) + (color2 & 0xFF) * alpha);
        D3DCOLOR color = D3DCOLOR_ARGB(255, r, g, b);
        FillRect(x, y + i, w, 1, color, pDevice); // Draw each row
    }
}
bool WorldToScreen(D3DXVECTOR3 worldPos, D3DXVECTOR3* screenPos, LPDIRECT3DDEVICE9 pDevice) {

    D3DVIEWPORT9 viewport;
    D3DXMATRIX projection, view, world;
    pDevice->GetViewport(&viewport);
    pDevice->GetTransform(D3DTS_PROJECTION, &projection);
    pDevice->GetTransform(D3DTS_VIEW, &view);
    D3DXMatrixIdentity(&world); // Use the default world matrix
    D3DXVec3Project(screenPos, &worldPos, &viewport, &projection, &view, &world);
    return (screenPos->z < 1.0f && screenPos->z > 0.0f); // Check if it's on screen
}
void DrawBorder(int x, int y, int w, int h, int px, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice) {FillRect(x, y, w, px, color, pDevice);
    FillRect(x, y + h - px, w, px, color, pDevice);
    FillRect(x, y, px, h, color, pDevice);
    FillRect(x + w - px, y, px, h, color, pDevice);
}

void DrawBox(int x, int y, int w, int h, D3DCOLOR fillColor, D3DCOLOR borderColor, LPDIRECT3DDEVICE9 pDevice) {
    FillRect(x, y, w, h, fillColor, pDevice);
    DrawBorder(x, y, w, h, 2, borderColor, pDevice);
}
void DrawTextSimple(int x, int y, DWORD color, const char* text) {
    RECT rect = { x, y, x + 300, y + 20 };
    pFont->DrawTextA(NULL, text, -1, &rect, DT_LEFT | DT_NOCLIP, color);
}
void MenuItemToggle(const char* label, int& value, int max) {
    if (selectedItem == totalItems) {
        if (IsKeyboardKeyDownOnce(DIK_RIGHT)) value = (value + 1) % max;
        if (IsKeyboardKeyDownOnce(DIK_LEFT)) value = (value - 1 + max) % max;
    }
    D3DCOLOR labelColor = D3DCOLOR_ARGB(255, 255, 255, 255);
    D3DCOLOR valueColor = (value == 1 || value == 2 || value == 3 || value == 4) ? D3DCOLOR_ARGB(255, 0, 255, 0) : D3DCOLOR_ARGB(255, 255, 50, 50);
    if (selectedItem == totalItems) labelColor = D3DCOLOR_ARGB(255, 255, 255, 100);
    int textY = menuY + 40 + totalItems * 22;
    DrawTextSimple(menuX + 15, textY, labelColor, label);
    const char* status = (value == 1) ? "ON" : "OFF";
    DrawTextSimple(menuX + 150, textY, valueColor, status);
    totalItems++;
}
void MenuItemArray(const char* label, int& value, char** options, int maxOptions) {
    // ตรวจสอบว่าตัวเลือกตรงกับรายการที่เลือกหรือไม่
    if (selectedItem == totalItems) {
        if (IsKeyboardKeyDownOnce(DIK_RIGHT)) value = (value + 1) % maxOptions;
        if (IsKeyboardKeyDownOnce(DIK_LEFT)) value = (value - 1 + maxOptions) % maxOptions;
    }
    // กำหนดสีให้กับรายการเมนู
    D3DCOLOR labelColor = D3DCOLOR_ARGB(255, 255, 255, 255); // สีของ label ปกติ
    D3DCOLOR valueColor = (value == 1 || value == 2 || value == 3 || value == 4) ? D3DCOLOR_ARGB(255, 0, 255, 0) : D3DCOLOR_ARGB(255, 255, 50, 50); // สีตัวเลือก
    if (selectedItem == totalItems) {
        labelColor = D3DCOLOR_ARGB(255, 255, 98, 0); // เปลี่ยนสีเฉพาะเมื่อตัวเลือกถูกเลือก (สีฟ้า)
        valueColor = D3DCOLOR_ARGB(255, 196, 22, 170); // เปลี่ยนสีเฉพาะตัวเลือกเมื่อถูกเลือก (สีเหลือง)
    } else {
        valueColor = D3DCOLOR_ARGB(255, 255, 255, 255); // หากไม่มีการเลือกให้ตั้งค่าสีให้เป็นสีขาว
    }
    // จัดตำแหน่งและวาดข้อความ
    int textY = menuY + 40 + totalItems * 22;
    DrawTextSimple(menuX + 15, textY, labelColor, label);
    DrawTextSimple(menuX + 220, textY, valueColor, options[value]);
    totalItems++;
}
void HandleMenuNavigation() {
    if (IsKeyboardKeyDownOnce(DIK_DOWN)) selectedItem++;
    if (IsKeyboardKeyDownOnce(DIK_UP)) selectedItem--;
    if (selectedItem >= totalItems) selectedItem = 0;
    if (selectedItem < 0) selectedItem = totalItems - 1;
}
void UpdateMenuDrag() {
    if (draggingMenu) {
        POINT mousePos;
        GetCursorPos(&mousePos);
        menuX = mousePos.x - dragOffsetX;
        menuY = mousePos.y - dragOffsetY;
    }
}
HRESULT APIENTRY IDirect3DDevice9::EndScene()
{
    fCurrentTickCount = clock() * 0.001f;
    ++fFps;
    if ((fCurrentTickCount - fLastTickCount) > 1.0f)
    {
        fLastTickCount = fCurrentTickCount;
        sprintf(cFrameRate, "[ FPS: %d ]", int(fFps));
        fFps = 0;
    }
    return Device->EndScene();
}

bool IsMouseOverMenu() {
    POINT mousePos;
    GetCursorPos(&mousePos);
    return (mousePos.x >= menuX && mousePos.x <= menuX + 250 && mousePos.y >= menuY && mousePos.y <= menuY + 30);
}

void StartMenuDrag() {
    POINT mousePos;
    GetCursorPos(&mousePos);
    dragOffsetX = mousePos.x - menuX;
    dragOffsetY = mousePos.y - menuY;
    draggingMenu = true;
}

void StopMenuDrag() {
    draggingMenu = false;
}

void HandleMenuInput() {
    if (IsMouseOverMenu() && (GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
        StartMenuDrag();
    }
    else if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
        StopMenuDrag();
    }
}

bool WorldToScreen(LPDIRECT3DDEVICE9 pDevice, const D3DXVECTOR3& worldPos, D3DXVECTOR3* screenPos) {
    D3DVIEWPORT9 viewport;
    D3DXMATRIX projection, view, world;

    if (FAILED(pDevice->GetViewport(&viewport))) return false;
    if (FAILED(pDevice->GetTransform(D3DTS_PROJECTION, &projection))) return false;
    if (FAILED(pDevice->GetTransform(D3DTS_VIEW, &view))) return false;
    D3DXMatrixIdentity(&world); // ใช้ world matrix เป็น Identity

    D3DXVec3Project(screenPos, &worldPos, &viewport, &projection, &view, &world);

    // ตรวจสอบว่าอยู่ในหน้าจอ
    if (screenPos->z < 1.0f && screenPos->z > 0.0f)
        return true;

    return false;
}

void DrawTextSmooth(int x, int y, DWORD color, const char* text) {
    RECT rect = { x, y, x + 250, y + 20 };
    pFont->DrawTextA(NULL, text, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE, color);
}

void DrawTextSimple(LPDIRECT3DDEVICE9 pDevice, int x, int y, D3DCOLOR color, const char* text)
{
    ID3DXFont* pFont = NULL;
    D3DXFONT_DESC fontDesc = {
        24,                  // ขนาดตัวอักษร (ปรับเป็น 24 เพื่อขนาดที่ใหญ่ขึ้น)
        0,                   // Width
        FW_NORMAL,           // หน้าตัวอักษร
        1,                   // สไตล์
        FALSE,               // ไม่ใช่ตัวอักษรเอียง
        FALSE,               // ไม่ใช่ตัวอักษรหนา
        DEFAULT_CHARSET,     // ชุดอักษร
        OUT_DEFAULT_PRECIS,  // การแสดงผล
        CLIP_DEFAULT_PRECIS, // การตัดคำ
        ANTIALIASED_QUALITY, // คุณภาพของตัวอักษร
        DEFAULT_PITCH,       // ขนาดตัวอักษร
        "Arial"              // ฟอนต์ที่ใช้
    };

    // สร้างฟอนต์
    if (FAILED(D3DXCreateFontIndirect(pDevice, &fontDesc, &pFont)))
        return;

    RECT rect = { x, y, x + 1000, y + 100 }; // ขนาดกล่องข้อความ
    pFont->DrawTextA(NULL, text, -1, &rect, DT_NOCLIP | DT_CENTER | DT_VCENTER, color); // วาดข้อความ

    if (pFont)
        pFont->Release();
}

void RenderMenu(LPDIRECT3DDEVICE9 pDevice)
{
    int menuX = 50; // ตำแหน่ง X ของเมนู
    int menuY = 50; // ตำแหน่ง Y ของเมนู

    // วาดข้อความ "Special Force NEW 25/4/2025"
    DrawTextSimple(pDevice, menuX + 8, menuY + 4, D3DCOLOR_ARGB(255, 72, 255, 0), "Special Force NEW 25/4/2025");
}

void DrawBoxWithText(int x, int y, int w, int h, D3DCOLOR fillColor, D3DCOLOR borderColor, const char* label, LPDIRECT3DDEVICE9 pDevice) {
    FillRect(x, y, w, h, fillColor, pDevice);  // Background box
    DrawBorder(x, y, w, h, 2, borderColor, pDevice);  // Box border
    DrawTextSmooth(x + w / 2, y + h / 2 - 10, D3DCOLOR_ARGB(255, 255, 255, 255), label);  // Center text
}

void RenderCustomMenu(LPDIRECT3DDEVICE9 pDevice) {
    if (IsKeyboardKeyDownOnce(DIK_INSERT))
        menuVisible = !menuVisible; // Toggle menu visibility

    if (!menuVisible) return;

    totalItems = 0; // Reset item count
    HandleMenuInput();   // ลูกศรขึ้นลง ซ้ายขวา
    UpdateMenuDrag();    // ลากเมนูด้วยเมาส์

    // พื้นหลังเมนู
    FillGradientRect(menuX, menuY, 250, 240,
        D3DCOLOR_ARGB(255, 0, 76, 255), D3DCOLOR_ARGB(255, 0, 0, 128), pDevice);

    // หัวเมนู
    DrawBox(menuX, menuY, 250, 20,
        D3DCOLOR_ARGB(255, 0, 76, 255), D3DCOLOR_ARGB(255, 0, 76, 255), pDevice);
   /* DrawTextSimple(menuX + 8, menuY + 4,
        D3DCOLOR_ARGB(255, 72, 255, 0), "           Special Force NEW 25/4/2025");*/

    // ===== ESP MENU =====

    MenuItemArray("Crosshair", MenuItem[1], Opt_OnOff, 2);

    MenuItemArray("ESP Box", MenuItem[2], Opt_ESPBox, 3);

    MenuItemArray("Skeleton", MenuItem[3], Opt_OnOff, 2);

    MenuItemArray("Box Color", MenuItem[500], Opt_ColorCheat, 5);

    MenuItemArray("Skeleton Color", MenuItem[600], Opt_ColorCheat, 5);

    MenuItemArray("Health", MenuItem[4], Opt_OnOff, 2);

    MenuItemArray("No Recoil", MenuItem[13], Opt_OnOff, 2);

    // ===== AIMBOT MENU =====

    MenuItemArray("Aimbot", MenuItem[9], Opt_OnOff, 2);

    MenuItemArray("Left Click Lock", MenuItem[11], Opt_AimKey, 2);

    HandleMenuNavigation();
}


bool WorldToScreen(const D3DXVECTOR3& worldPos, D3DXVECTOR3* screenPos) {
    D3DVIEWPORT9 viewport;
    D3DXMATRIX projection, view, world;
    D3DXVec3Project(screenPos, &worldPos, &viewport, &projection, &view, &world);
    return true;
}

