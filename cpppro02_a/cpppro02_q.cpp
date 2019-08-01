// cpppro02_q.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "cpppro02_q.h"

// グローバル変数
HINSTANCE hInst;

// このコード モジュールに含まれる関数の宣言を転送します:
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
// Q6A
INT_PTR CALLBACK	BmiWindowProc(HWND, UINT, WPARAM, LPARAM);
// Q6E

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
#if 0 // Q2R
//			short result = 0;
//			short value1 = 0;
//			short value2 = 0;
#else // Q2
#if 0 // Q3R
//			unsigned short result = 0;
//			unsigned short value1 = 0;
//			unsigned short value2 = 0;
#else // Q3
			double result = 0;
			double value1 = 0;
			double value2 = 0;
#endif // Q3E
#endif // Q2E
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
#if 0 // Q3R
//			sprintf(sOut, "結果は%dです。", result); // 整数値の場合
////			sprintf(sOut, "結果は%fです。", result); // 小数値の場合
#else // Q3
			sprintf(sOut, "結果は%fです。", result); // 小数値の場合
#endif // Q3E
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
// Q6A
		}else if(LOWORD(wParam) == IDC_BUTTON4){
			DialogBox(hInst, MAKEINTRESOURCE(IDD_BMIWINDOW), hDlg, BmiWindowProc);
// Q6E
		}
		break;
	}
	return (INT_PTR)FALSE;
}
// Q6A
INT_PTR CALLBACK BmiWindowProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message){
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;
		break;
	case WM_COMMAND:
		if(LOWORD(wParam) == IDC_BUTTON_CALC){
// Q7A
			double result = 0;
			double value1 = 0;
			double value2 = 0;
			char sBuf[256];
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT_HEIGHT), sBuf, sizeof(sBuf) -1);
			value1 = atof(sBuf);
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT_WEIGHT), sBuf, sizeof(sBuf) -1);
			value2 = atof(sBuf);
			result = value2 / (value1/100) / (value1/100); 

			char sOut[256];
			memset(sOut, 0, sizeof(sOut));
			sprintf(sOut, "結果は%fです。", result);
			MessageBox(hDlg, sOut, "結果", MB_OK);
// Q7E
		}else if(LOWORD(wParam) == IDCANCEL){
			EndDialog(hDlg, NULL);
		}
		break;
	}
	return (INT_PTR)FALSE;
}
// Q6E