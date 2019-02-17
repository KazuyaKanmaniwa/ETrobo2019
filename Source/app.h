
/******いじらないでね💛******/

#include "ev3api.h"

/*
 *  ターゲット依存の定義
 */
#include "target_test.h"

 /*
  *  各タスクの優先度の定義
  */

#define MAIN_PRIORITY	5		/* メインタスクの優先度 */
  /* HIGH_PRIORITYより高くすること */

#define HIGH_PRIORITY	9		/* 並行実行されるタスクの優先度 */
#define MID_PRIORITY	10
#define LOW_PRIORITY	11

/*
 *  ターゲットに依存する可能性のある定数の定義
 */

#ifndef STACK_SIZE
#define	STACK_SIZE		4096		/* タスクのスタックサイズ */
#endif /* STACK_SIZE */

 /*
  *  関数のプロトタイプ宣言
  */
#ifndef TOPPERS_MACRO_ONLY

#include <stdio.h>

#define MENU_FONT (EV3_FONT_MEDIUM)
#define MENU_FONT_WIDTH (default_menu_font_width)
#define MENU_FONT_HEIGHT (default_menu_font_height)

  /**
   * Tasks
   */

extern void	main_task(intptr_t exinf);

#endif /* TOPPERS_MACRO_ONLY */

