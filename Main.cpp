
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <tchar.h>
#include <intrin.h>
#include <algorithm>
#include <TlHelp32.h>
#include <string>
#include <vector>

#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <intrin.h>
#include "Xorstr.h"

#include "Main.h"
#include "key.h"
#include "Menu.h"

#include "Sound.h"


#include <ctime>
#include "VirtualizerSDK.h"

#include "detours_z.h"
#pragma comment(lib,"detours_z.lib")

#ifndef YOURHEADERFILE_H
#define YOURHEADERFILE_H

#include <d3dx9.h>



#endif // YOURHEADERFILE_H

#define VM_START VIRTUALIZER_START VIRTUALIZER_MUTATE1_START	VIRTUALIZER_MUTATE2_START VIRTUALIZER_MUTATE3_START
#define VM_END VIRTUALIZER_END

#define Green   D3DCOLOR_ARGB(255, 0, 255, 0)
#define Red     D3DCOLOR_ARGB(255, 255, 0, 0)
#define Orange  D3DCOLOR_ARGB(255, 255, 128, 0)
#define Black   D3DCOLOR_ARGB(255, 0, 0, 0)





int ANTI_TEAMVIEW = 0;
int TV_SHUTDOWN = 0;
int MenuFolder[100];
int KillerKey = 0;

char* Opt_OnOff[] = { "OFF", "ON" };
char* Opt_Folder[] = { "Open >", "< Close" };
char* Opt_AimHeight[] = { "ËÑÇ", "µÑÇ" };
char* Opt_AimKey[] = { "OFF", "Left Click", "Right Click" };
char* Opt_Aim[] = { "¡ÅÒ§à»éÒ", "AimFov" ,"AimTest" };
char* Opt_Enemy[] = { "·Ñé§ËÁ´", "ÈÑµÃÙ" };
char* Opt_Enemy1[] = { "OFF", "x2", "x3", "x5", "x7" };
char* Opt_Enemy2[] = { "OFF", "x1", "x2.1", "x2.2","x2.3", "x2.4", "x2.5", "x2.6", "x2.7","x3", "x4", "x5", "x6" };
char* Opt_Enemy3[] = { "OFF", "100", "200", "500", "1000", "1500", "2000" };
char* Opt_Enemy4[] = { "OFF", "Red", "Orange", "White", "Black", "Blue" };
char* Opt_Enemy5[] = { "OFF", "1", "2", "3", "4", "5", "6", "7", "8" };

char Victim[60];
char* optVictim[] = { "Victim", "Victim", "Victim", "Victim", "Victim", "Victim", "Victim", "Victim", "Victim", "Victim", "Victim", "Victim", "Victim", "Victim", "Victim" };
char* Opt_Target[] = { "OFF", "All Player", "All Ally", "All Enemy", "Single" };
char* Opt_Tale[] = { "OFF", "ON" };
char* Opt_SavePosion[] = { "F8" };
char* Opt_AimFov[] = { "OFF", "1",};
char* Opt_SavePosion2[] = { "F10" };
char* Moptonoff[] = { (PCHAR)"»Ô´", (PCHAR)"à»Ô´" };

char* Opt_Ammotype[] = { "OFF", "RGD", "Freezer", "M67", "VX", "FB", "Smoke","RobotBomb","RobotLazer" ,"Maverick Left" ,"Maverick Right" ,"Maverick_M1 Left" ,"Maverick_M1 Right" ,"Maverick_M2 Left" ,"Maverick_M2 Right" ,"Maverick_M3 Left" ,"Maverick_M3 Right" ,"HYPER_MK1 Left" ,"HYPER_MK1 Right" ,"HYPER_MK2 Left" ,"HYPER_MK2 Right" ,"HYPER_MK3 Left","HYPER_MK3 Right" };
char* Opt_Line[] = { "OFF", "Crosshair", "OnTop" };
char* Opt_ESPBox[] = { "OFF", "ON" };
const char* DEFAULT_FONT = "Arial"; // 
char* Opt_ColorCheat[] = { "OFF", "1", "2", "3", "4" };
char* Opt_SetWin[] = { "Default",  "1",  "2",  "3",  "4",  "5", "6", "7", "8",  "9",  "10" };
char* Opt_SetLose[] = { "Default",  "1",  "2",  "3",  "4",  "5", "6", "7", "8",  "9",  "10" };
char* Opt_Setkill[] = { "Default",  "10",  "20",  "30",  "40",  "50", "60", "70", "80",  "90",  "100" };
char* Opt_SetDeadth[] = { "Default",  "10",  "20",  "30",  "40",  "50", "60", "70", "80",  "90",  "100" };
char* Opt_SetAssists[] = { "Default",  "10",  "20",  "30",  "40",  "50", "60", "70", "80",  "90",  "100" };
char* Opt_SetMission[] = { "Default",  "10",  "30",  "60",  "99",  "115" };
char* Opt_SetHeadshot[] = { "Default",  "10",  "20",  "30",  "40",  "50", "60", "70", "80",  "90",  "100" };
char* Opt_SetTeamkill[] = { "Default",  "0" };
char* Opt_GameCount[] = { "Default",  "0", "1", "2", "3", "4", "5" };
char* Opt_GameType[] = { "Default",  "SingleBattle", "TeamBattle", "ClanWar", "Sniper", "Training", "TeamDeath", "CTC" , "CTC2" , "HorrorMode" , "HorrorMode2" };
char* Opt_Sp[] = { "Default", "50","100", "200", "300", "400", "500", "1000", "2000","3000", "4000", "5000" };


LPD3DXFONT mFont = NULL;

#define ADD_TRY __try {
#define END_TRY }__except (EXCEPTION_EXECUTE_HANDLER) {}


int antiTeamView = 0;
int tvShutdown = 0; // หรือค่าที่คุณต้องการเริ่มต้น เช่น 1

class CBoneSkeletonOffSet
{
public:
	char _0x0000[0x4];
	CBoneSkeletonOffSet* Next;
	char _0x0008[120];
	D3DXVECTOR3 BoneCords;
};

class CPlayerBoneSkeletonOffSet
{
public:
	char unknow[0x858];
	CBoneSkeletonOffSet* dwBonePtr;

	CBoneSkeletonOffSet* GetBoneSkeletonOffSet()
	{
		if (this->dwBonePtr && this->dwBonePtr->Next && this->dwBonePtr->Next->Next)
			return (CBoneSkeletonOffSet*)(this->dwBonePtr->Next->Next);
		return 0;
	}
};
class XCBONE
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

	CPlayerBoneSkeletonOffSet* GetPlayer(int index)
	{
		DWORD BasePtr = GetBase();

		if (BasePtr == 0)
			return 0;

		return *(CPlayerBoneSkeletonOffSet**)(BasePtr + (index * 4) + 4);
	}
};
XCBONE pXCBONE;

//DWORD BoneSkeletonOffSet = 0x1117C64; //   Bip01 Neck  // 0071A6C0 //1117C64

// นิยามฟังก์ชัน
unsigned long GetColorFromMenu(int menuIndex) {
	// สมมติว่าเราจะเลือกสีจากเมนู
	switch (menuIndex) {
	case 0:
		return 0xFFFFFF; // ตัวอย่างสีขาว
	case 1:
		return 0x000000; // ตัวอย่างสีดำ
		// เพิ่มกรณีอื่นๆ
	default:
		return 0xFFFFFF; // ค่า default
	}
}


typedef CBoneSkeletonOffSet* (__thiscall* tGetBonePtr)(CBoneSkeletonOffSet* GetBoneSkeletonOffSet, LPSTR szBoneName);
tGetBonePtr GetBonePtr = (tGetBonePtr)BoneSkeletonOffSet; //BoneSkeletonOffSet

D3DXVECTOR3 GetUserBone(int i, LPSTR szBoneName)
{
	CPlayerBoneSkeletonOffSet* pLocal = pXCBONE.GetPlayer(i);
	CBoneSkeletonOffSet* BoneName = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), szBoneName);

	return BoneName->BoneCords;
}
int coloraim = Red;
int AimmyGOD;

DOUBLE GetDistanceAim(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}


int AIM_TEST(LPDIRECT3DDEVICE9 pDevice)
{
	ADD_TRY

		int index = -1;
	CPlayer* pMyInfo = pClassManager.GetPlayerByIndex(pClassManager.GetMyIndex());

	for (int i = 0; i < 16; i++)
	{
		if (i == pClassManager.GetMyIndex()) continue; // ข้ามผู้เล่นคนปัจจุบัน

		bool Ally = pClassManager.SameTeam(i);
		if (MenuItem[8] && Ally) continue; // ข้ามเพื่อนร่วมทีมถ้ามีการตั้งค่า

		CPlayer* pInfo = pClassManager.GetPlayerByIndex(i);
		if (pInfo && pInfo->IsAlive && pInfo->health > 625)
		{
			D3DVIEWPORT9 ViewP;
			pDevice->GetViewport(&ViewP);

			// ใช้กระดูกคอในการล็อก
			D3DXVECTOR3 PositionEnemy = GetUserBone(i, "Bip01 Neck");
			D3DXVECTOR3 Center((float)(ViewP.Width / 2), (float)(ViewP.Height / 2), 0);
			D3DXVECTOR3 TeleDetermine;

			if (GetScreenCoordFromWorld(TeleDetermine, PositionEnemy, pDevice))
			{
				float distance = GetDistanceAim(TeleDetermine.x, TeleDetermine.y, Center.x, Center.y);
				int lockThreshold = 100; // ระยะที่จะล็อก

				if (distance < lockThreshold)
				{
					if (index == -1 || distance < GetDistanceAim(
						TeleDetermine.x, TeleDetermine.y,
						GetUserBone(index, "Bip01 Neck").x,
						GetUserBone(index, "Bip01 Neck").y))
					{
						index = i; // ล็อกเป้าหมายศัตรู
					}
				}
			}
		}
	}

	return (index == -1) ? NULL : index; // คืนค่าของเป้าหมายที่ถูกล็อก

	END_TRY
}

int CLOSESCREEN(LPDIRECT3DDEVICE9 pDevice)
{
	ADD_TRY
		float smallestDistance = FLT_MAX; // ค่าระยะห่างสูงสุด
	int index = -1;

	CPlayer* pMyInfo = pClassManager.GetPlayerByIndex(pClassManager.GetMyIndex());

	for (int i = 0; i < 16; i++)
	{
		if (i == pClassManager.GetMyIndex()) continue; // ข้ามผู้เล่นคนปัจจุบัน

		bool Ally = pClassManager.SameTeam(i);
		if (MenuItem[8] && Ally) continue; // ข้ามเพื่อนร่วมทีมถ้ามีการตั้งค่า

		CPlayer* pInfo = pClassManager.GetPlayerByIndex(i);
		if (pInfo && pInfo->IsAlive && (pInfo->health > 625))
		{
			D3DVIEWPORT9 ViewP;
			pDevice->GetViewport(&ViewP);

			D3DXVECTOR3 Center((float)(ViewP.Width / 2), (float)(ViewP.Height / 2), 0);
			D3DXVECTOR3 Enemy(0, 0, 0);

			// ใช้กระดูกคอในการล็อก
			D3DXVECTOR3 PositionEnemy = GetUserBone(i, "Bip01 Neck");

			if (GetScreenCoordFromWorld(Enemy, PositionEnemy, pDevice))
			{
				if (Enemy.z <= 1.0f && Enemy.z >= 0.0f) // ตรวจสอบว่าตำแหน่งอยู่ในมุมมอง
				{
					float fDistance = Distance(Enemy, Center);
					if (fDistance < smallestDistance) // เปรียบเทียบระยะห่าง
					{
						smallestDistance = fDistance;
						index = i; // อัปเดต index หากพบระยะที่ใกล้ที่สุด
					}
				}
			}
		}
	}

	return index >= 0 ? index : -1; // คืนค่าที่ถูกต้องถ้ามีเป้าหมาย
	END_TRY
}

// ฟังก์ชันที่เรียบง่ายลงในการเรียกใช้ CLOSESCREEN
int CLOSESCREENXX(LPDIRECT3DDEVICE9 pDevice)
{
	return CLOSESCREEN(pDevice); // ทำให้เรียบง่ายโดยการเรียกใช้ CLOSESCREEN
}


void drawRect(LPDIRECT3DDEVICE9 pDevice, int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT rect = { x, y, x + w, y + h };
	pDevice->Clear(1, &rect, D3DCLEAR_TARGET, color, 0.f, 0);
}

bool notking = 3;

float savex, savey, savez, saveenex, saveeney, saveenez;

void ESPPlayer(LPDIRECT3DDEVICE9 pDevice)
{
	ADD_TRY

		if (!pClassManager.GetBase())
			return;

	CPlayerBase* pBase = pClassManager.GetPlayerBase();
	if (!pBase)
		return;

	CPlayer* pMyInfo = pClassManager.GetPlayerByIndex(pClassManager.GetMyIndex());

	for (int i = 0; i < 16; i++)
	{
		if (i == pClassManager.GetMyIndex())
			continue;

		bool Ally = pClassManager.SameTeam(i);

		if (MenuItem[8] && Ally)
			continue;

		CPlayer* pInfo = pClassManager.GetPlayerByIndex(i);
		CPlayerBoneSkeletonOffSet* pLocal = pXCBONE.GetPlayer(i);

		if (pInfo)
		{
			if (pInfo->health - 625 < 1)
				continue;

			if (!pInfo->IsAlive)
				continue;

			CBoneSkeletonOffSet* pHead = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 HeadNub");
			CBoneSkeletonOffSet* pLToe = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 L Toe0");
			CBoneSkeletonOffSet* pRToe = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 R Toe0");
			CBoneSkeletonOffSet* pLHand = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 L Hand");
			CBoneSkeletonOffSet* pRHand = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 R Hand");
			CBoneSkeletonOffSet* pLCalf = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 L Calf");
			CBoneSkeletonOffSet* pRCalf = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 R Calf");
			CBoneSkeletonOffSet* pSpine = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 Spine");
			CBoneSkeletonOffSet* pNeck = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 Neck");
			CBoneSkeletonOffSet* pLUpperArm = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 L UpperArm");
			CBoneSkeletonOffSet* pRUpperArm = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 R UpperArm");
			CBoneSkeletonOffSet* pLForearm = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 L Forearm");
			CBoneSkeletonOffSet* pRForearm = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 R Forearm");
			CBoneSkeletonOffSet* LFoot = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 L Foot");
			CBoneSkeletonOffSet* RFoot = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 R Foot");
			CBoneSkeletonOffSet* pHeadxxx = GetBonePtr(pLocal->GetBoneSkeletonOffSet(), "Bip01 Head");

			if (!pHead || !pHeadxxx || !pNeck || !pSpine || !LFoot || !RFoot || !pLHand || !pRHand ||
				!pLToe || !pRToe || !pLCalf || !pRCalf || !pLUpperArm || !pRUpperArm || !pLForearm || !pRForearm)
				continue; // ถ้า Bone ไม่ครบ ให้ข้ามการวาด

			D3DXVECTOR3 HeadCordssxxx = pHeadxxx->BoneCords;
			D3DXVECTOR3 HeadCordss = pHead->BoneCords;
			D3DXVECTOR3 NeckCordss = pNeck->BoneCords;
			D3DXVECTOR3 SpineCordss = pSpine->BoneCords;
			D3DXVECTOR3 RFootCordss = RFoot->BoneCords;
			D3DXVECTOR3 LFootCordss = LFoot->BoneCords;
			D3DXVECTOR3 LHandCordss = pLHand->BoneCords;
			D3DXVECTOR3 RHandCordss = pRHand->BoneCords;
			D3DXVECTOR3 LToeCordss = pLToe->BoneCords;
			D3DXVECTOR3 RToeCordss = pRToe->BoneCords;
			D3DXVECTOR3 LCalfCordss = pLCalf->BoneCords;
			D3DXVECTOR3 RCalfCordss = pRCalf->BoneCords;
			D3DXVECTOR3 LUpperArmCordss = pLUpperArm->BoneCords;
			D3DXVECTOR3 RUpperArmCordss = pRUpperArm->BoneCords;
			D3DXVECTOR3 LForearmCordss = pLForearm->BoneCords;
			D3DXVECTOR3 RForearmCordss = pRForearm->BoneCords;

			D3DXVECTOR3 HeadCords, NeckCords, SpineCords, RFootCords, LFootCords, LHandCords, RHandCords, LToeCords, RToeCords, LCalfCords, RCalfCords, LUpperArmCords, RUpperArmCords, LForearmCords, RForearmCords;
			D3DXVECTOR3 Head(pInfo->xne, pInfo->yne, pInfo->zne), ScreenBot;
			D3DXVECTOR3 Foot(pInfo->xme, pInfo->yme, pInfo->zme), Screen; // Base Foot
			D3DXVECTOR3 PositionMe(pMyInfo->xme, pMyInfo->yme, pMyInfo->zme);
			D3DXVECTOR3 PositionBot(pInfo->xne, pInfo->yne, pInfo->zne);

			int ScreenX = GetSystemMetrics(0) / 2;
			int ScreenY = GetSystemMetrics(0) / 2;

			D3DVIEWPORT9 viewP;
			pDevice->GetViewport(&viewP);
			DWORD OnTopX = viewP.Width / 2;
			DWORD OnTopY = viewP.Y;

			if (pLocal)
			{
				D3DXVECTOR3 pTarget;
				switch (MenuItem[10])
				{
				case 0:
					pTarget = HeadCordssxxx;
					break;
				case 1:
					pTarget = SpineCordss;
					break;
				}

				D3DXVECTOR3 _Target(0, 0, 0), _Locked(0, 0, 0);

				if (GetScreenCoordFromWorld(_Target, pTarget, pDevice))
				{
					int curx = static_cast<int>(_Target.x); // การแปลงพิกัดให้เป็น int
					int cury = static_cast<int>(_Target.y); // การแปลงพิกัดให้เป็น int

					// ตรวจสอบให้แน่ใจว่า curx และ cury อยู่ในขอบเขตของ viewport
					if (curx < 0 || curx >= viewP.Width || cury < 0 || cury >= viewP.Height)
					{
						continue; // ข้ามหากอยู่นอกเขต
					}

					// ปรับ cury ตามค่าของ notking
					switch (notking)
					{
					case 0:
						cury = static_cast<int>(_Target.y);
						break;
					case 1:
						cury = static_cast<int>(_Target.y) + 2;
						break;
					case 2:
						cury = static_cast<int>(_Target.y) + 4;
						break;
					case 3:
						cury = static_cast<int>(_Target.y) + 6;
						break;
					case 4:
						cury = static_cast<int>(_Target.y) + 8;
						break;
					case 5:
						cury = static_cast<int>(_Target.y) + 10;
						break;
					case 6:
						cury = static_cast<int>(_Target.y) + 12;
						break;
					case 7:
						cury = static_cast<int>(_Target.y) + 14;
						break;
					case 8:
						cury = static_cast<int>(_Target.y) + 16;
						break;
					case 9:
						cury = static_cast<int>(_Target.y) + 18;
						break;
					case 10:
						cury = static_cast<int>(_Target.y) + 20;
						break;
					}

					pDevice->GetViewport(&viewP); // รับขนาดของ viewport
					double DistX = static_cast<double>(curx) - (viewP.Width / 2.0); // คำนวณระยะจากกลาง X
					double DistY = static_cast<double>(cury) - (viewP.Height / 2.0); // คำนวณระยะจากกลาง Y

					// แบ่งระยะเพื่อปรับสมดุล
					DistX /= 2.0;
					DistY /= 2.0;

					// .... (ต่อด้วยการใช้งาน DistX และ DistY ในส่วนการประมวลผลถัดไปของคุณ)



					if (MenuItem[21] == 1)
					{
						for (int i = 0; i < 16; i++)
						{
							CPlayerXx* xMyPlayerx = pClassManager.GetPlayerByIndexx(pClassManager.GetMyIndex());
							CPlayerXx* xEntityx = pClassManager.GetPlayerByIndexx(i);

							if (CLOSESCREEN(pDevice) == i)
							{
								if (GetAsyncKeyState(0x47) & 1)
								{
									xMyPlayerx->DamageBullet = xEntityx->DamageBullet;
									xMyPlayerx->ShotType1 = xEntityx->ShotType1;
									xMyPlayerx->ShotType2 = xEntityx->ShotType2;
									xMyPlayerx->WeaponID = xEntityx->WeaponID;
									xMyPlayerx->WeaponSound = xEntityx->WeaponSound;
									xMyPlayerx->WeaponVisual = xEntityx->WeaponVisual;
									xMyPlayerx->WeaponChange = xEntityx->WeaponChange; // last thing to complete the change
								}
							}
						}
					}


					if (MenuItem[9] == 1)
					{

						//if (MenuItem[25] == 0)
						{
							//if (CLOSESCREENXX(pDevice) == i)
							{
								//_Locked = _Target;


								if (MenuItem[11] == 1)
								{
									if (GetAsyncKeyState(0x01) & 0x8000) // ตรวจสอบการคลิกซ้าย
									{
										mouse_event(MOUSEEVENTF_MOVE, (int)DistX, (int)DistY, NULL, NULL); // เคลื่อนที่เมาส์
									}
								}
								else if (MenuItem[11] == 1)
								{
						            if (GetAsyncKeyState(0x01) & 0x8000) // ตรวจสอบการคลิกซ้าย
									{
										mouse_event(MOUSEEVENTF_MOVE, (int)DistX, (int)DistY, NULL, NULL);

									}
								}
								//else if (MenuItem[11] == 2)
								{
									//if (GetAsyncKeyState(0x10))
									{
										//mouse_event(MOUSEEVENTF_MOVE, (int)DistX, (int)DistY, NULL, NULL);

									}
								}



							}

						}

						//if (MenuItem[25] == 1)
						{
							//if (CLOSESCREEN(pDevice) == i)
							{
								//_Locked = _Target;

								//if (MenuItem[11] == 0)
								{
									//if (GetAsyncKeyState(0x02))
									{
										//mouse_event(MOUSEEVENTF_MOVE, (int)DistX, (int)DistY, NULL, NULL);
									}
								}

								//if (MenuItem[11] == 1)
								{
									//if (GetAsyncKeyState(0x01))
									{
										///mouse_event(MOUSEEVENTF_MOVE, (int)DistX, (int)DistY, NULL, NULL);

									}
								}

								//if (MenuItem[11] == 2)
								{
									//if (GetAsyncKeyState(0x10))
									{
										//mouse_event(MOUSEEVENTF_MOVE, (int)DistX, (int)DistY, NULL, NULL);

									}
								}
							}

						}

						if (MenuItem[25] == 2)
						{
							int curx = _Target.x;
							int cury = _Target.y;


							double DistX = (double)curx - viewP.Width / 2.0f;
							double DistY = (double)cury - viewP.Height / 2.0f;

							DistX /= (float)3;
							DistY /= (float)3;

							float AimDistance = Distance(HeadCordssxxx, HeadCordssxxx);
							int AimDist = (float)AimDistance / 100;

							float ScreenXxX = viewP.Width / 2;
							float ScreenYyY = viewP.Height / 2;


							int DistAim_ = 70;

							if (AIM_TEST(pDevice) == i)
							{


								coloraim = GREEN;


								if (AimDist < DistAim_)
								{
									coloraim = GREEN;


									if (AimmyGOD == 1 && coloraim == GREEN)
									{
										if (IsKeyPressed(VK_RBUTTON, 1) || IsKeyPressed(VK_RBUTTON, 2) || IsKeyPressed(VK_RBUTTON, 0) < 0)
										{


											if ((int)DistX > -249 && (int)DistY > -190)
											{

												mouse_event(MOUSEEVENTF_MOVE, (int)DistX, (int)DistY, NULL, NULL);



											}
										}


									}

								}
								else {

									AimmyGOD = 0;
									coloraim = Blue;
								}

							}
						}
					}

				}

			}


			if (GetScreenCoordFromWorld(HeadCords, HeadCordss, pDevice) &&
				GetScreenCoordFromWorld(NeckCords, NeckCordss, pDevice) &&
				GetScreenCoordFromWorld(SpineCords, SpineCordss, pDevice) &&
				GetScreenCoordFromWorld(LFootCords, LFootCordss, pDevice) &&
				GetScreenCoordFromWorld(RFootCords, RFootCordss, pDevice) &&
				GetScreenCoordFromWorld(LHandCords, LHandCordss, pDevice) &&
				GetScreenCoordFromWorld(RHandCords, RHandCordss, pDevice) &&
				GetScreenCoordFromWorld(LToeCords, LToeCordss, pDevice) &&
				GetScreenCoordFromWorld(RToeCords, RToeCordss, pDevice) &&
				GetScreenCoordFromWorld(LCalfCords, LCalfCordss, pDevice) &&
				GetScreenCoordFromWorld(RCalfCords, RCalfCordss, pDevice) &&
				GetScreenCoordFromWorld(LUpperArmCords, LUpperArmCordss, pDevice) &&
				GetScreenCoordFromWorld(RUpperArmCords, RUpperArmCordss, pDevice) &&
				GetScreenCoordFromWorld(LForearmCords, LForearmCordss, pDevice) &&
				GetScreenCoordFromWorld(RForearmCords, RForearmCordss, pDevice) &&
				GetScreenCoordFromWorld(Screen, Foot, pDevice) &&
				GetScreenCoordFromWorld(ScreenBot, Head, pDevice))
			{

				float fDistance = Distance(PositionBot, PositionMe);

				int boxsize = (int)(Screen.y - ScreenBot.y);
				if (boxsize < 5) boxsize = 20; // บังคับให้มีขนาดขั้นต่ำของกล่อง
				int boxwidth = boxsize / 3;
				int topleftx = (int)Screen.x - (boxwidth / 2);
				int toplefty = (int)ScreenBot.y;

				int flHealth = pInfo->health - 625;

				D3DVIEWPORT9 viewP;
				pDevice->GetViewport(&viewP);

				DWORD LineCrossX = viewP.Width / 2;
				DWORD LineCrossY = viewP.Height / 2;

				DWORD OnTopX = viewP.Width / 2;
				DWORD OnTopY = viewP.Y;

				D3DXVECTOR3 box;

				box.y = ((Screen.y - HeadCords.y) > 1.f) ? Screen.y - HeadCords.y : 1.f;
				box.x = box.y / 1.40f;

				D3DCOLOR boxColor;

				// --- วาดกล่อง + หลอดเลือด (เฉพาะศัตรู) ---
				if (!Ally) // แสดงเฉพาะศัตรูเท่านั้น
				{
					// --- สีกรอบจากเมนู ---
					D3DCOLOR boxColor;

					// เลือกสีกรอบจากเมนู
					switch (MenuItem[500])
					{
					case 0: boxColor = D3DCOLOR_ARGB(255, 255, 0, 0); break;  // สีแดง
					case 1: boxColor = D3DCOLOR_ARGB(255, 0, 255, 0); break;  // สีเขียว
					case 2: boxColor = D3DCOLOR_ARGB(255, 0, 0, 255); break;  // สีน้ำเงิน
					case 3: boxColor = D3DCOLOR_ARGB(255, 255, 255, 0); break; // สีเหลือง
					case 4: boxColor = D3DCOLOR_ARGB(255, 255, 165, 0); break; // สีส้ม
					default: boxColor = D3DCOLOR_ARGB(255, 255, 0, 0); break; // ค่าเริ่มต้นเป็นสีแดง
					}

					// --- วาดกล่องรอบตัว (Box) ---
					if (MenuItem[2] == 1 || MenuItem[2] == 2) // แบบเต็มหรือมุม
					{
						// วาดกรอบ (Box) รอบตัวศัตรู
						DrawLineX(pDevice, Screen.x - (box.x / 2), Screen.y - box.y, Screen.x + (box.x / 2), Screen.y - box.y, boxColor); // Top
						DrawLineX(pDevice, Screen.x + (box.x / 2), Screen.y - box.y, Screen.x + (box.x / 2), Screen.y, boxColor);         // Right
						DrawLineX(pDevice, Screen.x + (box.x / 2), Screen.y, Screen.x - (box.x / 2), Screen.y, boxColor);                 // Bottom
						DrawLineX(pDevice, Screen.x - (box.x / 2), Screen.y, Screen.x - (box.x / 2), Screen.y - box.y, boxColor);         // Left
					}

					// --- วาดหลอดเลือด (HP Bar) ---
					if (MenuItem[4] == 1) // แสดงหลอดเลือด
					{
						D3DCOLOR barColor;

						// เปลี่ยนสีของ Health Bar ตามค่าของ flHealth
						if (flHealth > 70)
							barColor = D3DCOLOR_ARGB(255, 0, 255, 0); // สีเขียว
						else if (flHealth > 40)
							barColor = D3DCOLOR_ARGB(255, 255, 165, 0); // สีส้ม
						else
							barColor = D3DCOLOR_ARGB(255, 255, 0, 0); // สีแดง

						// ปรับตำแหน่งให้แนบกับกรอบกล่อง
						int topleftx = Screen.x - (box.x / 2) - 6;        // ชิดซ้ายของกรอบ
						int toplefty = Screen.y - box.y;                  // เริ่มที่ด้านบนของกรอบ

						int barWidth = 4;  // ความกว้างของหลอดเลือด
						int barHeight = box.y; // ความสูงเท่ากับกล่อง

						// วาดหลอดเลือด
						DrawHealthBar_0(topleftx, toplefty, flHealth, barWidth, barHeight, barColor, D3DCOLOR_ARGB(255, 0, 0, 0), pDevice);
					}
				}




				if (MenuItem[3] == 1 && !Ally)
				{
					D3DCOLOR skeletonColor;

					// เปลี่ยนสีเป็นสีที่เลือกจากเมนู
					switch (MenuItem[600])
					{
					case 0:
						skeletonColor = D3DCOLOR_ARGB(255, 255, 0, 0); // สีแดง
						break;
					case 1:
						skeletonColor = D3DCOLOR_ARGB(255, 0, 255, 0); // สีเขียว
						break;
					case 2:
						skeletonColor = D3DCOLOR_ARGB(255, 0, 0, 255); // สีน้ำเงิน
						break;
					case 3:
						skeletonColor = D3DCOLOR_ARGB(255, 255, 255, 0); // สีเหลือง
						break;
					case 4:
						skeletonColor = D3DCOLOR_ARGB(255, 255, 165, 0); // สีส้ม
						break;
					default:
						skeletonColor = D3DCOLOR_ARGB(255, 255, 0, 0); // สีแดงเป็นค่าเริ่มต้น
						break;
					}

					// วาดเส้นซ้ำเพื่อเพิ่มความหนา
					for (int i = -1; i <= 1; i++) {
						DrawLineX(pDevice, HeadCords.x, HeadCords.y, NeckCords.x, NeckCords.y, skeletonColor);
						DrawLineX(pDevice, NeckCords.x, NeckCords.y, SpineCords.x, SpineCords.y, skeletonColor);
						DrawLineX(pDevice, SpineCords.x, SpineCords.y, LCalfCords.x, LCalfCords.y, skeletonColor);
						DrawLineX(pDevice, SpineCords.x, SpineCords.y, RCalfCords.x, RCalfCords.y, skeletonColor);
						DrawLineX(pDevice, LCalfCords.x, LCalfCords.y, LToeCords.x, LToeCords.y, skeletonColor);
						DrawLineX(pDevice, RCalfCords.x, RCalfCords.y, RToeCords.x, RToeCords.y, skeletonColor);
						DrawLineX(pDevice, NeckCords.x, NeckCords.y, LUpperArmCords.x, LUpperArmCords.y, skeletonColor);
						DrawLineX(pDevice, NeckCords.x, NeckCords.y, RUpperArmCords.x, RUpperArmCords.y, skeletonColor);
						DrawLineX(pDevice, LUpperArmCords.x, LUpperArmCords.y, LForearmCords.x, LForearmCords.y, skeletonColor);
						DrawLineX(pDevice, RUpperArmCords.x, RUpperArmCords.y, RForearmCords.x, RForearmCords.y, skeletonColor);
						DrawLineX(pDevice, LForearmCords.x, LForearmCords.y, LHandCords.x, LHandCords.y, skeletonColor);
						DrawLineX(pDevice, RForearmCords.x, RForearmCords.y, RHandCords.x, RHandCords.y, skeletonColor);
					}
				}
			}
		}
	}
	END_TRY
}
void EXPHACK()
{
	ADD_TRY
	{
		if (MenuItem[14] == 1)
		{
			/**(DWORD*)(0x07B9D41) = 0x1;*/
			(*(DWORD*)(*(DWORD*)(BattleManagerOffSet)+0xEA40) = 15000); //EXP ปรับได้สูงสุด 15000 
			(*(BYTE*)(*(DWORD*)(BattleManagerOffSet)+0xEA30) = 0); //ค่า EXP x2-x7 แต่เราต้องปิดไว้เพราะเราแฮค expแล้ว
			//(*(DWORD*)(*(DWORD*)(BattleManagerOffSet)+0xEA38) = 5000); //ต้องมีดับเบิ้ลอับ


		}


	}

		END_TRY
}



void (HACKWeapon)(void)
{
	ADD_TRY
		DWORD dw_GameBase = *(PDWORD)BattleManagerOffSet;

	if (dw_GameBase)
	{
		if (MenuItem[77] == 1)
		{
			int MyIndex;
			MyIndex = (*(PBYTE)(dw_GameBase + 0x8420));
			*(PDWORD)(dw_GameBase + MyIndex + 0xE958) = 1;  //FastAppear
		}

		DWORD Weapon_PTR = *(PDWORD)(dw_GameBase + 0x10E2C);// battlevehicleturret
		if (Weapon_PTR)
		{
			if (MenuItem[15] == 1)
			{
				*(PDWORD)(Weapon_PTR + 0x134) = 300; // Ammo
			}

			if (MenuItem[21] == 1)
			{
				*(PDWORD)(Weapon_PTR + 0x134) = 129; // Ammo
			}

			if (MenuItem[16] == 1)
			{
				*(PDWORD)(Weapon_PTR + 0x2AC) = 10001; // RapidFire	
			}

		}
	}

	END_TRY
}


void N0Recoil1(void)
{
	ADD_TRY
	{

	DWORD x1 = *(PDWORD)GameManagerOffSet;
	if (x1)
	{
		x1 = *(PDWORD)(x1 + 0x1C);
		if (x1)
		{
			x1 = *(PDWORD)(x1 + 0x10);
			if (x1)
			{
				x1 = *(PDWORD)(x1 + 0x44);
				if (x1)
				{
					if (MenuItem[13] == 1)
					{

						*(DWORD*)(x1 + 0x1C470) = 0; //SpecialForce.exe + 47DB58 - C7 86 70C40100 00000000 - mov[esi + 0001C470], 00000000 { 0 }
						*(DWORD*)(x1 + 0x1C474) = 0; //SpecialForce.exe + 47DB62 - C7 86 74C40100 00000000 - mov[esi + 0001C474], 00000000 { 0 }

					}
				}
			}
		}
	}
	}

		END_TRY
}

void Testyy(void)
{
	ADD_TRY
	{

	int PlayerIndex;
	DWORD gBase = *(PDWORD)GameManagerOffSet;
	if (!gBase) return;

	PlayerIndex = *(PBYTE)(gBase + 0x8420);

	if (MenuItem[56] == 1)
	{
		sprintf((char*)(gBase + (PlayerIndex)+0x980), "%s", "[GM]WarGod"); //0x980
	}
	}

		END_TRY
}



void AutoJumping()
{
	ADD_TRY
	{
		if (MenuItem[12] == 1)
		{
			/**(DWORD*)(0x07B9D41) = 0x1;*/
			(*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x118) = 37);
		}
	}

		END_TRY
}

void AutoGhostJum()
{
	ADD_TRY
	{
		if (MenuItem[22] == 1)
		{
			/**(DWORD*)(0x07B9D41) = 0x1;*/
			(*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x164) = 6);
		}
	}

		END_TRY
}



void ExterCerrer()
{
	ADD_TRY
	{

	if (MenuItem[17] == 1) {
		(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0xA0) + 0x930) = 100);
	}
	if (MenuItem[17] == 2) {
		(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0xA0) + 0x930) = 200);
	}
	if (MenuItem[17] == 3) {
		(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0xA0) + 0x930) = 500);
	}
	if (MenuItem[17] == 4) {
		(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0xA0) + 0x930) = 1000);
	}
	if (MenuItem[17] == 5) {
		(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0xA0) + 0x930) = 1500);
	}
	if (MenuItem[17] == 6) {
		(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0xA0) + 0x930) = 2000);
	}
	}

		END_TRY
}

void ExterSpeed()
{
	ADD_TRY
	{
	 if (MenuItem[18] == 1)
	  {
		(*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x1C) = 100);
		 (*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x20) = 100);
	  }

	  if (MenuItem[18] == 2)
	  {
		(*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x1C) = 200);
		(*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x20) = 200);
	  }

	  if (MenuItem[18] == 3)
	  {
		(*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x1C) = 300);
		(*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x20) = 300);
	  }

	if (MenuItem[18] == 4)
	{
		(*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x1C) = 500);
		  (*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x20) = 500);
	  }

	  if (MenuItem[18] == 5)
	  {
		(*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x1C) = 1000);
		(*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x20) = 1000);
	  }

	  if (MenuItem[18] == 6)
	  {
		(*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x1C) = 1999);
		(*(float*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(*(DWORD*)(GameManagerOffSet)+0x1C) + 0x10) + 0x0) + 0x20) = 1999);
	  }

	}

		END_TRY
}

#define POINTERVALID( ptr )	( ptr > NULL && ptr < ( void * )0xFFFFFFFF )


DWORD SFModule;
bool god_initiated;
// Function to edit bytes
void PatchBytes(void* lpAddress, BYTE* lpBytes, int nLen)
{
	if (!POINTERVALID(lpAddress) || !POINTERVALID(lpBytes) || nLen < 0)
		return;

	DWORD dwBack = 0;
	VirtualProtect(lpAddress, nLen, PAGE_READWRITE, &dwBack);
	memcpy(lpAddress, lpBytes, nLen);
	VirtualProtect(lpAddress, nLen, dwBack, &dwBack);
}


void WriteToMemory(DWORD AddressToWrite, char* valueToWrite, int byteNum)
{
	unsigned long oldProtection;
	VirtualProtect((LPVOID)AddressToWrite, byteNum, PAGE_EXECUTE_READWRITE, &oldProtection);
	memcpy((LPVOID)AddressToWrite, valueToWrite, byteNum);
	VirtualProtect((LPVOID)AddressToWrite, byteNum, oldProtection, NULL);
}

template <class cData>
void Write(DWORD dwBase, cData Value) {
	if (dwBase != NULL)
		(cData)(dwBase) = Value;
}
template <class cData>
void vSetControls(DWORD pAddress, cData pValueOn, cData pValueOff, int& Vars, int KeyState)
{

	if (Vars == TRUE)
		if (GetAsyncKeyState(KeyState) & 1)
			Vars = FALSE;

	if (Vars == FALSE)
		if (GetAsyncKeyState(KeyState) & 1)
			Vars = TRUE;

	if (Vars == -1)
		if (GetAsyncKeyState(KeyState) & 1)
			Vars = TRUE;


	if (Vars == TRUE) {
		(cData)(pAddress) = pValueOn;
	}
	if (Vars == FALSE) {
		(cData)(pAddress) = pValueOff;
		Vars = -1;
	}


}


void ESPNade(LPDIRECT3DDEVICE9 pDevice)
{

	CWeapon* Weapesp = pClassManager.Weapon();
	if (!Weapesp)
		return;

	//if (opt.player.weapon)
	//{
	Weapesp->NadeHack(pDevice);
	//}

}

HRESULT WINAPI hkReset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* ooReset)
{
	VM_START;

	if (pD3DFont)
	{
		pD3DFont->Release();
		pD3DFont = NULL;
	}

	if (mFont)
	{
		mFont->Release();
		mFont = NULL;
	}

	if (pFont)
	{
		pFont->Release();
		pFont = NULL;
	}

	if (pLine)
	{
		pLine->Release();
		pLine = NULL;
	}

	return oReset(pDevice, ooReset);

	VM_END;
}

void DrawLineZ(float x1, float y1, float x2, float y2, D3DXCOLOR color)
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

#define uint unsigned int

bool AntiKick;
static bool bInvalid = false;
static DWORD PresentRetAddr;
//D3DVIEWPORT9 viewPort;
LPDIRECT3DDEVICE9 npDevice;
typedef HRESULT(WINAPI* oPresent) (LPDIRECT3DDEVICE9 pDevice, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion);
oPresent tPresent = NULL;

void BypassVirtualProtect(HANDLE hProcess)
{
	DWORD dwVirtualProtect = (DWORD)VirtualProtect;
	PBYTE pVirtualProtect = (PBYTE)dwVirtualProtect;

	char buffRead[5];
	bool bHooked = false;

	while (!bHooked)
	{
		ReadProcessMemory(hProcess, (LPVOID)dwVirtualProtect, (LPVOID)buffRead, 5, NULL);

		for (int i = 0; i < 5; i++)
		{
			if (buffRead[i] != pVirtualProtect[i])
			{
				bHooked = true;
			}
		}
		Sleep(50);
	}

	WriteProcessMemory(hProcess, (LPVOID)dwVirtualProtect, (PVOID)pVirtualProtect, 5, NULL);

	HMODULE hNtdll = GetModuleHandle("ntdll.dll");
	DWORD dwNtProtectVirtualMemory = (DWORD)GetProcAddress(hNtdll, "NtProtectVirtualMemory");
	PBYTE pNtProtectVirtualMemory = (PBYTE)dwNtProtectVirtualMemory;

	bHooked = false;

	while (!bHooked)
	{
		ReadProcessMemory(hProcess, (LPVOID)dwNtProtectVirtualMemory, (LPVOID)buffRead, 5, NULL);

		for (int i = 0; i < 5; i++)
		{
			if (buffRead[i] != pNtProtectVirtualMemory[i])
			{
				bHooked = true;
			}
		}
		Sleep(50);
	}

	WriteProcessMemory(hProcess, (LPVOID)dwNtProtectVirtualMemory, (PVOID)pNtProtectVirtualMemory, 5, NULL);

	DWORD dwNtOpenFile = (DWORD)GetProcAddress(hNtdll, "NtOpenFile");
	PBYTE pNtOpenFile = (PBYTE)dwNtOpenFile;

	bHooked = false;

	while (!bHooked)
	{
		ReadProcessMemory(hProcess, (LPVOID)pNtOpenFile, (LPVOID)buffRead, 5, NULL);

		for (int i = 0; i < 5; i++)
		{
			if (buffRead[i] != pNtOpenFile[i])
			{
				bHooked = true;
			}
		}
		Sleep(50);
	}
	WriteProcessMemory(hProcess, (LPVOID)pNtOpenFile, (PVOID)pNtOpenFile, 5, NULL);
}

using fn_present = long(__stdcall*)(IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*);
fn_present o_present = nullptr;

bool Create;

HRESULT WINAPI Present_Detour(LPDIRECT3DDEVICE9 pDevice, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
	if (!Create)
	{
		D3DXCreateLine(pDevice, &pLine);
		D3DXCreateFont(pDevice, 14, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &pFont);
		Create = true;
	}
	if (!pFont || !pLine)
	{
		pFont->OnLostDevice();
		pLine->OnLostDevice();
	}
	else
	{

		AntiKick == true;
		ESPPlayer(pDevice);
		AutoJumping();
		AutoGhostJum();
		EXPHACK();
		//XEXP();
		ExterCerrer();
		N0Recoil1();
		HACKWeapon();
		ExterSpeed();
		ESPNade(pDevice);




		if (MenuItem[1] == 1) // เปิด Crosshair
		{
			pDevice->GetViewport(&viewPort);
			float centerX = viewPort.Width / 2.0f;
			float centerY = viewPort.Height / 2.0f;

			// ตั้งค่าสีเป็นสีแดงตลอด
			D3DCOLOR color = D3DCOLOR_ARGB(255, 255, 0, 0);  // สีแดง

			int size = 10;      // ขนาดเส้น (ปรับตามที่ต้องการ)
			int thickness = 1;  // ความหนาของเส้น (ปรับตามที่ต้องการ)

			// วาด Crosshair แบบคลาสสิก (ข้ามเส้นกลางทั้งสองแนว)
			for (int i = 0; i < thickness; i++)
			{
				// วาดเส้นแนวนอน
				drawRect(pDevice, centerX - size, centerY + i, size * 2, 1, color); // เส้นแนวนอน
				drawRect(pDevice, centerX - size, centerY - i, size * 2, 1, color); // เส้นแนวนอน
				drawRect(pDevice, centerX + i, centerY - size, 1, size * 2, color); // เส้นแนวตั้ง
				drawRect(pDevice, centerX - i, centerY - size, 1, size * 2, color); // เส้นแนวตั้ง
			}
		}


		if (MenuItem[95] == 1)
		{
			float Xenter_x = 0.0f;
			float Xenter_y = 0.0f;

			pDevice->GetViewport(&viewPort);
			Xenter_x = (float)viewPort.Width / 2;
			Xenter_y = (float)viewPort.Height / 2;



			aimfov = (MenuItem[98] * 5);

			DrawCircle2(pDevice, Xenter_x, Xenter_y, aimfov, 60, Red);
		}

		DirectInputLoop();
		RenderCustomMenu(pDevice);

		////////////////////////
		pFont->OnLostDevice();
		pFont->OnResetDevice();

		pLine->OnLostDevice();
		pLine->OnResetDevice();
	}


	return tPresent(pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

/*extern "C" __declspec(dllexport)*/void WINAPI iBowtzer_Thread(LPVOID pParam)
{
	LPDIRECT3D9 pD3d9 = NULL;

	LPDIRECT3DDEVICE9 pD3DDevice = NULL;
	pD3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	if (pD3d9 == NULL)
	{
		//Log("Hook Error 1");
		return;
	}
	D3DPRESENT_PARAMETERS pPresentParms;
	ZeroMemory(&pPresentParms, sizeof(pPresentParms));
	pPresentParms.Windowed = TRUE;
	pPresentParms.BackBufferFormat = D3DFMT_UNKNOWN;
	pPresentParms.SwapEffect = D3DSWAPEFFECT_DISCARD;
	if (FAILED(pD3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, GetDesktopWindow(), D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pPresentParms, &pD3DDevice)))
	{
		//Log("Hook Error 2");
		return;
	}
	DWORD* dwTable = (DWORD*)pD3DDevice;
	dwTable = (DWORD*)dwTable[0];
	PresentRetAddr = dwTable[17] + 5;
	tPresent = (oPresent)(DWORD)(dwTable[17]);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)tPresent, Present_Detour);
	DetourTransactionCommit();

}



BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	VM_START;

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);

		char szExeName[MAX_PATH];
		GetModuleFileNameA(NULL, szExeName, MAX_PATH);

		if (strstr(szExeName, "SpecialForce.exe"))
		{
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)iBowtzer_Thread, NULL, 0, NULL);
			HideThread(hModule);
		}
	}

	VM_END;
	return TRUE;
}
