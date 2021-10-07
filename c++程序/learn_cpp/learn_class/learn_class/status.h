#include "iostream"
using namespace std;

struct value
{
	double x;
	double y;
	double z;
};

class status
{
public:
	status(value accel, value speed, value posit,double time);
	~status();
	void set_accel(value accel);
	void set_speed(value speed);
	void set_posit(value posit);
	void set_dutation(double time);
	void show();
private:
	value org_speed;
	value org_accel;
	value org_posit;
	double duration;
};

status::status(value speed, value accel, value posit, double  time)
{
	org_accel = accel;
	org_speed = speed;
	org_posit = posit;
	duration = time;
}

status::~status()
{
	
}

void status::show()
{
	cout << "��״̬��ʼ���ٶ�Ϊ X: "<<org_accel.x<<" Y: "<< org_accel.y << " Z: "<<org_accel.z <<endl;
	cout << "��״̬��ʼ�ٶ�Ϊ X: " << org_speed.x << " Y: " << org_speed.y << " Z: " << org_speed.z << endl;
	cout << "��״̬��ʼλ��Ϊ X: " << org_posit.x << " Y: " << org_posit.y << " Z: " << org_posit.z << endl;
	cout << "���˶�״̬����ʱ��Ϊ: " << duration << endl;
}

void status::set_accel(value accel)
{
	org_accel = accel;
}
void status::set_speed(value speed)
{
	org_speed = speed;
}
void status::set_posit(value posit)
{
	org_posit = posit;
}