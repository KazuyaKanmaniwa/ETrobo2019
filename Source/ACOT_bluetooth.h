//作者：上馬庭
//日付：20180921

#ifndef ACOT_BLUETOOTH_H_
#define ACOT_BLUETOOTH_H_

//Bluetoothのシリアルポート
#define BT_SERIAL_PORT EV3_SERIAL_BT
//スタート判定のコマンド
#define BT_START_COMMAND '1'

//Bluetooth初期化設定
void bluetooth_init();
//通信を受け取った判定　返り値：true,false
int is_bluetooth_signal();

#endif


