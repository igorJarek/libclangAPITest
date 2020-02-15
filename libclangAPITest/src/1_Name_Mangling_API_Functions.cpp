#include "1_Name_Mangling_API_Functions.h"

void _1_printMangling(string& strData, const CXCursor& cursor, uint32_t curLevel)
{
	CXString mangling = clang_Cursor_getMangling(cursor);
	CXStringSet* CXXManglings = clang_Cursor_getCXXManglings(cursor);

	strData += tabOffset(curLevel + 1) + "Mangling : " + '\n';
	strData += tabOffset(curLevel + 2) + "clang_Cursor_getMangling : " + _11_CXString2String(mangling) + '\n';
	strData += tabOffset(curLevel + 2) + "clang_Cursor_getCXXManglings : " + '\n';

	vector<string> CXXManglingsStrings = _11_CXStringSet2StringVec(CXXManglings);
	for (string str : CXXManglingsStrings)
		strData += tabOffset(curLevel + 3) + str + '\n';

	_11_releaseCXStringSet(CXXManglings);
}

