#pragma once

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
//#include <detours.h>
#include <stdio.h>
#include "OFFSET.h"
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#define D3DCOLOR_GREEN D3DCOLOR_ARGB(255, 0, 255, 0)
ID3DXFont* pD3DFont = NULL;
LPD3DXLINE pLine = NULL;
LPD3DXFONT pFont = NULL;

int MenuItem[100];
int aimfov;

enum D3D_VTABLE_INDEX
{
	QUERYINTERFACE_INDEX,
	ADDREF_INDEX,
	RELEASE_INDEX,
	TESTCOOPERATIVELEVEL_INDEX,
	GETAVAILABLETEXTUREMEM_INDEX,
	EVICTMANAGEDRESOURCES_INDEX,
	GETDIRECT3D_INDEX,
	GETDEVICECAPS_INDEX,
	GETDISPLAYMODE_INDEX,
	GETCREATIONPARAMETERS_INDEX,
	SETCURSORPROPERTIES_INDEX,
	SETCURSORPOSITION_INDEX,
	SHOWCURSOR_INDEX,
	CREATEADDITIONALSWAPCHAIN_INDEX,
	GETSWAPCHAIN_INDEX,
	GETNUMBEROFSWAPCHAINS_INDEX,
	RESET_INDEX,
	PRESENT_INDEX,
	GETBACKBUFFER_INDEX,
	GETRASTERSTATUS_INDEX,
	SETDIALOGBOXMODE_INDEX,
	SETGAMMARAMP_INDEX,
	GETGAMMARAMP_INDEX,
	CREATETEXTURE_INDEX,
	CREATEVOLUMETEXTURE_INDEX,
	CREATECUBETEXTURE_INDEX,
	CREATEVERTEXBUFFER_INDEX,
	CREATEINDEXBUFFER_INDEX,
	CREATERENDERTARGET_INDEX,
	CREATEDEPTHSTENCILSURFACE_INDEX,
	UPDATESURFACE_INDEX,
	UPDATETEXTURE_INDEX,
	GETRENDERTARGETDATA_INDEX,
	GETFRONTBUFFERDATA_INDEX,
	STRETCHRECT_INDEX,
	COLORFILL_INDEX,
	CREATEOFFSCREENPLAINSURFACE_INDEX,
	SETRENDERTARGET_INDEX,
	GETRENDERTARGET_INDEX,
	SETDEPTHSTENCILSURFACE_INDEX,
	GETDEPTHSTENCILSURFACE_INDEX,
	BEGINSCENE_INDEX,
	ENDSCENE_INDEX,
	CLEAR_INDEX,
	SETTRANSFORM_INDEX,
	GETTRANSFORM_INDEX,
	MULTIPLYTRANSFORM_INDEX,
	SETVIEWPORT_INDEX,
	GETVIEWPORT_INDEX,
	SETMATERIAL_INDEX,
	GETMATERIAL_INDEX,
	SETLIGHT_INDEX,
	GETLIGHT_INDEX,
	LIGHTENABLE_INDEX,
	GETLIGHTENABLE_INDEX,
	SETCLIPPLANE_INDEX,
	GETCLIPPLANE_INDEX,
	SETRENDERSTATE_INDEX,
	GETRENDERSTATE_INDEX,
	CREATESTATEBLOCK_INDEX,
	BEGINSTATEBLOCK_INDEX,
	ENDSTATEBLOCK_INDEX,
	SETCLIPSTATUS_INDEX,
	GETCLIPSTATUS_INDEX,
	GETTEXTURE_INDEX,
	SETTEXTURE_INDEX,
	GETTEXTURESTAGESTATE_INDEX,
	SETTEXTURESTAGESTATE_INDEX,
	GETSAMPLERSTATE_INDEX,
	SETSAMPLERSTATE_INDEX,
	VALIDATEDEVICE_INDEX,
	SETPALETTEENTRIES_INDEX,
	GETPALETTEENTRIES_INDEX,
	SETCURRENTTEXTUREPALETTE_INDEX,
	GETCURRENTTEXTUREPALETTE_INDEX,
	SETSCISSORRECT_INDEX,
	GETSCISSORRECT_INDEX,
	SETSOFTWAREVERTEXPROCESSING_INDEX,
	GETSOFTWAREVERTEXPROCESSING_INDEX,
	SETNPATCHMODE_INDEX,
	GETNPATCHMODE_INDEX,
	DRAWPRIMITIVE_INDEX,
	DRAWINDEXEDPRIMITIVE_INDEX,
	DRAWPRIMITIVEUP_INDEX,
	DRAWINDEXEDPRIMITIVEUP_INDEX,
	PROCESSVERTICES_INDEX,
	CREATEVERTEXDECLARATION_INDEX,
	SETVERTEXDECLARATION_INDEX,
	GETVERTEXDECLARATION_INDEX,
	SETFVF_INDEX,
	GETFVF_INDEX,
	CREATEVERTEXSHADER_INDEX,
	SETVERTEXSHADER_INDEX,
	GETVERTEXSHADER_INDEX,
	SETVERTEXSHADERCONSTANTF_INDEX,
	GETVERTEXSHADERCONSTANTF_INDEX,
	SETVERTEXSHADERCONSTANTI_INDEX,
	GETVERTEXSHADERCONSTANTI_INDEX,
	SETVERTEXSHADERCONSTANTB_INDEX,
	GETVERTEXSHADERCONSTANTB_INDEX,
	SETSTREAMSOURCE_INDEX,
	GETSTREAMSOURCE_INDEX,
	SETSTREAMSOURCEFREQ_INDEX,
	GETSTREAMSOURCEFREQ_INDEX,
	SETINDICES_INDEX,
	GETINDICES_INDEX,
	CREATEPIXELSHADER_INDEX,
	SETPIXELSHADER_INDEX,
	GETPIXELSHADER_INDEX,
	SETPIXELSHADERCONSTANTF_INDEX,
	GETPIXELSHADERCONSTANTF_INDEX,
	SETPIXELSHADERCONSTANTI_INDEX,
	GETPIXELSHADERCONSTANTI_INDEX,
	SETPIXELSHADERCONSTANTB_INDEX,
	GETPIXELSHADERCONSTANTB_INDEX,
	DRAWRECTPATCH_INDEX,
	DRAWTRIPATCH_INDEX,
	DELETEPATCH_INDEX,
	CREATEQUERY_INDEX,
};

void DrawLineSet(float x1, float y1, float x2, float y2, D3DXCOLOR color, IDirect3DDevice9* pDevice)
{
	D3DXVECTOR2 vLine[2];

	pLine->SetWidth(1);
	pLine->SetAntialias(false);
	pLine->SetGLLines(true);

	vLine[0].x = (float)x1;
	vLine[0].y = (float)y1;
	vLine[1].x = (float)x2;
	vLine[1].y = (float)y2;

	pLine->Begin();
	pLine->Draw(vLine, 2, color);
	pLine->End();

}

void DrawLine(float x1, float y1, float x2, float y2, D3DXCOLOR color, IDirect3DDevice9* pDevice)
{
	D3DXVECTOR2 vLine[2];

	pLine->SetWidth(2);
	pLine->SetAntialias(false);
	pLine->SetGLLines(true);

	vLine[0].x = (float)x1;
	vLine[0].y = (float)y1;
	vLine[1].x = (float)x2;
	vLine[1].y = (float)y2;

	pLine->Begin();
	pLine->Draw(vLine, 2, color);
	pLine->End();

}

IDirect3DPixelShader9* pShader;

struct D3DTLVERTEX
{
	float x, y, z, rhw;
	DWORD color;
};

D3DTLVERTEX CreateD3DTLVERTEX(float X, float Y, float Z, float RHW, D3DCOLOR color)
{
	D3DTLVERTEX v = { X, Y, Z, RHW, color };
	return v;
}

void DrawLineX(LPDIRECT3DDEVICE9 pDevice, float x, float y, float x2, float y2, D3DCOLOR dwColor)
{
	D3DTLVERTEX qV[2] = {
		{ (float)x , (float)y, 0.0f, 1.0f, dwColor },
		{ (float)x2 , (float)y2 , 0.0f, 1.0f, dwColor },
	};

	pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	pDevice->SetTexture(0, NULL);
	pDevice->SetPixelShader(pShader);

	pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);
	pDevice->DrawPrimitiveUP(D3DPT_LINELIST, 2, qV, sizeof(D3DTLVERTEX));
	pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);

	pDevice->SetTexture(0, NULL);
	pDevice->SetPixelShader(pShader);
}

void DrawCircle2(IDirect3DDevice9* pDevice, int x, int y, float radius, int Sides, D3DCOLOR dwColor)
{
	const int NUMPOINTS = 24;
	D3DTLVERTEX Circle[NUMPOINTS + 1];
	int i;
	float X;
	float Y;
	float Theta;
	float WedgeAngle = (float)((2 * D3DX_PI) / NUMPOINTS);

	for (i = 0; i <= NUMPOINTS; i++)
	{
		Theta = i * WedgeAngle;
		X = (float)(x + radius * cos(Theta));
		Y = (float)(y - radius * sin(Theta));
		Circle[i] = CreateD3DTLVERTEX((float)X, (float)Y, 0.0f, 1.0f, dwColor);
	}

	pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	pDevice->SetTexture(0, NULL);
	pDevice->SetPixelShader(pShader);

	pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);
	pDevice->DrawPrimitiveUP(D3DPT_LINESTRIP, NUMPOINTS, &Circle[0], sizeof(Circle[0]));
	pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_STENCILENABLE, TRUE);

	pDevice->SetTexture(0, NULL);
	pDevice->SetPixelShader(pShader);
}

void FillRGB(int x, int y, int w, int h, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice)
{
	D3DRECT rec = { x, y, x + w, y + h };
	pDevice->Clear(1, &rec, D3DCLEAR_TARGET, color, 0, 0);
	return;
}

void DrawBorder(int x, int y, int w, int h, int px, D3DCOLOR BorderColor, D3DCOLOR Color, IDirect3DDevice9* pDevice)
{
	FillRGB(x, (y + h - 2), w, 2, Color, pDevice);
	FillRGB(x, y, 2, h, Color, pDevice);
	FillRGB(x, y, w, 2, Color, pDevice);
	FillRGB((x + w - 2), y, 2, h, Color, pDevice);

	FillRGB(x, (y + h - px), w, px, BorderColor, pDevice);
	FillRGB(x, y, px, h, BorderColor, pDevice);
	FillRGB(x, y, w, px, BorderColor, pDevice);
	FillRGB((x + w - px), y, px, h, BorderColor, pDevice);
}

void DrawHealthBar_0(int x, int y, float health, int w, int h, D3DCOLOR color, D3DCOLOR color1, IDirect3DDevice9* pDevice)
{
	// วาดพื้นหลังของ Health Bar
	FillRGB(x, y, w, h + 1, color1, pDevice);

	// คำนวณขนาดของ Health Bar ตามเปอร์เซ็นต์ของสุขภาพ
	UINT hh = (UINT)(((h - 2) * health) / 100);  // ใช้ health คำนวณขนาด

	// วาดส่วนที่เติมของ Health Bar (ด้านล่างสุดที่มีสี)
	FillRGB(x + 1, y + (h - hh) - 1, w - 1, hh, color, pDevice);
}




int DrawText(char* String, int x, int y, D3DCOLOR color, ID3DXFont* ifont)
{
	RECT Font;
	Font.bottom = 0;
	Font.left = x;
	Font.top = y;
	Font.right = 0;

	ifont->DrawTextA(0, String, strlen(String), &Font, DT_NOCLIP, color);

	return 0;
}

void DrawOutlineText(char* String, int x, int y, D3DCOLOR color, ID3DXFont* ifont)
{
	DrawText(String, x - 1, y, D3DCOLOR_ARGB(255, 0, 0, 0), ifont);
	DrawText(String, x + 1, y, D3DCOLOR_ARGB(255, 0, 0, 0), ifont);
	DrawText(String, x, y - 1, D3DCOLOR_ARGB(255, 0, 0, 0), ifont);
	DrawText(String, x, y + 1, D3DCOLOR_ARGB(255, 0, 0, 0), ifont);
	DrawText(String, x, y, color, ifont);
}

#define RED D3DCOLOR_ARGB(255, 255, 0, 0)
#define GREEN D3DCOLOR_ARGB(255, 0, 255, 0)
#define BLUE D3DCOLOR_ARGB(255, 0, 0, 255)
#define WHITE D3DCOLOR_ARGB(255, 255, 255, 255)
#define BLACK D3DCOLOR_ARGB(255, 0, 0, 0)
#define YELLOW D3DCOLOR_ARGB(255, 255, 255, 0)
#define TEAL D3DCOLOR_ARGB(255, 0, 255, 255)
#define PINK D3DCOLOR_ARGB(255, 255, 240, 0)
#define ORANGE D3DCOLOR_ARGB(255, 255, 132, 0)
#define LIME D3DCOLOR_ARGB(255, 198, 255, 0)
#define SKYBLUE D3DCOLOR_ARGB(255, 0, 180, 255)
#define MAROON D3DCOLOR_ARGB(255, 142, 30, 0)
#define LGRAY D3DCOLOR_ARGB(255, 174, 174, 174) //Light Gray
#define DGRAY D3DCOLOR_ARGB(255, 71, 65, 64) //Dark Gray
#define BROWN D3DCOLOR_ARGB(255, 77, 46, 38)
#define SHIT D3DCOLOR_ARGB(255, 74, 38, 38) //Shit and brown aint much different
#define PURPLE D3DCOLOR_ARGB(255, 125, 000, 255) 
#define GREY D3DCOLOR_ARGB(255, 128, 128, 128) 

D3DCOLOR black = D3DCOLOR_XRGB(0, 0, 0);
D3DCOLOR gray = D3DCOLOR_XRGB(175, 175, 175);
D3DCOLOR white = D3DCOLOR_XRGB(255, 255, 255);
D3DCOLOR red = D3DCOLOR_XRGB(255, 0, 0);
D3DCOLOR orange = D3DCOLOR_XRGB(255, 128, 0);
D3DCOLOR yellow = D3DCOLOR_XRGB(255, 242, 0);
D3DCOLOR green = D3DCOLOR_XRGB(0, 255, 0);
D3DCOLOR lime = D3DCOLOR_XRGB(128, 255, 0);
D3DCOLOR green_dark = D3DCOLOR_XRGB(0, 128, 0);
D3DCOLOR blue = D3DCOLOR_XRGB(0, 0, 255);
D3DCOLOR cyan = D3DCOLOR_XRGB(0, 128, 255);
D3DCOLOR purple = D3DCOLOR_XRGB(255, 0, 255);

#define Red		D3DCOLOR_ARGB(255, 255, 000, 000)
#define Green	D3DCOLOR_ARGB(255, 0, 255, 34)
#define Blue	D3DCOLOR_ARGB(255, 63, 50, 226)
#define White	D3DCOLOR_ARGB(255, 255, 255, 255)
#define Black	D3DCOLOR_ARGB(255, 000, 000, 000)
#define Yellow	D3DCOLOR_ARGB(255, 255, 255, 000)
#define Purple	D3DCOLOR_ARGB(255, 100, 000, 150)
#define Pink	D3DCOLOR_ARGB(255, 255, 020, 145)
#define Orange	D3DCOLOR_ARGB(255, 255, 165, 000)
#define Grey	D3DCOLOR_ARGB(255, 128, 128, 128)
#define TGrey	D3DCOLOR_ARGB(10, 128, 128, 128)
#define Cyan	D3DCOLOR_ARGB(255, 0, 142, 210)
#define TBlack  D3DCOLOR_ARGB(200, 0, 0, 0)
#define TBlack2  D3DCOLOR_ARGB(150, 0, 0, 0)
#define TBlue	D3DCOLOR_ARGB(200, 63, 50, 226)

#define TBlackB			D3DCOLOR_ARGB(200, 13, 7, 0)
#define Seletor			D3DCOLOR_ARGB(255, 89, 87, 87)
#define RedVinho		D3DCOLOR_ARGB(255, 122, 0, 0)
#define TGrayBlack		D3DCOLOR_ARGB(255, 42, 42, 42)
#define TGrayEdited		D3DCOLOR_ARGB(150, 50, 50, 50)
#define Green2			D3DCOLOR_ARGB(255, 28, 57, 24)

#define HOOK(func,addy)	o##func = (t##func)DetourFunction((PBYTE)addy,(PBYTE)hk##func)

typedef HRESULT(WINAPI* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene;

typedef HRESULT(WINAPI* tReset)(LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
tReset oReset;


int pNADEid = 0;
int pNADEf = 0;
int pNADEs = 0;

D3DVIEWPORT9 viewPort;
D3DXVECTOR3* GetScreenCoordFromWorld(D3DXVECTOR3& vScreenCoord, D3DXVECTOR3 vWorldLocation, LPDIRECT3DDEVICE9 pDevice) {
	if (!pDevice)
		return NULL;

	D3DXMATRIX projection, view, world, identity;

	pDevice->GetTransform(D3DTS_VIEW, &view);
	pDevice->GetTransform(D3DTS_PROJECTION, &projection);
	pDevice->GetTransform(D3DTS_WORLD, &world);
	pDevice->GetViewport(&viewPort);

	D3DXMatrixIdentity(&identity);

	viewPort.MinZ = 0;
	viewPort.MaxZ = 1;

	D3DXVec3Project(&vScreenCoord, &vWorldLocation, &viewPort, &projection, &view, &identity);

	if (vScreenCoord.z < 1)
	{
		return &vScreenCoord;
	}
	return NULL;
}

void PrintText2(PCHAR text, UINT X, UINT Y, D3DCOLOR Color, LPD3DXFONT Font)
{
	RECT rct;
	rct.top = Y;
	rct.left = X;

	Font->DrawText(NULL, text, -1, &rct, DT_NOCLIP, Color);
}

// นิยามฟังก์ชันวาดหลอด HP แนวตั้ง (main.h)
inline void DrawVerticalHealthBar(
	int x, int y, float health,
	int height, int width,
	D3DCOLOR fillColor, D3DCOLOR backColor,
	IDirect3DDevice9* pDevice)
{
	// พื้นหลังหลอด
	FillRGB(x, y, width, height, backColor, pDevice);

	// ความสูงที่ถูกเติม (0–height)
	int filled = int((health / 100.0f) * height);

	// วาดจากด้านล่างขึ้นบน
	int fillY = y + (height - filled);
	FillRGB(x, fillY, width, filled, fillColor, pDevice);
}



struct CWeapon
{
	bool FlashNade(int id)
	{
		if (id == 114)

			return true;
		return false;
	}

	bool SmokeNade(int id)
	{
		if (id == 115 || id == 396 || id == 5005 || id == 128 || id == 5930)
			return true;
		return false;
	}

	bool M67Nade(int id)
	{
		if (id == 109 || id == 7986)
			return true;
		return false;
	}

	bool RGDNade(int id)
	{
		if (id == 125)
			return true;
		return false;
	}

	bool MARKIINade(int id)
	{
		if (id == 340)
			return true;
		return false;
	}

	void NadeHack(LPDIRECT3DDEVICE9 pDevice)
	{
		int index = 0;
		int counter = 0;
		do
		{
			if (*(PDWORD)((DWORD)this + index + 0x8528))
			{


				float x = *(float*)((DWORD)this + index + 0x8560);
				float y = *(float*)((DWORD)this + index + 0x8564);
				float z = *(float*)((DWORD)this + index + 0x8568);


				D3DXVECTOR3 NadeHCords;



				auto NadeID = *(PDWORD)((DWORD)this + index + 0x858C); // NadeID
				auto NadePosx = *(D3DXVECTOR3*)((DWORD)this + index + 0x8560);



				char szNade[255];
				sprintf(szNade, "Nade [%d]", NadeID);

				if (GetScreenCoordFromWorld(NadeHCords, NadePosx, pDevice))
				{
					
					if (MenuItem[24] == 1)
					{

						if (MARKIINade(NadeID))
						{
							char szMARKII[255];
							sprintf(szMARKII, "MARKII", MARKIINade(NadeID));

							PrintText2(szMARKII, NadeHCords.x, NadeHCords.y, Red, pD3DFont);
						}

						if (RGDNade(NadeID))
						{
							char szRGD[255];
							sprintf(szRGD, "RGD", RGDNade(NadeID));

							PrintText2(szRGD, NadeHCords.x, NadeHCords.y, Red, pD3DFont);
						}

						if (M67Nade(NadeID))
						{
							char szM67[255];
							sprintf(szM67, "M67", M67Nade(NadeID));

							PrintText2(szM67, NadeHCords.x, NadeHCords.y, Red, pD3DFont);
						}

						if (FlashNade(NadeID))
						{
							char szFlash[255];
							sprintf(szFlash, "Flash", FlashNade(NadeID));

							PrintText2(szFlash, NadeHCords.x, NadeHCords.y, Green, pD3DFont);
						}

						if (SmokeNade(NadeID))
						{
							char szSmoke[255];
							sprintf(szSmoke, "Smoke", SmokeNade(NadeID));

							PrintText2(szSmoke, NadeHCords.x, NadeHCords.y, Blue, pD3DFont);
						}
		
						
					}
					

				}

				


				if (MenuItem[23] == 1 && FlashNade(NadeID)) 
				{
					

					*(PDWORD)((DWORD)this + index + 0x85DC) = 1; // Disable Effect
				}

				
				if (MenuItem[22] == 1 && SmokeNade(NadeID)) 
				{
				
					*(PDWORD)((DWORD)this + index + 0x85DC) = 1; // Disable Effect
				}
				

			}
			index += 272;
			counter++;
		} while (counter < 300);
	}
};

class WeaponControl
{
public:
	char _0x0001[0x1c438];
	D3DXVECTOR3 reAim1;//0x1c438
	D3DXVECTOR3 reAim2;
	char _0x0004[0x20];
	int spread;
	int recoil;
	virtual void function0();
};


//==============================================================================
class CPlayerBase
{
public:
	char Main[GameTypeOffSet];
	int Index;
	int GameType;
	int Unk;
	int GameCount;
};


class CPlayerBoost 
{
public:

	char _CafePoint[0xE88C];
	BYTE CafePoint[0x1];

	char _DoubleUp[0xE89F];
	BYTE DoubleUp;

	char _TimesXP[0xE8B2];
	BYTE ExpX2;
};

class CPlayerXx
{
public:
	char unknow1[PlayerNameOffSet];  //0x1DDEE8 
	char _Name[4]; //0x1DDEE8 

	char unknown2[260];
	DWORD health; //0x1DDFF0 - 0x1DDEE8 - 0x4 = 104(convert to decimal) = 260    //   MOV DWORD PTR DS:[ECX+0x1DDFF0],0x2D5
	char _0x555[0x8];
	int WeaponSound; // 0x1CB000  //-------- GetWeaponSound
	int ShotType1;// 0x1CB004  //-------- GetShotType1
	int DamageBullet;// 0x1CB008  //-------- GetWeaponDamage
	int ShotType2;// 0x1CB00C  //-------- GetShotType2
	int WeaponID;// 0x1CB010  //-------- GetWeaponID also WeaponIcon in the corner of your screen plus [FOR ESP Weapon]
	char _0x666[0x8];
	int WeaponVisual;   //-------- GetWeaponVisual
	int WeaponChange;   //-------- ChangeWeapon IMPORTANT to change your weapon!
};


//==============================================================================
class CPlayer
{
public:

	char unknow1[PlayerNameOffSet];  //0x1DDEE8 
	char _Name[4]; //0x1DDEE8 

	char unknown2[260];
	DWORD health; //0x1DDFF0 - 0x1DDEE8 - 0x4 = 104(convert to decimal) = 260    //   MOV DWORD PTR DS:[ECX+0x1DDFF0],0x2D5


	char unknown3[0x8];
	DWORD WeaponAmmo; //0x1DDFFC new  //0x57AE8 old
	DWORD WeaponType; //0x1DE000 new  //0x57AEC old


	char unknown4[120];                   // Base
	float xme; //0x1DE07C //0x57BA4 
	float yme; //0x1DE080  //0x57BA8 
	float zme; //0x1DE084 

			// Foot Position
	//char _0x019[96];
	//float vx; //0x56878 // Binary = 8B CD D9 1C 24 50
	//float vy; //
	//float vz; //

	char unknown5[0x33C]; //0x1DE3C4//	0x57f3c - 0x57C18 - 0x4 = 0x320
	DWORD IsAlive;


	char unknown[0x20];     //0x1DE3E8  //0x57F58	-	0x57F3c - 0x4 = 0x18        //Head
	float xne; //0x57F58 
	float yne; //0x57F5C 
	float zne; //0x57F60

	//// Head Position
	//char _0x021[540];
	//float xene; //0x56BC0 // Binary = DE F2 D9 C9 D9 5C 24 14 D8 4C 24 14
	//float yene; //
	//float zene; //

	char _PlayerAlive[0x48]; // 0x56C14 - 0x56BC8 - 0x4 = 0x48 
	DWORD IsAlive2;
};

class ClassManager
{

public:


	DWORD GetBase()
	{

		DWORD result = *(PDWORD)GameManagerOffSet;

		if (!result)
			return 0;

		result = *(PDWORD)(result + 0x1c);

		if (!result)return 0;

		return *(PDWORD)(result + 0x10);
	}

	DWORD GetBasePlayer()  //HackEXP
	{
		DWORD x2 = *(PDWORD)GameManagerOffSet;
		if (!x2) return 0;
		
		return *(PDWORD)(x2 + 0x228 + 1011); //TEST
		//return *(PDWORD)(x2 + 0x228);
	}

	CPlayerBoost* GetPlayerBoost()
	{
		return *(CPlayerBoost**)BattleManagerOffSet;
	}

	CPlayerBase* GetPlayerBase()
	{


		return *(CPlayerBase**)BattleManagerOffSet;
	}


	char* WeaponName(int i)
	{
		DWORD BasePtr = GetBase();

		if (BasePtr == 0)
			return "----";

		BasePtr = *(DWORD*)(BasePtr + (i * 4) + 4);
		if (BasePtr == 0)
			return "----";

		int qWeaponNumberOffSet = *(DWORD*)(BasePtr + WeaponNumberOffSet);


		DWORD Base = *(DWORD*)AutoUpdateOffSet;
		Base = *((DWORD*)Base + 5 * (unsigned __int16)qWeaponNumberOffSet + 3);

		char* gName = (char*)(Base + 0x18);


		return gName;
	}

	CPlayer* GetPlayerByIndex(int index)
	{
		DWORD BasePtr = GetBase();

		if (BasePtr == 0)
			return 0;

		return *(CPlayer**)(BasePtr + (index * 4) + 4);
	}

	CPlayerXx* GetPlayerByIndexx(int index)
	{
		DWORD BasePtr = GetBase();

		if (BasePtr == 0)
			return 0;

		return *(CPlayerXx**)(BasePtr + (index * 4) + 4);
	}


	int GetMyIndex()
	{
		CPlayerBase* pPlayerBase = GetPlayerBase();
		if (!pPlayerBase)
			return 0;

		return pPlayerBase->Index;
	}

	bool SameTeam(int i) //SF_CharRoutine::UserInfoSettingByUse
	{
		DWORD ptr = (DWORD)GetPlayerBase();
		BYTE myTeam = *(PBYTE)(2028 * GetMyIndex() + 0x5DC + ptr);
		BYTE iTeam = *(PBYTE)(2028 * i + 0x5DC + ptr);


		if (iTeam == myTeam)
			return true;

		return false;
	}

	CWeapon* Weapon()
	{
		DWORD zPlay = *(PDWORD)GameManagerOffSet;
		if (zPlay == 0)return 0;

		zPlay = *(PDWORD)(zPlay + 0x1c);
		if (zPlay == 0)return 0;

		zPlay = *(PDWORD)(zPlay + 0x10);
		if (zPlay == 0)return 0;

		return *(CWeapon**)(zPlay + 0x44);
	}
};
ClassManager pClassManager;

float Distance(D3DXVECTOR3 vPoint1, D3DXVECTOR3 vPoint2)
{
	float distance = sqrtf((vPoint2.x - vPoint1.x) * (vPoint2.x - vPoint1.x) +
		(vPoint2.y - vPoint1.y) * (vPoint2.y - vPoint1.y) +
		(vPoint2.z - vPoint1.z) * (vPoint2.z - vPoint1.z));

	return distance;
}


#pragma optimize("", off)
bool HideThread(HANDLE hThread)
{
	typedef NTSTATUS(NTAPI *pNtSetInformationThread)(HANDLE, UINT, PVOID, ULONG);
	NTSTATUS Status;

	// Get NtSetInformationThread
	pNtSetInformationThread NtSIT = (pNtSetInformationThread)
		GetProcAddress(GetModuleHandle(TEXT("ntdll.dll")),"NtSetInformationThread");

	// Shouldn't fail
	if (NtSIT == NULL) return false;

	if (hThread == NULL)
		Status = NtSIT(GetCurrentThread(), 0x11, 0, 0);
	else
		Status = NtSIT(hThread, 0x11, 0, 0);

	if (Status != 0x00000000)
		return false;
	else
		return true;
}



