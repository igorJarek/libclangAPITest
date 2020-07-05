#include "1_Name_Mangling_API_Functions.h"

void _1_printMangling(string& strData, const CXCursor& cursor, const uint32_t curLevel)
{
    CXString     mangling     = clang_Cursor_getMangling(cursor);                                             // 1.
    CXStringSet* CXXManglings = clang_Cursor_getCXXManglings(cursor);                                         // 2.

    ADD_STRING_OUT_NAME (curLevel + 1, "1. Mangling : ")
    ADD_STRING_OUT_NL   (curLevel + 2, "clang_Cursor_getMangling : ", CXString2String(mangling))
    ADD_STRING_OUT_NAME (curLevel + 2, "clang_Cursor_getCXXManglings : ")

    vector<string> CXXManglingsStrings = CXStringSet2StringVec(CXXManglings);
    for (string manglingString : CXXManglingsStrings)
        ADD_STRING_OUT_NAME(curLevel + 3, manglingString)
}

CXString        _1_getMangling          (CXCursor C) 
                                        { return clang_Cursor_getMangling(C); }

CXStringSet*    _1_getCXXManglings      (CXCursor C)
                                        { return clang_Cursor_getCXXManglings(C); }

CXStringSet*    _1_getObjCManglings     (CXCursor C)
                                        { return clang_Cursor_getObjCManglings(C); }