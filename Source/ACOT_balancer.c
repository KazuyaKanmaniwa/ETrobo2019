//��ҁF��n��
//���t�F20180921

#include "ACOT_balancer.h"
#include "ACOT_gyro_sensor.h"
#include "ACOT_wheel.h"
#include "ACOT_debug.h"
#include "ev3api.h"
#include "EV3_balancer.h"

signed char wheel_power_L;
signed char wheel_power_R;
int wheel_power[] = { 0,0 };

//�o�����T�[������
void acot_balancer_init() {
	gyro_sensor_init();//�W���C���Z���T�[������
	balance_init();//EV3�o�����T�[������
}

//�ԑ̂��|�ꂽ���� �Ԃ�l�Ftrue,false
bool_t is_balancer_down() {
	if (get_gyro_sensor_rate() > 300 || get_gyro_sensor_rate() < -300) {
		return true;
	}
	else {
		return false;
	}
}

//�o�����T�[����i�O�i����p���[�APID����̌v�Z�l�A�E�ԗւ̉�]�p�A���ԗւ̉�]�p�j�Ԃ�l�F�ԗւ̃p���[�z��
//�|���U�q�̌v�Z�����Ďԗւ̃p���[�𓱂�
int * acot_balance_control(signed char forward, signed char turn, int32_t wheel_counts_R, int32_t wheel_counts_L) {

	int gyro_accel_rate = get_gyro_sensor_rate();
	int volt = ev3_battery_voltage_mV();

	backlash_cancel(wheel_power_L, wheel_power_R, &wheel_counts_L, &wheel_counts_R);

	balance_control((float)forward, 
					(float)turn, 
					(float)gyro_accel_rate, 
					(float)GYRO_OFFSET, 
					(float)wheel_counts_L, 
					(float)wheel_counts_R,
					(float)volt,
					(signed char*)&wheel_power_L, 
					(signed char*)&wheel_power_R);

	wheel_power[0] = (int)wheel_power_R;
	wheel_power[1] = (int)wheel_power_L;

	return wheel_power;
}

//�o�����T�[�̐����}���i���ԗւ̃p���[�A�E�ԗւ̃p���[�A���ԗւ̉�]�p�A�E�ԗւ̉�]�p�j
void backlash_cancel(signed char wheel_power_L, signed char wheel_power_R, int32_t *wheel_counts_L, int32_t *wheel_counts_R)
{
	const int BACKLASHHALF = 4;   // �o�b�N���b�V���̔���[deg]

	if (wheel_power_L < 0) *wheel_counts_L += BACKLASHHALF;
	else if (wheel_power_L > 0) *wheel_counts_L -= BACKLASHHALF;

	if (wheel_power_R < 0) *wheel_counts_R += BACKLASHHALF;
	else if (wheel_power_R > 0) *wheel_counts_R -= BACKLASHHALF;
}

