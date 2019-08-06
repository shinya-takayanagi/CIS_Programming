// cpppro03_q.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "cpppro03_q.h"

#define MAX_LOADSTRING 100

// グローバル変数:
HINSTANCE hInst;								// 現在のインターフェイス
TCHAR szTitle[MAX_LOADSTRING];					// タイトル バーのテキスト
TCHAR szWindowClass[MAX_LOADSTRING];			// メイン ウィンドウ クラス名

HWND hCmbP1;
HWND hCmbP2;

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

		ComboBox_AddString(hCmbP1, "グー");
		ComboBox_AddString(hCmbP1, "チー");
		ComboBox_AddString(hCmbP1, "パー");
		ComboBox_SetCurSel(hCmbP1, 0);
		ComboBox_AddString(hCmbP2, "グー");
		ComboBox_AddString(hCmbP2, "チー");
		ComboBox_AddString(hCmbP2, "パー");
		ComboBox_SetCurSel(hCmbP2, 0);

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
			}
			else if (p2Win){
				strcpy(sOut, "P2のかちです");
			}
			else{
				strcpy(sOut, "あいこです。");
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
