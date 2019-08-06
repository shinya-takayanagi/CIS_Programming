// cpppro03_q.cpp : �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "cpppro03_q.h"

#define MAX_LOADSTRING 100

// �O���[�o���ϐ�:
HINSTANCE hInst;								// ���݂̃C���^�[�t�F�C�X
TCHAR szTitle[MAX_LOADSTRING];					// �^�C�g�� �o�[�̃e�L�X�g
TCHAR szWindowClass[MAX_LOADSTRING];			// ���C�� �E�B���h�E �N���X��

HWND hCmbP1;
HWND hCmbP2;

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

		ComboBox_AddString(hCmbP1, "�O�[");
		ComboBox_AddString(hCmbP1, "�`�[");
		ComboBox_AddString(hCmbP1, "�p�[");
		ComboBox_SetCurSel(hCmbP1, 0);
		ComboBox_AddString(hCmbP2, "�O�[");
		ComboBox_AddString(hCmbP2, "�`�[");
		ComboBox_AddString(hCmbP2, "�p�[");
		ComboBox_SetCurSel(hCmbP2, 0);

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
			}
			else if (p2Win){
				strcpy(sOut, "P2�̂����ł�");
			}
			else{
				strcpy(sOut, "�������ł��B");
			}
			MessageBox(hWnd, sOut, "", MB_OK);
		}
		break;
		// Q2E

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
