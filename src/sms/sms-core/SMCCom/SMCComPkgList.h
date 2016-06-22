/*
 * GPS Navigation ---An open source GPS navigation core software
 *
 *
 * Copyright (c) 2016  Hitachi, Ltd.
 *
 * This program is dual licensed under GPL version 2 or a commercial license.
 * See the LICENSE file distributed with this source file.
 */

#ifndef SMCCOM_PKG_LIST_H
#define SMCCOM_PKG_LIST_H

//---------------------------------------------------------------------------------
//インクルード
//---------------------------------------------------------------------------------


//---------------------------------------------------------------------------------
//外部関数宣言
//---------------------------------------------------------------------------------
E_SC_RESULT CC_PkgList(const Char *dirPath, SMPACKAGEINFO *pkgInfo, INT32 *pkgInfoNum);

#endif // #ifndef SMCCOM_PKG_LIST_H
