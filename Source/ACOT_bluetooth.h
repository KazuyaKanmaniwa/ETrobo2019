//��ҁF��n��
//���t�F20180921

#ifndef ACOT_BLUETOOTH_H_
#define ACOT_BLUETOOTH_H_

//Bluetooth�̃V���A���|�[�g
#define BT_SERIAL_PORT EV3_SERIAL_BT
//�X�^�[�g����̃R�}���h
#define BT_START_COMMAND '1'

//Bluetooth�������ݒ�
void bluetooth_init();
//�ʐM���󂯎��������@�Ԃ�l�Ftrue,false
int is_bluetooth_signal();

#endif


