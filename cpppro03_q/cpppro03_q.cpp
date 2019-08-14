// cpppro03_q.cpp : �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "cpppro03_q.h"
// Q5A
#include <stdio.h>
// Q5E

#define MAX_LOADSTRING 100

// �O���[�o���ϐ�:
HINSTANCE hInst;								// ���݂̃C���^�[�t�F�C�X
TCHAR szTitle[MAX_LOADSTRING];					// �^�C�g�� �o�[�̃e�L�X�g
TCHAR szWindowClass[MAX_LOADSTRING];			// ���C�� �E�B���h�E �N���X��

HWND hCmbP1;
HWND hCmbP2;

// Q5A
HWND hStP1;
HWND hStP2;
#if 0 // Q6R
//int win[2];
#else // Q6
int win[3];
#endif // Q6E
// Q5E
// Q6A
HWND hSt[3];
HWND hCmb[3];
// Q6E

// ���̃R�[�h ���W���[���Ɋ܂܂��֐��̐錾��]�����܂�:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: �����ɃR�[�h��}�����Ă��������B
	MSG msg;

	// �O���[�o������������������Ă��܂��B
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_CPPPRO03_Q, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// �A�v���P�[�V�����̏����������s���܂�:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	// ���C�� ���b�Z�[�W ���[�v:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}



//
//  �֐�: MyRegisterClass()
//
//  �ړI: �E�B���h�E �N���X��o�^���܂��B
//
//  �R�����g:
//
//    ���̊֐�����юg�����́A'RegisterClassEx' �֐����ǉ����ꂽ
//    Windows 95 ���O�� Win32 �V�X�e���ƌ݊�������ꍇ�ɂ̂ݕK�v�ł��B
//    �A�v���P�[�V�������A�֘A�t����ꂽ
//    �������`���̏������A�C�R�����擾�ł���悤�ɂ���ɂ́A
//    ���̊֐����Ăяo���Ă��������B
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CPPPRO03_Q));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_CPPPRO03_Q);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   �֐�: InitInstance(HINSTANCE, int)
//
//   �ړI: �C���X�^���X �n���h����ۑ����āA���C�� �E�B���h�E���쐬���܂��B
//
//   �R�����g:
//
//        ���̊֐��ŁA�O���[�o���ϐ��ŃC���X�^���X �n���h����ۑ����A
//        ���C�� �v���O���� �E�B���h�E���쐬����ѕ\�����܂��B
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // �O���[�o���ϐ��ɃC���X�^���X�������i�[���܂��B

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �֐�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �ړI:  ���C�� �E�B���h�E�̃��b�Z�[�W���������܂��B
//
//  WM_COMMAND	- �A�v���P�[�V���� ���j���[�̏���
//  WM_PAINT	- ���C�� �E�B���h�E�̕`��
//  WM_DESTROY	- ���~���b�Z�[�W��\�����Ė߂�
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
		CreateWindow("Static", "P1", WS_CHILD | WS_VISIBLE, 100, 80, 80, 20, hWnd, NULL, hInst, NULL);
		CreateWindow("Static", "P2", WS_CHILD | WS_VISIBLE, 300, 80, 80, 20, hWnd, NULL, hInst, NULL);
		hCmbP1 = CreateWindow("ComboBox", "", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 100, 100, 80, 120, hWnd, (HMENU)IDC_COMBO_P1, hInst, NULL);
		hCmbP2 = CreateWindow("ComboBox", "", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 300, 100, 80, 120, hWnd, (HMENU)IDC_COMBO_P2, hInst, NULL);

		// Q1A
		CreateWindow("Button", "������", WS_CHILD | WS_VISIBLE, 100, 160, 80, 30, hWnd, (HMENU)IDC_BUTTON_AIKO, hInst, NULL);
		// Q1E

		// Q2A
		CreateWindow("Button", "����񂯂�(if)", WS_CHILD | WS_VISIBLE, 200, 160, 120, 30, hWnd, (HMENU)IDC_BUTTON_JANKENIF, hInst, NULL);
		// Q2E

		// Q3A
		CreateWindow("Button", "����񂯂�(switch)", WS_CHILD | WS_VISIBLE, 340, 160, 140, 30, hWnd, (HMENU)IDC_BUTTON_JANKENSW, hInst, NULL);
		// Q3E

		// Q4A
		CreateWindow("Button", "����񂯂�(?)", WS_CHILD | WS_VISIBLE, 500, 160, 160, 30, hWnd, (HMENU)IDC_BUTTON_JANKENQ, hInst, NULL);
		// Q4E

		// Q5A
		hStP1 = CreateWindow("Static", "0", WS_CHILD | WS_VISIBLE, 100, 130, 80, 20, hWnd, NULL, hInst, NULL);
		hStP2 = CreateWindow("Static", "0", WS_CHILD | WS_VISIBLE, 300, 130, 80, 20, hWnd, NULL, hInst, NULL);
#if 0 // Q6R
		//		win[0] = 0;
		//		win[1] = 0;
#else // Q6
		CreateWindow("Static", "P3", WS_CHILD | WS_VISIBLE, 500, 80, 80, 20, hWnd, NULL, hInst, NULL);
		hCmb[0] = hCmbP1;
		hCmb[1] = hCmbP2;
		hCmb[2] = CreateWindow("ComboBox", "", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 500, 100, 80, 120, hWnd, (HMENU)IDC_COMBO_P3, hInst, NULL);
		CreateWindow("Button", "3�l����񂯂�", WS_CHILD | WS_VISIBLE, 640, 160, 120, 30, hWnd, (HMENU)IDC_BUTTON_3JANKEN, hInst, NULL);
		hSt[0] = hStP1;
		hSt[1] = hStP2;
		hSt[2] = CreateWindow("Static", "0", WS_CHILD | WS_VISIBLE, 500, 130, 80, 20, hWnd, NULL, hInst, NULL);
		memset(win, 0, sizeof(win));
#endif // Q6E
		// Q5E

		ComboBox_AddString(hCmbP1, "�O�[");
		ComboBox_AddString(hCmbP1, "�`�[");
		ComboBox_AddString(hCmbP1, "�p�[");
		ComboBox_SetCurSel(hCmbP1, 0);
		ComboBox_AddString(hCmbP2, "�O�[");
		ComboBox_AddString(hCmbP2, "�`�[");
		ComboBox_AddString(hCmbP2, "�p�[");
		ComboBox_SetCurSel(hCmbP2, 0);
		// Q6A
		ComboBox_AddString(hCmb[2], "�O�[");
		ComboBox_AddString(hCmb[2], "�`�[");
		ComboBox_AddString(hCmb[2], "�p�[");
		ComboBox_SetCurSel(hCmb[2], 0);
		// Q6E

		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �I�����ꂽ���j���[�̉��:
		switch (wmId)
		{

			// Q1A
		case IDC_BUTTON_AIKO:
			MessageBox(hWnd, "�������ł��B", "", MB_OK);
			break;
			// Q1E

			// Q2A
		case IDC_BUTTON_JANKENIF:
		{
			int p1 = ComboBox_GetCurSel(hCmbP1);
			int p2 = ComboBox_GetCurSel(hCmbP2);
			BOOL p1Win = FALSE;
			BOOL p2Win = FALSE;
			if (p1 == 0){ //�O�[
				if (p2 == 1){
					p1Win = TRUE;
				}
				else if (p2 == 2){
					p2Win = TRUE;
				}
			}
			else if (p1 == 1){ //�`�[
				if (p2 == 2){
					p1Win = TRUE;
				}
				else if (p2 == 0){
					p2Win = TRUE;
				}
			}
			else{ //�p�[
				if (p2 == 0){
					p1Win = TRUE;
				}
				else if (p2 == 1){
					p2Win = TRUE;
				}
			}
			char sOut[100];
			memset(sOut, 0, sizeof(sOut));
			if (p1Win){
				strcpy(sOut, "P1�̂����ł�");
				// Q5A
				win[0]++;
				// Q5E
			}
			else if (p2Win){
				strcpy(sOut, "P2�̂����ł�");
				// Q5A
				win[1]++;
				// Q5E
			}
			else{
				strcpy(sOut, "�������ł��B");
			}
			MessageBox(hWnd, sOut, "", MB_OK);
			// Q5A
			char sNum[10];
			sprintf(sNum, "%d", win[0]);
			SetWindowText(hStP1, sNum);
			sprintf(sNum, "%d", win[1]);
			SetWindowText(hStP2, sNum);
			// Q5E
		}
		break;
		// Q2E

		// Q3A
		case IDC_BUTTON_JANKENSW:
		{
			int p1 = ComboBox_GetCurSel(hCmbP1);
			int p2 = ComboBox_GetCurSel(hCmbP2);
			BOOL p1Win = FALSE;
			BOOL p2Win = FALSE;
			switch (p1){
			case 0: //�O�[
				switch (p2){
				case 1:
					p1Win = TRUE;
					break;
				case 2:
					p2Win = TRUE;
					break;
				}
				break;
			case 1: //�`�[
				switch (p2){
				case 0:
					p2Win = TRUE;
					break;
				case 2:
					p1Win = TRUE;
					break;
				}
				break;
			default: //�p�[
				switch (p2){
				case 0:
					p1Win = TRUE;
					break;
				case 1:
					p2Win = TRUE;
					break;
				}
			}

			char sOut[100];
			memset(sOut, 0, sizeof(sOut));
			if (p1Win){
				strcpy(sOut, "P1�̂����ł�");
				// Q5A
				win[0]++;
				// Q5E
			}
			else if (p2Win){
				strcpy(sOut, "P2�̂����ł�");
				// Q5A
				win[1]++;
				// Q5E
			}
			else{
				strcpy(sOut, "�������ł��B");
			}
			MessageBox(hWnd, sOut, "", MB_OK);
			// Q5A
			char sNum[10];
			sprintf(sNum, "%d", win[0]);
			SetWindowText(hStP1, sNum);
			sprintf(sNum, "%d", win[1]);
			SetWindowText(hStP2, sNum);
			// Q5E
		}
		break;
		// Q3E

		// Q4A
		case IDC_BUTTON_JANKENQ:
		{
			int p1 = ComboBox_GetCurSel(hCmbP1);
			int p2 = ComboBox_GetCurSel(hCmbP2);
			BOOL p1Win = p1 == 0 ? p2 == 1 : (p1 == 1 ? p2 == 2 : p2 == 0);
			BOOL p2Win = p1 == 0 ? p2 == 2 : (p1 == 1 ? p2 == 0 : p2 == 1);
			char sOut[100];
			memset(sOut, 0, sizeof(sOut));
			if (p1Win){
				strcpy(sOut, "P1�̂����ł�");
				// Q5A
				win[0]++;
				// Q5E
			}
			else if (p2Win){
				strcpy(sOut, "P2�̂����ł�");
				// Q5A
				win[1]++;
				// Q5E
			}
			else{
				strcpy(sOut, "�������ł��B");
			}
			MessageBox(hWnd, sOut, "", MB_OK);
			// Q5A
			char sNum[10];
			sprintf(sNum, "%d", win[0]);
			SetWindowText(hStP1, sNum);
			sprintf(sNum, "%d", win[1]);
			SetWindowText(hStP2, sNum);
			// Q5E
		}
		break;
		// Q4E
		// Q6A
		case IDC_BUTTON_3JANKEN:
		{
			// ���[�v�����g�p�̉񓚗�(�킩��Ȃ��ꍇ�͎���ȍ~�u�`�����Q�Ɖ�����)
			// ����񂯂񌋉ʂ�z��ŕێ� TRUE:����/�������@FALSE:����
			BOOL jkResult[3][3] = { { TRUE, TRUE, FALSE }, { FALSE, TRUE, TRUE }, { TRUE, FALSE, TRUE } };

			int p[3];
			BOOL pWin[3];
			for (int i = 0; i < 3; i++){
				p[i] = ComboBox_GetCurSel(hCmb[i]);
				pWin[i] = TRUE;
			}
			// 3�l����񂯂�
			// 2�l����񂯂�ɕϊ����A���ꂼ�ꂪ�����Ă��Ȃ����𔻒f
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					if (i == j){
						continue;
					}
					if (pWin[i]){ //�������ꍇ�͂���񂯂�X�L�b�v
						pWin[i] = jkResult[p[i]][p[j]];
					}
				}
			}
			char sOut[100];
			memset(sOut, 0, sizeof(sOut));
			// �S�������ĂȂ�/��������������
			if (pWin[0] == pWin[1] && pWin[0] == pWin[2]){
				strcpy(sOut, "�������ł��B");
			}
			else{
				char sWin[10];
				memset(sWin, 0, sizeof(sWin));
				for (int i = 0; i < 3; i++){
					if (pWin[i]){
						if (sWin[0] == 0){
							sprintf(sWin, "P%d", i + 1);
						}
						else{
							char sTmp[10];
							memset(sTmp, 0, sizeof(sTmp));
							sprintf(sTmp, ",P%d", i + 1);
							strcat(sWin, sTmp);
						}
						win[i]++;
					}
				}
				sprintf(sOut, "%s�̂����ł��B", sWin);
			}
			MessageBox(hWnd, sOut, "", MB_OK);
			char sNum[10];
			for (int i = 0; i < 3; i++){
				sprintf(sNum, "%d", win[i]);
				SetWindowText(hSt[i], sNum);
			}
		}
		break;
		// Q6E

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: �`��R�[�h�������ɒǉ����Ă�������...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
