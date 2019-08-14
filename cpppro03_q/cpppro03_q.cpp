// cpppro03_q.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "cpppro03_q.h"
// Q5A
#include <stdio.h>
// Q5E

#define MAX_LOADSTRING 100

// グローバル変数:
HINSTANCE hInst;								// 現在のインターフェイス
TCHAR szTitle[MAX_LOADSTRING];					// タイトル バーのテキスト
TCHAR szWindowClass[MAX_LOADSTRING];			// メイン ウィンドウ クラス名

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

// このコード モジュールに含まれる関数の宣言を転送します:
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

 	// TODO: ここにコードを挿入してください。
	MSG msg;

	// グローバル文字列を初期化しています。
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_CPPPRO03_Q, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// アプリケーションの初期化を実行します:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	// メイン メッセージ ループ:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}



//
//  関数: MyRegisterClass()
//
//  目的: ウィンドウ クラスを登録します。
//
//  コメント:
//
//    この関数および使い方は、'RegisterClassEx' 関数が追加された
//    Windows 95 より前の Win32 システムと互換させる場合にのみ必要です。
//    アプリケーションが、関連付けられた
//    正しい形式の小さいアイコンを取得できるようにするには、
//    この関数を呼び出してください。
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
//   関数: InitInstance(HINSTANCE, int)
//
//   目的: インスタンス ハンドルを保存して、メイン ウィンドウを作成します。
//
//   コメント:
//
//        この関数で、グローバル変数でインスタンス ハンドルを保存し、
//        メイン プログラム ウィンドウを作成および表示します。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // グローバル変数にインスタンス処理を格納します。

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
//  関数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:  メイン ウィンドウのメッセージを処理します。
//
//  WM_COMMAND	- アプリケーション メニューの処理
//  WM_PAINT	- メイン ウィンドウの描画
//  WM_DESTROY	- 中止メッセージを表示して戻る
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
		CreateWindow("Button", "あいこ", WS_CHILD | WS_VISIBLE, 100, 160, 80, 30, hWnd, (HMENU)IDC_BUTTON_AIKO, hInst, NULL);
		// Q1E

		// Q2A
		CreateWindow("Button", "じゃんけん(if)", WS_CHILD | WS_VISIBLE, 200, 160, 120, 30, hWnd, (HMENU)IDC_BUTTON_JANKENIF, hInst, NULL);
		// Q2E

		// Q3A
		CreateWindow("Button", "じゃんけん(switch)", WS_CHILD | WS_VISIBLE, 340, 160, 140, 30, hWnd, (HMENU)IDC_BUTTON_JANKENSW, hInst, NULL);
		// Q3E

		// Q4A
		CreateWindow("Button", "じゃんけん(?)", WS_CHILD | WS_VISIBLE, 500, 160, 160, 30, hWnd, (HMENU)IDC_BUTTON_JANKENQ, hInst, NULL);
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
		CreateWindow("Button", "3人じゃんけん", WS_CHILD | WS_VISIBLE, 640, 160, 120, 30, hWnd, (HMENU)IDC_BUTTON_3JANKEN, hInst, NULL);
		hSt[0] = hStP1;
		hSt[1] = hStP2;
		hSt[2] = CreateWindow("Static", "0", WS_CHILD | WS_VISIBLE, 500, 130, 80, 20, hWnd, NULL, hInst, NULL);
		memset(win, 0, sizeof(win));
#endif // Q6E
		// Q5E

		ComboBox_AddString(hCmbP1, "グー");
		ComboBox_AddString(hCmbP1, "チー");
		ComboBox_AddString(hCmbP1, "パー");
		ComboBox_SetCurSel(hCmbP1, 0);
		ComboBox_AddString(hCmbP2, "グー");
		ComboBox_AddString(hCmbP2, "チー");
		ComboBox_AddString(hCmbP2, "パー");
		ComboBox_SetCurSel(hCmbP2, 0);
		// Q6A
		ComboBox_AddString(hCmb[2], "グー");
		ComboBox_AddString(hCmb[2], "チー");
		ComboBox_AddString(hCmb[2], "パー");
		ComboBox_SetCurSel(hCmb[2], 0);
		// Q6E

		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 選択されたメニューの解析:
		switch (wmId)
		{

			// Q1A
		case IDC_BUTTON_AIKO:
			MessageBox(hWnd, "あいこです。", "", MB_OK);
			break;
			// Q1E

			// Q2A
		case IDC_BUTTON_JANKENIF:
		{
			int p1 = ComboBox_GetCurSel(hCmbP1);
			int p2 = ComboBox_GetCurSel(hCmbP2);
			BOOL p1Win = FALSE;
			BOOL p2Win = FALSE;
			if (p1 == 0){ //グー
				if (p2 == 1){
					p1Win = TRUE;
				}
				else if (p2 == 2){
					p2Win = TRUE;
				}
			}
			else if (p1 == 1){ //チー
				if (p2 == 2){
					p1Win = TRUE;
				}
				else if (p2 == 0){
					p2Win = TRUE;
				}
			}
			else{ //パー
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
				strcpy(sOut, "P1のかちです");
				// Q5A
				win[0]++;
				// Q5E
			}
			else if (p2Win){
				strcpy(sOut, "P2のかちです");
				// Q5A
				win[1]++;
				// Q5E
			}
			else{
				strcpy(sOut, "あいこです。");
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
			case 0: //グー
				switch (p2){
				case 1:
					p1Win = TRUE;
					break;
				case 2:
					p2Win = TRUE;
					break;
				}
				break;
			case 1: //チー
				switch (p2){
				case 0:
					p2Win = TRUE;
					break;
				case 2:
					p1Win = TRUE;
					break;
				}
				break;
			default: //パー
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
				strcpy(sOut, "P1のかちです");
				// Q5A
				win[0]++;
				// Q5E
			}
			else if (p2Win){
				strcpy(sOut, "P2のかちです");
				// Q5A
				win[1]++;
				// Q5E
			}
			else{
				strcpy(sOut, "あいこです。");
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
				strcpy(sOut, "P1のかちです");
				// Q5A
				win[0]++;
				// Q5E
			}
			else if (p2Win){
				strcpy(sOut, "P2のかちです");
				// Q5A
				win[1]++;
				// Q5E
			}
			else{
				strcpy(sOut, "あいこです。");
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
			// ループ処理使用の回答例(わからない場合は次回以降講義資料参照下さい)
			// じゃんけん結果を配列で保持 TRUE:勝ち/あいこ　FALSE:負け
			BOOL jkResult[3][3] = { { TRUE, TRUE, FALSE }, { FALSE, TRUE, TRUE }, { TRUE, FALSE, TRUE } };

			int p[3];
			BOOL pWin[3];
			for (int i = 0; i < 3; i++){
				p[i] = ComboBox_GetCurSel(hCmb[i]);
				pWin[i] = TRUE;
			}
			// 3人じゃんけん
			// 2人じゃんけんに変換し、それぞれが負けていないかを判断
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					if (i == j){
						continue;
					}
					if (pWin[i]){ //負けた場合はじゃんけんスキップ
						pWin[i] = jkResult[p[i]][p[j]];
					}
				}
			}
			char sOut[100];
			memset(sOut, 0, sizeof(sOut));
			// 全員負けてない/負けた＝あいこ
			if (pWin[0] == pWin[1] && pWin[0] == pWin[2]){
				strcpy(sOut, "あいこです。");
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
				sprintf(sOut, "%sのかちです。", sWin);
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
		// TODO: 描画コードをここに追加してください...
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
