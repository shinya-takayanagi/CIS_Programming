// cpppro02_q.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "cpppro02_q.h"

// グローバル変数
HINSTANCE hInst;

// このコード モジュールに含まれる関数の宣言を転送します:
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);    
	UNREFERENCED_PARAMETER(nCmdShow);
	hInst = hInstance;
	return (int)DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), HWND_DESKTOP, About);
}

// バージョン情報ボックスのメッセージ ハンドラです。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message){
	case WM_INITDIALOG:
		ComboBox_AddString(GetDlgItem(hDlg, IDC_COMBO1), "+");
		ComboBox_AddString(GetDlgItem(hDlg, IDC_COMBO1), "-");
		ComboBox_AddString(GetDlgItem(hDlg, IDC_COMBO1), "*");
		ComboBox_AddString(GetDlgItem(hDlg, IDC_COMBO1), "/");
		ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_COMBO1), 0);
		ComboBox_AddString(GetDlgItem(hDlg, IDC_COMBO2), "&");
		ComboBox_AddString(GetDlgItem(hDlg, IDC_COMBO2), "|");
		ComboBox_AddString(GetDlgItem(hDlg, IDC_COMBO2), "^");
		ComboBox_SetCurSel(GetDlgItem(hDlg, IDC_COMBO2), 0);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL){
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}else if(LOWORD(wParam) == IDC_BUTTON1){
			//			unsigned short result = 0;
//			short value1 = 0;
//			short value2 = 0;
			double result = 0;
			double value1 = 0;
			double value2 = 0;
			char sBuf[256];

			GetWindowText(GetDlgItem(hDlg, IDC_EDIT1), sBuf, sizeof(sBuf) -1);
			value1 = atoi(sBuf);
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT2), sBuf, sizeof(sBuf) -1);
			value2 = atoi(sBuf);

			char sOut[256];
			memset(sOut, 0, sizeof(sOut));
			switch(ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_COMBO1))){
				case 0: // +
					result = value1 + value2;
					break;
				case 1: // -
					result = value1 - value2;
					break;
				case 2: // *
					result = value1 * value2;
					break;
				case 3: // /
					if(value2){
						result = value1 / value2;
					}
					break;
			}
//			sprintf(sOut, "結果は%dです。", result); // 整数値の場合
			sprintf(sOut, "結果は%fです。", result); // 小数値の場合
			MessageBox(hDlg, sOut, "結果", MB_OK);
		}else if(LOWORD(wParam) == IDC_BUTTON2){
			long result = 0;
			char sBuf[256];
			char sOut[256];			
			memset(sOut, 0, sizeof(sOut));
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT3), sBuf, sizeof(sBuf) - 1);
			result = strtol(sBuf, NULL, 0);
			sprintf(sOut, "結果は%xです。", ~result);
			MessageBox(hDlg, sOut, "結果", MB_OK);
		}else if(LOWORD(wParam) == IDC_BUTTON3){
			long result = 0;
			long value1 = 0;
			long value2 = 0;
			char sBuf[256];

			GetWindowText(GetDlgItem(hDlg, IDC_EDIT4), sBuf, sizeof(sBuf) -1);
			value1 = strtol(sBuf, NULL, 0);
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT5), sBuf, sizeof(sBuf) -1);
			value2 = strtol(sBuf, NULL, 0);

			char sOut[256];
			memset(sOut, 0, sizeof(sOut));
			switch(ComboBox_GetCurSel(GetDlgItem(hDlg, IDC_COMBO2))){
				case 0: // &
					result = value1 & value2;
					break;
				case 1: // |
					result = value1 | value2;
					break;
				case 2: // ^
					result = value1 ^ value2;
					break;
			}
			sprintf(sOut, "結果は%xです。", result);
			MessageBox(hDlg, sOut, "結果", MB_OK);
		}
		break;
	}
	return (INT_PTR)FALSE;
}
