/*
 * GPS Navigation ---An open source GPS navigation core software
 *
 *
 * Copyright (c) 2016  Hitachi, Ltd.
 *
 * This program is dual licensed under GPL version 2 or a commercial license.
 * See the LICENSE file distributed with this source file.
 */

#ifndef SMCORE_ROUTE_COST_CONFIG_INI_H
#define SMCORE_ROUTE_COST_CONFIG_INI_H

//-----------------------------------
// 構造体定義
//-----------------------------------
typedef struct _SC_COST_CONFIG {
	Bool				valid_f;									// ファイル読み込み成功有無

	// [Speed]
	struct {
		UINT32			road[SC_ROADTYPE_NUM][SC_LINKTYPE_NUM];		// 道路種別・リンク種別毎の速度
	} speed;
	// [Weight]
	struct {
		UINT32			road[SC_ROADTYPE_NUM][SC_LINKTYPE_NUM];		// 道路種別・リンク種別毎のコスト
	} weight;
	// [Turn]
	struct {
		UINT32			dir[SC_TURNTYPE_NUM];						// 転向コスト
		UINT32			apply_f[SC_ROADTYPE_NUM][SC_ROADTYPE_NUM];	// 進脱道路種別毎の転向コスト適用有無
	} turn;

} SC_COST_CONFIG;

typedef struct _SC_ROUTE_COST_CONFIG {
	// [Mode Path]
	struct {
		Char			folder[SC_MAX_PATH];						// フォルダパス
		Char			file[SC_SRCHMODE_NUM][SC_MAX_PATH];			// 探索モード別ファイル名
		SC_COST_CONFIG	cost[SC_SRCHMODE_NUM];						// 探索モード別コスト
	} mode;

} SC_ROUTE_COST_CONFIG;

#if 0
// 道路種別・リンク種別毎の初期速度
static UINT32 SC_ROUTE_COST_INIT_SPEED[SC_SRCHMODE_NUM][SC_ROADTYPE_NUM][SC_LINKTYPE_NUM] =
	{
		// Highway
		{{91,100,50,42,61,5,42,5,5,5,50,5,5},
		{55,60,30,25,36,5,25,5,5,5,30,5,5},
		{73,80,40,33,48,5,33,5,5,5,40,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5},
		{62,68,34,28,41,5,28,5,5,5,34,5,5},
		{45,50,25,21,30,5,21,5,5,5,25,5,5},
		{55,60,30,25,36,5,25,5,5,5,30,5,5},
		{41,45,23,19,27,5,19,5,5,5,23,5,5},
		{36,40,20,17,24,5,17,5,5,5,20,5,5},
		{27,30,15,13,18,5,13,5,5,5,15,5,5},
		{18,20,10,8,12,5,8,5,5,5,10,5,5},
		{18,20,10,8,12,5,8,5,5,5,10,5,5},
		{8,8,8,8,8,5,8,5,5,5,8,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5}},

		// Normal
		{{91,100,50,42,61,5,42,5,5,5,50,5,5},
		{55,60,30,25,36,5,25,5,5,5,30,5,5},
		{73,80,40,33,48,5,33,5,5,5,40,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5},
		{62,68,34,28,41,5,28,5,5,5,34,5,5},
		{45,50,25,21,30,5,21,5,5,5,25,5,5},
		{55,60,30,25,36,5,25,5,5,5,30,5,5},
		{41,45,23,19,27,5,19,5,5,5,23,5,5},
		{36,40,20,17,24,5,17,5,5,5,20,5,5},
		{27,30,15,13,18,5,13,5,5,5,15,5,5},
		{18,20,10,8,12,5,8,5,5,5,10,5,5},
		{18,20,10,8,12,5,8,5,5,5,10,5,5},
		{8,8,8,8,8,5,8,5,5,5,8,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5}},

		// Time
		{{91,100,50,42,61,5,42,5,5,5,50,5,5},
		{55,60,30,25,36,5,25,5,5,5,30,5,5},
		{73,80,40,33,48,5,33,5,5,5,40,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5},
		{62,68,34,28,41,5,28,5,5,5,34,5,5},
		{45,50,25,21,30,5,21,5,5,5,25,5,5},
		{55,60,30,25,36,5,25,5,5,5,30,5,5},
		{41,45,23,19,27,5,19,5,5,5,23,5,5},
		{36,40,20,17,24,5,17,5,5,5,20,5,5},
		{27,30,15,13,18,5,13,5,5,5,15,5,5},
		{18,20,10,8,12,5,8,5,5,5,10,5,5},
		{18,20,10,8,12,5,8,5,5,5,10,5,5},
		{8,8,8,8,8,5,8,5,5,5,8,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5}},

		// Distance
		{{91,100,50,42,61,5,42,5,5,5,50,5,5},
		{55,60,30,25,36,5,25,5,5,5,30,5,5},
		{73,80,40,33,48,5,33,5,5,5,40,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5},
		{62,68,34,28,41,5,28,5,5,5,34,5,5},
		{45,50,25,21,30,5,21,5,5,5,25,5,5},
		{55,60,30,25,36,5,25,5,5,5,30,5,5},
		{41,45,23,19,27,5,19,5,5,5,23,5,5},
		{36,40,20,17,24,5,17,5,5,5,20,5,5},
		{27,30,15,13,18,5,13,5,5,5,15,5,5},
		{18,20,10,8,12,5,8,5,5,5,10,5,5},
		{18,20,10,8,12,5,8,5,5,5,10,5,5},
		{8,8,8,8,8,5,8,5,5,5,8,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5},
		{5,5,5,5,5,5,5,5,5,5,5,5,5}}
	};

// 道路種別・リンク種別毎の初期コスト
static UINT32 SC_ROUTE_COST_INIT_WEIGHT[SC_SRCHMODE_NUM][SC_ROADTYPE_NUM][SC_LINKTYPE_NUM] =
	{
		// Highway
		{{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{120,120,120,120,120,120,120,120,120,120,120,120,120},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{110,110,110,110,110,110,110,110,110,110,110,110,110},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100}},

		// Normal
		{{220,220,220,220,220,220,220,220,220,220,220,220,220},
		{220,220,220,220,220,220,220,220,220,220,220,220,220},
		{220,220,220,220,220,220,220,220,220,220,220,220,220},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100}},

		// Time
		{{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100}},

		// Distance
		{{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100,100,100,100,100}}
	};

// 道路種別毎の初期転向コスト
static UINT32 SC_ROUTE_COST_INIT_TURN[SC_SRCHMODE_NUM][SC_TURNTYPE_NUM] =
	{
		// Highway
		{12000,6000,5500,5000,4000,3500,500,300,0,200,300,1500,3000,3000,3500,4000},
		// Normal
		{12000,6000,5500,5000,4000,3500,500,300,0,200,300,1500,3000,3000,3500,4000},
		// Time
		{12000,6000,5500,5000,4000,3500,500,300,0,200,300,1500,3000,3000,3500,4000},
		// Distance
		{12000,6000,5500,5000,4000,3500,500,300,0,200,300,1500,3000,3000,3500,4000}
	};

// 道路種別毎の初期転向コスト
static UINT8 SC_ROUTE_COST_INIT_TURN_APPLY[SC_SRCHMODE_NUM][SC_ROADTYPE_NUM][SC_ROADTYPE_NUM] =
	{
		// Highway
		{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1}},

		// Normal
		{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1}},

		// Time
		{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1}},

		// Distance
		{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1}}
	};
#else
extern UINT32 SC_ROUTE_COST_INIT_SPEED[SC_SRCHMODE_NUM][SC_ROADTYPE_NUM][SC_LINKTYPE_NUM];
extern UINT32 SC_ROUTE_COST_INIT_WEIGHT[SC_SRCHMODE_NUM][SC_ROADTYPE_NUM][SC_LINKTYPE_NUM];
extern UINT32 SC_ROUTE_COST_INIT_TURN[SC_SRCHMODE_NUM][SC_TURNTYPE_NUM];
extern UINT8 SC_ROUTE_COST_INIT_TURN_APPLY[SC_SRCHMODE_NUM][SC_ROADTYPE_NUM][SC_ROADTYPE_NUM];
#endif

//-----------------------------------
// 外部I/F定義
//-----------------------------------
E_SC_RESULT SC_CONFIG_LoadRouteCostConfig(const Char *fileName, SC_ROUTE_COST_CONFIG *config);
E_SC_RESULT SC_CONFIG_SaveRouteCostConfig(const Char *fileName, SC_ROUTE_COST_CONFIG *config);

#endif // #ifndef SMCORE_ROUTE_COST_CONFIG_INI_H
